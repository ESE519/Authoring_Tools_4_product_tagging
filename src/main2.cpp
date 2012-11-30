#include "general.h"
#include "face.h"
#include "render.h"

using namespace cv;
using namespace std;
using namespace face;

int main(){
  FaceDetect F;
  Mat img, out, roi;
  float offset_x = 0.3, offset_y = 0.3;
  vector <struct Eye> eye;
  vector <Rect> face_pos;
  img = imread("/home/rajeev/Dropbox/vios/Sheldon/sheldon0235.png",0);
  
  F.detect_face(face_pos, eye, img);
  
  if (face_pos.size() > 0)
    cout <<eye[0].left_radius << " " << eye[0].right_radius<<endl;
  roi = img(face_pos[0]);
  if (face_pos.size() > 0 && eye[0].left_radius != -1 && eye[0].right_radius!=-1){
    eye[0].left_pos.x -= face_pos[0].x;
    eye[0].right_pos.x -= face_pos[0].x;
    eye[0].left_pos.y -= face_pos[0].y;
    eye[0].right_pos.y -= face_pos[0].y;
    F.align_face(out, roi, eye[0], offset_x, offset_y, Size(100,100));
  }
  circle(roi,eye[0].left_pos,eye[0].left_radius,CV_RGB(255,0,0),2,8,0);
  circle(roi,eye[0].right_pos,eye[0].right_radius,CV_RGB(0,255,0),2,8,0);
  imshow("original",roi);
  waitKey(0);
  //imshow("cropped",out);
  //waitKey(0);
  return 0;
}
