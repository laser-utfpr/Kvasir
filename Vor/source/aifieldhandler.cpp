#include "aifieldhandler.hpp"

AIFieldHandler::AIFieldHandler(CharAllocator &ca, StringAllocator &sa) :
    AIField(ca, sa), char_allocator(ca)
{

}

AIFieldHandler::~AIFieldHandler()
{

}

void AIFieldHandler::readChanges(boost::interprocess::managed_shared_memory &sm)
{
    AIField *sm_vf = sm.find<AIField>(AI_FIELD_MEMORY_NAME).first;

    this->image_width = sm_vf->image_width;
    this->image_height = sm_vf->image_height;
    this->time_us = sm_vf->time_us;

    this->ball = sm_vf->ball;
    for(int i=0; i<N_ROBOTS; i++)
    {
        this->robot[i] = sm_vf->robot[i];
        this->enemy_robot[i] = sm_vf->enemy_robot[i];
    }

    this->playable_field_ulc = sm_vf->playable_field_ulc;
    this->playable_field_lrc = sm_vf->playable_field_lrc;

    this->left_goal_ulc = sm_vf->left_goal_ulc;
    this->left_goal_lrc = sm_vf->left_goal_lrc;
    this->right_goal_ulc = sm_vf->right_goal_ulc;
    this->right_goal_lrc = sm_vf->right_goal_lrc;

    this->left_goalkeeper_area_ulc = sm_vf->left_goalkeeper_area_ulc;
    this->left_goalkeeper_area_lrc = sm_vf->left_goalkeeper_area_lrc;
    this->right_goalkeeper_area_ulc = sm_vf->right_goalkeeper_area_ulc;
    this->right_goalkeeper_area_lrc = sm_vf->right_goalkeeper_area_lrc;

    this->command = sm_vf->command;
}

void AIFieldHandler::writeChanges(boost::interprocess::managed_shared_memory &sm)
{
    AIField *sm_vf = sm.find<AIField>(AI_FIELD_MEMORY_NAME).first;

    for(int i=0; i<N_ROBOTS; i++)
        sm_vf->robot[i] = this->robot[i];

    sm_vf->command_list = this->command_list;
}

useconds_t AIFieldHandler::sampleTime(void)
{
    return time_us;
}

std::string AIFieldHandler::commandReceived(void)
{
    std::string scommand = command.c_str();
    return scommand;
}

void AIFieldHandler::addCommand(const char* new_command)
{
    BoostInterprocessString s(char_allocator);
    s = new_command;
    command_list.push_back(s);
}
