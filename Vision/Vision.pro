TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sightedobjects.cpp \
    framesholder.cpp \
    colormasks.cpp \
    vision.cpp

HEADERS += \
    sightedobjects.hpp \
    visionconstants.h \
    framesholder.hpp \
    ../hsvmask.h \
    hsvmask.h \
    colormasks.hpp \
    vision.hpp

INCLUDEPATH += /usr/local/include/opencv
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
