#ifndef COORD_HPP
#define COORD_HPP

#include <cmath>

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>

class Coord
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        ar & x & y;
    };

public:
    double x;
    double y;

    inline Coord() : x(0), y(0) {};
    inline Coord& operator=(const Coord &copied)
    {
        if(this != &copied)
        {
            x = copied.x;
            y = copied.y;
        }
        return *this;
    }
    inline double distance(Coord c)
    {
        double dx = c.x - x;
        double dy = c.y - y;
        return sqrt(dx*dx + dy*dy);
    }
    inline double angle(Coord c)
    {
        double dx = c.x - x;
        double dy = c.y - y;
        return atan2(dy,dx);
    }
};

#endif // COORD_HPP
