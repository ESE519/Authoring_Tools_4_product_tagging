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

int main(int argc, char ** argv){
  VideoCapture cap;
	char ch;
	string filename,destpath;
	if (argc == 3){
		destpath = string(argv[2]);
		if (destpath[destpath.size()-1] != '/')
			destpath.push_back('/');
    string filename = string(argv[1]);
    cap.open(filename);
  }
  else {
    cerr << "Need a path to a video file" << endl;
    return -1;
  }
  int cnt=0,framecnt=0;
  Mat frame;
  while (1){
		cap >> frame;
		if (frame.empty())
			break;
		if (framecnt%5 == 0){
    	string name="frame00000.jpg";
    	name[9]='0' + cnt%10;
    	name[8]='0' + (cnt/10)%10;
    	name[7]='0' + (cnt/100)%10;
    	name[6]='0' + (cnt/1000)%10;
    	name[5]='0' + (cnt/10000)%10;
    	name = destpath + name;
    	imwrite(name,frame);
    	cnt++;
		}
		framecnt++;
  }  
  
  return 0;
}
