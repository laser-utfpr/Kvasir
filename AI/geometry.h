#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2);

double distanceSquared(double x1, double y1, double x2, double y2);

double normalizeAngle(double angle);

bool angleCompare(double angle1, double angle2, double epsilon);

#endif //GEOMETRY_H
