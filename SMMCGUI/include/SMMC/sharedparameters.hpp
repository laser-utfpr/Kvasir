#ifndef SHAREDPARAMETERS_HPP
#define SHAREDPARAMETERS_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <QMutex>

#include <iostream>
#include <fstream>

#include "smmclib.hpp"

class SharedParameters
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);

    QMutex lock;

    void loadDefaults(void);

    //Vision variables
    VisionField vision_field;

    //AI variables
    AIField ai_field;

    //Communication variables
    Movement robot_movement[N_ROBOTS];

public:
    SharedParameters();
    ~SharedParameters();
    void loadSettingsFromFile(void);

    void readVisionParameters(VisionField v_field);
    void readAIParameters(AIField a_field);

    AIField getAIField(void);
    Movement getRobotMovement(int index);
};

#endif // SHAREDPARAMETERS_HPP
