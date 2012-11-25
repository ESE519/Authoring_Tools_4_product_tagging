#ifndef FACE_H
#define FACE_H

#include "general.h"

using namespace cv;
using namespace std;

struct Eye{
  Point2f left_pos,right_pos;  
  double left_radius,right_radius;
};

struct Transform{
  Mat rotmat;
  Mat pos;
};

namespace face{
	class Face{
		public:
		  //Face();
			//~Face();
			void align_face(Mat &out, Mat &img, string mode);
			void apply_transform(Mat &out, Mat &img, struct Transform T);
			void get_transform(vector <struct Transform> &T, vector <struct Eye> &eye);
	};

	class FaceDetect: public Face{
	  public:
	    double FACE_CLASSIFIER_SCALE, EYE_CLASSIFIER_SCALE;
	    int MIN_FACE_DETECT_SIZE, MAX_FACE_DETECT_SIZE, MIN_EYE_DETECT_SIZE, MAX_EYE_DETECT_SIZE;
	    string eye_classifier_name, face_classifier_name;
      CascadeClassifier eye_classifier, face_classifier;
		public:
			FaceDetect();
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
			  FACE_RECOGNIZE_SIZE = 50;
        EYE_LEVEL = 10;
        EIGEN_THRESH = 1400;
        FISHER_THRESH = 20;
        LBPH_THRESH = 45;
			};
			//~FaceRecognize();
			void train(string train_file, string class_file);
			void load(string file_name);
			void recognize_face(vector <string> &name, vector <double> &confidence, vector <int> &label, vector <Point2f> &face_pos, Mat &img, string classifier = "fisher");
			void label_face(Mat &img, vector <string> &label, vector <Rect> &face_pos);
	};
	
	class FaceTracker: public FaceRecognize{
	  public:
	    int NUM_FRAMES_WITHOUT_DETECTION, KLT_MAX_FEATURES_PER_FACE, ROI_ALLOWANCE;
	    double KLT_FEATURE_QUALITY, KLT_MIN_FEATURE_DIST;
		public:
			FaceTracker():FaceRecognize(){
			  NUM_FRAMES_WITHOUT_DETECTION = 5;
			  KLT_MAX_FEATURES_PER_FACE = 20;
			  KLT_FEATURE_QUALITY = 0.01;
			  KLT_MIN_FEATURE_DIST = 4;
			  ROI_ALLOWANCE = 10;
			}
			//~FaceTracker();
			void klt_face_tracker(vector <string> &name, vector <int> &label, vector <Rect> &face_pos, Mat &img, vector < vector <Point2f> > &features, string classifier = "fisher", string mode = "front");
	};
}

#endif
