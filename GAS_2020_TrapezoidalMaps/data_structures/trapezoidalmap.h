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

    Trapezoid * addTrapezoid(Trapezoid trapezoid);
    void deleteTrapezoid(const std::list<Trapezoid>::iterator& iterator);
    size_t trapezoidNumber() const;
    const std::list<Trapezoid> getTrapezoids() const;
    std::list<Trapezoid>* getTrapezoidsRef();


    /* generic */

    const cg3::BoundingBox2& getBoundingBox() const;


    /* Query */

    void storeQueryResult(Trapezoid * result);
    inline void clearQueryResult() { queryResult = nullptr; };

    void clear();



private:

    cg3::BoundingBox2 boundingBox;

    /* trapezoids */
    std::list<Trapezoid> _trapezoids;


protected:

    /* Query */
    Trapezoid * queryResult;

};

#endif // TRAPEZOIDALMAP_H
