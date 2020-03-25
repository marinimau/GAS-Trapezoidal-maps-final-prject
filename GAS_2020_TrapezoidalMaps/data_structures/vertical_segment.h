#ifndef VERTICAL_SEGMENT_H
#define VERTICAL_SEGMENT_H

#include <vector>
#include <utility>

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include <cg3/geometry/bounding_box2.h>

/**
 * @brief This class store the verticals segments of the trapezoidal map.
 */
class VerticalSegment{

public:

    VerticalSegment();

    size_t addSegment(const cg3::Segment2d& segment, bool& segmentInserted);
    size_t findSegment(const cg3::Segment2d& segment, bool& found);
    size_t segmentNumber();
    std::vector<cg3::Segment2d> getSegments() const;
    cg3::Segment2d getSegment(size_t id) const;

    void clear();

private:

};

#endif // VERTICAL_SEGMENT_H
