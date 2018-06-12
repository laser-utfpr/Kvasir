#include "sharedparameters.hpp"

void SharedParameters::loadDefaults(void)
{
    //find good defaults;
}

SharedParameters::SharedParameters() : provider_name("sharedparametersallocatorprovider")
{
    vision_path.clear();
    ai_path.clear();
    comm_path.clear();

    force_stop = false;

    settings_file.clear();

    boost::interprocess::shared_memory_object::remove(provider_name.c_str());
    allocator_provider = new boost::interprocess::managed_shared_memory(boost::interprocess::create_only, provider_name.c_str(), 65536);

    char_allocator = new CharAllocator(allocator_provider->get_segment_manager());;
    string_allocator = new StringAllocator(allocator_provider->get_segment_manager());;
    color_allocator = new ColorAllocator(allocator_provider->get_segment_manager());;
    colored_object_allocator = new ColoredObjectAllocator(allocator_provider->get_segment_manager());

    vision_field = new VisionField(*color_allocator, *colored_object_allocator);
    ai_field = new AIField(*char_allocator, *string_allocator);

    //tests
    /*ai_field->command_list.push_back("the");
    ai_field->command_list.push_back("thing");
    ai_field->command_list.push_back("goes");
    ai_field->command_list.push_back("skraa");
    ai_field->command_list.push_back("papakakaka");
    ai_field->command_list.push_back("anatoomtoomtooroomtoom");
    vision_field->ally_tag.push_back(VIOLET);

    ColoredObject obj;
    obj.coord.x = 100.0;
    obj.coord.y = 100.0;
    obj.color = BLUE;
    vision_field->found_object.push_back(obj);

    ai_field->robot[0].already_found = true;
    ai_field->robot[0].status = "wololo";
    ai_field->robot[0].coord.x = 120.0;
    ai_field->robot[0].coord.y = 120.0;

    ai_field->robot[0].movement.stay_still = false;
    ai_field->robot[0].movement.linear_vel_angle = M_PI_4;
    ai_field->robot[0].movement.linear_vel_scaling = 1.0;*/
}

SharedParameters::~SharedParameters()
{
    QMutexLocker m(&lock);

    std::ofstream new_file(settings_file);

    if(!new_file.fail())
    {
        try
        {
            boost::archive::text_oarchive archive_saver(new_file);
            archive_saver << *this;
            std::cout << settings_file << " saved successfully" << std::endl;
        }
        catch(...)
        {
            std::cout << "Exception called while trying to save settings file with boost serialization!" << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to create settings file!" << std::endl;
    }

    delete vision_field;
    delete ai_field;

    delete char_allocator;
    delete string_allocator;
    delete color_allocator;
    delete colored_object_allocator;
    delete allocator_provider;
}

void SharedParameters::loadSettingsFromFile(void)
{
    QMutexLocker m(&lock);

    //making the settings file in the same directory of the application
    QString q_app_path = QCoreApplication::applicationDirPath();
    std::string app_path = q_app_path.toStdString();

    std::string default_file(app_path);
    default_file += '/';
    default_file += SAVED_SETTINGS_FILENAME;

    settings_file = default_file;

    std::ifstream opened_file(default_file);

    if(!opened_file.fail())
    {
        try
        {
            boost::archive::text_iarchive archive_loader(opened_file);
            archive_loader >> *this;
            std::cout << SAVED_SETTINGS_FILENAME << " loaded successfully" << std::endl;
        }
        catch(...)
        {
            std::cout << "Exception called while trying to read " << SAVED_SETTINGS_FILENAME
            << " with boost serialization!" << std::endl;
            loadDefaults();
        }
    }
    else
    {
        std::string s;
        boost::filesystem::path path(app_path);
        for(auto & entry : boost::make_iterator_range(boost::filesystem::directory_iterator(path), {}))
        {
            std::stringstream ss;
            ss << entry;
            s = ss.str();
            s.erase(remove( s.begin(), s.end(), '\"' ),s.end());
            if(s[s.size()-3] == '.' && s[s.size()-2] == 's' && s[s.size()-1] == 'p')
            {
                settings_file = s;
                opened_file.open(s);
                break;
            }
        }

        /*settings_path += '/';
        settings_path += SAVED_SETTINGS_FILENAME;
        std::ifstream opened_file(settings_path);*/

        if(!opened_file.fail())
        {
            try
            {
                boost::archive::text_iarchive archive_loader(opened_file);
                archive_loader >> *this;
                std::cout << s << " loaded successfully" << std::endl;
            }
            catch(...)
            {
                std::cout << "Exception called while trying to read " << s
                << " with boost serialization!" << std::endl;
                loadDefaults();
            }
        }
        else
        {
            std::cout << "No .sp file found, loading defaults" << std::endl;
            loadDefaults();
        }
    }
}

void SharedParameters::readVisionParameters(VisionField v_field)
{
    QMutexLocker m(&lock);

    //assigning variables that should be updated from vision
    vision_field->image = v_field.image;
    vision_field->image_width = v_field.image_width;
    vision_field->image_height = v_field.image_height;
    vision_field->time_us = v_field.time_us;

    vision_field->found_object = v_field.found_object;

    vision_field->ball = v_field.ball;
    for(int i=0; i<N_ROBOTS; i++)
        vision_field->robot[i] = v_field.robot[i];
    for(int i=0; i<N_ROBOTS; i++)
        vision_field->enemy_robot[i] = v_field.enemy_robot[i];

    //applying changes to ai a_field
    (*ai_field) << (*vision_field);
}

void SharedParameters::readAIParameters(AIField a_field)
{
    QMutexLocker m(&lock);

    //assigning variables that should be updated from AI
    for(int i=0; i<N_ROBOTS; i++)
        ai_field->robot[i].movement = a_field.robot[i].movement;

    ai_field->command_list = a_field.command_list;

    //applying changes to comm movements
    for(int i=0; i<N_ROBOTS; i++)
        robot_movement[i] = ai_field->robot[i].movement;
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
    return vision_field->image;
}

std::vector<ColoredObject> SharedParameters::getColorObjects(void)
{
    QMutexLocker m(&lock);
    std::vector<ColoredObject> objects;
    objects.insert(objects.begin(), vision_field->found_object.begin(), vision_field->found_object.end());
    return objects;
}

Color SharedParameters::setBallColor(Color color)
{
    QMutexLocker m(&lock);
    vision_field->ball_color = color;
}

void SharedParameters::setAllyCenter(Color color)
{
    QMutexLocker m(&lock);
    vision_field->ally_center = color;
}

void SharedParameters::setEnemyCenter(Color color)
{
    QMutexLocker m(&lock);
    vision_field->enemy_center = color;
}

std::vector<Color> SharedParameters::getTags(void)
{
    QMutexLocker m(&lock);
    std::vector<Color> tags;
    tags.insert(tags.begin(), vision_field->ally_tag.begin(), vision_field->ally_tag.end());
    return tags;
}

Color SharedParameters::getBallColor(void)
{
    QMutexLocker m(&lock);
    return vision_field->ball_color;
}

Color SharedParameters::getAllyCenter(void)
{
    QMutexLocker m(&lock);
    return vision_field->ally_center;
}

Color SharedParameters::getEnemyCenter(void)
{
    QMutexLocker m(&lock);
    return vision_field->enemy_center;
}

Coord SharedParameters::getSearchedRegionULC(void)
{
    QMutexLocker m(&lock);
    return vision_field->searched_region_ulc;
}

Coord SharedParameters::getSearchedRegionLRC(void)
{
    QMutexLocker m(&lock);
    return vision_field->searched_region_lrc;
}

void SharedParameters::setSearchedRegionULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    vision_field->searched_region_ulc.x = ulc_x;
}

void SharedParameters::setSearchedRegionULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    vision_field->searched_region_ulc.y = ulc_y;
}

void SharedParameters::setSearchedRegionLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    vision_field->searched_region_lrc.x = lrc_x;
}

void SharedParameters::setSearchedRegionLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    vision_field->searched_region_lrc.y = lrc_y;
}

Coord SharedParameters::getPlayableFieldULC(void)
{
    QMutexLocker m(&lock);
    return ai_field->playable_field_ulc;
}

Coord SharedParameters::getPlayableFieldLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field->playable_field_lrc;
}

void SharedParameters::setPlayableFieldULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field->playable_field_ulc.x = ulc_x;
}

void SharedParameters::setPlayableFieldULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field->playable_field_ulc.y = ulc_y;
}

void SharedParameters::setPlayableFieldLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field->playable_field_lrc.x = lrc_x;
}

void SharedParameters::setPlayableFieldLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field->playable_field_lrc.y = lrc_y;
}

Coord SharedParameters::getLeftGoalULC(void)
{
    QMutexLocker m(&lock);
    return ai_field->left_goal_ulc;
}

Coord SharedParameters::getLeftGoalLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field->left_goal_lrc;
}

void SharedParameters::setLeftGoalULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field->left_goal_ulc.x = ulc_x;
}

void SharedParameters::setLeftGoalULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field->left_goal_ulc.y = ulc_y;
}

void SharedParameters::setLeftGoalLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field->left_goal_lrc.x = lrc_x;
}

void SharedParameters::setLeftGoalLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field->left_goal_lrc.y = lrc_y;
}

Coord SharedParameters::getRightGoalULC(void)
{
    QMutexLocker m(&lock);
    return ai_field->right_goal_ulc;
}

Coord SharedParameters::getRightGoalLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field->right_goal_lrc;
}

void SharedParameters::setRightGoalULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field->right_goal_ulc.x = ulc_x;
}

void SharedParameters::setRightGoalULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field->right_goal_ulc.y = ulc_y;
}

void SharedParameters::setRightGoalLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field->right_goal_lrc.x = lrc_x;
}

void SharedParameters::setRightGoalLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field->right_goal_lrc.y = lrc_y;
}

Coord SharedParameters::getLeftGKAreaULC(void)
{
    QMutexLocker m(&lock);
    return ai_field->left_goalkeeper_area_ulc;
}

Coord SharedParameters::getLeftGKAreaLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field->left_goalkeeper_area_lrc;
}

void SharedParameters::setLeftGKAreaULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field->left_goalkeeper_area_ulc.x = ulc_x;
}

void SharedParameters::setLeftGKAreaULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field->left_goalkeeper_area_ulc.y = ulc_y;
}

void SharedParameters::setLeftGKAreaLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field->left_goalkeeper_area_lrc.x = lrc_x;
}

void SharedParameters::setLeftGKAreaLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field->left_goalkeeper_area_lrc.y = lrc_y;
}

Coord SharedParameters::getRightGKAreaULC(void)
{
    QMutexLocker m(&lock);
    return ai_field->right_goalkeeper_area_ulc;
}

Coord SharedParameters::getRightGKAreaLRC(void)
{
    QMutexLocker m(&lock);
    return ai_field->right_goalkeeper_area_lrc;
}

void SharedParameters::setRightGKAreaULCx(double ulc_x)
{
    QMutexLocker m(&lock);
    ai_field->right_goalkeeper_area_ulc.x = ulc_x;
}

void SharedParameters::setRightGKAreaULCy(double ulc_y)
{
    QMutexLocker m(&lock);
    ai_field->right_goalkeeper_area_ulc.y = ulc_y;
}

void SharedParameters::setRightGKAreaLRCx(double lrc_x)
{
    QMutexLocker m(&lock);
    ai_field->right_goalkeeper_area_lrc.x = lrc_x;
}

void SharedParameters::setRightGKAreaLRCy(double lrc_y)
{
    QMutexLocker m(&lock);
    ai_field->right_goalkeeper_area_lrc.y = lrc_y;
}

bool SharedParameters::addTagColor(Color new_color)
{
    //if the tested color isn't currently a tag adds it and returns true
    //if it is returns false
    QMutexLocker m(&lock);
    for(int i=0; i < vision_field->ally_tag.size(); i++)
        if(vision_field->ally_tag[i] == new_color)
            return false;
    vision_field->ally_tag.push_back(new_color);
    return true;
}

bool SharedParameters::removeTagColor(Color dead_color)
{
    //if the tested color is currently a tag removes it and returns true
    //or else if it isn't returns false
    QMutexLocker m(&lock);
    int i = 0;
    for(auto it = vision_field->ally_tag.begin(); it != vision_field->ally_tag.end(); it++, i++)
        if(vision_field->ally_tag[i] == dead_color)
        {
            vision_field->ally_tag.erase(it);
            return true;
        }
    return false;
}

bool SharedParameters::isTagColor(Color searched_color)
{
    QMutexLocker m(&lock);
    for(int i=0; i < vision_field->ally_tag.size(); i++)
        if(vision_field->ally_tag[i] == searched_color)
            return true;
    return false;
}

std::string SharedParameters::getAICommand(void)
{
    QMutexLocker m(&lock);
    std::string str = ai_field->command.c_str();
    return str;
}

void SharedParameters::setAICommand(std::string str)
{
    QMutexLocker m(&lock);
    ai_field->command = str.c_str();
}

void SharedParameters::setForceStop(bool stop)
{
    QMutexLocker m(&lock);
    force_stop = stop;
}

AIField SharedParameters::getAIField(void)
{
    QMutexLocker m(&lock);
    return (*ai_field);
}

std::vector<std::string> SharedParameters::getCommandList(void)
{
    QMutexLocker m(&lock);
    std::vector<std::string> v;
    for(int i=0; i<ai_field->command_list.size(); i++)
        v.push_back(ai_field->command_list[i].c_str());
    return v;
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

Entity SharedParameters::getBall(void)
{
    QMutexLocker m(&lock);
    return vision_field->ball;
}

Player SharedParameters::getAllyRobot(int index)
{
    if(index >= 0 && index < N_ROBOTS)
        return ai_field->robot[index];
}

Entity SharedParameters::getEnemyRobot(int index)
{
    if(index >= 0 && index < N_ROBOTS)
        return vision_field->enemy_robot[index];
}
