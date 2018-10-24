#include "imageprocessingsettings.hpp"

ImageProcessingSettings::ImageProcessingSettings()
{
    for(int i=0; i<N_COLORS; i++)
        mask[i].color = static_cast<Color>(i);
}

ImageProcessingSettings::~ImageProcessingSettings()
{

}

void ImageProcessingSettings::applyMorphingOperations(cv::Mat &thresholded_image)
{
    if(use_morphing_operations)
    {
        cv::Mat erode_element = getStructuringElement(cv::MORPH_RECT,
                                cv::Size(erode_rect_size, erode_rect_size));
        cv::Mat dilate_element = getStructuringElement(cv::MORPH_RECT,
                                 cv::Size(dilate_rect_size, dilate_rect_size));

        erode(thresholded_image, thresholded_image, erode_element);
        erode(thresholded_image, thresholded_image, erode_element);

        dilate(thresholded_image, thresholded_image, dilate_element);
        dilate(thresholded_image, thresholded_image, dilate_element);
    }
}

void ImageProcessingSettings::setCameraID(int id)
{
    camera_id = id;
}
int ImageProcessingSettings::getCameraID(void)
{
    return camera_id;
}

void ImageProcessingSettings::setMinimumObjectArea(int moa)
{
    minimum_object_area = moa;
}

int ImageProcessingSettings::getMinimumObjectArea(void)
{
    return minimum_object_area;
}

void ImageProcessingSettings::setUseMorphingOperations(bool umo)
{
    use_morphing_operations = umo;
}

bool ImageProcessingSettings::getUseMorphingOperations(void)
{
    return use_morphing_operations;
}

void ImageProcessingSettings::setErodeRectSize(int ers)
{
    erode_rect_size = ers;
}

int ImageProcessingSettings::getErodeRectSize(void)
{
    return erode_rect_size;
}

void ImageProcessingSettings::setDilateRectSize(int drs)
{
    dilate_rect_size = drs;
}

int ImageProcessingSettings::getDilateRectSize(void)
{
    return dilate_rect_size;
}
