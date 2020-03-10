#ifndef TRAPEZOIDALMAP_DATASET_H
#define TRAPEZOIDALMAP_DATASET_H

#include <unordered_map>
#include <vector>
#include <utility>

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include <cg3/geometry/bounding_box2.h>

#include "data_structures/segment_intersection_checker.h"

/**
 * @brief This class allows to store segments, with indexed non-duplicates point.
 * Every segment is unique, non-degenerate, with points in general position, and
 * it does not have any intersections with the other segments.
 */
class TrapezoidalMapDataset {

public:

    typedef std::pair<size_t, size_t> IndexedSegment2d;

    TrapezoidalMapDataset();

    size_t addPoint(const cg3::Point2d& point, bool& pointInserted);
    size_t addSegment(const cg3::Segment2d& segment, bool& segmentInserted);
    size_t addIndexedSegment(const IndexedSegment2d& segment, bool& segmentInserted);

    size_t findPoint(const cg3::Point2d& point, bool& found);
    size_t findSegment(const cg3::Segment2d& segment, bool& found);
    size_t findIndexedSegment(const IndexedSegment2d& indexedSegment, bool& found);

    size_t pointNumber();
    size_t segmentNumber();

    const std::vector<cg3::Point2d>& getPoints() const;
    cg3::Point2d& getPoint(size_t id);
    const cg3::Point2d& getPoint(size_t id) const;

    std::vector<cg3::Segment2d> getSegments() const;
    cg3::Segment2d getSegment(size_t id) const;

    const std::vector<IndexedSegment2d>& getIndexedSegments() const;
    const IndexedSegment2d& getIndexedSegment(size_t id) const;
    IndexedSegment2d& getIndexedSegments(size_t id);

    const cg3::BoundingBox2& getBoundingBox() const;

    void clear();

private:

    std::vector<cg3::Point2d> points;
    std::vector<IndexedSegment2d> indexedSegments;

    std::unordered_map<cg3::Point2d, size_t> pointMap;
    std::unordered_map<IndexedSegment2d, size_t> segmentMap;
    std::unordered_set<double> xCoordSet;

    cg3::BoundingBox2 boundingBox;

    SegmentIntersectionChecker intersectionChecker;

};


#endif // TRAPEZOIDALMAP_DATASET_H
