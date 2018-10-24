#include "MemoryClient.h"

MemoryClient::MemoryClient()
{
    shared_memory_object::remove(AI_SHARED_MEMORY_NAME);
    shared_memory = new managed_shared_memory(open_or_create,AI_SHARED_MEMORY_NAME,AI_SHARED_MEMORY_SIZE);
    shared_memory_velocities = shared_memory->construct<velocity>(VELOCITIES_MEMORY_NAME)[N_PLAYERS]();
}

MemoryClient::~MemoryClient()
{
    shared_memory_object::remove(AI_SHARED_MEMORY_NAME);
    delete shared_memory;
}

void MemoryClient::sendVelX(int nameOfRobotIN, float velXIN)
{
    shared_memory_velocities[nameOfRobotIN].x = velXIN;
}

void MemoryClient::sendVelY(int nameOfRobotIN, float velYIN)
{
    shared_memory_velocities[nameOfRobotIN].y = velYIN;
}

void MemoryClient::sendVelAng(int nameOfRobotIN, float velAng)
{
    shared_memory_velocities[nameOfRobotIN].ang = velAng;
}
