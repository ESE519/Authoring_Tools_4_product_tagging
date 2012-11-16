#ifndef FACE_H
#define FACE_H

#include "general.h"

#define FACE_CLASSIFIER_SCALE 1.1
#define EYE_CLASSIFIER_SCALE 1.1
#define MIN_FACE_DETECT_SIZE 40
#define MAX_FACE_DETECT_SIZE 200
#define MIN_EYE_DETECT_SIZE 6
#define MAX_EYE_DETECT_SIZE 30

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
	  string eye_classifier_name, face_classifier_name;
    CascadeClassifier eye_classifier, face_classifier;
		public:
			FaceDetect();
			//~FaceDetect();
			double detect_face(vector <Rect> &face_pos, vector <struct Eye> &eye, Mat &img, double scale = 1, string mode = "front");
			void detect_eyes(struct Eye &eye_pos, Mat &img);
			void draw_face(vector <Rect> &face_pos, vector <struct Eye> & eye_pos, Mat &img, bool eye_flag = false);
	};

	class FaceRecognize: public Face{
		public:
			//FaceRecognize();
			//~FaceRecognize();
			void recognize_face(string &name, double &confidence, int &label, Mat &img, string classifier);
	};
	
	class FaceTracker: public Face{
		public:
			//FaceTracker();
			//~FaceTracker();
			void track_face(vector <Rect> &face_pos, vector <struct Eye> &eye, Mat &img);
	};
}

#endif
