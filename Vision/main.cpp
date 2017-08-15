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

    masks.setupMasks(&frames);
    masks.saveMaskFile(COLOR_MASK_FILENAME);

    return 0;
}

