#include "colormasks.hpp"

ColorMasks::ColorMasks()
{
    int i;
    for(i=0; i<N_COLOR_MASKS; i++)
    {
        mask[i].h_min = 0;
        mask[i].h_max = MAX_MASK_VALUE;
        mask[i].s_min = 0;
        mask[i].s_max = MAX_MASK_VALUE;
        mask[i].v_min = 0;
        mask[i].v_max = MAX_MASK_VALUE;
        mask[i].active_color = false;
    }
}

/**
    void ColorMasks::setupMasks(FramesHolder* frames)

    Sets up the masks from a windowed interface.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void ColorMasks::setupMasks(FramesHolder* frames)
{
    int i;
    for(i=0; i<N_COLOR_MASKS; i++)
    {
        frames->setupHSVMaskFromWindow(&(mask[i]),(objectColor)i);
    }
}

/**
    void ColorMasks::openMaskFile(const char* filename)

    Sets up the masks from a file.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void ColorMasks::openMaskFile(const char* filename)
{
    std::ifstream input_file;
    input_file.open(filename);

    int i,j;
    std::string value;

    for(i=0; i<N_COLOR_MASKS; i++)
    {
        for(j=0; j<N_COLOR_MASK_PARAMETERS; j++)
        {
            while(input_file.get()!='=')
                ;
            std::getline(input_file,value);

            //Some confusing pointer usage to save code lines
            *(&(mask[i].h_min)+j*sizeof(int)) = std::atoi(value.c_str());
        }
    }
}

/**
    void ColorMasks::saveMaskFile(const char* filename)

    Saves a file with the object's masks.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void ColorMasks::saveMaskFile(const char* filename)
{
    std::ofstream output_file;
    output_file.open(filename);

    int i;
    std::string color;

    for(i=0; i<N_COLOR_MASKS; i++)
    {
        switch(i)
        {
            case RED:
                color = "RED"; break;
            case ORANGE:
                color = "ORANGE"; break;
            case YELLOW:
                color = "YELLOW"; break;
            case GREEN:
                color = "GREEN"; break;
            case BLUE:
                color = "BLUE"; break;
            case VIOLET:
                color = "VIOLET"; break;
        }
        output_file << color << "_H_MIN=" << mask[i].h_min << std::endl;
        output_file << color << "_H_MAX=" << mask[i].h_max << std::endl;
        output_file << color << "_S_MIN=" << mask[i].s_min << std::endl;
        output_file << color << "_S_MAX=" << mask[i].s_max << std::endl;
        output_file << color << "_V_MIN=" << mask[i].v_min << std::endl;
        output_file << color << "_V_MAX=" << mask[i].v_max << std::endl;
        output_file << color << "_ACTIVE=" << mask[i].active_color << std::endl;
    }
}
