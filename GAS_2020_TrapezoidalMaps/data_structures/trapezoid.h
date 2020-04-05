#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <vector>
#include <utility>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/bounding_box2.h>

class Trapezoid {

public:

    enum pointPosition {topLeft, bottomLeft, topRight, bottomRight};

    enum adjacentPosition {leftTop, leftBottom, rightTop, rightBottom};

    /* Constructors */
    Trapezoid(const cg3::Point2d& topRight, const cg3::Point2d& topLeft, const cg3::Point2d& bottomLeft, const cg3::Point2d& bottomRight);

    /* Getters */
    double getArea() const;
    const std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d> getPoints() const;
    cg3::Point2d getPoint(const pointPosition position) const ;
    const std::tuple<Trapezoid *, Trapezoid *, Trapezoid *, Trapezoid *> getAdjacents() const;
    Trapezoid * getdAjacent(const adjacentPosition position);

    /* Setters */
    void setPoints(const cg3::Point2d& topRight, const cg3::Point2d& topLeft, const cg3::Point2d& bottomLeft, const cg3::Point2d& bottomRight);
    void setPoint(const cg3::Point2d point, const pointPosition position);
    void setAdjacents(Trapezoid * rightTop, Trapezoid * leftTop, Trapezoid * leftBottom, Trapezoid * rightBottom);
    void setAdjacent(Trapezoid * adjacent, const adjacentPosition position);

private:

    /* Points */
    cg3::Point2d tr;
    cg3::Point2d tl;
    cg3::Point2d bl;
    cg3::Point2d br;

    /* Adjacents trapezoids */
    Trapezoid * rt;
    Trapezoid * lt;
    Trapezoid * lb;
    Trapezoid * rb;


};

#endif // TRAPEZOID_H
