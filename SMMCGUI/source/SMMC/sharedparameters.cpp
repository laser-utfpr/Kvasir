#include "sharedparameters.hpp"

template<class Archive>
void SharedParameters::serialize(Archive &ar, const unsigned int version)
{
    ar & vision_path & ai_path & comm_path;
    ar & vision_field & ai_field; // & other stuff to be saved
}

void SharedParameters::loadDefaults(void)
{
    //find good defaults;
}

SharedParameters::SharedParameters()
{
    vision_path.clear();
    ai_path.clear();
    comm_path.clear();
    loadDefaults();
}

SharedParameters::~SharedParameters()
{
    std::ofstream new_file(SAVED_SETTINGS_FILENAME);
    boost::archive::text_oarchive archive_saver(new_file);
    archive_saver << *this;
}

void SharedParameters::loadSettingsFromFile(void)
{
    std::ifstream opened_file(SAVED_SETTINGS_FILENAME);
    if(!opened_file.fail())
    {
        try
        {
            boost::archive::text_iarchive archive_loader(opened_file);
            archive_loader >> *this;
        }
        catch(...) //REMEMBER TO TRY BOOST FILESYSTEM FOR FIXING FILE PATH
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

    //applying changes to comm movements
    for(int i=0; i<N_ROBOTS; i++)
        robot_movement[i] = ai_field.robot[i].movement;
}

std::string SharedParameters::getVisionPath(void)
{
    return vision_path;
}

std::string SharedParameters::getAIPath(void)
{
    return ai_path;
}

std::string SharedParameters::getCommPath(void)
{
    return comm_path;
}

AIField SharedParameters::getAIField(void)
{
    return ai_field;
}

Movement SharedParameters::getRobotMovement(int index)
{
    if(index >= 0 && index < N_ROBOTS)
        return robot_movement[index];
}
