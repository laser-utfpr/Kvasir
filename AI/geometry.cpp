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
    if(angle > 2*M_PI)
        while(angle > 2*M_PI)
            angle -= 2*M_PI;
    else if(angle < 0)
        while(angle < 0)
            angle += 2*M_PI;
    return angle;
}

bool angleCompare(double angle1, double angle2, double epsilon)
{
    angle1 = normalizeAngle(angle1);
    angle2 = normalizeAngle(angle2);
    double diff = angle1 - angle2;
    return (diff < epsilon) || (-diff > -epsilon);
}
