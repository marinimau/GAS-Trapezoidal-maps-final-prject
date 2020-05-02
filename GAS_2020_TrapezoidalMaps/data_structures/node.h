#ifndef NODE_H
#define NODE_H

#include "data_structures/trapezoid.h"
#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>

class Node
{
public:

    enum nodeType {p, q, s, t};

    /* Constructors */

    Node();
    Node(Trapezoid * trapezoid);
    Node(cg3::Segment2d * segment);
    Node(const nodeType& type, cg3::Point2d * point);

    /* destructors */
    ~Node();

    /* Getters */

    void * value() const;
    nodeType type() const;
    Node * leftChild() const;
    Node * rightChild() const;

    /* Setters */

    void setValue(Trapezoid * trapezoid);
    void setValue(cg3::Segment2d * segment);
    void setValue(const nodeType type, cg3::Point2d * point);

    void setLeftChild(Node * left_child);
    void setRightChild(Node * right_child);

    /* node can't change type, leaf node (type == t) can't have childs */

private:

    nodeType _type;
    void * _value;
    Node *_leftChild;
    Node * _rightChild;

};

#endif // NODE_H
