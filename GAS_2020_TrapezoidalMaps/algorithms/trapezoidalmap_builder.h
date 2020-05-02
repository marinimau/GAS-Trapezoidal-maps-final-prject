#ifndef TRAPEZOIDALMAPBUILDER_H
#define TRAPEZOIDALMAPBUILDER_H

#include <list>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

#include "algorithms/trapezoidalmap_query.h"
#include "data_structures/trapezoidalmap.h"
#include "data_structures/dag.h"
#include "drawables/drawable_vertical_segment.h"
#include "drawables/drawable_trapezoid.h"
#include "utils/point_utils.h"
#include "utils/consistence_checker.h"

namespace TrapezoidalMapBuilder {

/* Initialization */
Trapezoid boundingBox();

/* Insertion step */
cg3::Segment2d normalizeSegment(const cg3::Segment2d& insertedSegment);
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid, Dag * dag);
std::list<Trapezoid *> followSegment(const cg3::Segment2d& normalizedSegment, Dag * dag);

/* insertion cases */
Node * simpleInsertion(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid);

}

#endif // TRAPEZOIDALMAPBUILDER_H
