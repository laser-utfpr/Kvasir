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
    inline Coord(double xi, double yi) : x(xi), y(yi) {};
    inline Coord& operator=(const Coord &copied)
    {
        if(this != &copied)
        {
            x = copied.x;
            y = copied.y;
        }
        return *this;
    }
    inline Coord operator+(const Coord &added)
    {
        Coord new_coord(x + added.x, y + added.y);
        return new_coord;
    }
    inline Coord operator-(const Coord &subtracted)
    {
        Coord new_coord(x - subtracted.x, y - subtracted.y);
        return new_coord;
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
    inline double angle()
    {
        return atan2(y,x);
    }
    inline double norm()
    {
        return sqrt(x*x+y*y);
    }
    inline bool isInRect(Coord r1, Coord r2)
    {
        if(r1.x <= r2.x && r1.y <= r2.y)
        {
            if(x >= r1.x && x <= r2.x && y >= r1.y && y <= r2.y)
                return true;
        }
        else if(r1.x <= r2.x && r1.y >= r2.y)
        {
            if(x >= r1.x && x <= r2.x && y >= r2.y && y <= r1.y)
                return true;
        }
        else if(r1.x >= r2.x && r1.y <= r2.y)
        {
            if(x >= r2.x && x <= r1.x && y >= r1.y && y <= r2.y)
                return true;
        }
        else //if(r1.x >= r2.x && r1.y >= r2.y)
        {
            if(x >= r2.x && x <= r1.x && y >= r2.y && y <= r1.y)
                return true;
        }
        return false;
    }
    inline Coord bisector(Coord c1, Coord c2)
    {
        Coord vec1(c1.x-x, c1.y-y);
        Coord vec2(c2.x-x, c2.y-y);
        Coord bisec(vec1.x/vec1.norm() + vec2.x/vec2.norm(),
                    vec1.y/vec1.norm() + vec2.y/vec2.norm());
        return bisec;
    }
};

#endif // COORD_HPP
