#include "fill_color.h"

#define BASE 200
#define CONTRAST 37

namespace FillColor {

/**
 * @brief getFillColor: return a Color to fill the trapezoid, the color is calculated through
 * 3 simple pseudo hash functions based on vertices.
 * This beacause if I used a random function, the color of each trapezoid would change with each step.
 * @param trapezoid
 * @return
 */
cg3::Color getFillColor(const std::vector<cg3::Point2d>& vertices)
{
   int color[3];

   assert(BASE + CONTRAST < 255);

   std::ostringstream strs;
   strs << vertices[0].x();
   std::string str = strs.str();
   int randomIndex = (int)str.back();

   color[(randomIndex % 3)] = BASE + (static_cast<int>(vertices[0].x() + vertices[1].x() + vertices[2].x()) % CONTRAST);
   color[((randomIndex + 1) % 3)] = BASE + (static_cast<int>(vertices[0].y() + vertices[1].y() + vertices[2].y()) % CONTRAST);
   color[((randomIndex + 2) % 3)] = BASE + (static_cast<int>(vertices[0].y() + 2 * vertices[1].x() - vertices[2].x()) % CONTRAST);

   cg3::Color fillColor = cg3::Color(color[0], color[1], color[2]);

   return fillColor;

}

}
