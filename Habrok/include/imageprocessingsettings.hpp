#ifndef IMAGEPROCESSINGSETTINGS_HPP
#define IMAGEPROCESSINGSETTINGS_HPP

#include <opencv2/opencv.hpp>

#include <boost/serialization/string.hpp>
#include <boost/serialization/serialization.hpp>

#include <smmclib.hpp>

#include "hsvmask.hpp"

class ImageProcessingSettings
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        for(int i=0; i<N_COLORS; i++)
            ar & mask[i];
        ar & use_morphing_operations;
        ar & erode_rect_size & dilate_rect_size;
        ar & minimum_object_area;
    };

    bool use_morphing_operations;
    int erode_rect_size;
    int dilate_rect_size;

    double minimum_object_area;

public:
    HSVMask mask[N_COLORS];

    ImageProcessingSettings();
    ~ImageProcessingSettings();

    void applyMorphingOperations(cv::Mat &thresholded_image);

    double getMinimumObjectArea(void);
};

#endif //IMAGEPROCESSINGSETTINGS_HPP
