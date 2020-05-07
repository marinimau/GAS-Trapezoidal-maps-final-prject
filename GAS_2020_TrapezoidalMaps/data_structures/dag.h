#ifndef DAG_H
#define DAG_H

#include "data_structures/node.h"
#include <cg3/geometry/point2.h>
#include <list>

class Dag {

public:

    /* Constructors */
    Dag();

    /* Destructors */
    ~Dag();
    void clear();

    /* Getters */
    Node * root();

    /* Setters */
    void setRoot(Node * root);

    /* Others */
    Node * addNode(Node node);
    void deleteLeaf(Node * leaf);

    /* Debug */
    void inOrderVisit(Node * current);

private:

    Node * _root;
    std::list<Node> nodes;

};

#endif // DAG_H
