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
 * @brief TrapezoidalMap::addTrapezoid
 * @param trapezoid (the trapezoid object to insert)
 * @param trapezoidInserted (flag)
 * @return the id of the trapezoid inserted or an arbitry number in case of error.
 */
void TrapezoidalMap::addTrapezoid(Trapezoid * trapezoid)
{
    trapezoids.push_back(trapezoid);
}

/**
 * @brief TrapezoidalMap::trapezoidNumber
 * @return the size of the array that contains the trapezoids
 */
size_t TrapezoidalMap::trapezoidNumber() const
{
    return trapezoids.size();
}

/**
 * @brief TrapezoidalMap::getTrapezoidsData
 * @return the raw trapezoid's data
 */
const std::list<Trapezoid *> TrapezoidalMap::getTrapezoids() const
{
    return trapezoids;
}

/* Generic */

/**
 * @brief TrapezoidalMap::getBoundingBox
 * @return the boundingBox
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
    for(auto t: trapezoids) {
        delete t;
    }
    trapezoids.clear();
}
