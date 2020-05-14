#include "consistence_checker.h"
#define TOLLERANCE 0.1
#define BOUNDINGBOX 1e+6

namespace ConsistenceChecker {

/**
 * @brief equalArea: return true if the sum of areas of the trapezoid inserted
 * is equal to the area of the old trapezoid in the same place.
 * This function is called only if debug mode is active.
 * @param n
 * @param olds
 * @return
 */
bool equalArea(const std::list<Trapezoid>& before, const std::list<Trapezoid>& after)
{
    double before_area = 0, after_area = 0;

    for (auto const& b : before) {
        before_area += b.getArea();
    }

    for (auto const& a : after) {
        after_area += a.getArea();
    }

    return fabs(before_area - after_area) < (TOLLERANCE);
};


/**
 * @brief checkForWrongBuildArea: for each trapezoid in build area check if inserted segment cross it. It identifies followSegment errors.
 * This function is called only if debug mode is active.
 * @param insertedSegment
 * @param buildArea
 * @return
 */
bool checkForWrongBuildArea(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea)
{
    for(auto const& b : buildArea){
        if(!checkIntersection(insertedSegment, *b)){
            return false;
        }
    }
    return true;
}


/**
 * @brief checkIntersection: return true if segment has 1 or more points inside polygon
 * @param segment
 * @param polygon
 * @return
 */
bool checkIntersection(const cg3::Segment2d& segment, const Trapezoid& polygon)
{
    /* check if any segment endpoint is inside polygon */
    if(isInside(segment.p1(), polygon) || isInside(segment.p2(), polygon)){
        return true;
    }

    double segmentYAtLeftP = 0;

    /* no endpoints inside polyigon, check for crossing boundary, segment can cross only left or right side of trapezoid
     * (polygon.top and polygon.bottom are segment of trapezoidalmap dataset)
     * If only one side of polygon is crossed, one endpoint of segment is inside of the polygon (checked above)
     * At this step it is possible only a double crossing (left and right side of polygon), for this reason it is sufficient to check only one side. */

    if(polygon.leftP().x() >= segment.p1().x() && polygon.leftP().x() <= segment.p2().x()){
        segmentYAtLeftP = PointUtils::evaluateYValue(segment.p1(), segment.p2(), polygon.leftP().x());
        /* check if segment cross left-side of p */
        if(segmentYAtLeftP <= polygon.getVertex(Trapezoid::topLeft).y() && segmentYAtLeftP >= polygon.getVertex(Trapezoid::bottomLeft).y()){
            return true;
        }
    }
    return false;
}


/**
 * @brief isInside return true if the point is inside the poligon
 * @param point
 * @param polygon
 * @return
 */
bool isInside(const cg3::Point2d& point, const Trapezoid& polygon)
{
    if(point.x() >= polygon.leftP().x() && point.x() <= polygon.rightP().x()){
        if( (PointUtils::evaluateYValue(polygon.top().p1(), polygon.top().p2(), point.x()) >= point.y()) && (PointUtils::evaluateYValue(polygon.bottom().p1(), polygon.bottom().p2(), point.x()) <= point.y()) ){
            return true;
        }
    }
    return false;
}


/**
 * @brief adjacencyOk: check if all adjacency are ok
 * @param allTrapezoids
 * @return
 */
bool adjacencyOk(const std::list<Trapezoid>& allTrapezoids)
{
    for (auto const& t : allTrapezoids) {
        /* if one is upper or lower is null also the other must be null */
        if((t.getAdjacent(Trapezoid::upperLeft) == nullptr || t.getAdjacent(Trapezoid::lowerLeft) == nullptr) && t.leftP().x() != -BOUNDINGBOX){
            if(t.getAdjacent(Trapezoid::upperLeft) != nullptr || t.getAdjacent(Trapezoid::lowerLeft) != nullptr){
                return false;
            }
        }
        if((t.getAdjacent(Trapezoid::upperRight) == nullptr || t.getAdjacent(Trapezoid::lowerRight) == nullptr)  && t.rightP().x() != +BOUNDINGBOX){
            if(t.getAdjacent(Trapezoid::upperRight) != nullptr || t.getAdjacent(Trapezoid::lowerRight) != nullptr){
                return false;
            }
        }
    }
    return true;
}

}
