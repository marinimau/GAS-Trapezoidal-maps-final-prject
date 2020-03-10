#include "trapezoidalmap_dataset.h"

TrapezoidalMapDataset::TrapezoidalMapDataset() :
    boundingBox(cg3::Point2d(0,0),cg3::Point2d(0,0))
{

}

size_t TrapezoidalMapDataset::addPoint(const cg3::Point2d& point, bool& pointInserted)
{
    bool found;
    size_t id = findPoint(point, found);

    pointInserted = false;

    bool generalPosition = true;
    if (xCoordSet.find(point.x()) != xCoordSet.end()) {
        generalPosition = false;
    }

    //Point will be inserted
    if (!found && generalPosition) {
        pointInserted = true;

        id = points.size();

        //Add point
        points.push_back(point);

        pointMap.insert(std::make_pair(point, id));
        xCoordSet.insert(point.x());

        //Update bounding box
        boundingBox.setMax(cg3::Point2d(
                std::max(point.x(), boundingBox.max().x()),
                std::max(point.y(), boundingBox.max().y())));
        boundingBox.setMin(cg3::Point2d(
                std::min(point.x(), boundingBox.min().x()),
                std::min(point.y(), boundingBox.min().y())));
    }

    return id;
}

size_t TrapezoidalMapDataset::addSegment(const cg3::Segment2d& segment, bool& segmentInserted)
{
    size_t id;

    bool found;
    findSegment(segment, found);

    bool degenerate = segment.p1() == segment.p2();

    segmentInserted = false;
    id = std::numeric_limits<size_t>::max();

    if (!degenerate && !found) {
        bool generalPosition = true;

        bool foundPoint1;
        size_t id1 = findPoint(segment.p1(), foundPoint1);
        bool foundPoint2;
        size_t id2 = findPoint(segment.p2(), foundPoint2);

        if (!foundPoint1 && xCoordSet.find(segment.p1().x()) != xCoordSet.end()) {
            generalPosition = false;
        }
        if (!foundPoint2 && xCoordSet.find(segment.p2().x()) != xCoordSet.end()) {
            generalPosition = false;
        }

        if (generalPosition) {
            bool intersecting = intersectionChecker.checkIntersections(segment);

            if (!intersecting) {
                segmentInserted = true;

                id = indexedSegments.size();

                if (!foundPoint1) {
                    bool insertedPoint1;
                    id1 = addPoint(segment.p1(), insertedPoint1);
                    assert(insertedPoint1);
                }

                if (!foundPoint2) {
                    bool insertedPoint2;
                    id2 = addPoint(segment.p2(), insertedPoint2);
                    assert(insertedPoint2);
                }
                assert(id1 != id2 && id1 < points.size() && id2 < points.size());

                indexedSegments.push_back(IndexedSegment2d(id1, id2));

                segmentMap.insert(std::make_pair(IndexedSegment2d(id1, id2), id));

                intersectionChecker.insert(segment);
            }
        }
    }

    return id;
}

size_t TrapezoidalMapDataset::addIndexedSegment(const IndexedSegment2d& indexedSegment, bool& segmentInserted)
{
    bool found;
    size_t id;

    findIndexedSegment(indexedSegment, found);

    segmentInserted = false;
    id = std::numeric_limits<size_t>::max();

    bool degenerate = indexedSegment.first == indexedSegment.second;

    if (!degenerate && !found) {
        bool intersecting = intersectionChecker.checkIntersections(cg3::Segment2d(points[indexedSegment.first], points[indexedSegment.second]));

        if (!intersecting) {
            segmentInserted = true;

            id = indexedSegments.size();

            indexedSegments.push_back(IndexedSegment2d(indexedSegment.first, indexedSegment.second));

            segmentMap.insert(std::make_pair(IndexedSegment2d(indexedSegment.first, indexedSegment.second), id));

            intersectionChecker.insert(cg3::Segment2d(points[indexedSegment.first], points[indexedSegment.second]));
        }
    }

    return id;
}

size_t TrapezoidalMapDataset::findPoint(const cg3::Point2d &point, bool &found)
{
    std::unordered_map<cg3::Point2d, size_t>::iterator it = pointMap.find(point);

    //Point already in the data structure
    if (it != pointMap.end()) {
        found = true;
        return it->second;
    }
    //Point not in the data structure
    else {
        found = false;
        return std::numeric_limits<size_t>::max();
    }
}

size_t TrapezoidalMapDataset::findSegment(const cg3::Segment2d& segment, bool& found)
{
    found = false;

    bool foundPoint1;
    size_t id1 = findPoint(segment.p1(), foundPoint1);
    if (!foundPoint1)
        return std::numeric_limits<size_t>::max();

    bool foundPoint2;
    size_t id2 = findPoint(segment.p2(), foundPoint2);
    if (!foundPoint2)
        return std::numeric_limits<size_t>::max();

    return findIndexedSegment(IndexedSegment2d(id1, id2), found);
}

size_t TrapezoidalMapDataset::findIndexedSegment(const IndexedSegment2d& indexedSegment, bool& found)
{
    std::unordered_map<IndexedSegment2d, size_t>::iterator it = segmentMap.find(indexedSegment);

    //Segment already in the data structure
    if (it != segmentMap.end()) {
        found = true;
        return it->second;
    }
    //Segment not in the data structure
    else {
        found = false;
        return std::numeric_limits<size_t>::max();
    }
}

size_t TrapezoidalMapDataset::pointNumber()
{
    return points.size();
}

size_t TrapezoidalMapDataset::segmentNumber()
{
    return indexedSegments.size();
}

const std::vector<cg3::Point2d>& TrapezoidalMapDataset::getPoints() const
{
    return points;
}

cg3::Point2d& TrapezoidalMapDataset::getPoint(size_t id)
{
    return points[id];
}

const cg3::Point2d& TrapezoidalMapDataset::getPoint(size_t id) const
{
    return points[id];
}

std::vector<cg3::Segment2d> TrapezoidalMapDataset::getSegments() const
{
    std::vector<cg3::Segment2d> segments;
    for (size_t i = 0; i < indexedSegments.size(); i++) {
        segments.push_back(getSegment(i));
    }
    return segments;
}

cg3::Segment2d TrapezoidalMapDataset::getSegment(size_t id) const
{
    return cg3::Segment2d(points[indexedSegments[id].first], points[indexedSegments[id].second]);
}

const std::vector<TrapezoidalMapDataset::IndexedSegment2d> &TrapezoidalMapDataset::getIndexedSegments() const
{
    return indexedSegments;
}

const TrapezoidalMapDataset::IndexedSegment2d &TrapezoidalMapDataset::getIndexedSegment(size_t id) const
{
    return indexedSegments[id];
}

TrapezoidalMapDataset::IndexedSegment2d &TrapezoidalMapDataset::getIndexedSegments(size_t id)
{
    return indexedSegments[id];
}

const cg3::BoundingBox2& TrapezoidalMapDataset::getBoundingBox() const
{
    return boundingBox;
}

void TrapezoidalMapDataset::clear()
{
    points.clear();
    indexedSegments.clear();
    pointMap.clear();
    segmentMap.clear();
    xCoordSet.clear();
    boundingBox.setMin(cg3::Point2d(0,0));
    boundingBox.setMax(cg3::Point2d(0,0));
    intersectionChecker.clear();
}
