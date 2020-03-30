#include "algorithms/trapezoidal_map_builder.h"

namespace TrapezoidalMapBuilder {

void evaluateSegmentInserted(const cg3::Segment2d insertedSegment, DrawableVerticalSegment& drawableVerticalSegment)
{
    std::vector<cg3::Point2d> interestedPoints;
    bool inserted;
    // 1. check interested points (qua devo ottenere i Point2d)
    // 2. edit point extensions per i punti selezionati

    interestedPoints.push_back(insertedSegment.p1());
    interestedPoints.push_back(insertedSegment.p2());

    for (cg3::Point2d& p : interestedPoints){
        createPointExtension(p, inserted, drawableVerticalSegment);
        //assert(inserted);
    }
}

void createPointExtension(const cg3::Point2d point, bool& inserted, DrawableVerticalSegment& drawableVerticalSegment)
{
    inserted = false;
    VerticalSegment::PointExtension pointExtension = {500, point, -500};
    drawableVerticalSegment.addPointExtensions(pointExtension, inserted);
}

}
