#include "drawable_trapezoid.h"

#include <cg3/viewer/opengl_objects/opengl_objects2.h>


DrawableTrapezoid::DrawableTrapezoid():
    fillColor(255,255,0),
    boundarySize(0)
{

}

void DrawableTrapezoid::draw() const
{
    cg3::Point2d topLeft, bottomLeft, topRight, bottomRight;
    for (const Trapezoid& trapezoid : getTrapezoids()) {
        std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d> points = trapezoid.getVertices();
        cg3::opengl::drawQuad2(std::get<0>(points), std::get<1>(points), std::get<2>(points), std::get<3>(points), FillColor::getRandomColor(), 0, true);
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


