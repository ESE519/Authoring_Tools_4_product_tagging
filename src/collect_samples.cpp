#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace cv;
using namespace std;

int pos=0;
VideoCapture cap;

void onTrackbarSlide(int value, void* userData=NULL){
  value = pos;
	cap.set(CV_CAP_PROP_POS_FRAMES,value);
}
int main(int argc, char ** argv){
  char ch;
  int totalNumFrames;
  string path="";
  if (argc == 3){
    string filename = string(argv[1]);
    cap.open(filename);
    path = string(argv[2]);
  }
  else if (argc == 2){
    string filename = string(argv[1]);
    cap.open(filename);
  }
  else {
    cerr << "Need a path to a video file" << endl;
    return -1;
  }
  int cnt=0;
  Mat frame;
  namedWindow("result");
  totalNumFrames = cap.get(CV_CAP_PROP_FRAME_COUNT);
  createTrackbar("time","result",&pos,totalNumFrames,onTrackbarSlide);
  while (1){
    cap >> frame;
    setTrackbarPos("time","result",++pos);
    imshow("result",frame);
    if ((ch=waitKey(0)) == ' '){
      string name="frame00.jpg";
      name[6]='0' + cnt%10;
      name[5]='0' + cnt/10;
      name = path + name;
      imwrite(name,frame);
      cnt++;
    }
    //else if (ch=='n')
    //  continue;
  }  
  
  return 0;
}
