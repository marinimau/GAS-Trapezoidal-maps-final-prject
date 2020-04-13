#include "algorithms/trapezoidal_map_builder.h"

#define BOUNDINGBOX 1e+6

namespace TrapezoidalMapBuilder {

/**
 * @brief evaluateSegmentInserted: incremental step
 * @param insertedSegment
 * @param drawableVerticalSegment
 * @param drawableTrapezoid
 */
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid)
{
    std::vector<cg3::Point2d> interestedPoints;

    /* 1. check interested trapezoids */

    /* 2. for each trapezoid in interest trapezoid */

        // 2.1. interested_points = get point extension
        // 2.2  delete trapezoid from map

    /* 4. edit point extensions per i punti selezionati */

    interestedPoints.push_back(insertedSegment.p1());
    interestedPoints.push_back(insertedSegment.p2());

    for (cg3::Point2d& p : interestedPoints){
        createPointExtension(p, drawableVerticalSegment);
    }
}


/**
 * @brief followSegment: return all the trapezoids intersected by the new segment.
 * @param insertedSegment
 * @param drawableTrapezoid
 */
std::vector<Trapezoid *> followSegment(const cg3::Segment2d& insertedSegment, DrawableTrapezoid& drawableTrapezoid)
{
    cg3::Point2d p, q;
    std::vector<Trapezoid *> interestedTrapezoids;

    /* 1. Assign p and q based on x_coordinates */
    if(insertedSegment.p1().x()<insertedSegment.p2().x()){
        p = insertedSegment.p1();
        q = insertedSegment.p2();
    }
    else {
        p = insertedSegment.p2();
        q = insertedSegment.p1();
    }

    /* 2. Find the trapezoid that contains p */
    Trapezoid* t =  findTrapezoidThatContainsPoint(p, drawableTrapezoid);

    /* 3. Check iteratively if rightP of t is interested */
    while (q.x() < t->rightP().x()){

        interestedTrapezoids.push_back(t);

        double yAtRightP = PointUtils::evaluateYValue(p, q, t->rightP().x());

        if (t->rightP().y() > yAtRightP){
            t = t->getdAjacent(Trapezoid::lowerRight);
        }
        else {
            t = t->getdAjacent(Trapezoid::lowerRight);
        }
    }

    return interestedTrapezoids;

}

/**
 * @brief findTrapezoidThatContainsPoint: given a point, returns the trapezoid that contains it.
 * @param point
 * @param drawableTrapezoid
 * @return
 */
Trapezoid* findTrapezoidThatContainsPoint(cg3::Point2d point, DrawableTrapezoid& drawableTrapezoid)
{

}
/**
 * @brief createPointExtension: given a point create the 2 extensions associated with that point.
 * @param point
 * @param drawableVerticalSegment
 */
void createPointExtension(const cg3::Point2d point, DrawableVerticalSegment& drawableVerticalSegment)
{
    //find upper intersection
    double upper = BOUNDINGBOX;
    double lower = -BOUNDINGBOX;
    TrapezoidalMap::PointExtension pointExtension = {upper, point, lower};
    drawableVerticalSegment.addPointExtension(pointExtension);
}

}
