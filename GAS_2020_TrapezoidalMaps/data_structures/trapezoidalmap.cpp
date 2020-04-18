#include "data_structures/trapezoidalmap.h"

/* Constructors */

/**
 * @brief TrapezoidalMap::TrapezoidalMap
 */
TrapezoidalMap::TrapezoidalMap() :
    boundingBox(cg3::Point2d(0,0),cg3::Point2d(0,0))
{

}

/* Vertical segments */

/**
 * @brief TrapezoidalMap::addPointExtensions
 * @param pointExtension
 * @param extensionsInserted
 * @return index of arrai of the given point extension
 */
void TrapezoidalMap::addPointExtension(const PointExtension pointExtension)
{
    pointExtensions.insert(pointExtension);
}

/**
 * @brief TrapezoidalMap::pointExtensionsNumber
 * @return the number of point extensions
 */
size_t TrapezoidalMap::pointExtensionsNumber()
{
    return pointExtensions.size();
}

/**
 * @brief TrapezoidalMap::getPointExtensionsData
 * @return The raw point extension dataStructure
 */
const std::set<TrapezoidalMap::PointExtension> TrapezoidalMap::getPointExtensionsData() const
{
    return pointExtensions;
}

/**
 * @brief TrapezoidalMap::getVerticalSegments
 * @return The vertical segments
 */
std::vector<cg3::Segment2d> TrapezoidalMap::getVerticalSegments() const
{
    std::vector<cg3::Segment2d> verticalSegments;
    for (const TrapezoidalMap::PointExtension& pointExtention : getPointExtensionsData()) {
        /* upward segment of given point */
        cg3::Point2d upperEndPoint = cg3::Point2d(std::get<1>(pointExtention).x(),std::get<0>(pointExtention));
        verticalSegments.push_back(cg3::Segment2d(upperEndPoint, std::get<1>(pointExtention)));
        /* downward segment of given point */
        cg3::Point2d lowerEndPoint = cg3::Point2d(std::get<1>(pointExtention).x(),std::get<2>(pointExtention));
        verticalSegments.push_back(cg3::Segment2d(std::get<1>(pointExtention), lowerEndPoint));
    }
    return verticalSegments;
}

/**
 * @brief TrapezoidalMap::getPointExtensionById
 * @param id
 * @return the point extension at the given position
 */
/*
TrapezoidalMap::PointExtension TrapezoidalMap::findPointExtension(const TrapezoidalMap::PointExtension pointExtension) const
{
    return pointExtensions.find(pointExtension);
}*/


/* Trapezoids */

/**
 * @brief TrapezoidalMap::addTrapezoid
 * @param trapezoid (the trapezoid object to insert)
 * @param trapezoidInserted (flag)
 * @return the id of the trapezoid inserted or an arbitry number in case of error.
 */
void TrapezoidalMap::addTrapezoid(const Trapezoid trapezoid)
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
const std::vector<Trapezoid> TrapezoidalMap::getTrapezoids() const
{
    return trapezoids;
}


/**
 * @brief TrapezoidalMap::getTrapezoidById
 * @param id
 * @return the trapezoid object at the given position
 */
/*
TrapezoidalMap::Trapezoid TrapezoidalMap::getTrapezoidById(size_t id) const
{
    return trapezoids[id];
}*/


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
    pointExtensions.clear();
    trapezoids.clear();
}
