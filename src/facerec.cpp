// ----------------------------------------------------------------------
// facerec.cpp
// Author : Rajeev Kumar Jeevagan
// Created On: 1 October 2012
// Last Modified : 4 October 2012
// Direct Compile Command:
// g++ `pkg-config opencv --cflags` facerec.cpp -o facerec `pkg-config opencv --libs`
//
// ----------------------------------------------------------------------
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

#define IMG_SIZE_X 640
#define IMG_SIZE_Y 480
#define MIN_FACE_SIZE 50
#define MAX_FACE_SIZE 300
#define FACE_SIZE_STEP 20
#define REC_FACE_SIZE 70
#define FISHER_THRESH 85
#define EIGEN_THRESH 1900
#define LBPH_THRESH 70

using namespace std;
using namespace cv;

VideoWriter vidwriter;
vector <Mat> faceSamples;
vector <double> faceSize;
vector <string> classNamesVec;
int numSamples = 10, faceSampleCnt = 0, classId = 0, capFlag = 1, recFlag=0;
FILE * fid,*fid1;
char train_filename[40]="../train/train.csv", class_filename[40]="../train/class_label.csv";
Ptr<FaceRecognizer> fisherModel,eigenModel,LBPHModel;
string mode="Recognize",classifier="majority",vidout="default";
char className[20]="NotSpecified";
int totalNumFrames,pos=0;
void help(){
	cout << endl << "Face Recognition using basic OpenCV modules" << endl << endl;
  cout << "-d         detect mode" << endl;
  cout << "-r         recognize mode <default>" << endl;
	cout << "-cd        continuous detect mode" << endl;
  cout << "-scale     give the scale for the image for faster processing - img size/scale <default = 1>" << endl;
  cout << "-num       number of samples to get in detect mode <default = 10>" << endl;
  cout << "-del       remove the training samples and class id corresponding to the given name" << endl;
  cout << "-img       train based on images in a folder instead of video from webcam in detect mode" << endl;
  cout << "-dev       specify the camera device id in detect mode for training from webcam video" << endl;
  cout << "-c         specify the classifier eigen/fisher/LBPH/majority/all in recognize mode <default = majority>" << endl;
  cout << "-name      the name of the training face in detect mode" << endl;
	cout << "-vid       the path where the video file is stored" << endl;
	cout << "-cascade   the path to the cascade filter to use <default> frontal face" << endl;
	cout << "-record    path along with filename + extension of the file to record the current video" << endl << endl;
}
void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file)
        throw std::exception();
    string line, path, classlabel;
    Mat tmp;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        tmp = imread(path, 0);
        images.push_back(tmp);
        labels.push_back(atoi(classlabel.c_str()));
    }
}
VideoCapture cap;
void onTrackbarSlide(int value, void* userData=NULL){
  value = pos;
	cap.set(CV_CAP_PROP_POS_FRAMES,value);
}

vector <Rect> prev_face;
vector <int> prev_label;
int cntero=0;
void faceDetect(Mat& img,CascadeClassifier& cascade,double scale=1){
  cntero++;
  vector <int> tempy;
  vector <Rect> tempf;
  int bestFaceRadius = -1;
  Point pt1,pt2,center;
  double t = 0;
  vector<Rect> faces;
  const static Scalar colors[] = {CV_RGB(255,0,0),
    		                          CV_RGB(0,255,0),
    		                          CV_RGB(0,0,255),
    		                          CV_RGB(255,255,0),
    		                          CV_RGB(255,0,255),
    		                          CV_RGB(0,255,255),
                                  CV_RGB(0,128,255),
                                  CV_RGB(255,128,0)};        
        
  Mat gray, smallImg(cvRound (img.rows/scale), cvRound(img.cols/scale), CV_8UC1);

  cvtColor( img, gray, CV_BGR2GRAY );
  resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
  equalizeHist( smallImg, smallImg );

  t = (double)cvGetTickCount();
  cascade.detectMultiScale(smallImg, faces,1.1, 3, 0
                           //|CV_HAAR_FIND_BIGGEST_OBJECT
                           //|CV_HAAR_DO_ROUGH_SEARCH
                             |CV_HAAR_SCALE_IMAGE,
  			                   Size(MIN_FACE_SIZE, MIN_FACE_SIZE),
  			                   Size(MAX_FACE_SIZE, MAX_FACE_SIZE));
  t = (double)cvGetTickCount() - t;
  //printf( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );
  
  int i=0;
  for(vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++) {
    Point center;
    int radius;
    
    center.x = cvRound((r->x + r->width*0.5)*scale);
    center.y = cvRound((r->y + r->height*0.5)*scale);
    radius = cvRound((r->width + r->height)*0.25*scale);
    
    if (mode == "detect" && radius>bestFaceRadius){
      pt1.x = center.x - radius;
      pt1.y = center.y - radius;
      pt2.x = center.x + radius;
      pt2.y = center.y + radius;
      bestFaceRadius = radius;
    }
    else if (mode == "recognize"){
      Rect roi;
      Mat testSample;
      pt1.x = center.x - radius;
      pt1.y = center.y - radius;
      pt2.x = center.x + radius;
      pt2.y = center.y + radius;
      roi.x = pt1.x; 
      roi.y = pt1.y; 
      roi.width = pt2.x - pt1.x;
      roi.height = pt2.y - pt1.y;
      Mat faceROI = gray(roi);
      resize(faceROI,testSample,Size(REC_FACE_SIZE,REC_FACE_SIZE));
      int eigenPrediction=-1,fisherPrediction=-1,LBPHPrediction=-1,prediction=-1;
      double eigenConfidence=-1,fisherConfidence=-1,LBPHConfidence=-1,confidence=-1; 
      if (classifier == "eigen" || classifier == "majority" || classifier == "all")
        eigenModel->predict(testSample,eigenPrediction,eigenConfidence);
      if (classifier == "fisher" || classifier == "majority" || classifier == "all")
        fisherModel->predict(testSample,fisherPrediction,fisherConfidence);
      if (classifier == "LBPH" || classifier == "majority" || classifier == "all")
        LBPHModel->predict(testSample,LBPHPrediction,LBPHConfidence);
      if (classifier == "eigen"){
        prediction = eigenPrediction;
        confidence = eigenConfidence;
      }
      else if (classifier == "fisher"){
        prediction = fisherPrediction;
        confidence = fisherConfidence;
      }
      else if (classifier == "LBPH"){
        prediction = LBPHPrediction;
        confidence = LBPHConfidence;
      }
      else if (classifier == "majority"){
        if (eigenPrediction == fisherPrediction || eigenPrediction == LBPHPrediction)
          prediction = eigenPrediction;
        else if (fisherPrediction == LBPHPrediction)
          prediction = fisherPrediction;
        else
          prediction = -1;
        confidence = -1;
      }
      else { //"all" 
        if (eigenPrediction == fisherPrediction && eigenPrediction == LBPHPrediction)
          prediction = eigenPrediction;
        else
          prediction = -1;
        confidence = fisherConfidence;
      }
      if (prediction != -1){
        rectangle(img, pt1, pt2, colors[1], 4, 8, 0);
        pt1.x = pt1.x;
        pt1.y = pt1.y - 7;
	      putText(img,classNamesVec[prediction],pt1,CV_FONT_HERSHEY_SIMPLEX, 0.5, colors[1],1);
	      Rect tempo;
	      tempo.x = pt1.x;
	      tempo.y = pt1.y+7;
	      tempo.width = pt2.x - pt1.x;
	      tempo.height = pt2.y - tempo.y;
	      tempf.push_back(tempo);
	      tempy.push_back(prediction);
      }
      else{
        cout << "got here" << prev_face.size() << endl;
        for (int ii=0;ii<prev_label.size();ii++){
          if (abs(pt1.x - prev_face[ii].x) < 100 && abs(pt1.x - prev_face[ii].y) < 100){
           prediction = prev_label[ii];
           break;
          }
        }
        if (prediction >=0){
        cout << "Success" << endl;
          pt1.x = pt1.x;
        pt1.y = pt1.y - 7;
        rectangle(img, pt1, pt2, colors[1], 4, 8, 0);
	      putText(img,classNamesVec[prediction],pt1,CV_FONT_HERSHEY_SIMPLEX, 0.5, colors[1],1);
	      	      Rect tempo;
	      tempo.x = pt1.x;
	      tempo.y = pt1.y+7;
	      tempo.width = pt2.x - pt1.x;
	      tempo.height = pt2.y - tempo.y;
	      tempf.push_back(tempo);
	      tempy.push_back(prediction);
        }
        else
        rectangle(img, pt1, pt2, colors[2], 1, 8, 0);  
      }
      if (tempf.size() != 0 || cntero%20 == 0){
       prev_label.clear();
    prev_face.clear();
    for (int ii=0;ii<tempf.size();ii++){
      prev_label.push_back(tempy[ii]);
      prev_face.push_back(tempf[ii]);
    }
    }
    }
		else if (mode == "contidetect"){			
      pt1.x = center.x - radius;
      pt1.y = center.y - radius;
      pt2.x = center.x + radius;
      pt2.y = center.y + radius;
			rectangle(img, pt1, pt2, colors[2], 2, 8, 0);
		}
  }
   
  if (mode == "detect" && bestFaceRadius > 0){
    int flag = 1;
    for (int i=0; i < faceSampleCnt; i++){
      if (abs(faceSize[i]-2*bestFaceRadius) < FACE_SIZE_STEP){
        flag = 0;
        break;
      }
    }
    if (flag || !capFlag){
      Rect roi;
      roi.x = pt1.x; 
      roi.y = pt1.y; 
      roi.width = pt2.x - pt1.x;
      roi.height = pt2.y - pt1.y; 
      Mat faceROI = gray(roi);
			Mat tmp;
      resize(faceROI,tmp,Size(REC_FACE_SIZE,REC_FACE_SIZE));
			faceSamples.push_back(tmp);
      char txt[40]="../train/",fileName[15] = "/face0000.jpg";
      fileName[5] = '0' + (faceSampleCnt / 1000) % 10;
      fileName[6] = '0' + (faceSampleCnt / 100) % 10;
      fileName[7] = '0' + (faceSampleCnt / 10) % 10;
      fileName[8] = '0' + (faceSampleCnt % 10);
      strcat(txt,className);
      strcat(txt,fileName);
			if (!capFlag){
      	cout << "Sample ["<<faceSampleCnt+1<<"] Recorded : " << txt << endl;
      	fprintf(fid,"%s;%d\n",txt,classId);
			}
			else{
      	cout << "Sample ["<<faceSampleCnt+1<<"/"<<numSamples<<"] Recorded : " << txt << endl;
      	fprintf(fid,"%s;%d\n",txt,classId);
			}
      imwrite(txt,faceSamples[faceSampleCnt]);
      rectangle(img, pt1, pt2, colors[1], 4, 8, 0);
      faceSize.push_back(2*bestFaceRadius);
      faceSampleCnt++;
    }
    else
      rectangle(img, pt1, pt2, colors[0], 2, 8, 0);
	}
	if (mode == "detect"){
	  char txt[20];
	  Point txtPoint(20,10);
	  sprintf(txt,"Sample : %d/%d",faceSampleCnt,numSamples);
	  putText(img,txt,txtPoint,CV_FONT_HERSHEY_SIMPLEX, 0.5, colors[2],1);
	}
	if (!recFlag){
		cv::imshow( "result", img);
	}
	else{
		vidwriter << img;
	}
	if (!capFlag)
		waitKey(50);
  
}
int main(int argc, char ** argv){
  int  devId = 0, dflag=0,nflag=0;
  fid = fopen(train_filename,"a+");
	fid1 = fopen(class_filename,"a+");
  char * imgPath;
  Mat frame;
  String cascadeName = "/home/rajeev/ProgramFiles/OpenCV-2.4.3/data/haarcascades/haarcascade_frontalface_alt.xml";
	String nestedCascadeName = "/home/rajeev/OpenCV-2.3.1/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
	String vidPath="";
	double scale = 1;
	//faceSize.resize(numSamples);
	//faceSamples.resize(numSamples);	
  CascadeClassifier cascade, nestedCascade;
    
  if(argc < 2){
    help();
    return -1;
  }
	for (int i=1; i < argc; i++) {
	  if (strcmp(argv[i],"-scale") == 0)
	    scale = atof(argv[++i]); 
	  if (strcmp(argv[i],"-num") == 0)
	    numSamples = atoi(argv[++i]);
	  else if (strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"-help") == 0)
	    help();
	  else if (strcmp(argv[i],"-r") == 0)
	    mode = "recognize";
	  else if (strcmp(argv[i],"-d") == 0)
	    mode = "detect";
	  else if (strcmp(argv[i],"-del") == 0){
	    dflag = 1;
	    // Code to add samples in csv file
	  }
	  else if (strcmp(argv[i],"-img") == 0){
	    imgPath = argv[++i];
			cout << imgPath << endl;
	    mode = "detect";
	    capFlag = 0;
	  }
	  else if (strcmp(argv[i],"-dev") == 0)
	    devId = atoi(argv[++i]);
	  else if (strcmp(argv[i],"-c") == 0)
	    classifier = string(argv[++i]);
	  else if (strcmp(argv[i],"-vid") == 0)
	    vidPath = string(argv[++i]);
    else if (strcmp(argv[i],"-name") == 0){
	    strcpy(className,argv[++i]);
			nflag = 1;
		}
	  else if (strcmp(argv[i],"-cd") == 0){
	    mode = "contidetect";
			numSamples = -1;
		}
	  else if (strcmp(argv[i],"-cascade") == 0)
	    cascadeName = string (argv[++i]);
	  else if (strcmp(argv[i],"-record") == 0){
	    vidout = string (argv[++i]);
			recFlag =1;
		}
	}
	if(!cascade.load(cascadeName)){
    cerr << "ERROR: Could not load classifier cascade" << endl;
    return -1;
  }
	if (dflag){
		if (!nflag){
			cerr << "del command must be given with an -name option" << endl;
			return -1;
		}	
		vector <int> labels_old,labels_new;
		char cname[80];
		int cid;
		while(fscanf(fid1,"%s %d",cname,&cid) != EOF){
			if (strcmp(className,cname) != 0){
				classNamesVec.push_back(string(cname));
				labels_old.push_back(cid);
			}
			else
				classId = cid;
		}
		int n = labels_old.size();
		labels_new.resize(n+1);
		for (int i=0; i<n; i++)
			labels_new[labels_old[i]] = i;

		fclose(fid1);
		fid1 = fopen(class_filename,"w");
		n = classNamesVec.size();
		for (int i=0; i<n; i++)
			fprintf(fid1,"%s %d\n",classNamesVec[i].c_str(),i);
    
		fclose(fid);
		string filename=string(train_filename);
		char separator = ';';
		vector <int> labels;
		vector <string> paths;
		std::ifstream file(filename.c_str(), ifstream::in);
    if (!file)
        throw std::exception();
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
				if (atoi(classlabel.c_str()) != classId){ 
        	paths.push_back(path);
        	labels.push_back(atoi(classlabel.c_str()));
				}
    }
		file.close();
		
		fid=fopen(train_filename,"w");
		n = labels.size();
		for (int i=0; i<n; i++)
			fprintf(fid,"%s;%d\n",paths[i].c_str(),labels_new[labels[i]]);
		fclose(fid);
		string systxt="rm -r ../train/" + string(className);
		system(systxt.c_str());
		return 0;
	}
	if (mode == "detect") {
		if (!nflag){
			cerr << "detect command must be given with an -name option" << endl;
			return -1;
		}	
	  string txt;
		bool cflag=1;
		int maxid=-1;
		char cname[80];
		int cid;
		while(fscanf(fid1,"%s %d",cname,&cid) != EOF){
			if (strcmp(className,cname) == 0){
				classId=cid;
				cflag=0;
			}
			if (cid >  maxid)
				maxid = cid;
		}
		if (cflag){
			classId = maxid + 1;
	  	fprintf(fid1,"%s %d\n",className,classId);
			txt = "mkdir ../train/" + string(className);
	  	system(txt.c_str());
		}
	}
	else if (mode == "recognize") {
	  string fn_csv = string(train_filename);
	  vector<Mat> images;
    vector<int> labels;
    fid1 = fopen(class_filename,"r");
    // read in the data
    try {
      read_csv(fn_csv, images, labels);
    } 
    catch (exception&) {
      cerr << "Error opening file \"" << fn_csv << "\"." << endl;
      exit(1);
    }
    eigenModel = createEigenFaceRecognizer(80,EIGEN_THRESH);	  
    fisherModel = createFisherFaceRecognizer(0,FISHER_THRESH);	  
    LBPHModel = createLBPHFaceRecognizer(1,8,8,8,LBPH_THRESH);	 
    eigenModel->train(images, labels);
    fisherModel->train(images, labels);
    LBPHModel->train(images, labels);
    char cname[20];
    int cid=0;
    classNamesVec.resize(labels.size());
    while (fscanf(fid1,"%s",cname) != EOF){
      classNamesVec[cid++]=string(cname);
    }
	}
	if (!capFlag) {
		DIR *dp;
		struct dirent *dirp;
		struct stat filestat;
		dp = opendir(imgPath);
		if (dp == NULL){
			cerr << "Error opening image path" << endl;
			return -1;
		}
		while (dirp = readdir(dp)) {
			string filepath = string(imgPath) + dirp->d_name;
			cout << filepath << endl;
			if (stat(filepath.c_str(),&filestat)) 
				continue;
			if (S_ISDIR(filestat.st_mode))
				continue;
			frame = imread(filepath);
			faceDetect(frame, cascade, scale);
			waitKey(30);
		}
	}
	else {
		//VideoCapture cap;
		if (vidPath.size() == 0)
	  	cap.open(devId);
		else 
			cap.open(vidPath);
		if (recFlag){
			vidwriter.open(vidout,cap.get(CV_CAP_PROP_FOURCC),cap.get(CV_CAP_PROP_FPS),Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT)));
		}
    namedWindow( "result", 1 );
		if (vidPath.size() != 0){
			totalNumFrames = cap.get(CV_CAP_PROP_FRAME_COUNT);
			pos=0;
			createTrackbar("pos","result",&pos,totalNumFrames,onTrackbarSlide);
		}
	  while (1){
      cap >> frame;
      if (frame.empty())
        break;
			faceDetect(frame, cascade, scale);
			if (vidPath.size() != 0)
				setTrackbarPos("pos","result",++pos);
      if(waitKey( 10 ) >= 0 || faceSampleCnt == numSamples)
        break;
    }
    destroyWindow("result");
  }

  fclose(fid);
  fclose(fid1);
  return 0;
}

