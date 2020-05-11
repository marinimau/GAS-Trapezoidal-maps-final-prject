#ifndef FILL_COLOR_H
#define FILL_COLOR_H

#include <cg3/utilities/color.h>
#include <vector>
#include <cg3/geometry/point2.h>
#include <sstream>
#include <string>
#include "data_structures/trapezoid.h"

namespace FillColor {

    cg3::Color getFillColor(const std::vector<cg3::Point2d>& vertices);
}

#endif // FILL_COLOR_H
