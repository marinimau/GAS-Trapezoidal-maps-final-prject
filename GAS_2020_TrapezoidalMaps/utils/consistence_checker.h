#ifndef CONSISTENCECHECKER_H
#define CONSISTENCECHECKER_H

#include "data_structures/trapezoid.h"
#include "utils/point_utils.h"
#include <list>

/*
 * this namespace contains the function used only in debug mode to find mistakes
 */
namespace ConsistenceChecker {

bool equalArea(const std::list<Trapezoid>& before, const std::list<Trapezoid>& after);
bool checkForWrongBuildArea(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea);

/* i have included the following 2 functions here and not in point utils because they are needed only in debug mode */
bool checkIntersection(const cg3::Segment2d& segment, const Trapezoid& polygon);
bool isInside(const cg3::Point2d& point, const Trapezoid& polygon);

};

#endif // CONSISTENCECHECKER_H
