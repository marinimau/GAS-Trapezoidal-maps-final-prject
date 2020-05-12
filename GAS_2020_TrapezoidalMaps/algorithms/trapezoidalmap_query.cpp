#include "trapezoidalmap_query.h"

namespace TrapezoidalmapQuery
{

/**
 * @brief findTrapezoidThatContainsPoint: launch point query and extract trapezoid from resulting node
 * @param point
 * @param dag
 * @return
 */
Trapezoid* pointQuery(const cg3::Point2d& point,  Node * startNode, bool& isDegenere, const double& angularCoefficient)
{
    if(startNode != nullptr){
        return (Trapezoid *)((find(startNode, point, isDegenere, angularCoefficient))->value());
    }
    return nullptr;
}

/**
 * @brief find: (recoursive step) find the node associated to the trapezoid that contains the given point
 * @param query
 * @return
 */
Node * find(Node * current, const cg3::Point2d& query, bool& isDegenere, const double& angularCoefficient)
{
    switch (current->type()) {
        case Node::p:
        case Node::q:
            if(query.x() < ((cg3::Point2d *)(current->value()))->x()){
                return find(current->leftChild(), query, isDegenere, angularCoefficient);
            }
            else {
               return find(current->rightChild(), query, isDegenere, angularCoefficient);
            }
            break;
        case Node::s:
            if(fabs(query.y() - PointUtils::evaluateYValue(((cg3::Segment2d *)(current->value()))->p1(), ((cg3::Segment2d *)(current->value()))->p2(), query.x())) <= std::numeric_limits<double>::epsilon()){
                isDegenere = true;
                if(angularCoefficient > 0){
                    return find(current->leftChild(), query, isDegenere, angularCoefficient);
                }
                else {
                    return find(current->rightChild(), query, isDegenere, angularCoefficient);
                }

            }
            if(query.y() >= PointUtils::evaluateYValue(((cg3::Segment2d *)(current->value()))->p1(), ((cg3::Segment2d *)(current->value()))->p2(), query.x())){
                return find(current->leftChild(), query, isDegenere, angularCoefficient);
            }
            else {
                return find(current->rightChild(), query, isDegenere, angularCoefficient);
            }
            break;
        case Node::t:
            return current;
    }
    return nullptr;
}

};
