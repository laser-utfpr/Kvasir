#include "imageprocessingsettings.hpp"

ImageProcessingSettings::ImageProcessingSettings()
{
    for(int i=0; i<N_COLORS; i++)
        mask[i].color = static_cast<Color>(i);

    settings_file = SAVED_CALIBRATION_FILENAME;
}

ImageProcessingSettings::~ImageProcessingSettings()
{
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
}

void ImageProcessingSettings::loadCalibration(void)
{
    QString q_app_path = QCoreApplication::applicationDirPath();
    std::string app_path = q_app_path.toStdString();

    std::string default_file(app_path);
    default_file += '/';
    default_file += SAVED_CALIBRATION_FILENAME;

    settings_file = default_file;

    std::ifstream opened_file(default_file);

    if(!opened_file.fail())
    {
        try
        {
            boost::archive::text_iarchive archive_loader(opened_file);
            archive_loader >> *this;
            std::cout << SAVED_CALIBRATION_FILENAME << " loaded successfully" << std::endl;
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
            s.erase(remove(s.begin(), s.end(), '\"' ),s.end());
            if(s[s.size()-3] == '.' && s[s.size()-2] == 'c' && s[s.size()-1] == 'l')
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
            std::cout << "No .cl file found, loading defaults" << std::endl;
            loadDefaults();
        }
    }
}

void ImageProcessingSettings::loadDefaults(void)
{

}

void ImageProcessingSettings::setCameraID(int id)
{
    camera_id = id;
}
int ImageProcessingSettings::getCameraID(void)
{
    return camera_id;
}

void ImageProcessingSettings::setMinimumObjectArea(int moa)
{
    minimum_object_area = moa;
}

int ImageProcessingSettings::getMinimumObjectArea(void)
{
    return minimum_object_area;
}

void ImageProcessingSettings::setUseMorphingOperations(bool umo)
{
    use_morphing_operations = umo;
}

bool ImageProcessingSettings::getUseMorphingOperations(void)
{
    return use_morphing_operations;
}

void ImageProcessingSettings::setErodeRectSize(int ers)
{
    erode_rect_size = ers;
}

int ImageProcessingSettings::getErodeRectSize(void)
{
    return erode_rect_size;
}

void ImageProcessingSettings::setDilateRectSize(int drs)
{
    dilate_rect_size = drs;
}

int ImageProcessingSettings::getDilateRectSize(void)
{
    return dilate_rect_size;
}
