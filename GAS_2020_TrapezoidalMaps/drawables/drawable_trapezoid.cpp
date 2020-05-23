#include "drawable_trapezoid.h"

#include <cg3/viewer/opengl_objects/opengl_objects2.h>

/**
 * @brief DrawableTrapezoid::DrawableTrapezoid
 */
DrawableTrapezoid::DrawableTrapezoid():
    _lineColor(255,0,0),
    _queryAreaColor(0,0,255),
    boundarySize(0)
{
    queryResult = nullptr;
}


/**
 * @brief DrawableTrapezoid::draw
 */
void DrawableTrapezoid::draw() const
{
    for (const Trapezoid  trapezoid : getTrapezoids()) {
        if(trapezoid.active()){
            std::vector<cg3::Point2d> vertices = trapezoid.getVertices();

            /* remove degenere vertices */
            PointUtils::removeDegenerate(vertices);

            /* trapezoids */
            if(queryResult != nullptr && trapezoid == *(queryResult)){
                drawTrapezoid(vertices, _queryAreaColor);
            }
            else {
                drawTrapezoid(vertices, FillColor::getFillColor(vertices));
            }
        }
    }
}


/**
 * @brief DrawableTrapezoid::sceneCenter
 * @return
 */
cg3::Point3d DrawableTrapezoid::sceneCenter() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return cg3::Point3d(boundingBox.center().x(), boundingBox.center().y(), 0);
}


/**
 * @brief DrawableTrapezoid::sceneRadius
 * @return
 */
double DrawableTrapezoid::sceneRadius() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return boundingBox.diag();
}


/**
 * @brief DrawableTrapezoid::getFillColor
 * @return
 */
const cg3::Color& DrawableTrapezoid::lineColor() const
{
    return _lineColor;
}


/**
 * @brief DrawableTrapezoid::setFillColor
 * @param value
 */
void DrawableTrapezoid::setLineColor(const cg3::Color &value)
{
    _lineColor = value;
}


/**
 * @brief DrawableTrapezoid::getBoundarySize
 * @return
 */
unsigned int DrawableTrapezoid::getBoundarySize() const
{
    return boundarySize;
}


/**
 * @brief DrawableTrapezoid::setBoundarySize
 * @param value
 */
void DrawableTrapezoid::setBoundarySize(unsigned int value)
{
    boundarySize = value;
}


/**
 * @brief DrawableTrapezoid::drawTrapezoid
 * @param vertices
 */
inline void DrawableTrapezoid::drawTrapezoid(const std::vector<cg3::Point2d>& vertices, const cg3::Color& fillColor) const
{
    assert(vertices.size() == 4 || vertices.size() == 3);
    if (vertices.size() == 4){
         cg3::opengl::drawQuad2((std::array<cg3::Point2d, 4>){vertices[0], vertices[1], vertices[2], vertices[3]}, fillColor, 1, true);
    }
    else {
        cg3::opengl::drawTriangle2(vertices[0], vertices[1], vertices[2], fillColor, 1, true);
    }
}




