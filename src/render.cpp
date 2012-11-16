#include "render.h"

using namespace cv;
using namespace std;

const static Scalar colors[] = {CV_RGB(255,0,0),
    		                        CV_RGB(0,255,0),
    		                        CV_RGB(0,0,255),
    		                        CV_RGB(255,255,0),
    		                        CV_RGB(255,0,255),
    		                        CV_RGB(0,255,255),
                                CV_RGB(0,128,255),
                                CV_RGB(255,128,0)};
                                
void put_text_fps(Mat &img, double fps, Size img_size){
  char txt[15];
	Point txtPoint(img_size.width-100, img_size.height-10);
	cout << "fps : " << fps << endl;
	sprintf(txt,"fps : %.2f",fps);
	putText(img,txt,txtPoint,CV_FONT_HERSHEY_SIMPLEX, 0.5, colors[2],1);
	return;
}
