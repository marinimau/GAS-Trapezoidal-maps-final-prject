#ifndef POINT_UTILS_H
#define POINT_UTILS_H

#include <cg3/geometry/point2.h>

namespace PointUtils {

    double evaluateYValue(const cg3::Point2d a, const cg3::Point2d b, const double xValue);
    bool checkDegenere(const cg3::Point2d& p1, const cg3::Point2d& p2);
    void removeDegenere(std::vector<cg3::Point2d> points);

}

#endif // POINT_UTILS_H
