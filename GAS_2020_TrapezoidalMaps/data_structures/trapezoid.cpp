#include "data_structures/trapezoid.h"

/* Constructors */

/**
 * @brief Trapezoid::Trapezoid
 * @param topRight
 * @param topLeft
 * @param bottomLeft
 * @param bottomRight
 */
Trapezoid::Trapezoid(const cg3::Segment2d top, const cg3::Segment2d bottom, const cg3::Point2d leftP, const cg3::Point2d rightP)
{
    _top = top;
    _bottom = bottom;
    _leftP = leftP;
    _rightP = rightP;
    _active = true;
    _dagRef = nullptr;

    /* Adjacents trapezoids */
    _rt = nullptr;
    _lt = nullptr;
    _lb = nullptr;
    _rb = nullptr;
}


/* Getters */

/**
 * @brief Trapezoid::rightP return rightP
 * @return
 */
cg3::Point2d Trapezoid::rightP() const
{
    return _rightP;
}


/**
 * @brief Trapezoid::leftP return leftP
 * @return
 */
cg3::Point2d Trapezoid::leftP() const
{
    return _leftP;
}


/**
 * @brief Trapezoid::top return the top segment of the trapezoid
 * @return
 */
cg3::Segment2d Trapezoid::top() const
{
    return _top;
}


/**
 * @brief Trapezoid::bottom return the bottom segment of the given trapezoid
 * @return
 */
cg3::Segment2d Trapezoid::bottom() const
{
    return _bottom;
}


/**
 * @brief Trapezoid::getArea return the trapezoid area
 * @return
 */
double Trapezoid::getArea() const
{
    double b1 = PointUtils::evaluateYValue(_top.p1(), _top.p2(), _leftP.x()) - PointUtils::evaluateYValue(_bottom.p1(), _bottom.p2(), _leftP.x());
    double b2 = PointUtils::evaluateYValue(_top.p1(), _top.p2(), _rightP.x()) - PointUtils::evaluateYValue(_bottom.p1(), _bottom.p2(), _rightP.x());
    double h = _rightP.x() - _leftP.x();

    return (b1 + b2) * h / 2;
}


/**
 * @brief Trapezoid::getVertex
 * @param position
 * @return
 */
const cg3::Point2d Trapezoid::getVertex(const Trapezoid::vertexPosition& position) const
{
    switch(position){
        case topRight:
            return cg3::Point2d(_rightP.x(), (PointUtils::evaluateYValue(_top.p1(), _top.p2(), _rightP.x()))); // top right
        case topLeft:
            return cg3::Point2d(_leftP.x(), (PointUtils::evaluateYValue(_top.p1(), _top.p2(), _leftP.x()))); // top left
        case bottomLeft:
            return cg3::Point2d(_leftP.x(), (PointUtils::evaluateYValue(_bottom.p1(), _bottom.p2(), _leftP.x()))); // bottom left
        case bottomRight:
            return cg3::Point2d(_rightP.x(), (PointUtils::evaluateYValue(_bottom.p1(), _bottom.p2(), _rightP.x()))); // bottom right
    }
}


/**
 * @brief Trapezoid::getVertices return a vector that contains the vertices of trapezoid
 * in counter-clockwise order starting from topright
 * @return
 */
const std::vector<cg3::Point2d> Trapezoid::getVertices() const
{
    return {
        cg3::Point2d(_rightP.x(), (PointUtils::evaluateYValue(_top.p1(), _top.p2(), _rightP.x()))), // top right
        cg3::Point2d(_leftP.x(), (PointUtils::evaluateYValue(_top.p1(), _top.p2(), _leftP.x()))), // top left
        cg3::Point2d(_leftP.x(), (PointUtils::evaluateYValue(_bottom.p1(), _bottom.p2(), _leftP.x()))), // bottom left
        cg3::Point2d(_rightP.x(), (PointUtils::evaluateYValue(_bottom.p1(), _bottom.p2(), _rightP.x()))) // bottom right
    };
}


/**
 * @brief Trapezoid::getAdjacents return a tuple that contains the adjacent trapezoids in this order:
 *  1.rightTop
 *  2.leftTop
 *  3.leftBottom
 *  4.rightBottom
 * @return
 */
const std::tuple<Trapezoid *, Trapezoid *, Trapezoid *, Trapezoid *> Trapezoid::getAdjacents() const
{
    return {_rt, _lt, _lb, _rb};
}


/**
 * @brief Trapezoid::getdAjacent return the pointer to the adjacent trapezoid at the given position
 * @param position
 * @return
 */
Trapezoid * Trapezoid::getAdjacent(const Trapezoid::adjacentPosition& position) const
{
    switch (position) {
        case upperRight:
            return _rt;
        case upperLeft:
            return _lt;
        case lowerLeft:
            return _lb;
        case lowerRight:
            return _rb;
    }   
    return nullptr;
}


/**
 * @brief Trapezoid::active
 * @return
 */
bool Trapezoid::active() const
{
    return _active;
}


/**
 * @brief Trapezoid::dagRef return the node of dag that point to the trapezoid
 * @return
 */
Node * Trapezoid::dagRef() const
{
    return _dagRef;
}


/* Setters */

/**
 * @brief Trapezoid::setLeftP
 * @param leftP
 */
void Trapezoid::setLeftP(const cg3::Point2d& leftP)
{
    _leftP = leftP;
}


/**
 * @brief Trapezoid::setRightP
 * @param rightP
 */
void Trapezoid::setRightP(const cg3::Point2d& rightP)
{
    _rightP = rightP;
}


/**
 * @brief Trapezoid::setTop
 * @param top
 */
void Trapezoid::setTop(const cg3::Segment2d& top)
{
    _top = top;
}


/**
 * @brief Trapezoid::setBottom
 * @param bottom
 */
void Trapezoid::setBottom(const cg3::Segment2d& bottom)
{
    _bottom = bottom;
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
    _rt = rightTop;
    _lt = leftTop;
    _lb = leftBottom;
    _rb = rightBottom;
}


/**
 * @brief Trapezoid::setAdjacent: set the pointer to the adjacent trapezoid at the given position;
 * @param adjacent
 * @param position
 */
void Trapezoid::setAdjacent(Trapezoid * adjacent, const adjacentPosition& position)
{
    switch (position) {
        case upperRight:
            _rt = adjacent;
            break;
        case upperLeft:
            _lt = adjacent;
            break;
        case lowerLeft:
            _lb = adjacent;
            break;
        case lowerRight:
            _rb = adjacent;
            break;
    }
}


/**
 * @brief Trapezoid::deactivate: marks trapezoid for elimination
 */
void Trapezoid::deactivate()
{
    _active = false;
}


/**
 * @brief Trapezoid::setDagRef
 * @param ref
 */
void Trapezoid::setDagRef(Node *ref)
{
    _dagRef = ref;
}
