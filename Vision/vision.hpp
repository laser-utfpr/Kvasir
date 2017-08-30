#ifndef VISION_HPP
#define VISION_HPP

#include "framesholder.hpp"
#include "colormasks.hpp"
#include "sightedobjects.hpp"
#include "visionconstants.h"
#include "hsvmask.h"

void visionStart(bool setupMasks, bool printMasks, bool trackObjects,
                 bool printObjects, bool showImage, bool printTime, bool fixedSamplingPeriod);

#endif // VISION_HPP
