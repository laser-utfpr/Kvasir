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

double ImageProcessingSettings::getMinimumObjectArea(void)
{
    return minimum_object_area;
}

void setCameraID(int id)
{
    camera_id = id;
}
int getCameraID(void)
{
    return camera_id;
}
