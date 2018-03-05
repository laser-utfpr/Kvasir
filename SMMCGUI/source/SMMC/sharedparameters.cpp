#include "sharedparameters.hpp"

template<class Archive>
void SharedParameters::serialize(Archive &ar, const unsigned int version)
{
    ar & vision_field & ai_field; // & other stuff to be saved
}

void SharedParameters::loadDefaults(void)
{
    //find good defaults;
}

SharedParameters::SharedParameters()
{
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
        catch(...)
        {
            std::cout << "Exception called while trying to load settings file with boost serialization!" << std::endl;
        }
    }
}

void SharedParameters::readVisionParameters(VisionField v_field)
{
    QMutexLocker m(&lock);
    //read variables
}

void SharedParameters::readAIParameters(AIField a_field)
{
    QMutexLocker m(&lock);
    //read variables
}
