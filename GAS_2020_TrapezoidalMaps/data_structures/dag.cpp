#include "data_structures/dag.h"

/* Constructors */

/**
 * @brief Dag::Dag: constructor, set the root of the Dag.
 * @param root
 */
Dag::Dag()
{
    _root = NULL;
}

/**
 * @brief Dag::~Dag: starting recursive desctructor from root
 */
Dag::~Dag()
{
    clear(_root);

}

/**
 * @brief Dag::clear: recursive destructor
 */
void Dag::clear(Node * current)
{
    if(current != NULL){
        if(current->type() != Node::t){
            clear(current->leftChild());
            clear(current->rightChild());
        }
        delete current;
    }
}

/**
 * @brief Dag::clearIntermediateNodes: given a node destroy all its
 * childs except leaf nodes, leafs can be reached by other nodes.
 * @param current
 */
void Dag::clearIntermediateNodes(Node * current)
{
    if(current != NULL && current->type() != Node::t){
        clear(current->leftChild());
        clear(current->rightChild());
        delete current;
    }
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
Node * Dag::root()
{
    return _root;
}

/* Setters */

/**
 * @brief Dag::setRoot: set the root of the dag
 * @param root
 */
void Dag::setRoot(Node * root)
{
    _root = root;
}

/* Debug */

/**
 * @brief inOrderVisit: visit inorder the dag, and print values of the type of the node.
 * @param current
 */
void Dag::inOrderVisit(Node * current)
{
    if(current == nullptr){
        return;
    }
    inOrderVisit(current->leftChild());
    printf(" %d ", current->type());
    inOrderVisit(current->rightChild());
}





