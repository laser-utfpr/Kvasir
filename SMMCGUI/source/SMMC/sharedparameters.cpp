#include "sharedparameters.hpp"

template<class Archive>
void SharedParameters::serialize(Archive &ar, const unsigned int version)
{
    ar & vision_path & ai_path & comm_path;
    ar & vision_field & ai_field; // & other stuff to be saved
}

void SharedParameters::loadDefaults(void)
{
    QMutexLocker m(&lock);

    //find good defaults;
}

SharedParameters::SharedParameters()
{
    vision_path.clear();
    ai_path.clear();
    comm_path.clear();
    force_stop = false;
    loadDefaults();

    //test - to be deleted
    ai_field.command_list.push_back("the");
    ai_field.command_list.push_back("thing");
    ai_field.command_list.push_back("goes");
    ai_field.command_list.push_back("skraa");
    ai_field.command_list.push_back("papakakaka");
    ai_field.command_list.push_back("anatoomtoomtooroomtoom");
    vision_field.ally_tag.push_back(VIOLET);
}

SharedParameters::~SharedParameters()
{
    QMutexLocker m(&lock);

    QString app_dir_path = QCoreApplication::applicationDirPath();
    std::string settings_path = app_dir_path.toStdString();
    settings_path += '/';
    settings_path += SAVED_SETTINGS_FILENAME;
    std::ofstream new_file(settings_path);

    if(!new_file.fail())
    {
        try
        {
            boost::archive::text_oarchive archive_saver(new_file);
            archive_saver << *this;
        }
        catch(...)
        {
            std::cout << "Exception called while trying to save settings file with boost serialization!" << std::endl;
        }
    }
}

void SharedParameters::loadSettingsFromFile(void)
{
    QMutexLocker m(&lock);

    QString app_dir_path = QCoreApplication::applicationDirPath();
    std::string settings_path = app_dir_path.toStdString();
    settings_path += '/';
    settings_path += SAVED_SETTINGS_FILENAME;
    std::ifstream opened_file(settings_path);

    if(!opened_file.fail())
    {
        try
        {
            boost::archive::text_iarchive archive_loader(opened_file);
            archive_loader >> *this;
        }
        catch(...)
        {
            std::cout << "Exception called while trying to read settings file with boost serialization!" << std::endl;
        }
    }
}

void SharedParameters::readVisionParameters(VisionField v_field)
{
    QMutexLocker m(&lock);

    vision_field.image = v_field.image;
    vision_field.image_width = v_field.image_width;
    vision_field.image_height = v_field.image_height;
    vision_field.time_us = v_field.time_us;

    vision_field.found_object = v_field.found_object;

    vision_field.ball = v_field.ball;
    for(int i=0; i<N_ROBOTS; i++)
        vision_field.robot[i] = v_field.robot[i];
    for(int i=0; i<N_ROBOTS; i++)
        vision_field.enemy_robot[i] = v_field.enemy_robot[i];

    //applying changes to ai a_field
    ai_field << vision_field;
}

void SharedParameters::readAIParameters(AIField a_field)
{
    QMutexLocker m(&lock);

    for(int i=0; i<N_ROBOTS; i++)
        ai_field.robot[i].movement = a_field.robot[i].movement;

    ai_field.command_list = a_field.command_list;

    //applying changes to comm movements
    for(int i=0; i<N_ROBOTS; i++)
        robot_movement[i] = ai_field.robot[i].movement;
}

std::string SharedParameters::getVisionPath(void)
{
    QMutexLocker m(&lock);
    return vision_path;
}

std::string SharedParameters::getAIPath(void)
{
    QMutexLocker m(&lock);
    return ai_path;
}

std::string SharedParameters::getCommPath(void)
{
    QMutexLocker m(&lock);
    return comm_path;
}

void SharedParameters::setVisionPath(std::string str)
{
    QMutexLocker m(&lock);
    vision_path = str;
}

void SharedParameters::setAIPath(std::string str)
{
    QMutexLocker m(&lock);
    ai_path = str;
}

void SharedParameters::setCommPath(std::string str)
{
    QMutexLocker m(&lock);
    comm_path = str;
}

cv::Mat SharedParameters::getVisionImage(void)
{
    QMutexLocker m(&lock);
    return vision_field.image;
}

std::vector<ColoredObject> SharedParameters::getColorObjects(void)
{
    QMutexLocker m(&lock);
    return vision_field.found_object;
}

Color SharedParameters::setBallColor(Color color)
{
    QMutexLocker m(&lock);
    vision_field.ball_color = color;
}

void SharedParameters::setAllyCenter(Color color)
{
    QMutexLocker m(&lock);
    vision_field.ally_center = color;
}

void SharedParameters::setEnemyCenter(Color color)
{
    QMutexLocker m(&lock);
    vision_field.enemy_center = color;
}

std::vector<Color> SharedParameters::getTags(void)
{
    QMutexLocker m(&lock);
    return vision_field.ally_tag;
}

Color SharedParameters::getBallColor(void)
{
    QMutexLocker m(&lock);
    return vision_field.ball_color;
}

Color SharedParameters::getAllyCenter(void)
{
    QMutexLocker m(&lock);
    return vision_field.ally_center;
}

Color SharedParameters::getEnemyCenter(void)
{
    QMutexLocker m(&lock);
    return vision_field.enemy_center;
}

Coord SharedParameters::getSearchedRegionULC(void)
{
    QMutexLocker m(&lock);
    return vision_field.searched_region_ulc;
}

Coord SharedParameters::getSearchedRegionLRC(void)
{
    QMutexLocker m(&lock);
    return vision_field.searched_region_lrc;
}

void SharedParameters::setSearchedRegionULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    vision_field.searched_region_ulc.x = ulc_x;
}

void SharedParameters::setSearchedRegionULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    vision_field.searched_region_ulc.y = ulc_y;
}

void SharedParameters::setSearchedRegionLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    vision_field.searched_region_lrc.x = lrc_x;
}

void SharedParameters::setSearchedRegionLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    vision_field.searched_region_lrc.y = lrc_y;
}

Coord SharedParameters::getPlayableFieldULC(void)
{
    QMutexLocker m(&lock);
    return ai_field.playable_field_ulc;
}

Coord SharedParameters::getPlayableFieldLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field.playable_field_lrc;
}

void SharedParameters::setPlayableFieldULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field.playable_field_ulc.x = ulc_x;
}

void SharedParameters::setPlayableFieldULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field.playable_field_ulc.y = ulc_y;
}

void SharedParameters::setPlayableFieldLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field.playable_field_lrc.x = lrc_x;
}

void SharedParameters::setPlayableFieldLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field.playable_field_lrc.y = lrc_y;
}

Coord SharedParameters::getLeftGoalULC(void)
{
    QMutexLocker m(&lock);
    return ai_field.left_goal_ulc;
}

Coord SharedParameters::getLeftGoalLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field.left_goal_lrc;
}

void SharedParameters::setLeftGoalULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field.left_goal_ulc.x = ulc_x;
}

void SharedParameters::setLeftGoalULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field.left_goal_ulc.y = ulc_y;
}

void SharedParameters::setLeftGoalLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field.left_goal_lrc.x = lrc_x;
}

void SharedParameters::setLeftGoalLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field.left_goal_lrc.y = lrc_y;
}

Coord SharedParameters::getRightGoalULC(void)
{
    QMutexLocker m(&lock);
    return ai_field.right_goal_ulc;
}

Coord SharedParameters::getRightGoalLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field.right_goal_lrc;
}

void SharedParameters::setRightGoalULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field.right_goal_ulc.x = ulc_x;
}

void SharedParameters::setRightGoalULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field.right_goal_ulc.y = ulc_y;
}

void SharedParameters::setRightGoalLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field.right_goal_lrc.x = lrc_x;
}

void SharedParameters::setRightGoalLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field.right_goal_lrc.y = lrc_y;
}

Coord SharedParameters::getLeftGKAreaULC(void)
{
    QMutexLocker m(&lock);
    return ai_field.left_goalkeeper_area_ulc;
}

Coord SharedParameters::getLeftGKAreaLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field.left_goalkeeper_area_lrc;
}

void SharedParameters::setLeftGKAreaULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field.left_goalkeeper_area_ulc.x = ulc_x;
}

void SharedParameters::setLeftGKAreaULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field.left_goalkeeper_area_ulc.y = ulc_y;
}

void SharedParameters::setLeftGKAreaLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field.left_goalkeeper_area_lrc.x = lrc_x;
}

void SharedParameters::setLeftGKAreaLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field.left_goalkeeper_area_lrc.y = lrc_y;
}

Coord SharedParameters::getRightGKAreaULC(void)
{
    QMutexLocker m(&lock);
    return ai_field.right_goalkeeper_area_ulc;
}

Coord SharedParameters::getRightGKAreaLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field.left_goalkeeper_area_lrc;
}

void SharedParameters::setRightGKAreaULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field.right_goalkeeper_area_ulc.x = ulc_x;
}

void SharedParameters::setRightGKAreaULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field.right_goalkeeper_area_ulc.y = ulc_y;
}

void SharedParameters::setRightGKAreaLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field.right_goalkeeper_area_lrc.x = lrc_x;
}

void SharedParameters::setRightGKAreaLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field.right_goalkeeper_area_lrc.y = lrc_y;
}

bool SharedParameters::addTagColor(Color new_color)
{
    QMutexLocker m(&lock);
    for(int i=0; i < vision_field.ally_tag.size(); i++)
        if(vision_field.ally_tag[i] == new_color)
            return false;
    vision_field.ally_tag.push_back(new_color);
    return true;
}

bool SharedParameters::removeTagColor(Color dead_color)
{
    QMutexLocker m(&lock);
    int i = 0;
    for(std::vector<Color>::iterator it = vision_field.ally_tag.begin();
                                 it != vision_field.ally_tag.end(); it++, i++)
        if(vision_field.ally_tag[i] == dead_color)
        {
            vision_field.ally_tag.erase(it);
            return true;
        }
    return false;
}

bool SharedParameters::isTagColor(Color searched_color)
{
    QMutexLocker m(&lock);
    for(int i=0; i < vision_field.ally_tag.size(); i++)
        if(vision_field.ally_tag[i] == searched_color)
            return true;
    return false;
}

std::string SharedParameters::getAICommand(void)
{
    QMutexLocker m(&lock);
    return ai_field.command;
}

void SharedParameters::setAICommand(std::string str)
{
    QMutexLocker m(&lock);
    ai_field.command = str;
}

void SharedParameters::setForceStop(bool stop)
{
    QMutexLocker m(&lock);
    force_stop = stop;
}

AIField SharedParameters::getAIField(void)
{
    QMutexLocker m(&lock);
    return ai_field;
}

std::vector<std::string> SharedParameters::getCommandList(void)
{
    QMutexLocker m(&lock);
    return ai_field.command_list;
}

Movement SharedParameters::getRobotMovement(int index)
{
    QMutexLocker m(&lock);
    if(index >= 0 && index < N_ROBOTS)
    {
        Movement mov = robot_movement[index];
        mov.stay_still = force_stop;
        return mov;
    }
}
