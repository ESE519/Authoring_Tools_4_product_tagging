#include "general.h"
#include "face.h"
#include "render.h"

using namespace cv;
using namespace std;
using namespace face;
string mode, input_type, output_type, classifier, train_label, recognizer_path, delete_type, input_path;
bool slider_flag = 0;
VideoCapture cap;
void onTrackbarSlide2(int pos, void* userData=NULL){
  cap.set(CV_CAP_PROP_POS_FRAMES,pos);
}

void help_display(){
  cout << "--------------------------------------------------------------------------------------------------------" << endl;
  cout << "                               vios - Documentation                                                     " << endl;
  cout << "--------------------------------------------------------------------------------------------------------" << endl;
  cout << "-detect         Detect faces in video/webcam stream. Defaults to this mode." << endl << endl;
  cout << "-recognize      Recognizes faces and labels them in video/webcam stream." << endl;
  cout << "                Requires -recognizer to specify the recognizer path." << endl << endl;
  cout << "-train          Training for face recognition." << endl;
  cout << "                Requires -image/video/webcam to indicate input type. Defaults to webcam." << endl << endl;
  cout << "-delete         Deletes the trained .csv and .xml files." << endl;
  cout << "                Requires all/xml/label which specifies whether to remove all or only the" << endl;
  cout << "                trained data or a particular training label" << endl << endl;
  cout << "-image          the path to the location where training image csv file is located without the suffix" << endl <<endl;
  cout << "-video          the path to the location where the video input file is located" << endl << endl;
  cout << "-webcam         indicates input type is webcam" << endl << endl;
  cout << "-record         indicates whether to record the video with tagged faces or not." << endl;
  cout << "                Supported only with video format." << endl << endl;
  cout << "-classifier     specifies the type of classifier to be used in recognize mode" << endl << endl;
  cout << "-label          specifies the class label in train mode with webcam" << endl;
  cout << "--------------------------------------------------------------------------------------------------------" << endl;
}
void identify_mode(int argc, char ** argv){ 
  mode = input_type = output_type = classifier = delete_type = "default";
  for (int i=1; i < argc; i++) {
    if (strcmp(argv[i],"-detect") == 0){
      if (mode == "default")
	      mode = "detect";
	    else 
	      cerr << "Multiple Modes Specified. Use with -h option to trigger help" << endl;
	  }
	  else if (strcmp(argv[i],"-recognize") == 0){
	    if (mode == "default")
	      mode = "recognize";
	    else 
	      cerr << "Multiple Modes Specified. Use with -h option to trigger help" << endl;
	  }
	  else if (strcmp(argv[i],"-train") == 0){
	    if (mode == "default")
	      mode = "train";
	    else 
	      cerr << "Multiple Modes Specified. Use with -h option to trigger help" << endl;
	  } 
	  else if (strcmp(argv[i],"-delete") == 0){
	    if (mode == "default"){
	      mode = "delete";
	      delete_type = string(argv[++i]);
	    }
	    else {
	      cerr << "Multiple Modes Specified. Use with -h option to trigger help" << endl;
	    }
	  }
	  else if (strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"-help") == 0){
	    if (mode == "default")
	      mode = "help";
	    else 
	      cerr << "Multiple Modes Specified. Use with -h option to trigger help" << endl;
	  }	  
	  else if (strcmp(argv[i],"-image") == 0){
	    input_type = "image";
	    input_path = string(argv[++i]);
	  }
	  else if (strcmp(argv[i],"-video") == 0){
	    input_type = "video";
	    input_path = string(argv[++i]);
	  }
	  else if (strcmp(argv[i],"-webcam") == 0){
	    input_type = "webcam";
	  }
	  else if (strcmp(argv[i],"-record") == 0){
	    output_type = "record";
	  }
	  else if (strcmp(argv[i],"-recognizer") == 0){
	    recognizer_path = string(argv[++i]);
	  }
	  else if (strcmp(argv[i],"-classifier") == 0){
	    classifier = string(argv[++i]);
	  }
    else if (strcmp(argv[i],"-label") == 0){
      train_label = string(argv[++i]);
	  }
  }
  
  if (mode == "default")
    mode = "detect";
  if (input_type == "default")
    input_type = "webcam";
  if (delete_type == "default")
    delete_type = "all";
  if (output_type == "default")
    output_type = "screen";
  if (classifier == "default")
    classifier = "all";
}
int main(int argc, char ** argv){
  VideoWriter vidwriter;
  identify_mode(argc,argv);
  if (mode == "help"){
    help_display();
  }
  else if (mode == "detect"){
    FaceDetect detector;
    Mat frame;
    double fps;
    vector <Rect> face_pos;
    vector <struct Eye> eye_pos;
    namedWindow("Face Detection");
    cout << "Press ESC to end detection" << endl;
    if (input_type == "video" || input_type == "webcam"){
      if (input_type == "video")
        cap.open(input_path);
      else
        cap.open(0);
      
      string vidout,extn;
      int write_flag = 0;
      if (input_type == "video" && output_type == "record"){
        stringstream liness(input_path);
        getline(liness,vidout,'.');
        getline(liness,extn);
        vidout = vidout + "_with_face_tag." + extn;
        vidwriter.open(vidout,cap.get(CV_CAP_PROP_FOURCC),cap.get(CV_CAP_PROP_FPS),Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT)));
        write_flag = 1;
      }
      while (1) {
        cap >> frame;
        fps = 1.0/detector.detect_face(face_pos,eye_pos,frame);
        detector.draw_face(face_pos,eye_pos,frame,1);
        if (write_flag)
          vidwriter << frame; 
        put_text_fps(frame,fps);
        imshow("Face Detection",frame);
        if (waitKey(10) == 27)
          break;
      }  
    }
    else {
      DIR *dp;
		  struct dirent *dirp;
		  struct stat filestat;
		  dp = opendir(input_path.c_str());
		  if (dp == NULL){
			  cerr << "Error opening image folder specified" << endl;
			  return -1;
		  }
		  while (dirp = readdir(dp)) {
			  string filepath = string(input_path) + dirp->d_name;
			  if (stat(filepath.c_str(),&filestat)) 
				  continue;
			  if (S_ISDIR(filestat.st_mode))
				  continue;
				cout << dirp->d_name << endl;
			  frame = imread(filepath);
			  fps = 1.0/detector.detect_face(face_pos,eye_pos,frame);
        detector.draw_face(face_pos,eye_pos,frame,1);
			  imshow("Face Detection",frame);
        if (waitKey(0) == 27)
          break;
		  }
      //cerr << "Image type input not supported for detect mode" << endl;
    }
  }
  else if (mode == "recognize"){
    if (input_type == "video" || input_type == "webcam"){
      FaceTracker f;
      if (input_type == "video")
        cap.open(input_path);
      else
        cap.open(0);
      Mat frame,gray_frame,prev_frame;
      string class_file, train_file, recognizer_file;
      class_file = recognizer_path + "_class.csv";
      //f.load(recognizer_path,class_file);
      vector <string> name;
      vector <double> confidence;
      vector <int> label;
      vector <Rect> face_pos;
      vector <struct Eye> eye;
      vector < vector <Point2f> > features;
      string vidout,extn;
      int write_flag = 0;
      if (input_type == "video" && output_type == "record"){
        stringstream liness(input_path);
        getline(liness,vidout,'.');
        getline(liness,extn);
        vidout = vidout + "_with_face_tag." + extn;
        vidwriter.open(vidout,cap.get(CV_CAP_PROP_FOURCC),cap.get(CV_CAP_PROP_FPS),Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT)));
        write_flag = 1;
      }
      int totalNumFrames = cap.get(CV_CAP_PROP_FRAME_COUNT), pos = 0;
      namedWindow("frame",CV_WINDOW_NORMAL);
			createTrackbar("pos","frame",&pos,totalNumFrames,onTrackbarSlide2);
			int prev_pos = 0;
			cout << "Hello " << endl;
      while (1){
        cap >> frame;
        if (frame.empty())
          break;
        cvtColor(frame, gray_frame, CV_BGR2GRAY);
        //f.detect_face(face_pos, eye, frame);
        if(abs(pos - prev_pos) > 5)
          slider_flag = 1;
        else 
          slider_flag=0;
        prev_pos = pos;
        f.klt_track_face(name, label, face_pos, frame, prev_frame, features, slider_flag);
        frame.copyTo(prev_frame);
        //f.label_face(frame, name, face_pos);
        for (int i=0; i<features.size();i++){
          for (int j=0; j<features[i].size();j++){
            Point2f tmp;
            tmp.x = face_pos[i].x + features[i][j].x;
            tmp.y = face_pos[i].y + features[i][j].y;
            rectangle(frame,face_pos[i],CV_RGB(255,0,0),1,8,0);
            circle(frame, tmp, 2, CV_RGB(0,255,0), 1, 8, 0);
          }
        }
        imshow("frame",frame);
        setTrackbarPos("pos","frame",++pos);
        if (write_flag)
          vidwriter << frame;
        if (waitKey(10) == 27)
          break;
      }
    }
    else {
      cerr << "Image type input not supported for detect mode" << endl;
    }
  }
  else if (mode == "train"){
    FaceRecognize f;
    string class_file, train_file, recognizer_file;
    recognizer_file = recognizer_path;
    if (input_type == "image"){
      class_file = recognizer_path + "_class.csv";
      train_file = input_path;
    }
    else if (input_type == "video"){
      class_file = recognizer_path + "_class.csv";
      train_file = input_path;
    }
    else {
      cerr << "Format not supported in train mode" << endl;
    }
    f.train(train_file,class_file,recognizer_file);
  }
  else if (mode == "delete"){
    cerr << "Mode not currently supported. Check in future versions" << endl;
  }
  else if (mode == "help"){
    help_display();
  }
  else {
    cerr << "Wrong Usage. Type -h or --help to display help menu" << endl;
  }
  return 0;
}
