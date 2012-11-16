#include "general.h"
#include "face.h"
#include "render.h"

using namespace cv;
using namespace std;
using namespace face;

int main(){
  FaceDetect detector;
  VideoCapture cap(0);
  Mat frame;
  vector <Rect> face_pos;
  vector <struct Eye> eye_pos;
  namedWindow("Face Detection");
  while (1) {
    cap >> frame;
    double fps = 1.0/detector.detect_face(face_pos,eye_pos,frame);
    detector.draw_face(face_pos,eye_pos,frame);
    put_text_fps(frame,fps);
    imshow("Face Detection",frame);
    if (waitKey(30) == 27)
      break;
  }
  return 0;
}
