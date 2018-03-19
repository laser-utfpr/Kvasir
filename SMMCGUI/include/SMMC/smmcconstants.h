#ifndef SMMCCONSTANTS_H
#define SMMCCONSTANTS_H

enum Color {UNCOLORED, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET};

#define N_ROBOTS 3

#define SAVED_SETTINGS_FILENAME "settings.sp"

#define SHARED_MEMORY_BLOCK_NAME "smmc_memory_block"
#define SHARED_MEMORY_SIZE 65536

#define KEY_SIZE 9
#define EMPTY_KEY "777777777"

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

#endif // SMMCCONSTANTS_H
