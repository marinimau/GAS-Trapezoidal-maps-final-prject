#ifndef TRAPEZOIDALMAP_H
#define TRAPEZOIDALMAP_H

#include <unordered_map>
#include <vector>
#include <utility>

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include <cg3/geometry/bounding_box2.h>

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

    /**
     * This type rapresents the trapezoid of the trapezoidal map
     * The polygon is expressed by a Pair of Pair.
     * The 2 outer pair have the same format which is:
     *  - Point extension (see definition above)
     *  - typeOfInvolvement of PointExtension: this because a Point extension
     *    can partecipate to the polygon with its upper extension; its lower
     *    extension or both.
     */
    enum typeOfInvolvement { upper, lower, both};
    typedef std::pair<std::pair<PointExtension, typeOfInvolvement>,std::pair<PointExtension, typeOfInvolvement>> Trapezoid;


    /* constructors */
    TrapezoidalMap();

    /* vertical segments */
    void addPointExtension(const PointExtension pointExtension);
    size_t pointExtensionsNumber();
    const std::vector<PointExtension> getPointExtensionsData() const;
    std::vector<cg3::Segment2d> getVerticalSegments() const;
    PointExtension getPointExtensionById(size_t id) const;

    /* trapezoids */
    void addTrapezoid(const Trapezoid trapezoid);
    size_t trapezoidNumber() const;
    const std::vector<Trapezoid> getTrapezoidsData() const;
    void getPointsByVerticalSegment(const std::pair<PointExtension, typeOfInvolvement>& component, cg3::Point2d& p1, cg3::Point2d& p2) const;
    Trapezoid getTrapezoidById(size_t id) const;

    /* generic */
    const cg3::BoundingBox2& getBoundingBox() const;
    void clear();

private:

    /* point extensions */
    std::vector<PointExtension> pointExtensions;

    /* trapezoids */
    std::vector<Trapezoid> trapezoids;


    cg3::BoundingBox2 boundingBox;

};

#endif // TRAPEZOIDALMAP_H
