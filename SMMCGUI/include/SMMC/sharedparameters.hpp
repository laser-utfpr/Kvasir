#ifndef SHAREDPARAMETERS_HPP
#define SHAREDPARAMETERS_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <boost/serialization/string.hpp>
#include <boost/serialization/serialization.hpp>

#include <QCoreApplication>

#include <QMutex>

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "smmclib.hpp"

class SharedParameters
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        ar & vision_path & ai_path & comm_path;

        ar & vision_field->ball_color & vision_field->ally_center & vision_field->enemy_center;
        ar & vision_field->searched_region_ulc & vision_field->searched_region_lrc;
        //ar & vision_field;

        ar & ai_field->playable_field_ulc & ai_field->playable_field_lrc;
        ar & ai_field->left_goal_ulc & ai_field->left_goal_lrc & ai_field->right_goal_ulc & ai_field->right_goal_lrc;
        ar & ai_field->left_goalkeeper_area_ulc & ai_field->left_goalkeeper_area_lrc;
        ar & ai_field->right_goalkeeper_area_ulc & ai_field->right_goalkeeper_area_lrc;
        //ar & ai_field; // & other stuff to be saved
    };

    QMutex lock;

    bool force_stop;

    //paths
    std::string vision_path;
    std::string ai_path;
    std::string comm_path;

    std::string settings_file;

    //Vision variables
    VisionField *vision_field;

    //AI variables
    AIField *ai_field;

    //Communication variables
    Movement robot_movement[N_ROBOTS];

    //Boost Interprocess Allocators
    boost::interprocess::managed_shared_memory *allocator_provider; //only used to provide allocators
    std::string provider_name;
    CharAllocator *char_allocator;
    StringAllocator *string_allocator;
    ColorAllocator *color_allocator;
    ColoredObjectAllocator *colored_object_allocator;
    FloatAllocator *float_allocator;

public:
    SharedParameters();
    ~SharedParameters();
    void loadSettingsFromFile(void);
    void loadDefaults(void);

    void readVisionParameters(VisionField &v_field);
    void readAIParameters(AIField &a_field);

    std::string getVisionPath(void);
    std::string getAIPath(void);
    std::string getCommPath(void);
    void setVisionPath(std::string str);
    void setAIPath(std::string str);
    void setCommPath(std::string str);

    std::string getAICommand(void);
    void setAICommand(std::string str);
    std::vector<std::string> getCommandList(void);

    void setForceStop(bool stop);

    std::vector<float> getImageData(void);
    double getImageWidth(void);
    double getImageHeight(void);
    int getImageCVType(void);
    std::vector<ColoredObject> getColorObjects(void);

    void setBallColor(Color color);
    void setAllyCenter(Color color);
    void setEnemyCenter(Color color);
    Color getBallColor(void);
    Color getAllyCenter(void);
    Color getEnemyCenter(void);
    std::vector<Color> getTags(void);

    Coord getSearchedRegionULC(void);
    Coord getSearchedRegionLRC(void);
    void setSearchedRegionULCx(double ulc_x);
    void setSearchedRegionULCy(double ulc_y);
    void setSearchedRegionLRCx(double lrc_x);
    void setSearchedRegionLRCy(double lrc_y);

    Coord getPlayableFieldULC(void);
    Coord getPlayableFieldLRC(void);
    void setPlayableFieldULCx(double ulc_x);
    void setPlayableFieldULCy(double ulc_y);
    void setPlayableFieldLRCx(double lrc_x);
    void setPlayableFieldLRCy(double lrc_y);
    Coord getLeftGoalULC(void);
    Coord getLeftGoalLRC(void);
    void setLeftGoalULCx(double ulc_x);
    void setLeftGoalULCy(double ulc_y);
    void setLeftGoalLRCx(double lrc_x);
    void setLeftGoalLRCy(double lrc_y);
    Coord getRightGoalULC(void);
    Coord getRightGoalLRC(void);
    void setRightGoalULCx(double ulc_x);
    void setRightGoalULCy(double ulc_y);
    void setRightGoalLRCx(double lrc_x);
    void setRightGoalLRCy(double lrc_y);
    Coord getLeftGKAreaULC(void);
    Coord getLeftGKAreaLRC(void);
    void setLeftGKAreaULCx(double ulc_x);
    void setLeftGKAreaULCy(double ulc_y);
    void setLeftGKAreaLRCx(double lrc_x);
    void setLeftGKAreaLRCy(double lrc_y);
    Coord getRightGKAreaULC(void);
    Coord getRightGKAreaLRC(void);
    void setRightGKAreaULCx(double ulc_x);
    void setRightGKAreaULCy(double ulc_y);
    void setRightGKAreaLRCx(double lrc_x);
    void setRightGKAreaLRCy(double lrc_y);

    bool addTagColor(Color new_color);
    bool removeTagColor(Color dead_color);
    bool isTagColor(Color searched_color);

    AIField getAIField(void);
    Movement getRobotMovement(int index);

    Entity getBall(void);
    Player getAllyRobot(int index);
    Entity getEnemyRobot(int index);

    useconds_t getVisionTime(void);
};

#endif // SHAREDPARAMETERS_HPP
