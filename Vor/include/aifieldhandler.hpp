#ifndef AIFIELDHANDLER_HPP
#define AIFIELDHANDLER_HPP

#include <boost/interprocess/managed_shared_memory.hpp>

#include <string>
#include <vector>
#include <ctime>

#include <smmclib.hpp>

class AIFieldHandler : private AIField
{
private:
    CharAllocator &char_allocator;

public:
    AIFieldHandler(CharAllocator &ca, StringAllocator &sa);
    ~AIFieldHandler();

    void readChanges(boost::interprocess::managed_shared_memory &sm);
    void writeChanges(boost::interprocess::managed_shared_memory &sm);

    useconds_t sampleTime(void);

    std::string commandReceived(void);
    void addCommand(const char* new_command);

    std::string manualCommandReceived(void);
    void addManualCommand(const char* new_command);

    Entity getBall(void);
    Player getAlly(int n);
    Entity getEnemy(int n);

    void setMovement(Movement mov, int n);
    void setStatus(std::string stat, int n);

    Coord getPlayableFieldULC(void);
    Coord getPlayableFieldLRC(void);

    Coord getLeftGoalULC(void);
    Coord getLeftGoalLRC(void);
    Coord getRightGoalULC(void);
    Coord getRightGoalLRC(void);

    Coord getLeftGoalkeeperAreaULC(void);
    Coord getLeftGoalkeeperAreaLRC(void);
    Coord getRightGoalkeeperAreaULC(void);
    Coord getRightGoalkeeperAreaLRC(void);

};

#endif //AIFIELDHANDLER_HPP
