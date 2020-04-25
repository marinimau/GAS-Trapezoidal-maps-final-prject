#include "node.h"

/* Constructors */

/**
 * @brief Node::Node: default constructor
 */
Node::Node(){
    _type = Node::t;
    _value = nullptr;
}

/**
 * @brief Node::Node: costructor for a trapezoid node
 * @param type
 * @param trapezoid
 */
Node::Node(const Node::nodeType type, Trapezoid * trapezoid)
{
    assert(type == Node::t);
    _type = type;
    _value = trapezoid;

}

/**
 * @brief Node::Node: constructor for a segment node
 * @param type
 * @param segment
 */
Node::Node(const Node::nodeType type, cg3::Segment2d * segment)
{
    assert(type == Node::s);
    _type = type;
    _value = segment;
}

/**
 * @brief Node::Node: constructor for a point node (p or q)
 * @param type
 * @param point
 */
Node::Node(const Node::nodeType type, cg3::Point2d * point)
{
    assert(type == Node::p || type == Node::q);
    _type = type;
    _value = point;
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
    assert(_type != Node::t);
    return _left_child;
}

/**
 * @brief Node::rightChild: return the right child of the current node
 * @return
 */
Node * Node::rightChild() const
{
    assert(_type != Node::t);
    return _right_child;
}

/* Setters */

/**
 * @brief Node::setValue: set the value of the node (for leaf node)
 * @param type
 * @param trapezoid
 */
void Node::setValue(const Node::nodeType type, Trapezoid * trapezoid)
{
    assert(type == Node::t);
    _type = type;
    _value = trapezoid;
}

/**
 * @brief Node::setValue set the value of the node (for segment node)
 * @param type
 * @param segment
 */
void Node::setValue(const Node::nodeType type, cg3::Segment2d * segment)
{
    assert(type == Node::s);
    _type = type;
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
    _left_child = left_child;
}

/**
 * @brief setLeftChild: set the right child of the node
 * @param left_child
 */
void Node::setRightChild(Node * right_child)
{
    assert(_type != Node::t);
    _right_child = right_child;

}
