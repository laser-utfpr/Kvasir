#ifndef VISIONFIELD_HPP
#define VISIONFIELD_HPP

#include <opencv2/core/core.hpp>

#include <boost/serialization/utility.hpp>

#include <vector>

#include "smmcconstants.h"
#include "coord.hpp"
#include "entity.hpp"
#include "coloredobject.hpp"

class VisionField
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        ar & ball_color & ally_center & ally_tag & enemy_center;
        ar & Coord searched_region_ulc & searched_region_lrc;
    };

public:
    cv::Mat image;
    double image_width;
    double image_height;
    useconds_t time_us;

    std::vector<ColoredObject> found_object;

    Entity ball;
    Entity robot[N_ROBOTS];
    Entity enemy_robot[N_ROBOTS];

    Color ball_color;
    Color ally_center;
    Color ally_tag;
    Color enemy_center;

    Coord searched_region_ulc; //upper left corner
    Coord searched_region_lrc; //lower right corner

    //use filters?

    inline VisionField(){};
};

#endif // VISIONFIELD_HPP
