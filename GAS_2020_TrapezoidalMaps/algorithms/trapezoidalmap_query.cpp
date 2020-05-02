#include "trapezoidalmap_query.h"

namespace TrapezoidalmapQuery
{

/**
 * @brief findTrapezoidThatContainsPoint: given a point returns the trapezoid that contains it
 * @param point
 * @param dag
 * @return
 */
Trapezoid* pointQuery(cg3::Point2d point,  Dag * dag)
{
    if(dag->root() != NULL){
        return (Trapezoid *)((dag->find(dag->root(), point))->value());
    }

    printf("Il dag è vuoto\n");
    return nullptr;
}

};
