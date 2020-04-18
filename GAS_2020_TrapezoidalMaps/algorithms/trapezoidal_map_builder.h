#ifndef TRAPEZOIDALMAPBUILDER_H
#define TRAPEZOIDALMAPBUILDER_H

#include <vector>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

#include "data_structures/trapezoidalmap.h"
#include "drawables/drawable_vertical_segment.h"
#include "drawables/drawable_trapezoid.h"
#include "utils/point_utils.h"

namespace TrapezoidalMapBuilder {

/* Initialization */
void init(DrawableTrapezoid& drawableTrapezoid, double boundingBoxDimensions);

/* Insertion step */
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid);
cg3::Segment2d normalizeSegment(const cg3::Segment2d& insertedSegment);
std::vector<Trapezoid *> followSegment(const cg3::Segment2d& insertedSegment);
Trapezoid* findTrapezoidThatContainsPoint(cg3::Point2d point, DrawableTrapezoid& drawableTrapezoid);
void createPointExtension(const cg3::Point2d point, DrawableVerticalSegment& drawableVerticalSegment);

/* insertion cases */
void simpleInsertion(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid);

}

#endif // TRAPEZOIDALMAPBUILDER_H
