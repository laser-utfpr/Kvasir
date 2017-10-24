#include "strategy.hpp"

Strategy::Strategy()
{
    role[ROBOT_1-ROBOT_1] = GOALKEEPER;
    role[ROBOT_2-ROBOT_1] = DEFENDER;
    role[ROBOT_3-ROBOT_1] = ATTACKER;

    mode = nullptr;
}

/**
    int Strategy::kbhit(void)

    Manual implementaion of conio.h's kbhit.

    @author Lucca Rawlyk
    @version 2017.10.24-1
*/

bool Strategy::kbhit(void)
{
    struct timeval tv;
    fd_set read_fd;

    tv.tv_sec=0;
    tv.tv_usec=0;
    FD_ZERO(&read_fd);
    FD_SET(0,&read_fd);

    if(select(1, &read_fd, NULL, NULL, &tv) == -1)
        return false;

    if(FD_ISSET(0,&read_fd))
        return true;

    return 0;
}

/**
    void Strategy::updateField(void)

    Updates the field using the FieldLoader class.

    @author Lucca Rawlyk
    @version 2017.10.17-1
*/

void Strategy::updateField(void)
{
    FieldLoader *loader = FieldLoader::getInstance();
    current_field = loader->getField();
}

/**
    void Strategy::decideMode(void)

    Decides which mode to set based on the field and keyboard inputs.

    @author Lucca Rawlyk
    @version 2017.10.24-1
*/

void Strategy::decideMode(void)
{
    if(!mode->inProgress(this))
    {
        if(mode!=nullptr)
            delete mode;
        if(kbhit())
        {
            char key = std::cin.get();
            switch(key)
            {
                case 'i':
                mode = new InterruptMode; break;

                case 'f':
                mode = new FreeBallMode; break;

                default:
                break;
            }
        }
        if(shouldWeDefend())
            mode = new DefendMode;
        else
            mode = new AttackMode;
    }
}
