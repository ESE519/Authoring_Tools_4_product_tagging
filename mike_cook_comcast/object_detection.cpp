#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <fstream>

#define MIN_OBJ_SIZE 20
#define MAX_OBJ_SIZE 200

using namespace cv;
using namespace std;

CascadeClassifier cascade;
ofstream fout;
void obj_detect(vector <Rect> &out, Mat &img,double scale = 1.1){
  out.clear();
  Rect tmp;
  double t = 0;
  Point2f pt1,pt2;
  vector <Rect> object;
  Mat gray, smallImg(round (img.rows/scale), round(img.cols/scale), CV_8UC1);

  cvtColor( img, gray, CV_BGR2GRAY );
  resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
  equalizeHist( smallImg, smallImg );

  t = (double)cvGetTickCount();
  cascade.detectMultiScale(smallImg, object,1.1, 3, 0
                           //|CV_HAAR_FIND_BIGGEST_OBJECT
                           //|CV_HAAR_DO_ROUGH_SEARCH
                             |CV_HAAR_SCALE_IMAGE,
  			                   Size(MIN_OBJ_SIZE, MIN_OBJ_SIZE),
  			                   Size(MAX_OBJ_SIZE, MAX_OBJ_SIZE));
  t = (double)cvGetTickCount() - t;
  //printf( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );
  int cnt=0;
  for(vector<Rect>::const_iterator r = object.begin(); r != object.end(); r++) {
    pt1.x = r->x*scale;
    pt1.y = r->y*scale;
    pt2.x = (r->x + r->width)*scale;
    pt2.y = (r->y + r->height)*scale;
    rectangle(img, pt1, pt2, CV_RGB(255,0,0), 1, 8, 0);
    tmp.x = pt1.x;
    tmp.y = pt2.y;
    tmp.width = r->width*scale;
    tmp.height = r->height*scale;
    out.push_back(tmp);
    //fout << " <o1_x>" << (int)pt1.x << "</o1_x>" << endl;
    //fout << " <o1_y>" << (int)pt1.y << "</o1_y>" << endl;
    //fout << " <o1_width>" << (int)r->width << "</o1_width>" << endl;
    //fout << " <o1_height>" << (int)r->height << "</o1_height>" << endl;
    if(++cnt >= 5) break;
  }
  /*if (object.size() == 0){
    fs << "obj" << "{";
    fs << "x" << 0;
    fs << "y" << 0;
    fs << "width" << 0;
    fs << "height" << 0;
    fs << "}";
  }*/
  return;
}
int main(int argc,char **argv){
  string input_file,output_file,classifier_file;
  vector <Rect> out;
  Mat frame;
  for (int i=1;i<argc;i++){  
    if (strcmp(argv[i],"-i")==0)
      input_file = string(argv[++i]);
    else if (strcmp(argv[i],"-o")==0)
      output_file = string(argv[++i]);
    else if (strcmp(argv[i],"-c")==0)
      classifier_file = string(argv[++i]);   
    else
      cerr << "Wrong Usage" << endl;
  }
  if(!cascade.load(classifier_file)){
    cerr << "ERROR: Could not load classifier cascade" << endl;
    return -1;
  }
  fout.open(output_file.c_str(),ofstream::out);
  VideoCapture cap(input_file);
  namedWindow("Object Detection",CV_WINDOW_NORMAL);
  int frame_count = 0;
  fout << "<?xml version=\"1.0\"?>" << endl;
  fout << "<data xmlns:mac=\"http://www.tvworks.com/tva/xml/ns/max/data-types\"" << endl;
  fout << " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"" << endl;
  fout<<" xsi:noNamespaceSchemaLocation=\"light_trigger.xsd\">" << endl;
  fout << "<object_detection_data>" << endl;
  while (1){
    cap >> frame;
    if (frame.empty())
      break;
    
    obj_detect(out,frame);
    if (out.size()>0){
      fout << "<row time=\"" << (int)cap.get(CV_CAP_PROP_POS_MSEC)<< "\">" << endl;
      for(int i=0;i<out.size();i++){
        fout << " <o" <<i+1<< "_x>" << (int)out[i].x << "</o" <<i+1<< "_x>" << endl;
        fout << " <o" <<i+1<< "_y>" << (int)out[i].y << "</o" <<i+1<< "_y>" << endl;
        fout << " <o" <<i+1<< "_width>" << (int)out[i].width << "</o" <<i+1<< "_width>" << endl;
        fout << " <o" <<i+1<< "_height>" << (int)out[i].height << "</o" <<i+1<< "_height>" << endl;
      }
      fout << "</row>" << endl;
    }
    imshow("Object Detection",frame);
    if(waitKey(30) == 27)
      break;
  }
  fout << "</object_detection_data>"<< endl;
  fout << "</data>" << endl;
  return 0;
}
