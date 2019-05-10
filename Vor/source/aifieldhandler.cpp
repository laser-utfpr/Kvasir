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
    this->manual_command = sm_vf->manual_command;
    this->manual_player = sm_vf->manual_player;
    this->side = sm_vf->side;
}

void AIFieldHandler::writeChanges(boost::interprocess::managed_shared_memory &sm)
{
    AIField *sm_vf = sm.find<AIField>(AI_FIELD_MEMORY_NAME).first;

    for(int i=0; i<N_ROBOTS; i++)
        sm_vf->robot[i] = this->robot[i];

    sm_vf->command_list = this->command_list;
    sm_vf->manual_command_list = this->manual_command_list;
    sm_vf->side_list = this->side_list;
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

std::string AIFieldHandler::manualCommandReceived(void)
{
    std::string smanual_command = manual_command.c_str();
    return smanual_command;
}

void AIFieldHandler::addManualCommand(const char* new_command)
{
    BoostInterprocessString s(char_allocator);
    s = new_command;
    manual_command_list.push_back(s);
}

int AIFieldHandler::manualPlayer(void)
{
    int imanual_player = std::stoi(manual_player.c_str());
    return imanual_player;
}

std::string AIFieldHandler::getSide(void)
{
    std::string sside = side.c_str();
    return sside;
}

void AIFieldHandler::addSide(const char* new_command)
{
    BoostInterprocessString s(char_allocator);
    s = new_command;
    side_list.push_back(s);
}

Entity AIFieldHandler::getBall(void)
{
    //ball.coord = Coord(200,200);
    return ball;
}

Player AIFieldHandler::getAlly(int n)
{
    /*switch(n)
    {
        case 0:
            robot[n].coord = Coord(400,400); break;
        case 1:
            robot[n].coord = Coord(600,600); break;
        case 2:
            robot[n].coord = Coord(800,800); break;
        case 3:
            robot[n].coord = Coord(800,800); break;
        case 4:
            robot[n].coord = Coord(800,800); break;
    }*/
    if(n < N_ROBOTS && n >= 0)
        return robot[n];
    Player trash;
    return trash;
}

Entity AIFieldHandler::getEnemy(int n)
{
    if(n < N_ROBOTS && n >= 0)
        return enemy_robot[n];
    Entity trash;
    return trash;
}

void AIFieldHandler::setMovement(Movement mov, int n)
{
    if(n < N_ROBOTS && n >= 0)
        robot[n].movement = mov;
}

void AIFieldHandler::setStatus(std::string stat, int n)
{
    if(n < N_ROBOTS && n >= 0)
        robot[n].status = stat;
}

Coord AIFieldHandler::getPlayableFieldULC(void)
{
    return playable_field_ulc;
}

Coord AIFieldHandler::getPlayableFieldLRC(void)
{
    return playable_field_lrc;
}

Coord AIFieldHandler::getLeftGoalULC(void)
{
    return left_goal_ulc;
}

Coord AIFieldHandler::getLeftGoalLRC(void)
{
    return left_goal_lrc;
}

Coord AIFieldHandler::getRightGoalULC(void)
{
    return right_goal_ulc;
}

Coord AIFieldHandler::getRightGoalLRC(void)
{
    return right_goal_lrc;
}

Coord AIFieldHandler::getLeftGoalkeeperAreaULC(void)
{
    return left_goalkeeper_area_ulc;
}

Coord AIFieldHandler::getLeftGoalkeeperAreaLRC(void)
{
    return left_goalkeeper_area_lrc;
}

Coord AIFieldHandler::getRightGoalkeeperAreaULC(void)
{
    return right_goalkeeper_area_ulc;
}

Coord AIFieldHandler::getRightGoalkeeperAreaLRC(void)
{
    return right_goalkeeper_area_lrc;
}
