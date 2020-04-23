#include "point_utils.h"

namespace PointUtils {

/**
 * @brief evaluateYValue: given a segment and a x value compute the y
 * @param a: first point of a segment
 * @param b: second point of a segment
 * @param xValue: the value of x in which to compute y
 * @return the Y value for the given X
 */
double evaluateYValue(const cg3::Point2d a, const cg3::Point2d b, const double xValue)
{
    double m = (b.y() - a.y()) / (b.x() - a.x());
    return m * (xValue - a.x()) + a.y();
}


}