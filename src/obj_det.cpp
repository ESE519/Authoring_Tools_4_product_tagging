/* Object detection for processing PASCAL dataset files */
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <sstream>

using namespace std;

int main(int argc, char ** argv){
	int checkno;
	char separator = ' ';
	string path ="/home/pitchai/Documents/Object_Det/";
	string img_path = path + "JPEGImages/";
	string annotation_path = path + "Annotations/";
  ifstream file( (path + "ImageSets/Main/bottle_train.txt").c_str(),ifstream::in);
	ofstream filecpy1( (path + "bottle_pos_imgs.txt").c_str(), ofstream::out);
	ofstream filecpy2( (path + "bottle_neg_imgs.txt").c_str(), ofstream::out);
	if(!file)	
	  throw std::exception();
	string line,name,num,cmd,cmd1;
	while(getline(file,line)){
	  stringstream liness(line);
	  getline(liness,name, separator);
	  getline(liness,num);
	  checkno=(atoi(num.c_str()));
	  if(checkno == 1){
	    filecpy1 << name << endl;
	    cmd = "cp " + img_path + name + ".jpg " + path + "bottle_pos_images/" +name + ".jpg";
	    cmd1 = "cp " + annotation_path + name + ".xml " + path + "bottle_pos_images/" +name + ".xml";
	    }
	  else if (checkno == -1){
	    filecpy2 << name << endl;
	    cmd = "cp " + img_path + name + ".jpg " + path + "bottle_neg_images/" +name + ".jpg";
	     cmd1 = "cp " + annotation_path + name + ".xml " + path + "bottle_neg_images/" +name + ".xml";
	    }
	  system(cmd.c_str());
	  system(cmd1.c_str());
	}
}
	
	  
