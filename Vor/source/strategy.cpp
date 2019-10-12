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

void Strategy::makeSideList(void)
{
    const char *side_name[] = SIDE_NAMES;
    for(int i=0; i < 2; i++)
        ai_field_handler.addSide(side_name[i]);
}

void Strategy::calculateMovementsFromDestinations(void)
{
    for(int i=0; i<N_ROBOTS; i++)
    {
        if(std::isnan(robot[i].angle))
        {
            robot[i].angle = 0;
        }
        if(command == MANUAL_CONTROL && i == manual_controlled_robot && i != previous_manual_controlled_robot)
        {
            //moveStraight(M_PI_2);//passar o angulo do momento que foi pedido o comando
            previous_robot_angle = 0;//robot[i].angle;
            previous_manual_controlled_robot = i;
            switch (previous_command)
            {
                case FORWARD:
                    robot[i].previous_destination = calculatePreviousDestination(i);break;
                case TURN_LEFT:
                    robot[i].previous_destination = calculatePreviousDestination(i, 3*M_PI_2);break;
                case TURN_RIGHT:
                    robot[i].previous_destination = calculatePreviousDestination(i, M_PI_2);break;
                case BACK:
                    robot[i].previous_destination = calculatePreviousDestination(i, M_PI);break;
                case FL:
                    robot[i].previous_destination = calculatePreviousDestination(i, 7*M_PI_2/2);break;
                case FR:
                    robot[i].previous_destination = calculatePreviousDestination(i, M_PI_2/2);break;
                case BL:
                    robot[i].previous_destination = calculatePreviousDestination(i, 5*M_PI_2/2);break;
                case BR:
                    robot[i].previous_destination = calculatePreviousDestination(i, 3*M_PI_2/2);break;
            }

        }
        robot[i].movement.linear_vel_angle = robot[i].coord.angle(robot[i].destination) - robot[i].angle;
        if(command == MANUAL_CONTROL && i == manual_controlled_robot)
        {
            robot[i].movement.linear_vel_angle = atan2(robot[i].destination.y, robot[i].destination.x);
        }
        robot[i].movement.linear_vel_angle = -robot[i].movement.linear_vel_angle;
        //std::cout <<robot[i].coord.x <<" "<<robot[i].coord.y<<" "<<robot[i].movement.linear_vel_angle<<std::endl;
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
        if(!robot[i].already_found)
            robot[i].movement.stay_still = true;
        else
            robot[i].movement.stay_still = false;
    }

    const char *side_name[] = SIDE_NAMES;
    std::string side_received = ai_field_handler.getSide();
    //std::cout << "recebi o lado "<<side_received<<std::endl;
    for(int i=0; i < 2; i++)
    {
        if(side_received == side_name[i])
        {
    //        std::cout << "ta feio"<<std::endl;
            side = static_cast<Side>(i);
            break;
        }
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
        role[0] = GOALKEEPER;
    else
    {
        //assign an attacker
        std::vector<Player> ball_sorted;
        for(int i=0; i<N_ROBOTS; i++)
            ball_sorted.push_back(robot[i]);
        compared_object_coord = ball.coord;//ordenar em relacao a bola
        std::sort(ball_sorted.begin(), ball_sorted.end(), &Strategy::comparePlayerDistance);

        for(int i=0; i<N_ROBOTS; i++)
        {
            if(robot[i].coord == ball_sorted[0].coord)
            {
                role[i] = ATTACKER;
                break;
            }
        }

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
            {
                if(role[i] == NO_ROLE)
                {
                    goal_sorted.push_back(robot[i]);
                }
            }
            if(side == LEFT)//ordenar em relacao a area do gol a ser defendida
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
            {
                if(robot[i].coord == goal_sorted[0].coord)
                {
                    role[i] = GOALKEEPER;
                    break;
                }
            }

            bool enemies_defending = true;
            for(int i=0; i<N_ROBOTS; i++)
            {
                if(side == LEFT)
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
            if(enemies_defending)
            {
                //assign  supports
                for(int i=0; i<N_ROBOTS; i++)
                {
                    if(role[i] == NO_ROLE)
                    {
                        role[i] = SUPPORT;
                    }
                }
            }
            else
            {
                //assign defenders
                for(int i=0; i<N_ROBOTS; i++)
                {
                    if(role[i] == NO_ROLE)
                    {
                        role[i] = DEFENDER;
                    }
                }
            }
        }
    }

    const char *role_name[] = ROLE_MEMBER_NAMES;
    for(int i=0; i<N_ROBOTS; i++)
    {
        if(static_cast<int>(role[i]) >= 0)
        {
            ai_field_handler.setStatus(role_name[static_cast<int>(role[i])], i);
            //std::cout <<"robo "<<i<<": "<<role_name[static_cast<int>(role[i])]<<std::endl;
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
    if(side == LEFT)
    {
        if(ball.coord.x < ((pf_lrc.x - pf_ulc.x)/2+pf_ulc.x))
        {
            /*robot[n].destination.y = ball.coord.y;
            robot[n].destination.x = ball.coord.x;*/

            robot[n].destination = calculateMovementsToBall(n);

            //if (ball.coord.x <= lg_lrc.x)
            //    robot[n].destination.x = ball.coord.x;
            if(robot[n].coord.y < (lga_ulc.y + GOALKEEPER_BALL_OFFSET))
                robot[n].destination.y = lga_ulc.y + GOALKEEPER_BALL_OFFSET;
            else if(robot[n].coord.y > (lga_lrc.y - GOALKEEPER_BALL_OFFSET))
                robot[n].destination.y = lga_lrc.y - GOALKEEPER_BALL_OFFSET;
            if(robot[n].coord.x > (lga_lrc.x - GOALKEEPER_BALL_OFFSET))
                robot[n].destination.x = lga_lrc.x - GOALKEEPER_BALL_OFFSET;

            /*robot[n].destination.y = ball.coord.y;
            if (robot[n].destination.y < lg_ulc.y + GOALKEEPER_AREA_OFFSET + 15)
                robot[n].destination.y = lg_ulc.y + GOALKEEPER_AREA_OFFSET + 15;
            else if (robot[n].destination.y > lg_lrc.y - GOALKEEPER_AREA_OFFSET - 15)
                robot[n].destination.y = lg_lrc.y - GOALKEEPER_AREA_OFFSET - 15;
            robot[n].destination.x = lga_ulc.x - GOALKEEPER_AREA_OFFSET;*/
        }
        else if(robot[n].coord.y < ((lg_lrc.y-lg_ulc.y)/2 + lg_ulc.y - GOALKEEPER_OFFSET_RANGE) || robot[n].coord.y > ((lg_lrc.y-lg_ulc.y)/2 + lg_ulc.y + GOALKEEPER_OFFSET_RANGE) || robot[n].coord.x > lga_lrc.x)
        {
            robot[n].destination.x = (lga_lrc.x - lga_ulc.x)/2 + lga_ulc.x;
            robot[n].destination.y = (lg_lrc.y-lg_ulc.y)/2 + lg_ulc.y;
        }
        else
            robot[n].movement.stay_still = true;
    }
    else
    {
        if(ball.coord.x > ((pf_lrc.x - pf_ulc.x)/2 + pf_ulc.x))
        {
            robot[n].destination = calculateMovementsToBall(n);

            if(robot[n].coord.y < (lga_ulc.y + GOALKEEPER_BALL_OFFSET))
                robot[n].destination.y = lga_ulc.y + GOALKEEPER_BALL_OFFSET;
            else if(robot[n].coord.y > (lga_lrc.y - GOALKEEPER_BALL_OFFSET))
                robot[n].destination.y = lga_lrc.y - GOALKEEPER_BALL_OFFSET;
            if(robot[n].coord.x < (rga_ulc.x + GOALKEEPER_BALL_OFFSET))
                robot[n].destination.x = rga_ulc.x + GOALKEEPER_BALL_OFFSET;
        }
        else if(robot[n].coord.y < ((rg_lrc.y - rg_ulc.y)/2 + rg_ulc.y - GOALKEEPER_OFFSET_RANGE) || robot[n].coord.y > ((rg_lrc.y-rg_ulc.y)/2 + rg_ulc.y + GOALKEEPER_OFFSET_RANGE) || robot[n].coord.x < lga_ulc.x)
        {
            robot[n].destination.x = (rga_lrc.x - rga_ulc.x)/2 + rga_ulc.x;
            robot[n].destination.y = (rg_lrc.y - rg_ulc.y)/2 + rg_ulc.y;
        }
        else
            robot[n].movement.stay_still = true;
    }

    robot[n].movement.angular_vel_scaling = 0;
}

void Strategy::moveDefender(int n)
{
    if(side == LEFT)
    {
        Coord goal_center(lg_lrc.x, (lg_lrc.y-lg_ulc.y)/2 + lg_ulc.y);
        robot[n].destination.x = goal_center.x + (ball.coord.x - goal_center.x)/2;
        robot[n].destination.y = goal_center.y + (ball.coord.y - goal_center.y)/2;
        if(robot[n].destination.x < lga_lrc.x)//colocar deltas depois ou meio termo
        {
            if(robot[n].destination.y > lga_ulc.y && robot[n].destination.y < ((lga_lrc.y - lga_ulc.y)/2 + lga_ulc.y))
            {
                robot[n].destination.y = lga_ulc.y;
                //robot[n].destination.x = lga_lrc.x;
            }
            else if(robot[n].destination.y < lga_lrc.y && robot[n].destination.y > ((lga_lrc.y - lga_ulc.y)/2 + lga_ulc.y))
            {
                robot[n].destination.y = lga_lrc.y;
                //robot[n].destination.x = lga_lrc.x;
            }
        }
    }
    else
    {
        Coord goal_center(rg_ulc.x, (rg_lrc.y-rg_ulc.y)/2 + rg_ulc.y);
        robot[n].destination.x = goal_center.x + (ball.coord.x - goal_center.x)/2;
        robot[n].destination.y = goal_center.y + (ball.coord.y - goal_center.y)/2;
        if(robot[n].destination.x < lga_lrc.x)//colocar deltas depois ou meio termo
        {
            if(robot[n].destination.y > rga_ulc.y && robot[n].destination.y < ((rga_lrc.y - rga_ulc.y)/2 + rga_ulc.y))
            {
                robot[n].destination.y = rga_ulc.y;
                //robot[n].destination.x = lga_lrc.x;
            }
            else if(robot[n].destination.y < rga_lrc.y && robot[n].destination.y > ((rga_lrc.y - rga_ulc.y)/2 + rga_ulc.y))
            {
                robot[n].destination.y = rga_lrc.y;
                //robot[n].destination.x = lga_lrc.x;
            }
        }
    }

    robot[n].movement.angular_vel_scaling = 0;
}

void Strategy::moveAttacker(int n)
{
    if(SPIN_WHEN_CLOSE && robot[n].coord.distance(ball.coord) < ATTACKER_OFFSET_RANGE)
        frames_close[n]++;
    else
        frames_close[n] = 0;

    if(frames_close[n] >= FRAMES_TO_SPIN && ((side == LEFT && (robot[n].coord.x < (ball.coord.x-ATTACKER_BALL_OFFSET)) && (robot[n].coord.y <= (pf_lrc.y+pf_ulc.y)/2)) || ((side == RIGHT && robot[n].coord.x > ball.coord.x) && robot[n].coord.y <= (pf_lrc.y+pf_ulc.y)/2)))
    {
        robot[n].movement.angular_vel_scaling = 1;
    }
    else if (frames_close[n] >= FRAMES_TO_SPIN && ((side == LEFT && (robot[n].coord.x < (ball.coord.x-ATTACKER_BALL_OFFSET)) && (robot[n].coord.y > (pf_lrc.y+pf_ulc.y)/2)) || ((side == RIGHT && robot[n].coord.x > ball.coord.x) && robot[n].coord.y > (pf_lrc.y+pf_ulc.y)/2)))
    {
        robot[n].movement.angular_vel_scaling = -1;
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
            robot[n].movement.angular_vel_scaling = 0.3;
        }
        else
        {
            robot[n].movement.angular_vel_scaling = 0;
        }

        //std::cout << robot[n].coord.distance(ball.coord) <<" "<< robot[n].coord.x <<" " <<robot[n].coord.y<<" "<<ball.coord.x<<" "<<ball.coord.y<< std::endl;
        if(side == LEFT)
        {
            if((robot[n].coord.distance(ball.coord) > ATTACKER_OFFSET_RANGE) || (robot[n].coord.x > (ball.coord.x - ATTACKER_BALL_OFFSET)))
            {
                //std::cout << "indo pra bola com "<< robot[n].coord.distance(ball.coord)<<std::endl;
                /*robot[n].destination.y = ball.coord.y;
                robot[n].destination.x = ball.coord.x - ATTACKER_BALL_OFFSET;*/
                robot[n].destination = calculateMovementsToBall(n);
                //std::cout << robot[n].destination.x << ' ' << robot[n].destination.y << std::endl;

            }
            else //se a bola esta em reta com o gol -- melhorar
            {
                //std::cout << "indo para o gol com "<<robot[n].coord.x -ball.coord.x<<std::endl;
                Coord goal_center(rg_lrc.x, (rg_lrc.y-rg_ulc.y)/2 + rg_ulc.y);
                robot[n].destination = goal_center;
            }
        }
        else
        {
            if((robot[n].coord.distance(ball.coord) > ATTACKER_OFFSET_RANGE) || (robot[n].coord.x > (ball.coord.x - ATTACKER_BALL_OFFSET)))
            {
                robot[n].destination = calculateMovementsToBall(n);
            }
            else //se a bola esta em reta com o gol -- melhorar
            {
                Coord goal_center(lg_lrc.x, (lg_lrc.y-lg_ulc.y)/2 + lg_ulc.y);
                robot[n].destination = goal_center;
            }
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
    if(side == LEFT)
    {
        Coord goal_center(rg_ulc.x, (rg_lrc.y-rg_ulc.y)/2 + rg_ulc.y);
        robot[0].destination = goal_center;
        robot[0].movement.angular_vel_scaling = 1;
    }

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
        manual_controlled_robot = n;
        current_manual_command = manual_command;
        robot[n].movement.stay_still = false;
        if(manual_command == STOP)
        {
            robot[n].movement.stay_still = true;
        }
        else
        {
            if(!robot[n].already_found)
            {
                switch (manual_command)
                {
                    case FORWARD:
                        robot[n].destination.x = 0;
                        robot[n].destination.y = -1; break;
                    case TURN_LEFT:
                        robot[n].destination.x = -1;
                        robot[n].destination.y = 0; break;
                    case TURN_RIGHT:
                        robot[n].destination.x = 1;
                        robot[n].destination.y = 0; break;
                    case BACK:
                        robot[n].destination.x = 0;
                        robot[n].destination.y = 1; break;
                    case FL:
                        robot[n].destination.x = -1;
                        robot[n].destination.y = -1; break;
                    case FR:
                        robot[n].destination.x = 1;
                        robot[n].destination.y = -1; break;
                    case BL:
                        robot[n].destination.x = -1;
                        robot[n].destination.y = 1; break;
                    case BR:
                        robot[n].destination.x = 1;
                        robot[n].destination.y = 1; break;
                }

            }
            else
            {
                if (manual_command != previous_command)
                {
                    previous_manual_controlled_robot = -1;
                    previous_command = manual_command;

                }

                //robot[n].destination = calculateDestination(n, robot[n].previous_destination.x - robot[n].coord.x, robot[n].previous_destination.y - robot[n].coord.y);
                Coord t_vec = robot[n].coord - robot[1].coord;
                Coord dest;
                dest.x = (rg_ulc.x - robot[n].coord.x);
                dest.y = (rg_ulc.y - robot[n].coord.y);
                if (t_vec.norm() <= 200)
                {
                    dest.x += (t_vec.x)  * 1000000 * 3 *(1/t_vec.norm() - 1/200) / (t_vec.norm() * t_vec.norm());
                    dest.y += (t_vec.y)  * 1000000 * 3 *(1/t_vec.norm() - 1/200) / (t_vec.norm() * t_vec.norm());
                }
                robot[n].destination = calculateDestination(n, dest.x, dest.y);

            }
        }
        Coord t_vec = robot[n].coord - robot[1].coord;
        //std::cout << "norm "<< t_vec.norm() << " att " << rg_ulc.x - robot[n].coord.x + (t_vec.x)  * 1000000 * 3 *(1/t_vec.norm() - 1/300) / (t_vec.norm() * t_vec.norm())
        //<< " rep1 " << (t_vec.x) << " rep2 " << 1000000 * 3 << " rep3 " << (1/t_vec.norm() - 1/300) << " rep4 " << (t_vec.norm() * t_vec.norm()) << std::endl;
        //std::cout << "n: " << n << " x: " << robot[n].destination.x << " y: " << robot[n].destination.y << std::endl;
        robot[n].movement.angular_vel_scaling = 0;
    }
}

Coord Strategy::calculateDestination(int n, double x, double y)
{
    Coord destination;
    destination.x = x * (cos(robot[n].angle - previous_robot_angle)) + y * (sin(robot[n].angle - previous_robot_angle));
    destination.y = x * (-sin(robot[n].angle - previous_robot_angle)) + y * (cos(robot[n].angle - previous_robot_angle));
    return destination;
}

Coord Strategy::calculatePreviousDestination(int n, double angle)
{
    Coord pos = robot[n].coord;
    double robot_angle = normalizeAngle(robot[n].angle + angle);
    double angle1, angle2, angle3, angle4;
    angle1 = atan2(rga_lrc.x - pos.x, pos.y - pf_ulc.y);
    angle2 = atan2(pf_lrc.x - pos.x, pf_lrc.y - pos.y);
    angle3 = atan2(pos.x - lga_ulc.x, pf_lrc.y - pos.y);
    angle4 = atan2(pos.x - lga_ulc.x, pos.y - pf_ulc.y);

    if (robot_angle == 0)
        return Coord(pos.x, pf_ulc.y);
    if (robot_angle > 0 && robot_angle <= angle1 || (robot_angle > - angle4 && robot_angle < 0) || robot_angle > 2 * M_PI - angle4)
    {
        return Coord(pos.x + (pos.y - pf_ulc.y) * tan(robot_angle), pf_ulc.y);
    }
    if (robot_angle > angle1 && robot_angle <= M_PI - angle2)
    {
        return Coord(rga_lrc.x, pos.y - (rg_lrc.x - pos.x) / tan(robot_angle));
    }
    if (robot_angle > M_PI - angle2 && robot_angle <= M_PI + angle3 && robot_angle != M_PI)
    {
        return Coord(pos.x + (pos.y - pf_lrc.y) * tan(robot_angle), pf_lrc.y);
    }
    if (robot_angle > M_PI + angle3 && robot_angle <= 2 * M_PI - angle4 || (robot_angle < -angle4 && robot_angle < 0))
    {
        return Coord(lga_ulc.x, pos.y + (pos.x - lga_ulc.x) / tan(robot_angle));
    }
    return Coord(0,0);
}

Coord Strategy::calculateMovementsToBall(int n)
{
    if (side == LEFT)
    {
        if (robot[n].coord.x < ball.coord.x - BALL_OFFSET/2 && attacker_returning)
        {
            attacker_returning = false;
            return Coord(ball.coord.x, ball.coord.y);
        }
        else
        {
            if (!attacker_returning)
            {
                attacker_returning = true;
            }
            else
            {
                if (robot[n].coord.y < (pf_ulc.y + pf_lrc.y)/2)
                    return Coord(ball.coord.x - BALL_OFFSET/2, ball.coord.y - BALL_OFFSET);
                else
                    return Coord(ball.coord.x - BALL_OFFSET/2, ball.coord.y + BALL_OFFSET);   
            }
        }
        /*Coord t_vec = robot[n].coord - ball.coord;
        Coord dest;
        dest.x = (ball.coord.x - BALL_OFFSET - robot[n].coord.x);
        dest.y = ball.coord.y;
        if (t_vec.norm() <= 200)
        {
            std::cout << dest.x << ' ';
            dest.x += (t_vec.x)  * 750000 *(1/t_vec.norm() - 1/200) / (t_vec.norm() * t_vec.norm());
            std::cout << dest.x << std::endl;
            dest.y += (t_vec.y)  * 750000 *(1/t_vec.norm() - 1/200) / (t_vec.norm() * t_vec.norm());
        }*/
        return dest;

    }
    else
    {
        if (robot[n].coord.x > ball.coord.x)
            return Coord(ball.coord.x, ball.coord.y);
        else
        {
            if (robot[n].coord.y < (pf_ulc.x + pf_lrc.x)/2)
                return Coord(ball.coord.x + BALL_OFFSET, ball.coord.y - BALL_OFFSET);
            else
                return Coord(ball.coord.x + BALL_OFFSET, ball.coord.y + BALL_OFFSET);
        }
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
    double diff = fabs(angle1 - angle2);
    return (diff < epsilon);
}

void Strategy::moveStraight(double angle)
{
    if(robot[manual_controlled_robot].already_found)
    {

        if(robot[manual_controlled_robot].angle - angle > ANGLE_COMPARE_EPSILON)
        {
            std::cout<<"vou diminuir"<<std::endl;
            //robot[manual_controlled_robot].movement.linear_vel_angle += robot[manual_controlled_robot].angle - angle;
            robot[manual_controlled_robot].movement.linear_vel_angle += ANGLE_COMPARE_EPSILON/5;
            //robot[manual_controlled_robot].movement.angular_vel_scaling += ANGLE_COMPARE_EPSILON;
            if(robot[manual_controlled_robot].movement.linear_vel_angle > 2*M_PI)
                robot[manual_controlled_robot].movement.linear_vel_angle -= 2*M_PI;
        }
        else if(angle - robot[manual_controlled_robot].angle > ANGLE_COMPARE_EPSILON)
        {
            std::cout<<"vou aumentar"<<std::endl;
            //robot[manual_controlled_robot].movement.linear_vel_angle -= angle - robot[manual_controlled_robot].angle;
            robot[manual_controlled_robot].movement.linear_vel_angle -= ANGLE_COMPARE_EPSILON/5;
            //robot[manual_controlled_robot].movement.angular_vel_scaling -= ANGLE_COMPARE_EPSILON;
            if(robot[manual_controlled_robot].movement.linear_vel_angle < 2*M_PI)
                robot[manual_controlled_robot].movement.linear_vel_angle += 2*M_PI;
        }
        std::cout<<robot[manual_controlled_robot].angle<<"  "<<robot[manual_controlled_robot].movement.linear_vel_angle<<std::endl;

    }
}
