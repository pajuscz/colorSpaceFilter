#include "trackbar.h"


const int Trackbar::SLIDER_MAX = 255;

Trackbar::Trackbar(){

}

Trackbar::Trackbar(string name)
{
    this->setName(name);
    this->setValue(0);
}

Trackbar::Trackbar(string name, int value)
{
    this->setName(name);
    this->setValue(value);
}

void Trackbar::setValue(int value){
    if(value <= Trackbar::SLIDER_MAX){
        this->value = value;
    }
}

int Trackbar::getValue(){
    return this->value;
}

int* Trackbar::getRefValue(){
    return &this->value;
}

void Trackbar::setName(string name){
    this->name = name;
}

string Trackbar::getName(){
    return this->name;
}

string Trackbar::toString(){
    stringstream ss;
    ss << this->getName() << ": " << this->getValue();
    return ss.str();
}


/**
 * @brief TrackBarPair::TrackBarPair
 * @param low
 * @param high
 */

TrackBarPair::TrackBarPair(){}

TrackBarPair::TrackBarPair(Trackbar &low, Trackbar &high){
    tb1 = low;
    tb2 = high;
}

int TrackBarPair::getHighValue(){
    return tb2.getValue();
}
int TrackBarPair::getLowValue(){
    return tb1.getValue();
}

/**
  */

TrackBars::TrackBars(TrackBarPair &R, TrackBarPair &G, TrackBarPair &B){
    r = R;
    g = G;
    b = B;
}


void TrackBars::setImage(Mat &img){
    this->img_orig = img;
    this->img_orig.copyTo(img_rgb);
    this->img_orig.copyTo(img_tmp);
}

void TrackBars::setHSV(){
    cvtColor(img_orig,img_orig,CV_BGR2HSV_FULL);
}

Mat TrackBars::applyFilters(){
    cv::inRange(img_orig,
                cv::Scalar(b.getLowValue(),
                           g.getLowValue(),
                           r.getLowValue()),
                cv::Scalar(b.getHighValue(),
                           g.getHighValue(),
                           r.getHighValue()),
                img_tmp);
    return img_tmp;
}

Mat TrackBars::getRGBImage(){
    return this->img_rgb;
}

Mat TrackBars::getImage(){
    return this->img_tmp;
}

Mat TrackBars::getOriginalImage(){
    return this->img_orig;
}
