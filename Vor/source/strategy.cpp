#include "strategy.hpp"

Strategy::Strategy(AIFieldHandler &afh) : ai_field_handler(afh)
{

}

Strategy::~Strategy()
{

}

void Strategy::makeCommandList(void)
{
    const char *command_name[] = COMMAND_MEMBER_NAMES;
    for(int i=0; i < N_COMMANDS; i++)
        ai_field_handler.addCommand(command_name[i]);
}

void Strategy::calculateVelocities(void)
{
    const char *command_name[] = COMMAND_MEMBER_NAMES;
    std::string command_received = ai_field_handler.commandReceived();
    for(int i=0; i < N_COMMANDS; i++)
        if(command_received == command_name[i])
        {
            command = static_cast<Command>(i);
            break;
        }
}
