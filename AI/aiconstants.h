#ifndef AICONSTANTS_H
#define AICONSTANTS_H

enum roles {GOALKEEPER = 0, DEFENDER = 1, ATTACKER = 2};

enum modes {ATTACK_MODE = 0, DEFEND_MODE = 1, INTERRUPT_MODE = 2, FREEBALL_MODE = 3};

enum side {LEFT, RIGHT};

#define N_MODES 4

#define GOAL_Y 400
#define GOAL_X 100

#define GOALKEEPER_AREA_Y 600
#define GOALKEEPER_AREA_X 100

#define SIDE LEFT

#endif //AICONSTANTS_H