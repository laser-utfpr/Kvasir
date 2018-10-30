#ifndef IMAGEPROCESSINGSETTINGS_HPP
#define IMAGEPROCESSINGSETTINGS_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/serialization/string.hpp>
#include <boost/serialization/serialization.hpp>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <QtCore>

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include <smmclib.hpp>

#include "habrokconstants.h"
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
        ar & camera_id;
    };

    std::string settings_file;

    bool use_morphing_operations = false;
    int erode_rect_size = 0;
    int dilate_rect_size = 0;

    int minimum_object_area = 100;

    int camera_id = 0;

public:
    ImageProcessingSettings();
    ~ImageProcessingSettings();

    void loadCalibration(void);
    void loadDefaults(void);

    void setCameraID(int id);
    int getCameraID(void);

    void setMinimumObjectArea(int moa);
    int getMinimumObjectArea(void);

    void setUseMorphingOperations(bool umo);
    bool getUseMorphingOperations(void);

    void setErodeRectSize(int ers);
    int getErodeRectSize(void);

    void setDilateRectSize(int drs);
    int getDilateRectSize(void);

    HSVMask mask[N_COLORS];
};

#endif //IMAGEPROCESSINGSETTINGS_HPP
