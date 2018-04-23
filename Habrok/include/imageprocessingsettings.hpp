#ifndef IMAGEPROCESSINGSETTINGS_HPP
#define IMAGEPROCESSINGSETTINGS_HPP

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
        //ar &
    };

public:
    HSVMask mask[N_COLORS];

    ImageProcessingSettings();
    ~ImageProcessingSettings();
};

#endif //IMAGEPROCESSINGSETTINGS_HPP
