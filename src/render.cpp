#include "render.h"

using namespace cv;
using namespace std;
                                
void put_text_fps(Mat &img, double fps, Size img_size){
  char txt[15];
	Point txt_pt(img_size.width-100, img_size.height-10);
	sprintf(txt,"fps : %.2f",fps);
	putText(img, txt, txt_pt, CV_FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(0,0,255), 1);
	return;
}
