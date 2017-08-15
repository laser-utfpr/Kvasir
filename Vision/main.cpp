#include "framesholder.hpp"
#include "colormasks.hpp"
#include "sightedobjects.hpp"
#include "visionconstants.h"
#include "hsvmask.h"

int main()
{
    FramesHolder frames;
    ColorMasks masks;

    frames.setCameraToDefault();

    //masks.setupMasks(&frames);
    //masks.saveMaskFile(COLOR_MASKS_FILENAME);

    masks.openMaskFile(COLOR_MASKS_FILENAME);
    masks.printMask();

    return 0;
}

