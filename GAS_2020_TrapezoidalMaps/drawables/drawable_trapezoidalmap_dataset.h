#ifndef DRAWABLE_TRAPEZOIDALMAP_DATASET_H
#define DRAWABLE_TRAPEZOIDALMAP_DATASET_H

#include "data_structures/trapezoidalmap_dataset.h"

#include <cg3/viewer/interfaces/drawable_object.h>

#include <cg3/utilities/color.h>

/**
 * @brief Class to draw the segment container.
 */
class DrawableTrapezoidalMapDataset : public TrapezoidalMapDataset, public cg3::DrawableObject
{

public:

    DrawableTrapezoidalMapDataset();

    void draw() const;
    cg3::Point3d sceneCenter() const;
    double sceneRadius() const;

    const cg3::Color& getPointColor() const;
    void setPointColor(const cg3::Color& value);

    const cg3::Color& getSegmentColor() const;
    void setSegmentColor(const cg3::Color& value);

    unsigned int getPointSize() const;
    void setPointSize(unsigned int value);

    unsigned int getSegmentSize() const;
    void setSegmentSize(unsigned int value);

private:

    cg3::Color pointColor;
    cg3::Color segmentColor;

    unsigned int pointSize;
    unsigned int segmentSize;

};

#endif // DRAWABLE_TRAPEZOIDALMAP_DATASET_H
