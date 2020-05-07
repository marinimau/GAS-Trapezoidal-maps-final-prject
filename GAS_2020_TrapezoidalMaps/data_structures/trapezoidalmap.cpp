#include "data_structures/trapezoidalmap.h"

/* Constructors */

/**
 * @brief TrapezoidalMap::TrapezoidalMap
 */
TrapezoidalMap::TrapezoidalMap() :
    boundingBox(cg3::Point2d(0,0),cg3::Point2d(0,0))
{

}


/* Trapezoids */

/**
 * @brief TrapezoidalMap::addTrapezoid add a trapezoid and return the ref of the trapezoid inserted.
 * @param trapezoid (the trapezoid object to insert)
 * @param trapezoidInserted (flag)
 * @return
 */
Trapezoid * TrapezoidalMap::addTrapezoid(Trapezoid trapezoid)
{
    trapezoids.push_back(trapezoid);
    return &trapezoids.back();
}

/**
 * @brief TrapezoidalMap::trapezoidNumber returns the size of the array that contains the trapezoids
 * @return
 */
size_t TrapezoidalMap::trapezoidNumber() const
{
    return trapezoids.size();
}

/**
 * @brief TrapezoidalMap::getTrapezoidsData returns  the raw trapezoid's data
 * @return
 */
const std::list<Trapezoid> TrapezoidalMap::getTrapezoids() const
{
    return trapezoids;
}

/* Generic */

/**
 * @brief TrapezoidalMap::getBoundingBox returns the boundingBox
 * @return
 */
const cg3::BoundingBox2& TrapezoidalMap::getBoundingBox() const
{
    return boundingBox;
}

/**
 * @brief TrapezoidalMap::clear (clear both pointExtension and trapezoids)
 */
void TrapezoidalMap::clear()
{
    trapezoids.clear();
}
