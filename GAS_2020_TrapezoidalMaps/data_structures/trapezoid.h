#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <vector>
#include <utility>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include <cg3/geometry/bounding_box2.h>
#include "utils/point_utils.h"

/* Because i can't include Node here and Trapezoid in Node */
class Node;

class Trapezoid {

public:

    enum adjacentPosition {upperLeft, lowerLeft, upperRight, lowerRight};

    /* Constructors */
    Trapezoid(const cg3::Segment2d top, const cg3::Segment2d bottom, const cg3::Point2d leftP, const cg3::Point2d rightP);

    /* Getters */
    cg3::Point2d rightP() const;
    cg3::Point2d leftP() const;
    cg3::Segment2d top() const;
    cg3::Segment2d bottom() const;
    double getArea() const;
    const std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d> getVertices() const;
    const std::tuple<Trapezoid *, Trapezoid *, Trapezoid *, Trapezoid *> getAdjacents() const;
    Trapezoid * getdAjacent(const adjacentPosition position);
    bool active() const;
    Node * dagRef() const;

    /* Setters */
    void setAdjacents(Trapezoid * rightTop, Trapezoid * leftTop, Trapezoid * leftBottom, Trapezoid * rightBottom);
    void setAdjacent(Trapezoid * adjacent, const adjacentPosition position);
    void deactivate();
    void setDagRef(Node * ref);

    /* Operator override */
    inline bool operator < (const Trapezoid& otherTrapezoid) const
    {
        if (this->_leftP < otherTrapezoid._leftP) return true;
        if (this->_leftP > otherTrapezoid._leftP) return false;
        if (this->_rightP < otherTrapezoid._rightP) return true;
        return false;
    }

private:

    /* Points */
    cg3::Segment2d _top;
    cg3::Segment2d _bottom;
    cg3::Point2d _leftP;
    cg3::Point2d _rightP;

    /* Adjacents trapezoids */
    Trapezoid * _rt;
    Trapezoid * _lt;
    Trapezoid * _lb;
    Trapezoid * _rb;

    /* active */
    bool _active;

    /* Node */
    Node * _dagRef;
    /* 2-way reference can cause inconsistence, but allow to access in O(1)
     * at the dag leaf after the execution of followSegment */

};

#endif // TRAPEZOID_H
