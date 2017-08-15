#ifndef COLORMASKS_HPP
#define COLORMASKS_HPP

#include "framesholder.hpp"
#include "visionconstants.h"
#include "hsvmask.h"

#include <iostream>
#include <fstream>

class ColorMasks
{
    HSVMask mask[N_COLOR_MASKS];
    //bool active_color[N_COLOR_MASKS];
public:
    ColorMasks();
    void setupMasks(FramesHolder* frames);
    void openMaskFile(const char* filename);
    void saveMaskFile(const char* filename);
    void printMask(void);
};

#endif // COLORMASKS_HPP
