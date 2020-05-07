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

}

/**
 * @brief DrawableTrapezoid::draw
 */
void DrawableTrapezoid::draw() const
{
    size_t trapezoidCount = trapezoidNumber();

    for (const Trapezoid  trapezoid : getTrapezoids()) {
        if(trapezoid.active()){
            std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d> vertices = trapezoid.getVertices();

            /* vertical lines */
            drawVerticalLine(vertices);

            /* trapezoids */
            if(trapezoidCount == trapezoidsCountWhenQuery && trapezoid == *(queryResult)){
                drawTrapezoid(vertices, _queryAreaColor);
            }
            else {
                drawTrapezoid(vertices, FillColor::getFillColor(trapezoid));
            }
        }
        else {
            /* eliminare dalla lista */
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
 * @brief DrawableTrapezoid::storeQueryResult: store pointer to the result trapezoid
 * and number of trapezoid in the map. If another query is executed result change,
 * if a building step is executed, trapezoidCount change.
 * by combining these two parameters, draw() highlights the result only when required.
 * @param result
 */
void DrawableTrapezoid::storeQueryResult(Trapezoid * result)
{
    trapezoidsCountWhenQuery = trapezoidNumber();
    queryResult = result;
}

/**
 * @brief DrawableTrapezoid::drawTrapezoid
 * @param vertices
 */
inline void DrawableTrapezoid::drawTrapezoid(const std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d>& vertices, const QColor& fillColor) const
{
    cg3::opengl::drawQuad2(std::get<0>(vertices), std::get<1>(vertices), std::get<2>(vertices), std::get<3>(vertices), fillColor, 0, true);
}

/**
 * @brief drawVerticalLine
 * @param vertices
 */
inline void DrawableTrapezoid::drawVerticalLine(const std::tuple<cg3::Point2d, cg3::Point2d, cg3::Point2d, cg3::Point2d>& vertices) const
{
    cg3::opengl::drawLine2(std::get<1>(vertices), std::get<2>(vertices), _lineColor, static_cast<int>(1));
    cg3::opengl::drawLine2(std::get<0>(vertices), std::get<3>(vertices), _lineColor, static_cast<int>(1));
}



