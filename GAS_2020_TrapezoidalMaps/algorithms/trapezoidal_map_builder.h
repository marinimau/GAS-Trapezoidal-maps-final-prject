#ifndef TRAPEZOIDALMAPBUILDER_H
#define TRAPEZOIDALMAPBUILDER_H

#include <vector>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

#include "data_structures/trapezoidal_map.h"
#include "drawables/drawable_vertical_segment.h"

namespace TrapezoidalMapBuilder {

void evaluateSegmentInserted(const cg3::Segment2d insertedSegment, DrawableVerticalSegment& drawableVerticalSegment);
void createPointExtension(const cg3::Point2d point, bool& inserted, DrawableVerticalSegment& drawableVerticalSegment);


}

#endif // TRAPEZOIDALMAPBUILDER_H
