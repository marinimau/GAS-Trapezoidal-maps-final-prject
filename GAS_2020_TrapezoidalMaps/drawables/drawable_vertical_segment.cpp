#include "drawable_vertical_segment.h"

#include <cg3/viewer/opengl_objects/opengl_objects2.h>


DrawableVerticalSegment::DrawableVerticalSegment():
    segmentColor(255,0,0),
    segmentSize(1)
{

}

void DrawableVerticalSegment::draw() const
{
    for (const Trapezoid * trapezoid : getTrapezoids()) {
        std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d> vertices = trapezoid->getVertices(); // topRight, topLeft, bottomLeft, bottomRight
        cg3::opengl::drawLine2(std::get<1>(vertices), std::get<2>(vertices), segmentColor, static_cast<int>(segmentSize));
        cg3::opengl::drawLine2(std::get<0>(vertices), std::get<3>(vertices), segmentColor, static_cast<int>(segmentSize));
    }
}

cg3::Point3d DrawableVerticalSegment::sceneCenter() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return cg3::Point3d(boundingBox.center().x(), boundingBox.center().y(), 0);
}

double DrawableVerticalSegment::sceneRadius() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return boundingBox.diag();
}

const cg3::Color& DrawableVerticalSegment::getSegmentColor() const
{
    return segmentColor;
}

void DrawableVerticalSegment::setSegmentColor(const cg3::Color& value)
{
    segmentColor = value;
}

unsigned int DrawableVerticalSegment::getSegmentSize() const
{
    return segmentSize;
}

void DrawableVerticalSegment::setSegmentSize(unsigned int value)
{
    segmentSize = value;
}


