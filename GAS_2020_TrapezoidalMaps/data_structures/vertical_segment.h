#ifndef VERTICAL_SEGMENT_H
#define VERTICAL_SEGMENT_H

#include <unordered_map>
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

    /**
     * This type contains the trapezoidalmap_dataset's segment Point  (second parameter) and
     * the value of y respectively of the upward vertical segment's endpoint (first parameter)
     * and the downward vertical segment's endpoint (third parameter)
     */
    typedef std::tuple<double, cg3::Point2d, double> PointExtension;

    VerticalSegment();

    size_t addPointExtensions(const PointExtension pointExtension, bool& extensionsInserted);
    //size_t findPointExtension(const VerticalSegment::PointExtensions& point, bool& found);
    size_t pointExtensionsNumber();
    const std::vector<PointExtension> getPointExtensions() const;
    std::vector<cg3::Segment2d> getVerticalSegments() const;
    PointExtension getPointExtension(size_t id) const;

    const cg3::BoundingBox2& getBoundingBox() const;

    void clear();

private:

    std::vector<PointExtension> pointExtensions;
    //std::unordered_map<PointExtensions, size_t> pointExtensionsMap;

    cg3::BoundingBox2 boundingBox;

};

#endif // VERTICAL_SEGMENT_H
