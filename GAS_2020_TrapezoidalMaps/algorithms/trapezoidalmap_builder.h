#ifndef TRAPEZOIDALMAPBUILDER_H
#define TRAPEZOIDALMAPBUILDER_H

#include <list>
#include <vector>
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
Trapezoid * boundingBox();
void init(DrawableTrapezoid& drawableTrapezoid, Dag * dag);

/* Insertion step */
cg3::Segment2d normalizeSegment(const cg3::Segment2d& insertedSegment);
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid, Dag * dag);
std::vector<Trapezoid *> followSegment(const cg3::Segment2d& normalizedSegment, Dag * dag);
Node * find(Node * current, const cg3::Point2d query);
Node * createLeafNode(Trapezoid * t);

/* insertion cases */
Node * simpleInsertion(const cg3::Segment2d insertedSegment, Trapezoid * buildArea, DrawableTrapezoid& drawableTrapezoid);
Node * twoInterestedTrapezoidInsertion(const cg3::Segment2d insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid);

Node * leftOfMultipleInsertion(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid);
Node * intermediateOfMultiple(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid);
Node * rightOfMultipleInsertion(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid);

/* Neighbor Adjacency */
void setNeighborOfNeighborLeftSide(Trapezoid * insertedLeft, Trapezoid * buildArea);
void setNeighborOfNeighborRightSide(Trapezoid * inseretedRight, Trapezoid * buildArea);

}

#endif // TRAPEZOIDALMAPBUILDER_H
