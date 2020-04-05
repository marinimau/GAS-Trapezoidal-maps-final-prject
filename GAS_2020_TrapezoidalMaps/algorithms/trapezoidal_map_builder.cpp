#include "algorithms/trapezoidal_map_builder.h"

#define BOUNDINGBOX 1e+6

namespace TrapezoidalMapBuilder {

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

void followSegment(const cg3::Segment2d& insertedSegment, DrawableTrapezoid& drawableTrapezoid)
{
    cg3::Point2d p, q;

    /* 1. Assing p and q based on x_coordinates */
    if(insertedSegment.p1().x()<insertedSegment.p2().x()){
        p = insertedSegment.p1();
        q = insertedSegment.p2();
    }
    else {
        p = insertedSegment.p2();
        q = insertedSegment.p1();
    }

    /* 2 Find the trapezoid that contains p */
    TrapezoidalMap::Trapezoid t0 =  findTrapezoidThatContainsPoint(p, drawableTrapezoid);

}

TrapezoidalMap::Trapezoid findTrapezoidThatContainsPoint(cg3::Point2d point, DrawableTrapezoid& drawableTrapezoid)
{

}

void createPointExtension(const cg3::Point2d point, DrawableVerticalSegment& drawableVerticalSegment)
{
    //find upper intersection
    double upper = BOUNDINGBOX;
    double lower = -BOUNDINGBOX;
    TrapezoidalMap::PointExtension pointExtension = {upper, point, lower};
    drawableVerticalSegment.addPointExtension(pointExtension);
}

}
