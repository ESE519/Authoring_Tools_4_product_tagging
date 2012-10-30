#ifndef FACE_H
#define FACE_H

#include "general.h"

using namespace cv;
using namespace std;

namespace face{
	class Face{
		protected:
			Face();
			~Face();
			void align_face(Mat &, Mat &, String);
			void transform(Mat &, Mat &, Transform);
			Transform get_transform(Mat &);
	};

	class FaceDetect: public Face{
		protected:
			FaceDetect();
			~FaceDetect();
	};

	class FaceRecognize: public Face{
		protected:
			FaceRecognize();
			~FaceRecognize();
	};
}

#endif
