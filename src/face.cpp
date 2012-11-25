#include "general.h"
#include "face.h"

using namespace face;

FaceDetect::FaceDetect(){
  FACE_CLASSIFIER_SCALE = 1.1;
  EYE_CLASSIFIER_SCALE = 1.1;
	MIN_FACE_DETECT_SIZE = 40;
	MAX_FACE_DETECT_SIZE = 200;
	MIN_EYE_DETECT_SIZE = 6;
	MAX_EYE_DETECT_SIZE = 30;
  eye_classifier_name = "/home/rajeev/Program\ Files/OpenCV-2.4.3/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
  face_classifier_name = "/home/rajeev/Program\ Files/OpenCV-2.4.3/data/haarcascades/haarcascade_frontalface_alt.xml";
  
  if (!face_classifier.load(face_classifier_name))
    cerr << "Face Detection Classifier cannot be loaded" << endl;
  if (!eye_classifier.load(eye_classifier_name))
    cerr << "Eye Detection Classifier cannot be loaded" << endl; 
}
  
double FaceDetect::detect_face(vector <Rect> &face_pos, vector <struct Eye> &eye, Mat &img, double scale, string mode){
  double tt, dt;
  struct Eye eye_pos;
  Mat scaled_img(cvRound(img.rows/scale),cvRound(img.cols/scale),CV_8UC1), face_ROI, gray_img;
  if (img.dims > 1) 
    cvtColor(img, gray_img, CV_RGB2GRAY);
  else
    gray_img = img;
    
  resize(gray_img, scaled_img, scaled_img.size(), 0, 0, INTER_LINEAR );
  equalizeHist(scaled_img, scaled_img);
  
  tt = (double)getTickCount();
  face_classifier.detectMultiScale(scaled_img, face_pos, FACE_CLASSIFIER_SCALE,
                                  3, // Number of neighbours
                                  (0 | CV_HAAR_SCALE_IMAGE), 
                                  Size(MIN_FACE_DETECT_SIZE, MIN_FACE_DETECT_SIZE),
                                  Size(MAX_FACE_DETECT_SIZE, MAX_FACE_DETECT_SIZE));
  for(vector <Rect>::const_iterator r = face_pos.begin(); r != face_pos.end(); r++){
    face_ROI = scaled_img(*r);
    FaceDetect::detect_eyes(eye_pos, face_ROI);
    eye_pos.left_pos.x = (r->x + eye_pos.left_pos.x)*scale;
    eye_pos.left_pos.y = (r->y + eye_pos.left_pos.y)*scale;
    eye_pos.right_pos.x = (r->x + eye_pos.right_pos.x)*scale;
    eye_pos.right_pos.y = (r->y + eye_pos.right_pos.y)*scale;
    eye.push_back(eye_pos);
  }
  
  tt = (double)getTickCount() - tt;
  dt = tt/((double)getTickFrequency());
  //cout << "Face Detection time = " << tt/((double)getTickFrequency()*1000)<< " ms" << endl;
  return dt;
}

void FaceDetect::detect_eyes(struct Eye &eye_pos, Mat &img){
  double radius, radius1 = -1, radius2 = -1;
  Point2f center, center1, center2;
  vector <Rect> eye_objects;
  eye_classifier.detectMultiScale(img, eye_objects, FACE_CLASSIFIER_SCALE,
                                  3, // Number of neighbours
                                  (0 | CV_HAAR_SCALE_IMAGE), 
                                  Size(MIN_EYE_DETECT_SIZE, MIN_EYE_DETECT_SIZE),
                                  Size(MAX_EYE_DETECT_SIZE, MAX_EYE_DETECT_SIZE));
  for(vector <Rect>::const_iterator r = eye_objects.begin(); r != eye_objects.end(); r++){
    radius = 0.25*(r->width + r->height);
    center.x = r->x + r->width*0.5;
    center.y = r->y + r->height*0.5;
    if (radius > radius1){
      radius2 = radius1;
      center2.x = center1.x;
      center2.y = center1.y;
      radius1 = radius;
      center1.x = center.x;
      center1.y = center.y;
    }
    else if (radius > radius2){
      radius2 = radius;
      center2.x = center.x;
      center2.y = center.y;
    }
  }
  if (center1.x < center2.x){
    eye_pos.left_pos.x = center2.x;
    eye_pos.left_pos.y = center2.y;
    eye_pos.left_radius = radius2;
    eye_pos.right_pos.x = center1.x;
    eye_pos.right_pos.y = center1.y;
    eye_pos.right_radius = radius1;
  }
  else {
    eye_pos.left_pos.x = center1.x;
    eye_pos.left_pos.y = center1.y;
    eye_pos.left_radius = radius1;
    eye_pos.right_pos.x = center2.x;
    eye_pos.right_pos.y = center2.y;
    eye_pos.right_radius = radius2;
  }
  return;
}

void FaceDetect::draw_face(vector <Rect> &face_pos, vector <struct Eye> & eye_pos, Mat &img, bool eye_flag){
  Point pt1,pt2;
  for(int i=0; i<face_pos.size(); i++){
    pt1.x = face_pos[i].x;
    pt1.y = face_pos[i].y;
    pt2.x = pt1.x + face_pos[i].width;
    pt2.y = pt1.y + face_pos[i].height;
    rectangle(img,pt1,pt2,CV_RGB(0,0,255),1,8,0);
    if (eye_flag){
      circle(img, eye_pos[i].left_pos, eye_pos[i].left_radius, CV_RGB(0,0,255), 1, 8, 0);
      circle(img, eye_pos[i].right_pos, eye_pos[i].right_radius, CV_RGB(0,0,255), 1, 8, 0);
    }
  }
  return;
}

void FaceRecognize::load(string file_name){
  eigen_recognizer->load(file_name + "_eigen.xml");
  fisher_recognizer->load(file_name + "_fisher.xml");
  lbph_recognizer->load(file_name + "_lbph.xml");
  string face_name_file = file_name + "_names.csv";
  ifstream file(face_name_file.c_str(), ifstream::in);
  if (!file)
    throw std::exception();
  string line, name;
  while (getline(file, line)) {
    stringstream liness(line);
    getline(liness, name);  
    face_name.push_back(name);
  }
}

void FaceRecognize::recognize_face(vector <string> &name, vector <double> &confidence, vector <int> &label, vector <Rect> &face_pos, Mat &img, string classifier){
  Mat scaled_img;
  int eigen_prediction, fisher_prediction, lbph_prediction, N = face_pos.size();
  double eigen_confidence, fisher_confidence, lbph_confidence; 
  
  confidence.resize(N);
  label.resize(N);
  name.resize(N);
  for (int i=0; i<N; i++){
    resize(img(face_pos[i]), scaled_img, Size(FACE_RECOGNIZE_SIZE, FACE_RECOGNIZE_SIZE), 0, 0, INTER_LINEAR );   
    eigen_prediction = -1; fisher_prediction = -1; lbph_prediction = -1;
    eigen_confidence = -1; fisher_confidence = -1; lbph_confidence = -1; 
    label.push_back(-1);
    confidence.push_back(-1);
    
    if (classifier == "eigen" || classifier == "majority" || classifier == "all")
      eigen_recognizer->predict(scaled_img,eigen_prediction,eigen_confidence);
    if (classifier == "fisher" || classifier == "majority" || classifier == "all")
      fisher_recognizer->predict(scaled_img,fisher_prediction,fisher_confidence);
    if (classifier == "lbph" || classifier == "majority" || classifier == "all")
      lbph_recognizer->predict(scaled_img,lbph_prediction,lbph_confidence);
    
    if (classifier == "eigen"){
      label[i] = eigen_prediction;
      confidence[i] = eigen_confidence;
    }
    else if (classifier == "fisher"){
      label[i] = fisher_prediction;
      confidence[i] = fisher_confidence;
    }
    else if (classifier == "lbph"){
      label[i] = lbph_prediction;
      confidence[i] = lbph_confidence;
    }
    else if (classifier == "majority"){
      if (eigen_prediction == fisher_prediction || eigen_prediction == lbph_prediction)
        label[i] = eigen_prediction;
      else if (fisher_prediction == lbph_prediction)
        label[i] = fisher_prediction;
      else
        label[i] = -1;
      confidence[i] = -1;
    }
    else { //"all" 
      if (eigen_prediction == fisher_prediction && eigen_prediction == lbph_prediction)
        label[i] = eigen_prediction;
      else
        label[i] = -1;
      confidence[i] = fisher_confidence;
    }
    
    if (label[i] == -1)
      name[i] = "Unknown";
    else
      name[i] = face_name[label[i]];
  }   
}

void FaceRecognize::label_face(Mat &img, vector <string> &label, vector <Rect> &face_pos){
	Point2f txtpt, pt1, pt2;
	int N = label.size();
	for (int i=0; i<N; i++){
	  txtpt.x = face_pos[i].x;
	  txtpt.y = face_pos[i].y - 7;
	  pt1.x = face_pos[i].x;
	  pt1.y = face_pos[i].y;
	  pt2.x = face_pos[i].x + face_pos[i].width;
	  pt2.y = face_pos[i].y + face_pos[i].height;
	  rectangle(img, pt1, pt2, CV_RGB(0,255,0), 2, 8, 0);
	  putText(img, label[i], txtpt, CV_FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(0,255,0), 1);
	}
	return;
}

void FaceRecognize::train(string train_file, string class_file){
  Mat img,scaled_img,recognize_img;
  vector <Rect> face_pos;
  vector <struct Eye> eye;
  vector <string> face_name;
  vector <int> face_count;
  
  double scale = 1 ;
  ifstream file(train_file.c_str(), ifstream::in), filec(class_file.c_str(), ifstream::in);
  
  if (!file || !filec)
    throw std::exception();
  
  string line, path, name;
  
  while (getline(filec, line)){
    stringstream liness(line);
    getline(liness, name);
    face_name.push_back(name);
    face_count.push_back(0);
    string cmd = "mkdir ../train/" + name;
    system(cmd.c_str());
  }
  
  char separator = ';';
  string label;
  vector <int> labels;
  vector <Mat> images;
  while (getline(file, line)){
    stringstream liness(line);
    getline(liness, path, separator);
    getline(liness, label);
    img = imread(path, 0);
    
    if (img.rows > 600 || img.cols > 800){
      scale = img.rows/480;
      scaled_img.create(cvRound(img.rows/scale),cvRound(img.cols/scale),CV_8UC1);
      resize(img, scaled_img, scaled_img.size(), 0, 0, INTER_LINEAR );
    }
    else{
      scaled_img = img;
    }    
    
    detect_face(face_pos, eye, scaled_img, 1);
    recognize_img = scaled_img(face_pos[0]);
    resize(recognize_img, recognize_img, Size(FACE_RECOGNIZE_SIZE, FACE_RECOGNIZE_SIZE), 0, 0, INTER_LINEAR );
    string num_label = "00000";
    int nlabel = atoi(label.c_str());
    num_label[4] = face_count[nlabel] % 10;
    num_label[3] = (face_count[nlabel]/10) % 10;
    num_label[2] = (face_count[nlabel]/100) % 10;
    num_label[1] = (face_count[nlabel]/1000) % 10;
    num_label[0] = (face_count[nlabel]/10000) % 10;
    string filepath = "../train/" + face_name[nlabel] + "/" + face_name[nlabel] + num_label;
    imwrite(filepath,recognize_img);
    images.push_back(recognize_img);
    labels.push_back(nlabel);
    face_count[nlabel]++;
  }
  
  eigen_recognizer = createEigenFaceRecognizer(80,EIGEN_THRESH);	  
  fisher_recognizer = createFisherFaceRecognizer(0,FISHER_THRESH);	  
  lbph_recognizer = createLBPHFaceRecognizer(1,8,8,8,LBPH_THRESH);	 
  eigen_recognizer->train(images, labels);
  fisher_recognizer->train(images, labels);
  lbph_recognizer->train(images, labels); 
  return;
}

void FaceTracker::klt_face_tracker(vector <string> &name, vector <int> &label, vector <Rect> &face_pos, Mat &img, Mat &prev_img, vector < vector <Point2f> > &features, string classifier, string mode){
  int N = face_pos.size(), Ni, num_features, displacement_x, displacement_y;
  static int frame_count=0;
  vector <double> confidence,err;
  vector <bool> status;
  vector <Point2f> nfeatures;
  vector <struct Eye> eye;
  Rect roi;
  if (frame_count == 0){
    detect_face(face_pos, eye, img, 1, mode);
    recognize_face(name, confidence, label, face_pos, img, classifier);
    N = face_pos.size();
    features.clear();
    features.resize(N);
  }
  for (int i=0; i<N; i++){
    roi.x = face_pos[i].x - ROI_ALLOWANCE;
    roi.y = face_pos[i].y - ROI_ALLOWANCE;
    roi.width = face_pos[i].width + 2*ROI_ALLOWANCE;
    roi.height = face_pos[i].height + 2*ROI_ALLOWANCE;
    
    if (frame_count != 0){
      status.clear();
      err.clear();
      nfeatures.clear();
      calcOpticalFlowPyrLK(prev_img(roi),img(roi),features[i],nfeatures,status,err);
      Ni = status.size();
      displacement_x = 0;
      displacement_y = 0;
      for (int j=0; j<Ni; j++){
        if (status[j]){
          displacement_x += nfeatures[j].x - features[i][j].x;
          displacement_y += nfeatures[j].y - features[i][j].y;
        }
      }
      features[i].clear();
      for (int j=0; j<Ni; j++)
        if (status[j])
          features[i].push_back(nfeatures[j]);
      displacement_x /= features[i].size();
      displacement_y /= features[i].size();
      face_pos[i].x += displacement_x;
      face_pos[i].y += displacement_y;
    }
    num_features = features[i].size();
    if (num_features < KLT_MIN_FEATURES_PER_FACE){
      features[i].clear();
      goodFeaturesToTrack(img(roi), features[i], KLT_MAX_FEATURES_PER_FACE, KLT_FEATURE_QUALITY, KLT_MIN_FEATURE_DIST);
    }
  }
  frame_count++;
  if (frame_count == NUM_FRAMES_WITHOUT_DETECTION)
    frame_count = 0;
  return;
}
