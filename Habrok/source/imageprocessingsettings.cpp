#include "imageprocessingsettings.hpp"

ImageProcessingSettings::ImageProcessingSettings()
{
    for(int i=0; i<N_COLORS; i++)
        mask[i].color = static_cast<Color>(i);
}

ImageProcessingSettings::~ImageProcessingSettings()
{

}

cv::Mat ImageProcessingSettings::applyMorphingOperations(cv::Mat thresholded_image)
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

    return thresholded_image;
}

double ImageProcessingSettings::getMinimumObjectArea(void)
{
    return minimum_object_area;
}
