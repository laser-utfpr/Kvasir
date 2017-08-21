#ifndef COLORMASKS_HPP
#define COLORMASKS_HPP

#include "framesholder.hpp"
class FramesHolder;

#include "visionconstants.h"
#include "hsvmask.h"

#include <iostream>
#include <fstream>

class ColorMasks
{
private:
    HSVMask mask[N_COLOR_MASKS];
    friend class FramesHolder;
public:
    ColorMasks();
    void setupMasks(FramesHolder* frames);
    void openMaskFile(const char* filename);
    void saveMaskFile(const char* filename);
    void printMasks(void);
};

#endif // COLORMASKS_HPP
