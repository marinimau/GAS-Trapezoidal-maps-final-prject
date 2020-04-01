#include "data_structures/trapezoidal_map.h"

TrapezoidalMap::TrapezoidalMap() :
    boundingBox(cg3::Point2d(0,0),cg3::Point2d(0,0))
{

}

size_t TrapezoidalMap::addPointExtensions(const PointExtension pointExtension, bool& extensionsInserted)
{
    extensionsInserted = false;
    bool found = false;
    size_t id = 0; //TrapezoidalMap::findPointExtension(pointExtension, found);

    // if point is not inserted
    if(!found){
        // do the insertion
        pointExtensions.push_back(pointExtension);
        id = pointExtensions.size();
        //pointExtensionsMap.insert(std::make_pair(pointExtension, id));
    }

    return id;
}

/*
size_t TrapezoidalMap::findPointExtension(const TrapezoidalMap::PointExtensions& pointExtension, bool& found)
{
    std::unordered_map<TrapezoidalMap::PointExtensions, size_t>::iterator it = pointExtensionsMap.find(pointExtension);

    // if pointExtension already exists return true and its id
    if (it != pointExtensionsMap.end()) {
        found = true;
        return it->second;
    }
    // else return false
    else {
        found = false;
        return std::numeric_limits<size_t>::max();
    }
}
*/

size_t TrapezoidalMap::pointExtensionsNumber()
{
    return pointExtensions.size();
}

const std::vector<TrapezoidalMap::PointExtension> TrapezoidalMap::getPointExtensions() const
{
    return pointExtensions;
}

std::vector<cg3::Segment2d> TrapezoidalMap::getVerticalSegments() const
{
    std::vector<cg3::Segment2d> verticalSegments;
    for (const TrapezoidalMap::PointExtension& pointExtention : getPointExtensions()) {
        /* upward segment of given point */
        cg3::Point2d upperEndPoint = cg3::Point2d(std::get<1>(pointExtention).x(),std::get<0>(pointExtention));
        verticalSegments.push_back(cg3::Segment2d(upperEndPoint, std::get<1>(pointExtention)));
        /* downward segment of given point */
        cg3::Point2d lowerEndPoint = cg3::Point2d(std::get<1>(pointExtention).x(),std::get<2>(pointExtention));
        verticalSegments.push_back(cg3::Segment2d(std::get<1>(pointExtention), lowerEndPoint));
    }
    return verticalSegments;
}

TrapezoidalMap::PointExtension TrapezoidalMap::getPointExtension(size_t id) const
{
    return pointExtensions[id];
}

const cg3::BoundingBox2& TrapezoidalMap::getBoundingBox() const
{
    return boundingBox;
}

void TrapezoidalMap::clear()
{
    pointExtensions.clear();
    //pointExtensionsMap.clear();
}
