#include "geometry.h"

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double distanceSquared(double x1, double y1, double x2, double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

double normalizeAngle(double angle)
{
    if(angle > 2.0*M_PI)
        while(angle > 2.0*M_PI)
            angle -= 2.0*M_PI;
    else if(angle < 0.0)
        while(angle < 0.0)
            angle += 2.0*M_PI;
    return angle;
}

bool angleCompare(double angle1, double angle2, double epsilon)
{
    angle1 = normalizeAngle(angle1);
    angle2 = normalizeAngle(angle2);
    double diff = angle1 - angle2;
    return (diff < epsilon) || (-diff > -epsilon);
}

double adjustYToLineSeg(double x, double point1_x, double point1_y, double point2_x, double point2_y)
{
    double a, b, y;
    a = (point1_y - point2_y)/(point1_x - point2_x);
    b = point1_y - (a*point1_x);
    y = a*x + b;
    return y;
}

velocity calculateVelocity(entity ent, std::pair<double,double> destination)
{
    velocity vel;
    vel.x = destination.first - ent.x;
    vel.y = destination.second - ent.y;

    //invert x because of mirroring
    if(INVERT_Y)
        vel.y = -vel.y;
    //rotating axis to the robot´s orientation
    double cosine = cos(ent.angle), sine = sin(ent.angle), x_backup = vel.x;

    if(ANGLE_ORIENTATION == CLOCKWISE)
    {
        vel.x = vel.x*cosine - vel.y*sine;
        vel.y = x_backup*sine + vel.y*cosine;
    }
    else //if(ANGLE_ORIENTATION == ANTI_CLOCKWISE)
    {
        vel.x = vel.x*cosine + vel.y*sine;
        vel.y = vel.y*cosine - x_backup*sine;
    }

    if(vel.x != 0.0)
    {
        if(vel.y != 0.0)
        {
            double normalizer;
            //normalizing to max velocity
            if(abs(vel.x) > abs(vel.y))
            {
                normalizer = MAX_VELOCITY/abs(vel.x);
                vel.x = vel.x > 0 ? MAX_VELOCITY : -MAX_VELOCITY;
                vel.y = vel.y*normalizer;
            }
            else
            {
                normalizer = MAX_VELOCITY/abs(vel.y);
                vel.y = vel.y > 0 ? MAX_VELOCITY : -MAX_VELOCITY;
                vel.x = vel.x*normalizer;
            }
        }
        else
        {
            vel.x = vel.x > 0 ? MAX_VELOCITY : -MAX_VELOCITY;
        }
    }
    else if(vel.y != 0.0)
    {
        vel.y = vel.y > 0 ? MAX_VELOCITY : -MAX_VELOCITY;
    }

    //adjusting angle to move with a face to the destination
    if(ANGLE_ADJUSTING)
    {
        if(angleCompare(atan2(vel.y,vel.x),0.0,ANGLE_EPISILON) ||
           angleCompare(atan2(vel.y,vel.x),M_PI_2,ANGLE_EPISILON) ||
           angleCompare(atan2(vel.y,vel.x),M_PI,ANGLE_EPISILON) ||
           angleCompare(atan2(vel.y,vel.x),-M_PI_2,ANGLE_EPISILON))
        {
            vel.ang = 0.0;
        }
        else
        {
            vel.ang = MAX_ANG_VELOCITY;
        }
    }
    else
    {
        vel.ang = 0.0;
    }

    return vel;
}
