#include "general.h"
#include "face.h"

using namespace face;

FaceDetect::FaceDetect(){
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
