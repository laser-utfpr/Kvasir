#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>

#include "../ObRo/entity.h"
#include "velocity.h"

#include "aiconstants.h"

double distance(double x1, double y1, double x2, double y2);

double distanceSquared(double x1, double y1, double x2, double y2);

double normalizeAngle(double angle);

bool angleCompare(double angle1, double angle2, double epsilon);

double adjustYToLineSeg(double x, double point1_x, double point1_y, double point2_x, double point2_y);

velocity calculateVelocity(entity ent, std::pair<double,double> destination);

#endif //GEOMETRY_H
