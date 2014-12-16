#ifndef CV_SUPPORT_H
#define CV_SUPPORT_H

#include <vector>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <opencv/highgui.h>

#include "../support/support.h"

using namespace std;
using namespace cv;

/**
  Get pixel values under line segment from point A to B in the image.
  */
namespace cvSupport{
vector<uchar> pixsUnderLine(Mat & image, Point A, Point B);
int numOfSegments(vector<uchar> &line);
int numberOf(vector<uchar> &line, uchar pix);

int indexBrowser(uint &index, uint size);
void imageBrowser(vector<string> &images);

Point rotatePoint2D(Point p, Mat M);
Mat rotateImg(Mat &img, double angle, Point center = Point(0,0));
Mat translateImg(Mat &img, int offsetx, int offsety);

enum BORDER_PLACE {BORDER_TOP, BORDER_BOTTOM, BORDER_LEFT, BORDER_RIGHT};

Mat addRows(Mat &img, int rows2add, BORDER_PLACE border = BORDER_BOTTOM);


}


#endif
