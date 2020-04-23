#include "data_structures/dag.h"

/* Constructors */

/**
 * @brief Dag::Dag: constructor, set the root of the Dag.
 * @param root
 */
Dag::Dag(Node * root)
{
    _root = root;
}

/**
 * @brief Dag::find: find the node associated to the trapezoid that contains the given point
 * @param query
 * @return
 */
Node * Dag::find(Node * current, cg3::Point2d query) const
{
    switch (current->type()) {
        case Node::p:
            break;
        case Node::q:
            break;
        case Node::s:
            break;
        case Node::t:
            break;
    }
}


/* Getters */

/**
 * @brief Dag::root: return the root of the dag
 * @return
 */
Node * Dag::root() const
{
    return _root;
}





