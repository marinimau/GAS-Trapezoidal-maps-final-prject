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
    clear();

}

/**
 * @brief Dag::clear: recursive destructor
 */
void Dag::clear()
{
    _root = nullptr;
    nodes.clear();
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

/* Others */

/**
 * @brief addNode
 * @param node
 * @return
 */
Node * Dag::addNode(Node node)
{
    nodes.push_back(node);
    return &nodes.back();

}

/**
 * @brief Dag::deleteLeaf
 * @param trapezoid
 */
void Dag::deleteLeaf(Node * leaf)
{

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





