#ifndef VERTICALSEGMENT_H
#define VERTICALSEGMENT_H

#include <cg3/geometry/bounding_box2.h>
#include "data_structures/trapezoid.h"
#include <list>

class VerticalSegment
{
public:

    /* Constructor */
    VerticalSegment();

    const cg3::BoundingBox2& getBoundingBox() const;

    void setDataSource(std::list<Trapezoid>* source);

    void clear();


protected:

    cg3::BoundingBox2 boundingBox;

    std::list<Trapezoid>* _source;

};

#endif // VERTICALSEGMENT_H
