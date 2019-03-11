#include "strategy.hpp"

Coord Strategy::compared_object_coord;

Strategy::Strategy(AIFieldHandler &afh) : ai_field_handler(afh)
{
    for(int i=0; i<N_ROBOTS; i++)
    {
        role[i] = NO_ROLE;
        frames_close[i] = 0;
    }
}

Strategy::~Strategy()
{

}

bool Strategy::comparePlayerDistance(Player p1, Player p2)
{
    return (Strategy::compared_object_coord.distance(p1.coord) <
            Strategy::compared_object_coord.distance(p2.coord));
}

void Strategy::makeCommandList(void)
{
    const char *command_name[] = COMMAND_MEMBER_NAMES;
    for(int i=0; i < N_COMMANDS; i++)
        ai_field_handler.addCommand(command_name[i]);
}

void Strategy::makeManualCommandList(void)
{
    const char *manual_command_name[] = MANUAL_COMMAND_NAMES;
    for(int i=0; i < N_MANUAL_COMMANDS; i++)
        ai_field_handler.addManualCommand(manual_command_name[i]);
}

void Strategy::calculateMovementsFromDestinations(void)
{
    for(int i=0; i<N_ROBOTS; i++)
    {
        if(command != MANUAL_CONTROL)
        {
            if(robot[i].already_found)
                robot[i].movement.stay_still = false;
            else
                robot[i].movement.stay_still = true;
        }
        if(std::isnan(robot[i].angle))
        {
            robot[i].angle = 0;
        }
        robot[i].movement.linear_vel_angle = robot[i].coord.angle(robot[i].destination) - robot[i].angle;
        robot[i].movement.linear_vel_angle = -robot[i].movement.linear_vel_angle;
        robot[i].movement.linear_vel_scaling = 1;
        ai_field_handler.setMovement(robot[i].movement, i);
    }
}

void Strategy::calculateMovements(void)
{
    const char *command_name[] = COMMAND_MEMBER_NAMES;
    std::string command_received = ai_field_handler.commandReceived();
    for(int i=0; i < N_COMMANDS; i++)
        if(command_received == command_name[i])
        {
            command = static_cast<Command>(i);
            break;
        }

    ball = ai_field_handler.getBall();
    for(int i=0; i<N_ROBOTS; i++)
    {
        robot[i] = ai_field_handler.getAlly(i);
        enemy_robot[i] = ai_field_handler.getEnemy(i);
    }

    pf_ulc = ai_field_handler.getPlayableFieldULC();
    pf_lrc = ai_field_handler.getPlayableFieldLRC();
    lg_ulc = ai_field_handler.getLeftGoalULC();
    lg_lrc = ai_field_handler.getLeftGoalLRC();
    rg_ulc = ai_field_handler.getRightGoalULC();
    rg_lrc = ai_field_handler.getRightGoalLRC();
    lga_ulc = ai_field_handler.getLeftGoalkeeperAreaULC();
    lga_lrc = ai_field_handler.getLeftGoalkeeperAreaLRC();
    rga_ulc = ai_field_handler.getRightGoalkeeperAreaULC();
    rga_lrc = ai_field_handler.getRightGoalkeeperAreaLRC();

    switch(command)
    {
        case NO_COMMAND:
        normalPlay(); break;

        case NORMAL_PLAY:
        normalPlay(); break;

        case ALLY_KICKOFF:
        allyKickOff(); break;

        case ENEMY_KICKOFF:
        enemyKickOff(); break;

        case FREEKICK:
        freeKick(); break;

        case PENALTY:
        penalty(); break;

        case MANUAL_CONTROL:
        manualControl(); break;
    }

    calculateMovementsFromDestinations();
}

void Strategy::assignRoles(void)
{
    //assign an attacker
    if(N_ROBOTS == 1)
        role[0] = ATTACKER;
    else
    {
        //assign an attacker
        std::vector<Player> ball_sorted;
        for(int i=0; i<N_ROBOTS; i++)
            ball_sorted.push_back(robot[i]);
        compared_object_coord = ball.coord;
        std::sort(ball_sorted.begin(), ball_sorted.end(), &Strategy::comparePlayerDistance);

        for(int i=0; i<N_ROBOTS; i++)
            if(robot[i].coord == ball_sorted[0].coord)
                role[i] = ATTACKER;

        //assign a goalkeeper
        if(N_ROBOTS == 2)
        {
            if(role[0] == ATTACKER)
                role[1] == GOALKEEPER;
            else
                role[0] == GOALKEEPER;
        }
        else
        {
            //assign a goalkeeper
            std::vector<Player> goal_sorted;
            for(int i=0; i<N_ROBOTS; i++)
                goal_sorted.push_back(robot[i]);
            if(SIDE == LEFT)
            {
                compared_object_coord.x = (lg_lrc.x - lg_ulc.x)/2 + lg_ulc.x;
                compared_object_coord.y = (lg_lrc.y - lg_ulc.y)/2 + lg_ulc.x;
            }
            else
            {
                compared_object_coord.x = (rg_lrc.x - rg_ulc.x)/2 + rg_ulc.x;
                compared_object_coord.y = (rg_lrc.y - rg_ulc.y)/2 + rg_ulc.x;
            }
            std::sort(goal_sorted.begin(), goal_sorted.end(), &Strategy::comparePlayerDistance);

            for(int i=0; i<N_ROBOTS; i++)
                if(robot[i].coord == goal_sorted[0].coord)
                {
                    if(role[i] == NO_ROLE)
                        role[i] = GOALKEEPER;
                    else
                        for(int j=0; j<N_ROBOTS; j++)
                            if(robot[j].coord == goal_sorted[1].coord)
                                role[j] = GOALKEEPER;
                }
            if(N_ROBOTS == 3)
            {
                //assign a defender or support
                bool enemies_defending = true;
                for(int i=0; i<N_ROBOTS; i++)
                {
                    if(SIDE == LEFT)
                    {
                        if(enemy_robot[i].coord.isInRect(pf_ulc, Coord((pf_lrc.x - pf_ulc.x)/2 + pf_ulc.x, pf_lrc.y)))
                        {
                            enemies_defending = false;
                            break;
                        }
                    }
                    else
                    {
                        if(enemy_robot[i].coord.isInRect(Coord((pf_lrc.x - pf_ulc.x)/2 + pf_ulc.x, pf_ulc.y), pf_lrc))
                        {
                            enemies_defending = false;
                            break;
                        }
                    }
                }
                for(int i=0; i<N_ROBOTS; i++)
                    if(role[i] == NO_ROLE)
                    {
                        if(enemies_defending)
                            role[i] = SUPPORT;
                        else
                            role[i] = DEFENDER;
                    }
            }
            else
            {
                //assign a defender
                for(int i=0; i<N_ROBOTS; i++)
                    if(robot[i].coord == ball_sorted[1].coord)
                    {
                        if(role[i] == NO_ROLE)
                            role[i] = DEFENDER;
                        else
                            for(int j=0; j<N_ROBOTS; j++)
                                if(role[j] == NO_ROLE || role[j] == DEFENDER)
                                {
                                    role[j] = DEFENDER;
                                    break;
                                }
                    }

                //assign supports
                for(int i=0; i<N_ROBOTS; i++)
                    if(role[i] == NO_ROLE)
                        role[i] = SUPPORT;
            }
        }
    }

    const char *role_name[] = ROLE_MEMBER_NAMES;
    for(int i=0; i<N_ROBOTS; i++)
    {
        if(static_cast<int>(role[i]) >= 0)
        {
            ai_field_handler.setStatus(role_name[static_cast<int>(role[i])], i);
        }
    }
}

void Strategy::normalPlay(void)
{
    for(int i=0; i<N_ROBOTS; i++)
        role[i] = NO_ROLE;
    assignRoles();
    for(int i=0; i<N_ROBOTS; i++)
    {
        //moveAttacker(i);
        switch(role[i])
        {
            case NO_ROLE:
            moveAttacker(i); break;
            case GOALKEEPER:
            moveGoalkeeper(i); break;
            case DEFENDER:
            moveDefender(i); break;
            case ATTACKER:
            moveAttacker(i); break;
            case SUPPORT:
            moveDefender(i); break;
        }
    }
}

void Strategy::moveGoalkeeper(int n)
{
    if(SIDE == LEFT)
    {
        robot[n].destination.x = (lga_lrc.x-lga_ulc.x)/2 + lga_ulc.x;
        if(ball.coord.isInRect(pf_ulc, Coord((pf_lrc.x - pf_ulc.x)/2 + pf_ulc.x, pf_lrc.y)))
            robot[n].destination.y = ball.coord.y;
        else
            robot[n].destination.y = (lga_lrc.y - lga_ulc.y)/2 + lga_ulc.y;
    }
    else
    {
        robot[n].destination.x = (rga_lrc.x-rga_ulc.x)/2 + rga_ulc.x;
        if(ball.coord.isInRect(Coord((pf_lrc.x - pf_ulc.x)/2 + pf_ulc.x, pf_ulc.y), pf_lrc))
            robot[n].destination.y = ball.coord.y;
        else
            robot[n].destination.y = (rga_lrc.y - rga_ulc.y)/2 + rga_ulc.y;
    }

    robot[n].movement.angular_vel_scaling = 0;
}

void Strategy::moveDefender(int n)
{
    if(SIDE == LEFT)
    {
        Coord goal_center(lg_lrc.x, (lg_lrc.y-lg_ulc.y)/2 + lg_ulc.y);
        robot[n].destination.x = goal_center.x + (ball.coord.x - goal_center.x)/2;
        robot[n].destination.y = goal_center.y + (ball.coord.y - goal_center.y)/2;
    }
    else
    {
        Coord goal_center(rg_ulc.x, (rg_lrc.y-rg_ulc.y)/2 + rg_ulc.y);
        robot[n].destination.x = goal_center.x + (ball.coord.x - goal_center.x)/2;
        robot[n].destination.y = goal_center.y + (ball.coord.y - goal_center.y)/2;
    }

    robot[n].movement.angular_vel_scaling = 0;
}

void Strategy::moveAttacker(int n)
{
    if(SPIN_WHEN_CLOSE && robot[n].coord.distance(ball.coord) < SPIN_RANGE)
        frames_close[n]++;
    else
        frames_close[n] = 0;

    if(frames_close[n] >= FRAMES_TO_SPIN && ((SIDE == LEFT && robot[n].coord.x < ball.coord.x) || (SIDE == RIGHT && robot[n].coord.x > ball.coord.x)))
    {
        robot[n].movement.angular_vel_scaling = 1;
    }
    else
    {
        auto robot_ball_angle = robot[n].coord.angle(ball.coord);
        if(ADJUST_ANGLE &&
           !angleCompare(robot[n].angle, robot_ball_angle, ANGLE_COMPARE_EPSILON) &&
           !angleCompare(robot[n].angle, robot_ball_angle + M_PI_2, ANGLE_COMPARE_EPSILON) &&
           !angleCompare(robot[n].angle, robot_ball_angle + M_PI, ANGLE_COMPARE_EPSILON) &&
           !angleCompare(robot[n].angle, robot_ball_angle + 3*M_PI_2, ANGLE_COMPARE_EPSILON))
        {
            robot[n].movement.angular_vel_scaling = 1;
        }
        else
        {
            robot[n].movement.angular_vel_scaling = 0;
        }

        //std::cout << robot[n].coord.distance(ball.coord) << std::endl;
        if(robot[n].coord.distance(ball.coord) < ATTACKER_OFFSET_RANGE)
        {
            robot[n].destination = ball.coord;
        }
        else if(SIDE == LEFT)
        {
            robot[n].destination.x = ball.coord.x - ATTACKER_BALL_OFFSET;
            robot[n].destination.y = ball.coord.y;
        }
        else
        {
            robot[n].destination.x = ball.coord.x + ATTACKER_BALL_OFFSET;
            robot[n].destination.y = ball.coord.y;
        }
    }
}

void Strategy::moveSupport(int n)
{

}

void Strategy::allyKickOff(void)
{

}

void Strategy::enemyKickOff(void)
{

}

void Strategy::freeKick(void)
{

}

void Strategy::penalty(void)
{

}

void Strategy::manualControl(void)
{
    Manual_Command manual_command;
    const char *manual_command_name[] = MANUAL_COMMAND_NAMES;
    std::string manual_command_received = ai_field_handler.manualCommandReceived();
    bool there_is_command = false;
    for(int i=0; i < N_MANUAL_COMMANDS; i++)
    {
        if(manual_command_received == manual_command_name[i])
        {
            manual_command = static_cast<Manual_Command>(i);
            there_is_command = true;
            break;
        }
    }
    if(there_is_command)
    {
        int n = ai_field_handler.manualPlayer();
        robot[n].movement.stay_still = false;
        switch (manual_command)
        {
            case STOP:
                robot[n].movement.stay_still = true; break;
            case FORWARD:
                robot[n].destination.x = 0;
                robot[n].destination.y = 1; break;
            case TURN_LEFT:
                robot[n].destination.x = -1;
                robot[n].destination.y = 0; break;
            case TURN_RIGHT:
                robot[n].destination.x = 1;
                robot[n].destination.y = 0; break;
            case BACK:
                robot[n].destination.x = 0;
                robot[n].destination.y = -1; break;
            case FL:
                robot[n].destination.x = -1;
                robot[n].destination.y = 1; break;
            case FR:
                robot[n].destination.x = 1;
                robot[n].destination.y = 1; break;
            case BL:
                robot[n].destination.x = -1;
                robot[n].destination.y = -1; break;
            case BR:
                robot[n].destination.x = 1;
                robot[n].destination.y = -1; break;
        }
        robot[n].movement.angular_vel_scaling = 0;
    }
}

double Strategy::normalizeAngle(double angle)
{
    if(angle > 2.0*M_PI)
        while(angle > 2.0*M_PI)
            angle -= 2.0*M_PI;
    else if(angle < 0.0)
        while(angle < 0.0)
            angle += 2.0*M_PI;
    return angle;
}

bool Strategy::angleCompare(double angle1, double angle2, double epsilon)
{
    angle1 = normalizeAngle(angle1);
    angle2 = normalizeAngle(angle2);
    double diff = angle1 - angle2;
    return (diff < epsilon) || (-diff > -epsilon);
}
