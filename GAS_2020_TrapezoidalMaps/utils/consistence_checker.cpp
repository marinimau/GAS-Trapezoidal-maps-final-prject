#include "consistence_checker.h"
#define TOLLERANCE 0.01

namespace ConsistenceChecker {

/**
 * @brief equalArea: return true if the sum of areas of the trapezoid inserted
 * is equal to the area of the old trapezoid in the same place.
 * This function is called only if debug mode is active.
 * @param n
 * @param olds
 * @return
 */
bool equalArea(const std::list<Trapezoid>& before, const std::list<Trapezoid>& after)
{
    double before_area = 0, after_area = 0;

    for (auto const& b : before) {
        before_area += b.getArea();
    }

    for (auto const& a : after) {
        after_area += a.getArea();
    }

    return fabs(before_area - after_area) < (std::numeric_limits<double>::epsilon() + TOLLERANCE);
};

}
