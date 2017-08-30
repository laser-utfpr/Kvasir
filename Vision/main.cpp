///TO DO - DEFENSIVE PROGRAMMING

#include "vision.hpp"

#define SETUP_MASKS false
#define PRINT_MASKS false
#define TRACK_OBJECTS true
#define PRINT_OBJECTS false
#define SHOW_IMAGE true
#define PRINT_TIME true
#define FIXED_SAMPLING_PERIOD false

int main()
{
    visionStart(SETUP_MASKS, PRINT_MASKS, TRACK_OBJECTS, PRINT_OBJECTS,
                SHOW_IMAGE, PRINT_TIME, FIXED_SAMPLING_PERIOD);
    return 0;
}

