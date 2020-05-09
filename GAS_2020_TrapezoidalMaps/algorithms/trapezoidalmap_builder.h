#ifndef TRAPEZOIDALMAPBUILDER_H
#define TRAPEZOIDALMAPBUILDER_H

#include <list>
#include <vector>
#include <tuple>
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
void init(DrawableTrapezoid& drawableTrapezoid, Dag * dag);

/* Insertion step */
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid, Dag * dag);
cg3::Segment2d normalizeSegment(const cg3::Segment2d& insertedSegment);
std::vector<Trapezoid *> followSegment(const cg3::Segment2d& normalizedSegment, Dag * dag);
Node * createLeafNode(Trapezoid * t, Dag * dag);

Node * find(Node * current, const cg3::Point2d query);

/* insertion cases */
void simpleInsertion(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, Dag * dag);
void twoInterestedTrapezoidsInsertion(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, Dag * dag);

/* Trapezoid creation step */
/* General */
std::tuple<Trapezoid *, Trapezoid *> addLeftAndRightTrapezoid(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid);
Trapezoid * addLeftTrapezoid(const cg3::Segment2d& insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid);
Trapezoid * addRightTrapezoid(const cg3::Segment2d& insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid);

/* Center trapezoids in 2 interested trapezoid insertion case */
std::tuple<Trapezoid *, Trapezoid *, Trapezoid *> twoInterestedTrapezoidsBuldCenterTrapezoids(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, bool& segmentAboveRightP);

/* Adjacency steps */

/* simple case (1 interested trapezoid) */
void simpleCaseBuildAdjacency(Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenterTop, Trapezoid * tCenterBottom, const Trapezoid& buildArea);
void simpleCaseAdjacencyLeft(Trapezoid * tLeft, Trapezoid * tCenterBottom, Trapezoid * tCenterTop, const Trapezoid & buildArea);
void simpleCaseAdjacencyRight(Trapezoid * tRight, Trapezoid * tCenterBottom, Trapezoid * tCenterTop, const Trapezoid & buildArea);

/* Neighbor Adjacency step */
void setNeighborOfNeighborLeftSide(Trapezoid * insertedLeftUpper, Trapezoid * insertedLeftLower, const Trapezoid& buildArea);
void setNeighborOfNeighborRightSide(Trapezoid * inseretedRightUpper, Trapezoid * insertedRightLower, const Trapezoid& buildArea);

/* Dag update */
void simpleCaseDagUpdate(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenterTop, Trapezoid * tCenterBottom, Trapezoid * buildArea, Dag * dag);
void twoInterestedTrapezoidsDagUpdate(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenter1, Trapezoid * tCenter2, Trapezoid * tCenter3, std::vector<Trapezoid *>& buildArea, Dag * dag, const bool& segmentAboveRightP);
}

#endif // TRAPEZOIDALMAPBUILDER_H
