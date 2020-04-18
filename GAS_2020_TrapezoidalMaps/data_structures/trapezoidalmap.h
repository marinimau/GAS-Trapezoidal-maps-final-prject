#ifndef TRAPEZOIDALMAP_H
#define TRAPEZOIDALMAP_H

#include <set>
#include <vector>
#include <utility>

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include <cg3/geometry/bounding_box2.h>
#include "data_structures/trapezoid.h"

/**
 * @brief This class store the verticals segments of the trapezoidal map.
 */
class TrapezoidalMap{

public:

    /**
     * This type contains the vertical extensions of a given point.
     * the first value is the upward segment size (in terms of y-distance from the point)
     * the second value is the point of segment (from trapezoidalmap_dataset)
     * the third value is the downward segment size (in terms of y-distance from the point)
     */
    typedef std::tuple<double, cg3::Point2d, double> PointExtension;


    /* constructors */
    TrapezoidalMap();

    /* vertical segments */
    void addPointExtension(const PointExtension pointExtension);
    size_t pointExtensionsNumber();
    const std::set<PointExtension> getPointExtensionsData() const;
    std::vector<cg3::Segment2d> getVerticalSegments() const;

    /* trapezoids */
    void addTrapezoid(const Trapezoid trapezoid);
    size_t trapezoidNumber() const;
    const std::vector<Trapezoid> getTrapezoids() const;
    Trapezoid getTrapezoidById(size_t id) const;

    /* generic */
    const cg3::BoundingBox2& getBoundingBox() const;
    void clear();

private:

    /* point extensions */
    std::set<PointExtension> pointExtensions;

    /* trapezoids */
    std::vector<Trapezoid> trapezoids;


    cg3::BoundingBox2 boundingBox;

};

#endif // TRAPEZOIDALMAP_H
