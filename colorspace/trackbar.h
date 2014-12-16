#ifndef TRACKBAR_H
#define TRACKBAR_H

#include <string>
#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;



class Trackbar
{
public:
    Trackbar();
    Trackbar(string name);
    Trackbar(string name, int value);

    void setValue(int value);
    int getValue();
    int* getRefValue();

    string getName();
    void setName(string name);

    static const int SLIDER_MAX;

    string toString();
private:
    int value;
    string name;


};

class TrackBarPair
{
public:
    TrackBarPair();
    TrackBarPair(Trackbar &low, Trackbar &high);

    int getHighValue();
    int getLowValue();

    void setHighValue();
    void setLowValue();

    Trackbar tb1;
    Trackbar tb2;

};


class TrackBars
{
public:
    TrackBars(TrackBarPair &R, TrackBarPair &G,TrackBarPair &B);

    void setImage(Mat &img);
    Mat applyFilters();

    Mat getOriginalImage();
    Mat getImage();

    TrackBarPair r;
    TrackBarPair g;
    TrackBarPair b;
private:
    Mat img_orig;
    Mat img_tmp;
};

#endif // TRACKBAR_H
