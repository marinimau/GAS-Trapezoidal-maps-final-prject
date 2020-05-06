#include "trapezoidalmap_query.h"

namespace TrapezoidalmapQuery
{

/**
 * @brief findTrapezoidThatContainsPoint: launch point query and extract trapezoid from resulting node
 * @param point
 * @param dag
 * @return
 */
Trapezoid* pointQuery(cg3::Point2d point,  Node * startNode)
{
    if(startNode != nullptr){
        return (Trapezoid *)((find(startNode, point))->value());
    }
    return nullptr;
}

/**
 * @brief find: (recoursive step) find the node associated to the trapezoid that contains the given point
 * @param query
 * @return
 */
Node * find(Node * current, const cg3::Point2d query)
{
    switch (current->type()) {
        case Node::p:
        case Node::q:
            if(query.x() < ((cg3::Point2d *)(current->value()))->x()){
                return find(current->leftChild(), query);
            }
            else {
               return find(current->rightChild(), query);
            }
            break;
        case Node::s:
            if(query.y() >= PointUtils::evaluateYValue(((cg3::Segment2d *)(current->value()))->p1(), ((cg3::Segment2d *)(current->value()))->p2(), query.x())){
                return find(current->leftChild(), query);
            }
            else {
                return find(current->rightChild(), query);
            }
            break;
        case Node::t:
            return current;
    }
    return nullptr;
}

};
