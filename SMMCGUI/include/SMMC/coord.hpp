#ifndef COORD_HPP
#define COORD_HPP

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
};

#endif // COORD_HPP
