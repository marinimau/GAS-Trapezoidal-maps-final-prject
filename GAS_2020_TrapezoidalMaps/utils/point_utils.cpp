#include "point_utils.h"

namespace PointUtils {


/**
 * @brief angularCoefficient: given 2 points returns the angular coefficient
 * @param m;
 * @param a
 * @param b
 */
inline void angularCoefficient(double& m, const cg3::Point2d& a, const cg3::Point2d& b)
{
    m = (b.y() - a.y()) / (b.x() - a.x());
}


/**
 * @brief evaluateYValue: given 2 points and an x value compute the y
 * @param a: first point of a segment
 * @param b: second point of a segment
 * @param xValue: the value of x in which to compute y
 * @return the Y value for the given X
 */
double evaluateYValue(const cg3::Point2d& a, const cg3::Point2d& b, const double& xValue)
{
    double m = 0;
    /* i have split angularCoefficent in another function because i need to call only angular coefficient in some cases */
    angularCoefficient(m, a, b);
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
 * @return
 */
void removeDegenere(std::vector<cg3::Point2d>& points)
{
    assert(points.size() == 4);
    for(int i = 0; i<4; i++){
        if(checkDegenere(points[i], points[(i+1) % 4])){
            points.erase(points.begin()+i);
            return;
        }
    }
}


}
