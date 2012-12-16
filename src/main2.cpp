#include "general.h"
#include "face.h"
#include "render.h"

using namespace cv;
using namespace std;
using namespace face;

int main(){
  FaceTracker F;
  vector <string> class_name;
  vector <int> class_label;
  vector <Rect> face_pos;
  Mat frame,prev_img,buffer;
  vector < vector <Point2f> > features;
  string classifier="fisher";
  
  VideoCapture cap;
  cap.open("/home/rajeev/Dropbox/vios_team_use/face_recognition/videos/bbt_s04e18_hd.avi");
  namedWindow("Features",1);
  while(1){
    cap >> frame;
    if (frame.empty())
       break;
    F.klt_track_face(class_name, class_label, face_pos, frame, prev_img, features, classifier);   
    frame.copyTo(prev_img);
    frame.copyTo(buffer);
    for (int i=0; i<features.size();i++){
      for (int j=0; j<features[i].size();j++){
        circle(buffer, features[i][j], 2, CV_RGB(0,255,0), 1, 8, 0);
      }
    }
    imshow("Features",frame);
    if(waitKey(20) == 27)
     break;
  }
  return 0;
}
