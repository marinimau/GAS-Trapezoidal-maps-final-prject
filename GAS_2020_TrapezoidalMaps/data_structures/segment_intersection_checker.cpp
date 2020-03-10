#include "segment_intersection_checker.h"

#include <cg3/geometry/intersections2.h>

SegmentIntersectionChecker::SegmentIntersectionChecker()
    : aabbTree(&aabbValueExtractor),
      keyOverlapChecker(&checkSegmentIntersection)
{

}

void SegmentIntersectionChecker::insert(const cg3::Segment2d& seg) {
    aabbTree.insert(seg);
}

size_t SegmentIntersectionChecker::countIntersections(const cg3::Segment2d& seg) {
    std::vector<cg3::AABBTree<2, cg3::Segment2d>::iterator> out;
    aabbTree.aabbOverlapQuery(seg, std::back_inserter(out), this->keyOverlapChecker);
    return out.size();
}

bool SegmentIntersectionChecker::checkIntersections(const cg3::Segment2d& seg) {
    return aabbTree.aabbOverlapCheck(seg, this->keyOverlapChecker);
}

size_t SegmentIntersectionChecker::countIntersection(const std::vector<cg3::Segment2d>& segVec) {
    size_t result = 0;
    for (const cg3::Segment2d& seg : segVec) {
        std::vector<cg3::AABBTree<2, cg3::Segment2d>::iterator> out;
        aabbTree.aabbOverlapQuery(seg, std::back_inserter(out), this->keyOverlapChecker);
        result += out.size();
    }
    return result;
}

bool SegmentIntersectionChecker::checkIntersections(const std::vector<cg3::Segment2d>& segVec) {
    for (const cg3::Segment2d& seg : segVec) {
        if (aabbTree.aabbOverlapCheck(seg, this->keyOverlapChecker)) {
            return true;
        }
    }
    return false;
}

double SegmentIntersectionChecker::aabbValueExtractor(
        const cg3::Segment2d& segment,
        const cg3::AABBValueType& valueType,
        const int& dim)
{
    if (valueType == cg3::AABBValueType::MIN) {
        switch (dim) {
        case 1:
            return static_cast<double>(std::min(segment.p1().x(), segment.p2().x()));
        case 2:
            return static_cast<double>(std::min(segment.p1().y(), segment.p2().y()));
        }
    }
    else if (valueType == cg3::AABBValueType::MAX) {
        switch (dim) {
        case 1:
            return static_cast<double>(std::max(segment.p1().x(), segment.p2().x()));
        case 2:
            return static_cast<double>(std::max(segment.p1().y(), segment.p2().y()));
        }
    }
    throw new std::runtime_error("Impossible to extract an AABB value.");
}


bool SegmentIntersectionChecker::checkSegmentIntersection(const cg3::Segment2d& seg1, const cg3::Segment2d& seg2)
{
    return cg3::checkSegmentIntersection2(seg1, seg2, true);
}

void SegmentIntersectionChecker::clear()
{
    aabbTree.clear();
}
