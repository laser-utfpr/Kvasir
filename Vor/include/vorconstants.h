#ifndef VORCONSTANTS_H
#define VORCONSTANTS_H

typedef enum {NO_COMMAND = -1, NORMAL_PLAY = 0, ALLY_KICKOFF, ENEMY_KICKOFF, FREEKICK, PENALTY, MANUAL_CONTROL} Command;
#define COMMAND_MEMBER_NAMES {"Normal Play", "Ally Kick Off", "Enemy Kick Off", "Free Kick", "Penalty", "Manual Control"}
#define N_COMMANDS 6

typedef enum{STOP, FORWARD, TURN_LEFT, TURN_RIGHT, BACK, FL, FR, BL, BR} Manual_Command;
#define MANUAL_COMMAND_NAMES {"Stop", "Forward", "Left", "Right", "Back", "Forward and Left", "Forward and Right", "Back and Left", "Back and Right"}
#define N_MANUAL_COMMANDS 9

typedef enum {NO_ROLE = -1, GOALKEEPER = 0, DEFENDER, ATTACKER, SUPPORT} Role;
#define ROLE_MEMBER_NAMES {"Goalkeeper", "Defender", "Attacker", "Support"}
#define N_ROLES 4

typedef enum {LEFT, RIGHT} Side;
#define SIDE LEFT

#define ATTACKER_BALL_OFFSET 2 //60
#define ATTACKER_OFFSET_RANGE 70//140

#define ADJUST_ANGLE false

#define SPIN_WHEN_CLOSE true

#define FRAMES_TO_SPIN 7

#define SPIN_RANGE 40

#define ANGLE_COMPARE_EPSILON 0.15

#endif //VORCONSTANTS_H
