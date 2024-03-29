#ifndef DRAWABLE_TRAPEZOID_H
#define DRAWABLE_TRAPEZOID_H

#include "data_structures/trapezoidalmap.h"

#include <cg3/viewer/interfaces/drawable_object.h>

#include <cg3/utilities/color.h>
#include "utils/fill_color.h"

/**
 * @brief Class to draw the trapezoids of the trapezoidal map.
 * I had use 2 different drawable for manage indipendetely
 * vertical segments and trapezoids from the manager UI.
 */
class DrawableTrapezoid : public TrapezoidalMap, public cg3::DrawableObject
{

public:

    DrawableTrapezoid();

    void draw() const;
    cg3::Point3d sceneCenter() const;
    double sceneRadius() const;

    const cg3::Color& lineColor() const;
    void setLineColor(const cg3::Color& value);

    unsigned int getBoundarySize() const;
    void setBoundarySize(unsigned int value);

    inline void drawTrapezoid(const std::vector<cg3::Point2d>& vertices, const cg3::Color& fillColor) const;

private:

    cg3::Color _lineColor;
    cg3::Color _queryAreaColor;
    unsigned int boundarySize;

};

#endif // DRAWABLE_TRAPEZOID_H
