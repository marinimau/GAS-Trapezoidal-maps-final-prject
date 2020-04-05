#ifndef TRAPEZOIDALMAPBUILDER_H
#define TRAPEZOIDALMAPBUILDER_H

#include <vector>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

#include "data_structures/trapezoidalmap.h"
#include "drawables/drawable_vertical_segment.h"
#include "drawables/drawable_trapezoid.h"

namespace TrapezoidalMapBuilder {

void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid);
void followSegment(const cg3::Segment2d& insertedSegment);
TrapezoidalMap::Trapezoid findTrapezoidThatContainsPoint(cg3::Point2d point, DrawableTrapezoid& drawableTrapezoid);
void createPointExtension(const cg3::Point2d point, DrawableVerticalSegment& drawableVerticalSegment);


}

#endif // TRAPEZOIDALMAPBUILDER_H
