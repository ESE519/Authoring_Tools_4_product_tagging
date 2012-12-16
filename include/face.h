#ifndef FACE_H
#define FACE_H

#include "general.h"

using namespace cv;
using namespace std;

struct Eye{
  Point2f left_pos,right_pos;  
  float left_radius,right_radius;
};

namespace face{
	class Face{
		public:
		  //Face();
			//~Face();
			void align_face(Mat &out, Mat &img, struct Eye eye, float offset_x, float offset_y, Size sz, string mode = "front");
	};

	class FaceDetect: public Face{
	  public:
	    double FACE_CLASSIFIER_SCALE, EYE_CLASSIFIER_SCALE;
	    int MIN_FACE_DETECT_SIZE, MAX_FACE_DETECT_SIZE, MIN_EYE_DETECT_SIZE, MAX_EYE_DETECT_SIZE, EYE_DETECT_FACE_SIZE;
	    string eye_classifier_name, face_classifier_name;
      CascadeClassifier eye_classifier, face_classifier;
		public:
			FaceDetect():Face(){
        FACE_CLASSIFIER_SCALE = 1.2;
        EYE_CLASSIFIER_SCALE = 1.2;
      	MIN_FACE_DETECT_SIZE = 40;
      	MAX_FACE_DETECT_SIZE = 300;
	      MIN_EYE_DETECT_SIZE = 1;
	      MAX_EYE_DETECT_SIZE = 60;
	      EYE_DETECT_FACE_SIZE = 200;
        eye_classifier_name = "/home/rajeev/ProgramFiles/OpenCV-2.4.3/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
        //eye_classifier_name = "/home/rajeev/ProgramFiles/OpenCV-2.4.3/data/haarcascades/haarcascade_lefteye_2splits.xml";
        face_classifier_name = "/home/rajeev/ProgramFiles/OpenCV-2.4.3/data/haarcascades/haarcascade_frontalface_alt.xml";
        
        if (!face_classifier.load(face_classifier_name))
          cerr << "Face Detection Classifier cannot be loaded" << endl;
        if (!eye_classifier.load(eye_classifier_name))
          cerr << "Eye Detection Classifier cannot be loaded" << endl; 
      }
			//~FaceDetect();
			double detect_face(vector <Rect> &face_pos, vector <struct Eye> &eye, Mat &img, double scale = 1, string mode = "front");
			void detect_eyes(struct Eye &eye_pos, Mat &img);
			void draw_face(vector <Rect> &face_pos, vector <struct Eye> & eye_pos, Mat &img, bool eye_flag = false);
	};

	class FaceRecognize: public FaceDetect{
	  public:
	    int FACE_RECOGNIZE_SIZE, EYE_LEVEL, EIGEN_THRESH, FISHER_THRESH, LBPH_THRESH;
	    vector <string> face_name;
	    Ptr<FaceRecognizer> eigen_recognizer, fisher_recognizer, lbph_recognizer;
		public:
			FaceRecognize():FaceDetect(){
			  FACE_RECOGNIZE_SIZE = 70;
        EYE_LEVEL = FACE_RECOGNIZE_SIZE/3;
        EIGEN_THRESH = 2000;
        FISHER_THRESH = 90;
        LBPH_THRESH = 70;
			};
			//~FaceRecognize();
			void train(string train_file, string class_file, string recognizer_file);
			void load(string file_recognizer, string file_class, string file_train);
			void recognize_face(vector <string> &name, vector <double> &confidence, vector <int> &label, vector <Rect> &face_pos, Mat &img, string classifier = "fisher");
			void label_face(Mat &img, vector <string> &label, vector <Rect> &face_pos);
	};
	
	class FaceTracker: public FaceRecognize{
	  public:
	    int NUM_FRAMES_WITHOUT_DETECTION, KLT_MAX_FEATURES_PER_FACE, KLT_MIN_FEATURES_PER_FACE, ROI_ALLOWANCE, frame_count;
	    double KLT_FEATURE_QUALITY, KLT_MIN_FEATURE_DIST;
		public:
			FaceTracker():FaceRecognize(){
			  NUM_FRAMES_WITHOUT_DETECTION = 10;
			  KLT_MAX_FEATURES_PER_FACE = 50;
			  KLT_MIN_FEATURES_PER_FACE = 2;
			  KLT_FEATURE_QUALITY = 0.01;
			  KLT_MIN_FEATURE_DIST = 2;
			  ROI_ALLOWANCE = 20;
			  frame_count = 0;
			}
			//~FaceTracker();
			bool klt_track_face(vector <string> &name, vector <int> &label, vector <Rect> &face_pos, Mat &img, Mat &prev_img, vector < vector <Point2f> > &features, bool slider_flag = 0, string classifier = "fisher", string mode = "front");
			void camshift_track_face(vector <string> &name, vector <string> &prev_name, vector <int> &label, vector <int> &prev_label, vector <double> &confidence, vector <double> &prev_confidence, vector <Rect> &face_pos, vector <Rect> &prev_face_pos, Mat &img, Mat &prev_img, vector <struct Eye> eye, string classifier = "fisher", string mode = "front");
	};
}

#endif
