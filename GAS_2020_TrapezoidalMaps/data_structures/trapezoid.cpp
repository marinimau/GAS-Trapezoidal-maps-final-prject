#include "data_structures/trapezoid.h"

/* Constructors */

/**
 * @brief Trapezoid::Trapezoid
 * @param topRight
 * @param topLeft
 * @param bottomLeft
 * @param bottomRight
 */
Trapezoid::Trapezoid(const cg3::Point2d& topRight, const cg3::Point2d& topLeft, const cg3::Point2d& bottomLeft, const cg3::Point2d& bottomRight)
{
    assert(topRight.x() == bottomRight.x());
    assert(topLeft.x() == bottomLeft.x());

    tr = topRight;
    tl = topLeft;
    bl = bottomLeft;
    br = bottomRight;
}


/* Getters */

/**
 * @brief Trapezoid::getArea
 * @return the trapezoid area
 */
double Trapezoid::getArea() const
{
    double b1 = tl.y() - bl.y();
    double b2 = tr.y() - br.y();
    double h = tr.x() - tl.x();

    return (b1 + b2) * h / 2;
}

/**
 * @brief Trapezoid::getPoints
 * @return a tuple that contains the trapezoids points
 * in counter-clockwise order starting from topright
 */
const std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d> Trapezoid::getPoints() const
{
    return {tr, tl, bl, tr};
}

/**
 * @brief Trapezoid::getPoint
 * @param position (pointPosition enum)
 * @return the point of trapezoid at the given position
 */
cg3::Point2d Trapezoid::getPoint(const pointPosition position) const
{
    switch (position) {
        case topRight:
            return tr;
        case topLeft:
            return tl;
        case bottomLeft:
            return bl;
        case bottomRight:
            return br;
    }
}

/**
 * @brief Trapezoid::getAdjacents
 * @return a tuple that contains the adjacent trapezoids in this order:
 *  1.rightTop
 *  2.leftTop
 *  3.leftBottom
 *  4.rightBottom
 */
const std::tuple<Trapezoid *, Trapezoid *, Trapezoid *, Trapezoid *> Trapezoid::getAdjacents() const
{
    return {rt, lt, lb, rb};
}

/**
 * @brief Trapezoid::getdAjacent
 * @param position
 * @return the pointer to the adjacent trapezoid at the given posizion
 */
Trapezoid * Trapezoid::getdAjacent(const Trapezoid::adjacentPosition position)
{
    switch (position) {
        case rightTop:
            return rt;
        case leftTop:
            return lt;
        case leftBottom:
            return lb;
        case rightBottom:
            return rb;
    }
}


/* Setters */

/**
 * @brief Trapezoid::setPoints: set all the points of trapezoid
 * @param topRight
 * @param topLeft
 * @param topBottomLeft
 * @param bottomRight
 */
void Trapezoid::setPoints(const cg3::Point2d& topRight, const cg3::Point2d& topLeft, const cg3::Point2d& bottomLeft, const cg3::Point2d& bottomRight)
{
    tr = topRight;
    tl = topLeft;
    bl = bottomLeft;
    br = bottomRight;
}

/**
 * @brief Trapezoid::setPoint: set the given point at the given position
 * @param position
 */
void Trapezoid::setPoint(const cg3::Point2d point, const pointPosition position)
{
    switch (position) {
        case topRight:
            tr = point;
            break;
        case topLeft:
            tl = point;
            break;
        case bottomLeft:
            bl = point;
            break;
        case bottomRight:
            br = point;
    }
}

/**
 * @brief Trapezoid::setAdjacents: set all the the adjacents trapezoid, in case of the same trapezoid both in top and bottom use the same pointer
 * @param rightTop
 * @param leftTop
 * @param leftBottom
 * @param rightBottom
 */
void Trapezoid::setAdjacents(Trapezoid * rightTop, Trapezoid * leftTop, Trapezoid * leftBottom, Trapezoid * rightBottom)
{
    rt = rightTop;
    lt = leftTop;
    lb = leftBottom;
    rb = rightBottom;
}

/**
 * @brief Trapezoid::setAdjacent: set the pointer to the adjacent trapezoid at the given position;
 * @param adjacent
 * @param position
 */
void Trapezoid::setAdjacent(Trapezoid * adjacent, const adjacentPosition position)
{
    switch (position) {
        case rightTop:
            rt = adjacent;
            break;
        case leftTop:
            lt = adjacent;
            break;
        case leftBottom:
            lb = adjacent;
            break;
        case rightBottom:
            rb = adjacent;
            break;
    }
}
