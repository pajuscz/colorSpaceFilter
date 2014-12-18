#include <iostream>

#include "support/support.h"
#include "cvSupport/cvSupport.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#include "trackbar.h"


const string WIN_NAME = "Filter";

void on_A_low (int value, void * data){

    TrackBars * bars = (TrackBars *) data;

    vector<TrackBarPair> barPair;
    barPair.push_back(bars->r);
    barPair.push_back(bars->g);
    barPair.push_back(bars->b);

    for(uint i = 0; i < barPair.size(); ++i){
        TrackBarPair bp = barPair[i];
        //cout << bp.tb1.toString() << ", " << bp.tb2.toString() << endl;
        if(bp.tb2.getValue() < bp.tb1.getValue()){
            // Zalezi na poradni bud se hybe velky nebo maly (nejde to atomicky)
            setTrackbarPos(bp.tb2.getName(), WIN_NAME, bp.tb1.getValue());
            setTrackbarPos(bp.tb1.getName(), WIN_NAME, bp.tb2.getValue());
        }
    }

    imshow(WIN_NAME,bars->applyFilters());
}



int main(int argc, char ** argv)
{

    Trackbar R_low("R_low",0);
    Trackbar R_high("R_high",255);

    Trackbar G_low("G_low",0);
    Trackbar G_high("G_high",255);

    Trackbar B_low("B_low",0);
    Trackbar B_high("B_high",255);

    TrackBarPair R(R_low, R_high);
    TrackBarPair G(G_low, G_high);
    TrackBarPair B(B_low, B_high);

    TrackBars RGB(R,G,B);

    if(argc > 1){
        vector<string> files = Support::pathVector(argv[1]);
        sort(files.begin(), files.end());

        for(uint i = 0; i < files.size(); ++i){
            cout << files[i] << endl;
            Mat img = imread(files[i], CV_LOAD_IMAGE_ANYCOLOR);

            if(img.data){
                namedWindow(WIN_NAME, WINDOW_AUTOSIZE);

                RGB.setImage(img);
                RGB.setHSV();
                RGB.applyFilters();

                createTrackbar(R_low.getName(), WIN_NAME, RGB.r.tb1.getRefValue(), Trackbar::SLIDER_MAX, on_A_low, &RGB);
                createTrackbar(R_high.getName(), WIN_NAME, RGB.r.tb2.getRefValue(), Trackbar::SLIDER_MAX, on_A_low, &RGB);

                createTrackbar(G_low.getName(), WIN_NAME, RGB.g.tb1.getRefValue(), Trackbar::SLIDER_MAX, on_A_low, &RGB);
                createTrackbar(G_high.getName(), WIN_NAME, RGB.g.tb2.getRefValue(), Trackbar::SLIDER_MAX, on_A_low, &RGB);

                createTrackbar(B_low.getName(), WIN_NAME, RGB.b.tb1.getRefValue(), Trackbar::SLIDER_MAX, on_A_low, &RGB);
                createTrackbar(B_high.getName(), WIN_NAME, RGB.b.tb2.getRefValue(), Trackbar::SLIDER_MAX, on_A_low, &RGB);
                imshow(WIN_NAME,RGB.getImage());
                imshow("original",RGB.getRGBImage());
                imshow("hsv",RGB.getOriginalImage());
            }
            cvSupport::indexBrowser(i,files.size());
        }
    }
    cout << "a" << endl;
    return 0;
}

