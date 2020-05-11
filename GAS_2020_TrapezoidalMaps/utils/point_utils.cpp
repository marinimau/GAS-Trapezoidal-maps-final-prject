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


/**
 * @brief checkSameX
 * @param p1
 * @param p2
 * @return
 */
bool checkSameX(const cg3::Point2d& p1, const cg3::Point2d& p2)
{
    return (fabs(p1.x() - p2.x()) <= std::numeric_limits<double>::epsilon());
}

/**
 * @brief checkDegenere: return true if points are degenere
 * @param p1
 * @param p2
 * @return
 */
bool checkDegenere(const cg3::Point2d& p1, const cg3::Point2d& p2)
{
    return (fabs(p1.x() - p2.x()) <= std::numeric_limits<double>::epsilon() && fabs(p1.y() - p2.y()) <= std::numeric_limits<double>::epsilon());
}


/**
 * @brief removeDegenere
 * @param points
 */
void removeDegenere(std::vector<cg3::Point2d> points)
{
    assert(points.size() == 4);
    if(checkDegenere(points[0], points[3])){
        points.pop_back();
    }
    if(checkDegenere(points[1], points[2])) {
        points.erase(points.begin()+1);
    }
}


}
