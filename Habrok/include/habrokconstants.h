#ifndef HABROKCONSTANTS_H
#define HABROKCONSTANTS_H

#define CALIBRATION_WINDOW_TITLE "Habrok Calibration"
#define SAVED_CALIBRATION_FILENAME "calibration.cl"

#define IMAGE_CAPTURE_WIDTH 1920.0
#define IMAGE_CAPTURE_HEIGHT 1080.0

typedef enum {NO_IMAGE = -1, RAW = 0, HSV, THRESHOLDED} ImageType;
#define IMAGE_TYPE_MEMBER_NAMES {"Raw Image","HSV Image","Thresholded Image"}
#define N_IMAGE_TYPES 3

#define FRAME_REFRESH_RATE_MS 10

#define INTERPOLATION_METHOD CV_INTER_LANCZOS4 //CV_INTER_CUBIC

#define TAG_MAX_DISTANCE 400 //to be change to calibrate

/*
 * T = team color
 * 0 = color 0
 * 1 = color 1
 *
 * PLAYER 1 at angle = 0
 *
 * 0       -
 *
 *     T
 *
 * -       -
 *
 * PLAYER 2 at angle = 0
 *
 * 0       0
 *
 *     T
 *
 * -       -
 *
 * PLAYER 3 at angle = 0
 *
 * 0       0
 *
 *     T
 *
 * -       0
 *
 * PLAYER 4 at angle = 0
 *
 * 1       -
 *
 *     T
 *
 * -       -
 *
 * PLAYER 5 at angle = 0
 *
 * 1       1
 *
 *     T
 *
 * -       -
 *
 * PLAYER 6 at angle = 0
 *
 * 1       1
 *
 *     T
 *
 * -       1
 *
 * PLAYER 7 at angle = 0
 *
 * 0       1
 *
 *     T
 *
 * -       -
 *
 * PLAYER 8 at angle = 0
 *
 * 1       0
 *
 *     T
 *
 * -       -
 *
 * PLAYER 9 at angle = 0
 *
 * 0       -
 *
 *     T
 *
 * -       1
 *
 * PLAYER 10 at angle = 0
 *
 * 0       0
 *
 *     T
 *
 * -       1
 *
 * PLAYER 11 at angle = 0
 *
 * 0       1
 *
 *     T
 *
 * -       0
 *
 * PLAYER 12 at angle = 0
 *
 * 1       0
 *
 *     T
 *
 * -       0
 *
 * PLAYER 13 at angle = 0
 *
 * 1       1
 *
 *     T
 *
 * -       0
 *
 * PLAYER 14 at angle = 0
 *
 * 1       0
 *
 *     T
 *
 * -       1
 *
 * PLAYER 15 at angle = 0
 *
 * 0       1
 *
 *     T
 *
 * -       1
 *
 * PLAYER 16 at angle = 0
 *
 * 1       1
 *
 *     T
 *
 * 0       0
 *
 * PLAYER 17 at angle = 0
 *
 * 0       0
 *
 *     T
 *
 * 1       0
 *
 * PLAYER 18 at angle = 0
 *
 * 1       1
 *
 *     T
 *
 * 0       1
*/

#endif //HABROKCONSTANTS_H
