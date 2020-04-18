#include "fill_color.h"

#define BASE 200
#define CONTRAST 40

namespace FillColor {

   QColor getFillColor(const Trapezoid& trapezoid)
   {
       int color[3];

       assert(BASE + CONTRAST -1 <= 255);

       /* like 3 hash functions: this is beacuse the color of single trapezoid must not change at each step  */
       color[0] = BASE + (static_cast<int>(trapezoid.top().p1().y()) % CONTRAST);
       color[1] = BASE + (static_cast<int>(trapezoid.leftP().x() + trapezoid.top().p1().y()) % CONTRAST);
       color[2] = BASE + (static_cast<int>(trapezoid.rightP().y()) % CONTRAST);

       QColor fillColor = QColor();
       fillColor.setRgb(color[0], color[1], color[2]);

       return fillColor;

   }

}
