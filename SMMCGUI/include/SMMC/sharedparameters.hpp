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
#include <algorithm>

#include "smmclib.hpp"

class SharedParameters
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);

    QMutex lock;

    void loadDefaults(void);

    bool force_stop;

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
    void setVisionPath(std::string str);
    void setAIPath(std::string str);
    void setCommPath(std::string str);

    void sendAICommand(std::string str);
    std::vector<std::string> getCommandList(void);

    void setForceStop(bool stop);

    void setAllyCenter(Color color);
    void setEnemyCenter(Color color);
    Color getAllyCenter(void);
    Color getEnemyCenter(void);

    Coord getSearchedRegionULC(void);
    Coord getSearchedRegionLRC(void);
    void setSearchedRegionULCx(double ulc_x);
    void setSearchedRegionULCy(double ulc_y);
    void setSearchedRegionLRCx(double lrc_x);
    void setSearchedRegionLRCy(double lrc_y);

    bool addTagColor(Color new_color);
    bool removeTagColor(Color dead_color);
    bool isTagColor(Color searched_color);

    AIField getAIField(void);
    Movement getRobotMovement(int index);
};

#endif // SHAREDPARAMETERS_HPP
