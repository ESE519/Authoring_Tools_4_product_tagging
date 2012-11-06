#ifndef FACE_H
#define FACE_H

#include "general.h"

using namespace cv;
using namespace std;

struct Eye{
  Point2f left_pos,right_pos;  
  double left_radius,right_radius;
};

namespace face{
	class Face{
		protected:
			Face();
			~Face();
			void align_face(Mat &out, Mat &img, string mode);
			void apply_transform(Mat &out, Mat &img, Transform T);
			vector <Transform> get_transform(vector <struct Eye> &eye);
	};

	class FaceDetect: public Face{
		protected:
			FaceDetect();
			~FaceDetect();
			void detect_face(vector <Rect> &face_pos, vector <struct Eye> &eye, Mat &img, string mode);
			void detect_eyes(vector <struct Eye> &eye_pos, Mat &img);
	};

	class FaceRecognize: public Face{
		protected:
			FaceRecognize();
			~FaceRecognize();
			void recognize_face(string &name, double &confidence, int &label, Mat &img, string classifier);
	};
	
	class FaceTracker: public Face{
		protected:
			FaceTracker();
			~FaceTracker();
			void track_face(vector <Rect> &face_pos, vector <struct Eye> &eye, Mat &img);
	};
}

#endif
