#include "trapezoidalmap_query.h"

namespace TrapezoidalmapQuery
{

/**
 * @brief findTrapezoidThatContainsPoint: launch point query and extract trapezoid from resulting node
 * @param point
 * @param dag
 * @return
 */
Trapezoid* pointQuery(const cg3::Point2d& point,  Node * startNode, bool& isDegenere, const cg3::Point2d* q)
{
    if(startNode != nullptr){
        return (Trapezoid *)((find(startNode, point, isDegenere, q))->value());
    }
    return nullptr;
}

/**
 * @brief find: (recoursive step) find the node associated to the trapezoid that contains the given point
 * @param query
 * @return
 */
Node * find(Node * current, const cg3::Point2d& query, bool& isDegenere, const cg3::Point2d* q)
{
    switch (current->type()) {
        case Node::p:
        case Node::q:
            /* horizontal split */
            if(query.x() < ((cg3::Point2d *)(current->value()))->x()){
                return find(current->leftChild(), query, isDegenere, q);
            }
            else {
               return find(current->rightChild(), query, isDegenere, q);
            }
            break;
        case Node::s:
            /* vertical split */
            /* check if is a degenerate point */
            if(((cg3::Segment2d *)current->value())->p1() == query){
                isDegenere = true;
                /* in this case there is an ambiguity, to avoid mistaking the trapeze in case of insertion, it is evaluated the position of p2 */
                if(((cg3::Segment2d *)current->value())->p2().y() < PointUtils::evaluateYValue(query, *q, ((cg3::Segment2d *)current->value())->p2().x())){
                    return find(current->leftChild(), query, isDegenere, q);
                }
                else {
                    return find(current->rightChild(), query, isDegenere, q);
                }
            }
            /* the point is not degenerate */
            if(query.y() >= PointUtils::evaluateYValue(((cg3::Segment2d *)(current->value()))->p1(), ((cg3::Segment2d *)(current->value()))->p2(), query.x())){
                return find(current->leftChild(), query, isDegenere, q);
            }
            else {
                return find(current->rightChild(), query, isDegenere, q);
            }
            break;
        case Node::t:
            return current;
    }
    return nullptr;
}

};
