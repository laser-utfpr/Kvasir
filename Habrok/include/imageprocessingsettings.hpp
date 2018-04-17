#ifndef IMAGEPROCESSINGSETTINGS_HPP
#define IMAGEPROCESSINGSETTINGS_HPP

#include <boost/serialization/string.hpp>
#include <boost/serialization/serialization.hpp>

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

};

#endif //IMAGEPROCESSINGSETTINGS_HPP
