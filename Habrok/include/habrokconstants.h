#ifndef HABROKCONSTANTS_H
#define HABROKCONSTANTS_H

#define CALIBRATION_WINDOW_TITLE "Habrok Calibration"

#define IMAGE_CAPTURE_WIDTH 1920.0
#define IMAGE_CAPTURE_HEIGHT 1080.0

typedef enum {RAW = 0, HSV, THRESHOLDED} ImageType;
#define IMAGE_TYPE_MEMBER_NAMES {"Raw Image","HSV Image","Thresholded Image"}
#define N_IMAGE_TYPES 3

#endif //HABROKCONSTANTS_H
