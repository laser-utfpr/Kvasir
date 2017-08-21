#ifndef VISION_HPP
#define VISION_HPP

#include "framesholder.hpp"
#include "colormasks.hpp"
#include "sightedobjects.hpp"
#include "visionconstants.h"
#include "hsvmask.h"

void visionStart(bool setupMasks, bool printMasks, bool trackObjects, bool printObjects, bool showImage);

#endif // VISION_HPP
