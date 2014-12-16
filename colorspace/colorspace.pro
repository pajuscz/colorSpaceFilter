TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    support/support.cpp \
    cvSupport/cvSupport.cpp \
    trackbar.cpp

INCLUDEPATH += /usr/local/include\
/usr/local/include/opencv2
LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_contrib \
-lopencv_legacy \
-lopencv_flann

HEADERS += \
    support/support.h \
    cvSupport/cvSupport.h \
    trackbar.h

