#include "drawable_trapezoid.h"

#include <cg3/viewer/opengl_objects/opengl_objects2.h>


DrawableTrapezoid::DrawableTrapezoid():
    fillColor(255,255,0),
    boundarySize(0)
{

}

void DrawableTrapezoid::draw() const
{
    for (const cg3::Segment2d& vLine : getVerticalSegments()) {
        cg3::opengl::drawLine2(vLine.p1(), vLine.p2(), fillColor, static_cast<int>(boundarySize));
    }
}

cg3::Point3d DrawableTrapezoid::sceneCenter() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return cg3::Point3d(boundingBox.center().x(), boundingBox.center().y(), 0);
}

double DrawableTrapezoid::sceneRadius() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return boundingBox.diag();
}

const cg3::Color& DrawableTrapezoid::getFillColor() const
{
    return fillColor;
}

void DrawableTrapezoid::setFillColor(const cg3::Color &value)
{
    fillColor = value;
}

unsigned int DrawableTrapezoid::getBoundarySize() const
{
    return boundarySize;
}

void DrawableTrapezoid::setBoundarySize(unsigned int value)
{
    boundarySize = value;
}


