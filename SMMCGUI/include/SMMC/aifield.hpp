#ifndef AIFIELD_HPP
#define AIFIELD_HPP

#include <boost/serialization/utility.hpp>

#include <vector>

#include "smmcconstants.h"
#include "coord.hpp"
#include "entity.hpp"

class AIField
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        ar & left_goal_ulc & left_goal_lrc & right_goal_ulc & right_goal_lrc;
        left_goalkeeper_area_ulcleft_goalkeeper_area_lrc
        right_goalkeeper_area_ulc right_goalkeeper_area_lrc;;
    };

public:
    double image_width;
    double image_height;

    Entity ball;
    Entity robot[N_ROBOTS];
    Entity enemy_robot[N_ROBOTS];

    Coord left_goal_ulc; //upper left corner
    Coord left_goal_lrc; //lower right corner
    Coord right_goal_ulc;
    Coord right_goal_lrc;

    Coord left_goalkeeper_area_ulc;
    Coord left_goalkeeper_area_lrc;
    Coord right_goalkeeper_area_ulc;
    Coord right_goalkeeper_area_lrc;

    inline AIField(){};
};

#endif // AIFIELD_HPP
