#ifndef FILL_COLOR_H
#define FILL_COLOR_H

#include <QColor>
#include "data_structures/trapezoid.h"

namespace FillColor {

    QColor getFillColor(const Trapezoid& trapezoid);
}

#endif // FILL_COLOR_H
