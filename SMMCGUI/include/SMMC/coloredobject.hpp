#ifndef COLOREDOBJECT_HPP
#define COLOREDOBJECT_HPP

#include <opencv2/opencv.hpp>

#include "coord.hpp"
#include "smmcconstants.h"

class ColoredObject
{
private:

public:
    Coord coord;
    double area;
    Color color;
    cv::vector<cv::Point> contour;
    bool linked_to_entity;

    inline ColoredObject() : area(NAN),
    color(UNCOLORED), linked_to_entity(false) {};

    inline ColoredObject& operator=(const ColoredObject &copied)
    {
        if(this != &copied)
        {
            coord = copied.coord;
            area = copied.area;
            color = copied.color;
            linked_to_entity = copied.linked_to_entity;
        }
        return *this;
    }
};

#endif // COLOREDOBJECT_HPP
