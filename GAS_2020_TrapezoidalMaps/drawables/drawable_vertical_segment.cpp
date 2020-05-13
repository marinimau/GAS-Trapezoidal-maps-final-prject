#include "drawable_vertical_segment.h"

#include <cg3/viewer/opengl_objects/opengl_objects2.h>

/**
 * @brief DrawableVerticalSegment::DrawableVerticalSegment
 */
DrawableVerticalSegment::DrawableVerticalSegment():
    segmentColor(255,0,0),
    segmentSize(1)
{

}


/**
 * @brief DrawableVerticalSegment::draw
 */
void DrawableVerticalSegment::draw() const
{
    for (const Trapezoid  trapezoid : *_source) {
        if(trapezoid.active()){
            /* vertical lines */
            std::vector<cg3::Point2d> vertices = trapezoid.getVertices();
            drawVerticalLine(vertices);
        }
    }
}


/**
 * @brief DrawableVerticalSegment::sceneCenter
 * @return
 */
cg3::Point3d DrawableVerticalSegment::sceneCenter() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return cg3::Point3d(boundingBox.center().x(), boundingBox.center().y(), 0);
}


/**
 * @brief DrawableVerticalSegment::sceneRadius
 * @return
 */
double DrawableVerticalSegment::sceneRadius() const
{
    const cg3::BoundingBox2& boundingBox = this->getBoundingBox();
    return boundingBox.diag();
}


/**
 * @brief DrawableVerticalSegment::getSegmentColor
 * @return
 */
const cg3::Color& DrawableVerticalSegment::getSegmentColor() const
{
    return segmentColor;
}


/**
 * @brief DrawableVerticalSegment::setSegmentColor
 * @param value
 */
void DrawableVerticalSegment::setSegmentColor(const cg3::Color& value)
{
    segmentColor = value;
}


/**
 * @brief DrawableVerticalSegment::getSegmentSize
 * @return
 */
unsigned int DrawableVerticalSegment::getSegmentSize() const
{
    return segmentSize;
}


/**
 * @brief DrawableVerticalSegment::setSegmentSize
 * @param value
 */
void DrawableVerticalSegment::setSegmentSize(unsigned int value)
{
    segmentSize = value;
}


/**
 * @brief drawVerticalLine
 * @param vertices
 */
inline void DrawableVerticalSegment::drawVerticalLine(const std::vector<cg3::Point2d>& vertices) const
{
    cg3::opengl::drawLine2(vertices[1], vertices[2], segmentColor, static_cast<int>(1));
    cg3::opengl::drawLine2(vertices[0], vertices[3], segmentColor, static_cast<int>(1));
}


