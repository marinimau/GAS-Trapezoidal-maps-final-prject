#ifndef TRAPEZOIDALMAPBUILDER_H
#define TRAPEZOIDALMAPBUILDER_H

#include <vector>
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

#include "data_structures/trapezoidalmap.h"
#include "data_structures/dag.h"
#include "drawables/drawable_vertical_segment.h"
#include "drawables/drawable_trapezoid.h"
#include "utils/point_utils.h"
#include "utils/consistence_checker.h"

namespace TrapezoidalMapBuilder {

/* Initialization */
void boundngBox(DrawableTrapezoid& drawableTrapezoid, double boundingBoxDimensions);
void initDag(Dag * dag);

/* Insertion step */
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid, Dag * dag);
cg3::Segment2d normalizeSegment(const cg3::Segment2d& insertedSegment);
std::vector<Trapezoid *> followSegment(const cg3::Segment2d& insertedSegment, Trapezoid * t);
Trapezoid* findTrapezoidThatContainsPoint(cg3::Point2d point,  Dag * dag);
void createPointExtension(const cg3::Point2d point, DrawableVerticalSegment& drawableVerticalSegment);

/* insertion cases */
void simpleInsertion(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid, Node * insertionRoot);

}

#endif // TRAPEZOIDALMAPBUILDER_H
