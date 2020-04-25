#ifndef SEGMENTINTERSECTIONCHECKER_H
#define SEGMENTINTERSECTIONCHECKER_H

#include <cg3/data_structures/trees/aabbtree.h>
#include <cg3/geometry/segment2.h>


class SegmentIntersectionChecker {

public:

    typedef cg3::AABBTree<2, cg3::Segment2d> AABBTree;
    typedef AABBTree::KeyOverlapChecker KeyOverlapChecker;

    SegmentIntersectionChecker();

    void insert(const cg3::Segment2d& seg);

    size_t countIntersections(const cg3::Segment2d& seg);
    bool checkIntersections(const cg3::Segment2d& seg);

    size_t countIntersection(const std::vector<cg3::Segment2d>& segVec);
    bool checkIntersections(const std::vector<cg3::Segment2d>& segVec);


    static double aabbValueExtractor(
            const cg3::Segment2d& segment,
            const cg3::AABBValueType& valueType,
            const int& dim);

    static bool checkSegmentIntersection(
            const cg3::Segment2d& seg1, const cg3::Segment2d& seg2);

    void clear();

private:

    AABBTree aabbTree;
    KeyOverlapChecker keyOverlapChecker;

};

#endif // SEGMENTINTERSECTIONCHECKER_H
