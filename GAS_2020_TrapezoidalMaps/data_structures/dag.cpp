#include "data_structures/dag.h"

/* Constructors */

/**
 * @brief Dag::Dag: constructor, set the root of the Dag.
 * @param root
 */
Dag::Dag(Node root)
{
    _root = root;
}

/**
 * @brief Dag::find: find the node associated to the trapezoid that contains the given point
 * @param query
 * @return
 */
Node * Dag::find(Node * current, const cg3::Point2d query) const
{
    switch (current->type()) {
        case Node::p:
        case Node::q:
            if(query.x() < ((cg3::Point2d *)(current->value()))->x()){
                return Dag::find(current->leftChild(), query);
            }
            else {
               return Dag::find(current->rightChild(), query);
            }
            break;
        case Node::s:
            if(query.y() > PointUtils::evaluateYValue(((cg3::Segment2d *)(current->value()))->p1(), ((cg3::Segment2d *)(current->value()))->p2(), query.x())){
                return Dag::find(current->leftChild(), query);
            }
            else {
                return Dag::find(current->rightChild(), query);
            }
            break;
        case Node::t:
            return current;
    }
    return nullptr;
}


/* Getters */

/**
 * @brief Dag::root: return the root of the dag
 * @return
 */
Node Dag::root() const
{
    return _root;
}

Node * Dag::rootRef()
{
    return &_root;
}

/* Setters */

void Dag::setRoot(Node root)
{
    _root = root;
}




