#ifndef SHAREDPARAMETERS_HPP
#define SHAREDPARAMETERS_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/serialization.hpp>

#include <QCoreApplication>

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

    //paths
    std::string vision_path;
    std::string ai_path;
    std::string comm_path;

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

    std::string getVisionPath(void);
    std::string getAIPath(void);
    std::string getCommPath(void);

    AIField getAIField(void);
    Movement getRobotMovement(int index);
};

#endif // SHAREDPARAMETERS_HPP
