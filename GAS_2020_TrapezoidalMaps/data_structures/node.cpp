#include "node.h"

/* Constructors */

/**
 * @brief Node::Node: default constructor
 */
Node::Node(){
    _type = Node::t;
    _value = nullptr;
    _leftChild = nullptr;
    _rightChild = nullptr;
}

/**
 * @brief Node::Node: costructor for a trapezoid node
 * @param trapezoid
 */
Node::Node(Trapezoid * trapezoid)
{
    _type = Node::t;
    _value = (void *)trapezoid;
    _leftChild = nullptr;
    _rightChild = nullptr;
}

/**
 * @brief Node::Node: constructor for a segment node
 * @param segment
 */
Node::Node(cg3::Segment2d * segment)
{
    _type = Node::s;
    _value = (void *)segment;
    _leftChild = nullptr;
    _rightChild = nullptr;
}

/**
 * @brief Node::Node: constructor for a point node (p or q)
 * @param point
 */
Node::Node(const Node::nodeType& type, cg3::Point2d * point)
{
    assert(type == Node::p || type == Node::q);
    _type = type;
    _value = (void *)point;
    _leftChild = nullptr;
    _rightChild = nullptr;
}

/* Destructors */

/**
 * @brief Node::~Node default destructor
 */
Node::~Node()
{

}

/* Getters */
/**
 * @brief value, return value of the node
 * @return
 */
void * Node::value() const
{
    return _value;
}

/**
 * @brief Node::type: return the type of the node
 * @return
 */
Node::nodeType Node::type() const
{
    return _type;
}

/**
 * @brief Node::leftChild: return the left child of current node
 * @return
 */
Node * Node::leftChild() const
{
    return _leftChild;
}

/**
 * @brief Node::rightChild: return the right child of the current node
 * @return
 */
Node * Node::rightChild() const
{
    return _rightChild;
}

/* Setters */

/**
 * @brief Node::setValue: set the value of the node (for leaf node)
 * @param trapezoid
 */
void Node::setValue(Trapezoid * trapezoid)
{
    _type = Node::t;
    _value = trapezoid;
}

/**
 * @brief Node::setValue set the value of the node (for segment node)
 * @param segment
 */
void Node::setValue(cg3::Segment2d * segment)
{
    _type = Node::s;
    _value = segment;
}

/**
 * @brief Node::setValue set the value of the node (for point node)
 * @param type
 * @param segment
 */
void Node::setValue(const Node::nodeType type, cg3::Point2d * point)
{
    assert(type == Node::p || type == Node::q);
    _type = type;
    _value = point;
}

/**
 * @brief setLeftChild: set the left child of the node
 * @param left_child
 */
void Node::setLeftChild(Node * left_child)
{
    assert(_type != Node::t);
    _leftChild = left_child;
}

/**
 * @brief setLeftChild: set the right child of the node
 * @param left_child
 */
void Node::setRightChild(Node * right_child)
{
    assert(_type != Node::t);
    _rightChild = right_child;

}
