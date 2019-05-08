#ifndef SMMCCONSTANTS_H
#define SMMCCONSTANTS_H

//adding a new color requires adding the member name and incrementing N_COLORS!
//the first color after uncolored needs to be set to 0
typedef enum {UNCOLORED = -1, RED = 0, ORANGE, YELLOW, GREEN, BLUE, VIOLET} Color;
#define COLOR_MEMBER_NAMES {"RED","ORANGE","YELLOW","GREEN","BLUE","VIOLET"}
#define N_COLORS 6

#define N_ROBOTS 1

#define SAVED_SETTINGS_FILENAME "settings.sp"

#define SHARED_MEMORY_BLOCK_NAME "smmc_memory_block"
#define SHARED_MEMORY_SIZE 67108864

#define KEY_SIZE 5
#define EMPTY_KEY "77777"

#define VISION_WRITE_KEY_MEMORY_NAME "vision_write_key"
#define VISION_READ_KEY_MEMORY_NAME "vision_read_key"
#define VISION_SHUTDOWN_KEY_MEMORY_NAME "vision_shutdown_key"
#define AI_WRITE_KEY_MEMORY_NAME "ai_write_key"
#define AI_READ_KEY_MEMORY_NAME "ai_read_key"
#define AI_SHUTDOWN_KEY_MEMORY_NAME "ai_shutdown_key"
#define COMM_WRITE_KEY_MEMORY_NAME "comm_write_key"
#define COMM_READ_KEY_MEMORY_NAME "comm_read_key"
#define COMM_SHUTDOWN_KEY_MEMORY_NAME "comm_shutdown_key"

#define VISION_FIELD_MEMORY_NAME "vision_field"

#define AI_FIELD_MEMORY_NAME "ai_field"

#define ROBOT_MOVEMENT_MEMORY_NAME "robot_movement"

#define MODULE_SHUTDOWN_WAIT_TIME_US 300000

#endif // SMMCCONSTANTS_H
