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

    Node(nodeType type, Trapezoid * trapezoid);
    Node(nodeType type, cg3::Segment2d * segment);
    Node(nodeType type, cg3::Point2d * point);

    /* Getters */

    void * value();
    Node * leftChild();
    Node * rightChild();

    /* Setters */

    void setValue(nodeType type, Trapezoid * trapezoid);
    void setValue(nodeType type, cg3::Segment2d * segment);
    void setValue(nodeType type, cg3::Point2d * point);

    void setLeftChild(Node * left_child);
    void setRightChild(Node * right_child);

private:

    nodeType _type;
    void * _value;
    Node * _left_child;
    Node * _right_child;

};

#endif // NODE_H
