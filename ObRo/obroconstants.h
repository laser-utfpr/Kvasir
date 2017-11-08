#ifndef OBROCONSTANTS_H
#define OBROCONSTANTS_H

enum entityType {DEFAULT=-1,BALL=0,ROBOT_1=1,ROBOT_2=2,ROBOT_3=3,ROBOT_4=4,ROBOT_5=5,ROBOT_6=6,
              ROBOT_7=7,ROBOT_8=8,ROBOT_9=9,ROBOT_10=10,ROBOT_11=11,ROBOT_12=12,ROBOT_13=13,
              ROBOT_14=14,ROBOT_15=15,ROBOT_16=16,ROBOT_17=17,ROBOT_18=18,ENEMY_ROBOT=19,IDENTIFIER=20};

#define OBRO_SHARED_MEMORY_NAME "field"
#define OBRO_SHARED_MEMORY_SIZE 131072
#define FIELD_MEMORY_NAME "sighted_field"

#define BALL_COLOR ORANGE
#define ALLY_CENTER_COLOR BLUE
#define ENEMY_CENTER_COLOR YELLOW

#define MIN_BALL_AREA 100.0
#define MAX_BALL_AREA 100000.0
#define MIN_CENTER_AREA 100.0
#define MAX_CENTER_AREA 100000.0
#define MAX_IDENTIFIER_DISTANCE 100.0

#define N_PLAYERS 3
#define N_COLOR_IDENTIFIERS 1
#define IDENTIFIER_COLOR_1 GREEN
#define IDENTIFIER_COLOR_2 RED

/* N_COLOR_IDENTIFIERS = 1 -> max N_PLAYERS = 3
 * N_COLOR_IDENTIFIERS = 2 -> max N_PLAYERS = 18
 *
 * T = team color
 * 0 = color 0
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

#endif //OBROCONSTANTS_H
