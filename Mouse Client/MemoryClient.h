//cria uma memoria compartilhada para leitura do server

#include <iostream>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

using namespace boost::interprocess;

#define AI_SHARED_MEMORY_NAME "AI"
#define AI_SHARED_MEMORY_SIZE 65536
#define VELOCITIES_MEMORY_NAME "velocities"
#define N_PLAYERS 5


typedef struct
{
    double x;
    double y;
    double ang;
}velocity;


class MemoryClient{
private:
        managed_shared_memory* shared_memory;
        velocity* shared_memory_velocities;
public:
        MemoryClient();
        ~MemoryClient();

        void sendVelX(int nameOfRobotIN, float velXIN);
        void sendVelY(int nameOfRobotIN, float velYIN);
        void sendVelAng(int nameOfRobotIN, float velAng);
};
