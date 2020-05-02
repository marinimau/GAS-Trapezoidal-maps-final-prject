#ifndef TRAPEZOIDALMAP_H
#define TRAPEZOIDALMAP_H

#include <set>
#include <list>
#include <utility>

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include <cg3/geometry/bounding_box2.h>
#include "data_structures/trapezoid.h"

/**
 * @brief This class store the verticals segments of the trapezoidal map.
 */
class TrapezoidalMap{

public:

    /* constructors */
    TrapezoidalMap();

    /* trapezoids */
    void addTrapezoid(Trapezoid * trapezoid);
    size_t trapezoidNumber() const;
    const std::list<Trapezoid *> getTrapezoids() const;

    /* generic */
    const cg3::BoundingBox2& getBoundingBox() const;
    void clear();

private:

    /* trapezoids */
    std::list<Trapezoid *> trapezoids;

    cg3::BoundingBox2 boundingBox;

};

#endif // TRAPEZOIDALMAP_H
