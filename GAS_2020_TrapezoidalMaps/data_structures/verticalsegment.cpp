#include "Verticalsegment.h"

/* Constructors */

/**
 * @brief TrapezoidalMap::TrapezoidalMap
 */
VerticalSegment::VerticalSegment() :
    boundingBox(cg3::Point2d(0,0),cg3::Point2d(0,0))
{

}


/**
 * @brief TrapezoidalMap::getBoundingBox returns the boundingBox
 * @return
 */
const cg3::BoundingBox2& VerticalSegment::getBoundingBox() const
{
    return boundingBox;
}


/**
 * @brief setDataSource
 * @param source
 */
void VerticalSegment::setDataSource(std::list<Trapezoid>* source)
{
    _source = source;
}




/**
 * @brief TrapezoidalMap::clear (clear both pointExtension and trapezoids)
 */
void VerticalSegment::clear()
{

}


