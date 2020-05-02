#include "fill_color.h"

#define BASE 200
#define CONTRAST 40
#define MUL 3

namespace FillColor {

/**
 * @brief getFillColor: return a QColor to fill the trapezoid, the color is calculated through
 * 3 simple pseudo hash functions using some parameters of the trapezoid itself.
 * This beacause if I used a random function, the color of each trapezoid would change with each step.
 * @param trapezoid
 * @return
 */
QColor getFillColor(const Trapezoid& trapezoid)
{
   int color[3];

   assert(BASE + CONTRAST < 255);

   color[0] = BASE + (static_cast<int>(trapezoid.top().p1().y())*MUL % CONTRAST);
   color[1] = BASE + (static_cast<int>(trapezoid.leftP().x() + trapezoid.top().p1().y()) % CONTRAST);
   color[2] = BASE + (static_cast<int>(trapezoid.rightP().y() - trapezoid.bottom().p2().x())*MUL % CONTRAST);

   QColor fillColor = QColor();
   fillColor.setRgb(color[0], color[1], color[2]);

   return fillColor;

}

}
