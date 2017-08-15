#include "framesholder.hpp"
#include "colormasks.hpp"
#include "sightedobjects.hpp"
#include "visionconstants.h"
#include "hsvmask.h"

///TO DO - DESTRUCTORS, DEFENSIVE PROGRAMMATION

int main()
{
    FramesHolder frames;
    ColorMasks masks;
    SightedObjects objects;

    frames.setCameraToDefault();

    //masks.setupMasks(&frames);
    //masks.saveMaskFile(COLOR_MASKS_FILENAME);

    masks.openMaskFile(COLOR_MASKS_FILENAME);
    //masks.printMask();

    while(1)
    {
        frames.updateRawAndHSVImages();
        frames.findObjectsFromMasks(&masks,&objects);
        objects.paintObjects(&frames);
        frames.showRawImage();
        if(cv::waitKey(WAIT_KEY_PRESS_TIME) == DONE_KEY)
            break;
    }
    return 0;
}

