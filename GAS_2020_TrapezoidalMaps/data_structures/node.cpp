#include "node.h"

/* Constructors */

/**
 * @brief Node::Node: costructor for a trapezoid node
 * @param type
 * @param trapezoid
 */
Node::Node(Node::nodeType type, Trapezoid * trapezoid)
{
    assert(type == Node::nodeType.t);
    _type = type;
    _value = trapezoid;

}

/**
 * @brief Node::Node: constructor for a segment node
 * @param type
 * @param segment
 */
Node::Node(Node::nodeType type, cg3::Segment2d * segment)
{
    assert(type == Node::nodeType.s);
    _type = type;
    _value = segment;
}

/**
 * @brief Node::Node: constructor for a point node (p or q)
 * @param type
 * @param point
 */
Node::Node(Node::nodeType type, cg3::Point2d * point)
{
    assert(type == Node::nodeType.p || type == Node::nodeType.q);
    _type = type;
    _value = point;
}

/* Getters */
/**
 * @brief value, return value of the node
 * @return
 */
void * Node::value()
{
    return _value;
}

/**
 * @brief Node::leftChild: return the left child of current node
 * @return
 */
Node * Node::leftChild()
{
    assert(_type != t);
    return _left_child;
}

/**
 * @brief Node::rightChild: return the right child of the current node
 * @return
 */
Node * Node::rightChild(){
    assert(_type != t);
    return _right_child;
}

/* Setters */

/**
 * @brief Node::setValue: set the value of the node (for leaf node)
 * @param type
 * @param trapezoid
 */
void Node::setValue(Node::nodeType type, Trapezoid * trapezoid)
{
    assert(type == t);
    _type = type;
    _value = trapezoid;
}

/**
 * @brief Node::setValue set the value of the node (for segment node)
 * @param type
 * @param segment
 */
void Node::setValue(Node::nodeType type, cg3::Segment2d * segment)
{
    assert(type == s);
    _type = type;
    _value = segment;
}

/**
 * @brief Node::setValue set the value of the node (for point node)
 * @param type
 * @param segment
 */
void Node::setValue(Node::nodeType type, cg3::Point2d * point)
{
    assert(type == p || type == q);
    _type = type;
    _value = point;
}

/**
 * @brief setLeftChild: set the left child of the node
 * @param left_child
 */
void Node::setLeftChild(Node * left_child)
{
    assert(_type != t);
    _left_child = left_child;
}

/**
 * @brief setLeftChild: set the right child of the node
 * @param left_child
 */
void Node::setRightChild(Node * right_child)
{
    assert(_type != t);
    _right_child = right_child;

}
