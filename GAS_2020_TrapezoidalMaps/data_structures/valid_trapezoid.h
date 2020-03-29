#ifndef CG3_VALID_TRAPEZOID_H
#define CG3_VALID_TRAPEZOID_H

#include "cg3/geometry/polygon2.h"
#include "cg3/geometry/point2.h"

namespace cg3 {

template <class T>
using ValidTrapezoid = ValidTrapezoid<Point2<T>>;

typedef Trapezoid<double> Trapezoid_d;
typedef Trapezoid<float> Trapezoid_f;
typedef Trapezoid<int> Trapezoid_i;

}

#endif // TRAPEZOID_H
