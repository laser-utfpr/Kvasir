#ifndef VORCONSTANTS_H
#define VORCONSTANTS_H

typedef enum {NO_COMMAND = -1, NORMAL_PLAY = 0, ALLY_KICKOFF, ENEMY_KICKOFF, FREEKICK, PENALTY} Command;
#define COMMAND_MEMBER_NAMES {"Normal Play", "Ally Kick Off", "Enemy Kick Off", "Free Kick", "Penalty"}
#define N_COMMANDS 5

typedef enum {NO_ROLE = -1, GOALKEEPER = 0, DEFENDER, ATTACKER, SUPPORT} Role;
#define ROLE_MEMBER_NAMES {"Goalkeeper", "Defender", "Attacker", "Support"}
#define N_ROLES 4

typedef enum {LEFT, RIGHT} Side;
#define SIDE LEFT

#define ATTACKER_BALL_OFFSET 50
#define ATTACKER_OFFSET_RANGE 100

#define INVERT_Y true

#define ADJUST_ANGLE true

#define FRAMES_TO_SPIN 3

#define SPIN_RANGE 100

#define ANGLE_COMPARE_EPSILON 0.1

#endif //VORCONSTANTS_H
