#ifndef DAG_H
#define DAG_H

#include "data_structures/node.h"
#include <cg3/geometry/point2.h>

class Dag {

public:

    /* Constructors */
    Dag(Node root);
    Node * find(Node * current, const cg3::Point2d query) const;

    /* Getters */
    Node root() const;
    Node * rootRef();

    /* Setters */
    void setRoot(Node root);


private:

    Node _root;

};

#endif // DAG_H
