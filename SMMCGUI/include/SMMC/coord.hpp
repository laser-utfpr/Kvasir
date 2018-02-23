#ifndef COORD_HPP
#define COORD_HPP

#include <boost/serialization/utility.hpp>

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
    inline Coord(){};
};

#endif // COORD_HPP
