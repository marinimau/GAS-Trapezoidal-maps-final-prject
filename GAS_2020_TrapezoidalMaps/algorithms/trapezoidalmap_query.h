#ifndef TRAPEZOIDALMAPQUERY_H
#define TRAPEZOIDALMAPQUERY_H

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

#include "data_structures/trapezoid.h"
#include "data_structures/dag.h"


namespace TrapezoidalmapQuery
{
    Trapezoid* pointQuery(cg3::Point2d point,  Node * startNode);
    Node * find(Node * current, const cg3::Point2d query);
};

#endif // TRAPEZOIDALMAPQUERY_H
