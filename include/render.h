#ifndef RENDER_H
#define RENDER_H

#include "general.h"

using namespace cv;

void put_text_fps(Mat &img, double fps, Size img_size = Size(640,480));

#endif
