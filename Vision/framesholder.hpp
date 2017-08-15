#ifndef FRAMESHOLDER_HPP
#define FRAMESHOLDER_HPP

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <string>

#include "visionconstants.h"
#include "hsvmask.h"

class FramesHolder
{
private:
    cv::VideoCapture camera;
    cv::Mat raw_image;
    cv::Mat hsv_image;
    cv::Mat thresholded_image;
public:
    FramesHolder();
    void setCameraToDefault(void);
    void updateRawAndHSVImages(void);
    void updateThresholdedImage(HSVMask* mask);
    void useMorphingOperations(void);
    void showAllImages(void);
    void showRawImage(void);
    void showHSVImage(void);
    void showThresholdedImage(void);
    void setupHSVMaskFromWindow(HSVMask *mask, objectColor color);
};

#endif // FRAMESHOLDER_HPP
