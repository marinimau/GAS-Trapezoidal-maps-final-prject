#ifndef DRAWABLE_VERTICAL_SEGMENT_H
#define DRAWABLE_VERTICAL_SEGMENT_H

#include "data_structures/trapezoidalmap.h"

#include <cg3/viewer/interfaces/drawable_object.h>

#include <cg3/utilities/color.h>

/**
 * @brief Class to draw the vertical segments of the trapezoidal map.
 */
class DrawableVerticalSegment : public TrapezoidalMap, public cg3::DrawableObject
{

public:

    DrawableVerticalSegment();

    void draw() const;
    cg3::Point3d sceneCenter() const;
    double sceneRadius() const;

    const cg3::Color& getSegmentColor() const;
    void setSegmentColor(const cg3::Color& value);

    unsigned int getSegmentSize() const;
    void setSegmentSize(unsigned int value);

private:

    cg3::Color segmentColor;
    unsigned int segmentSize;

};

#endif // DRAWABLE_VERTICAL_SEGMENT_H
