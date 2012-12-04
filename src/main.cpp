#include "general.h"
#include "face.h"
#include "render.h"

using namespace cv;
using namespace std;
using namespace face;

int main(){
  FaceDetect F;
  Mat nimg,img, out, roi;
  float offset_x = 0.2, offset_y = 0.2;
  vector <struct Eye> eye;
  vector <Rect> face_pos;
  img = imread("/home/rajeev/Dropbox/vios/sheldon/sheldon0235.png");
  img.copyTo(nimg);
  F.detect_face(face_pos, eye, img,1);
  F.draw_face(face_pos,eye,nimg,1);
  imshow("frame",nimg);
  if (face_pos.size() > 0)
    cout <<eye[0].left_radius << " " << eye[0].right_radius<<endl;
  roi = img(face_pos[0]);
  if (face_pos.size() > 0 && eye[0].left_radius > 0 && eye[0].right_radius > 0){
    eye[0].left_pos.x -= face_pos[0].x;
    eye[0].right_pos.x -= face_pos[0].x;
    eye[0].left_pos.y -= face_pos[0].y;
    eye[0].right_pos.y -= face_pos[0].y;
    F.align_face(out, roi, eye[0], offset_x, offset_y, Size(100,100));
  }
  circle(roi,eye[0].left_pos,eye[0].left_radius,CV_RGB(255,0,0),2,8,0);
  circle(roi,eye[0].right_pos,eye[0].right_radius,CV_RGB(255,0,0),2,8,0);
  line(roi,eye[0].left_pos,eye[0].right_pos,CV_RGB(0,255,0),2,8,0);
  imshow("original",roi);
  imshow("aligned",out);
  waitKey(0);
  //imshow("cropped",out);
  //waitKey(0);
  return 0;
}
