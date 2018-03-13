#ifndef AIFIELD_HPP
#define AIFIELD_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>

#include <vector>

#include "smmcconstants.h"
#include "coord.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "visionfield.hpp"

class AIField
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        ar & left_goal_ulc & left_goal_lrc & right_goal_ulc & right_goal_lrc;
        ar & left_goalkeeper_area_ulc & left_goalkeeper_area_lrc;
        ar & right_goalkeeper_area_ulc & right_goalkeeper_area_lrc;
    };

public:
    double image_width;
    double image_height;

    Entity ball;
    Player robot[N_ROBOTS];
    Entity enemy_robot[N_ROBOTS];

    Coord left_goal_ulc; //upper left corner
    Coord left_goal_lrc; //lower right corner
    Coord right_goal_ulc;
    Coord right_goal_lrc;

    Coord left_goalkeeper_area_ulc;
    Coord left_goalkeeper_area_lrc;
    Coord right_goalkeeper_area_ulc;
    Coord right_goalkeeper_area_lrc;

    std::string command;
    std::string command_feedback;

    inline AIField(){};
    inline AIField& operator<<(const VisionField& vision)
    {
        image_width = vision.image_width;
        image_height = vision.image_height;

        ball = vision.ball;
        for(int i=0; i<N_ROBOTS; i++)
            robot[i] = vision.robot[i];
        for(int i=0; i<N_ROBOTS; i++)
            enemy_robot[i] = vision.enemy_robot[i];

        return *this;
    }
};

#endif // AIFIELD_HPP
