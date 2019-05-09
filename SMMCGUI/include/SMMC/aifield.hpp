#ifndef AIFIELD_HPP
#define AIFIELD_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>

#include <vector>
#include <string>

#include "interprocessvariabledefinitions.hpp"

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
        ar & playable_field_ulc & playable_field_lrc;
        ar & left_goal_ulc & left_goal_lrc & right_goal_ulc & right_goal_lrc;
        ar & left_goalkeeper_area_ulc & left_goalkeeper_area_lrc;
        ar & right_goalkeeper_area_ulc & right_goalkeeper_area_lrc;
    };

public:
    double image_width;
    double image_height;
    useconds_t time_us;

    Entity ball;
    Player robot[N_ROBOTS];
    Entity enemy_robot[N_ROBOTS];

    Coord playable_field_ulc;
    Coord playable_field_lrc;

    Coord left_goal_ulc; //upper left corner
    Coord left_goal_lrc; //lower right corner
    Coord right_goal_ulc;
    Coord right_goal_lrc;

    Coord left_goalkeeper_area_ulc;
    Coord left_goalkeeper_area_lrc;
    Coord right_goalkeeper_area_ulc;
    Coord right_goalkeeper_area_lrc;

    BoostInterprocessString command, manual_command, manual_player, side;
    StringVector command_list, manual_command_list, side_list;

    inline AIField(CharAllocator &char_allocator, StringAllocator &string_allocator) :
    image_width(0), image_height(0), time_us(0),
    command(char_allocator), command_list(string_allocator),
    manual_command(char_allocator), manual_command_list(string_allocator), manual_player((char_allocator)),
    side(char_allocator), side_list(string_allocator){};

    inline AIField& operator<<(const VisionField& vision)
    {
        image_width = vision.image_width;
        image_height = vision.image_height;
        time_us = vision.time_us;

        ball = vision.ball;
        for(int i=0; i<N_ROBOTS; i++)
            robot[i] = vision.robot[i];
        for(int i=0; i<N_ROBOTS; i++)
            enemy_robot[i] = vision.enemy_robot[i];

        return *this;
    }
};

#endif // AIFIELD_HPP
