#ifndef DAG_H
#define DAG_H

#include "data_structures/node.h"
#include <cg3/geometry/point2.h>

class Dag {

public:

    /* Constructors */
    Dag();

    /* Destructors */
    ~Dag();
    void clear(Node * current);
    void clearIntermediateNodes(Node * current);

    /* Getters */
    Node * root();

    /* Setters */
    void setRoot(Node * root);

    /* Others */
    void deleteTrapezoid(Node * trapezoid);

    /* Debug */
    void inOrderVisit(Node * current);

private:

    Node * _root;

};

#endif // DAG_H
