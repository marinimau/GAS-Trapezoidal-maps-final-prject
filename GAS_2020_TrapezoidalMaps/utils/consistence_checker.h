#ifndef CONSISTENCECHECKER_H
#define CONSISTENCECHECKER_H

#include "data_structures/trapezoid.h"
#include <list>

namespace ConsistenceChecker {

bool equalArea(const std::list<Trapezoid *> before, const std::list<Trapezoid *> after);

};

#endif // CONSISTENCECHECKER_H
