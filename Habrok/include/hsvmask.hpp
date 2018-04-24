#ifndef HSVMASK_HPP
#define HSVMASK_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>

#include <smmclib.hpp>

class HSVMask
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        ar & color;
        ar & h_min & h_max;
        ar & s_min & s_max;
        ar & v_min & v_max;
    };

public:
    Color color;

    int h_min;
    int h_max;
    int s_min;
    int s_max;
    int v_min;
    int v_max;

    inline HSVMask() : color(UNCOLORED), h_min(0), h_max(255), s_min(0),
                                         s_max(255), v_min(0), v_max(255) {};
};

#endif //HSVMASK_HPP
