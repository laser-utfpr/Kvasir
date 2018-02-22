#ifndef VISIONFIELD_HPP
#define VISIONFIELD_HPP

#include <opencv2/core/core.hpp>
#include <vector>

#include "visionconstants.h"
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
        ar & upper_left_searched_region_corner & lower_right_searched_region_corner;
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

    Coord upper_left_searched_region_corner;
    Coord lower_right_searched_region_corner;

    //use filters?
};

#endif // VISIONFIELD_HPP
