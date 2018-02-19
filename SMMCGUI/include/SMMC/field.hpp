#ifndef FIELD_HPP
#define FIELD_HPP

#include <opencv2/core/core.hpp>

#include "visionconstants.h"
#include "coord.hpp"

class Entity
{

}

class Field
{
private:

public:
    cv::Mat image;
    Entity ball;
    Entity robot[N_ROBOTS];
    Entity enemy_robot[N_ROBOTS];
    color ball_color;
    color ally_center;
    color ally_edge;
    color enemy_center;
    Coord upper_left_searched_region_corner;
    Coord lower_right_searched_region_corner;
    //use filters?
};

#endif // FIELD_HPP
