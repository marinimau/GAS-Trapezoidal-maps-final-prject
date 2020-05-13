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
    _trapezoids.push_back(trapezoid);
    return &_trapezoids.back();
}


/**
 * @brief TrapezoidalMap::trapezoidNumber returns the size of the array that contains the trapezoids
 * @return
 */
size_t TrapezoidalMap::trapezoidNumber() const
{
    return _trapezoids.size();
}


/**
 * @brief TrapezoidalMap::getTrapezoidsData returns  the raw trapezoid's data
 * @return
 */
const std::list<Trapezoid> TrapezoidalMap::getTrapezoids() const
{
    return _trapezoids;
}


/**
 * @brief TrapezoidalMap::getTrapezoidsRef return a reference to the trapezoids list
 * @return
 */
std::list<Trapezoid>* TrapezoidalMap::getTrapezoidsRef()
{
    return &_trapezoids;
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


/* query */

/**
 * @brief DrawableTrapezoid::storeQueryResult: store pointer to the result trapezoid
 * and number of trapezoid in the map. If another query is executed result change,
 * if a building step is executed, trapezoidCount change.
 * by combining these two parameters, draw() highlights the result only when required.
 * @param result
 */
void TrapezoidalMap::storeQueryResult(Trapezoid * result)
{
    trapezoidsCountWhenQuery = trapezoidNumber();
    queryResult = result;
}


/**
 * @brief TrapezoidalMap::clear (clear both pointExtension and trapezoids)
 */
void TrapezoidalMap::clear()
{
    _trapezoids.clear();
    trapezoidsCountWhenQuery = 0;
    queryResult = nullptr;
}
