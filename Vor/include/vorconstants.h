#ifndef VORCONSTANTS_H
#define VORCONSTANTS_H

typedef enum {NO_COMMAND = -1, RESUME = 0, ALLY_KICKOFF , ENEMY_KICKOFF, FREEKICK, PENALTY} Command;
#define COMMAND_MEMBER_NAMES {"Resume", "Ally Kick Off", "Enemy Kick Off", "Free Kick", "Penalty"}
#define N_COMMANDS 5

#endif //VORCONSTANTS_H
