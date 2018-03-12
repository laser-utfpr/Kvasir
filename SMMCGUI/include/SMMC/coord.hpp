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

    inline Coord() : x(NAN), y(NAN) {};
    inline Coord& operator=(const Coord &copied)
    {
        if(this != &copied)
        {
            x = copied.x;
            y = copied.y;
        }
        return *this;
    }
};

#endif // COORD_HPP
