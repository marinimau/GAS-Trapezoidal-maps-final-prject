#include "algorithms/trapezoidalmap_builder.h"

#define BOUNDINGBOX 1e+6

namespace TrapezoidalMapBuilder {


/* Initializaiton */
/**
 * @brief boundingBox() return the boundingBox
 * @return
 */
Trapezoid * boundingBox()
{
    cg3::Point2d topLeft = cg3::Point2d(-BOUNDINGBOX, BOUNDINGBOX);
    cg3::Point2d topRight = cg3::Point2d(BOUNDINGBOX, BOUNDINGBOX);
    cg3::Point2d bottomLeft = cg3::Point2d(-BOUNDINGBOX, -BOUNDINGBOX);
    cg3::Point2d bottomRight = cg3::Point2d(BOUNDINGBOX, -BOUNDINGBOX);
    return new Trapezoid(cg3::Segment2d(topLeft, topRight), cg3::Segment2d(bottomLeft, bottomRight), topLeft, bottomRight);
}

/**
 * @brief init: setup of dag and trapezoidal map
 * @param drawableTrapezoid
 * @param dag
 */
void init(DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{
    /* create bounding box trapezoid */
    Trapezoid * bBox = boundingBox();
    /* add the trapezoid to the trapezoidal map */
    drawableTrapezoid.addTrapezoid(bBox);
    dag->setRoot(createLeafNode(bBox));
}

/* Insertion step */
/**
 * @brief evaluateSegmentInserted: incremental step
 * @param insertedSegment
 * @param drawableVerticalSegment
 * @param drawableTrapezoid
 */
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableVerticalSegment& drawableVerticalSegment, DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{
    assert(dag->root() != nullptr);

    /* segment normalization p1.x < p2.x */
    cg3::Segment2d normalizedSegment = normalizeSegment(insertedSegment);

    /* 1. check interested trapezoids */
    std::vector<Trapezoid *> interestedTrapezoid = followSegment(normalizedSegment, dag);

    /* 2.a Simple insertion */
    if(interestedTrapezoid.size()==1){

        Node * insertionRoot = interestedTrapezoid[0]->dagRef();
        delete insertionRoot;
         interestedTrapezoid[0]->deactivate();
        *(insertionRoot) = *(simpleInsertion(normalizedSegment, interestedTrapezoid[0], drawableTrapezoid));

    }
    /* 2.b the new segment intersects more than one trapezoid */
    else {
        if(interestedTrapezoid.size() == 2){
            twoInterestedTrapezoidInsertion(normalizedSegment, interestedTrapezoid, drawableTrapezoid);
        }


        /* firs interested trapezoid from its leftp to normalizedSegment.p1 (top e bottom segments invariated */

        /* last interested trapezoid from normalizedSegment.p2 to its rightP (top and bottom invariated */

        // 2.1. interested_points = get point extension
        // 2.1  delete trapezoid from map

    }

    // if debug, print dag nodes (inorder)
    #ifdef QT_DEBUG
    dag->inOrderVisit(dag->root());
    #endif

}


/**
 * @brief normalizeSegment returns a segment where p1 is ever at the left of p2.
 * @param insertedSegment
 * @return
 */
cg3::Segment2d normalizeSegment(const cg3::Segment2d& insertedSegment)
{
    if(insertedSegment.p1().x() < insertedSegment.p2().x()){
        return cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2());
    }
    else {
        return cg3::Segment2d(insertedSegment.p2(), insertedSegment.p1());
    }
}


/**
 * @brief followSegment: find all the trapezoid interested by the segment insertion
 * @param insertedSegment
 * @param t
 * @return
 */
std::vector<Trapezoid *> followSegment(const cg3::Segment2d& normalizedSegment,  Dag * dag)
{
    cg3::Point2d p = normalizedSegment.p1(), q = normalizedSegment.p2();
    std::vector<Trapezoid *> interestedTrapezoids;

    /* Search with p in the search strucutre D to find T */
    Trapezoid * t = TrapezoidalmapQuery::pointQuery(p, dag->root());
    /* insert the first trapezoid */
    interestedTrapezoids.push_back(t);

    /* while q lies to the right of rightp */
    while (t != nullptr && q.x() > t->rightP().x()){

        double yAtRightP = PointUtils::evaluateYValue(p, q, t->rightP().x());
        if (t->rightP().y() > yAtRightP){
            t = t->getAdjacent(Trapezoid::lowerRight);
        }
        else {
            t = t->getAdjacent(Trapezoid::upperRight);
        }

        /* insert trapezoid */
        interestedTrapezoids.push_back(t);
    }

    return interestedTrapezoids;

}


/**
 * @brief createLeafNode: create a leaf node and set the reference to the node just created on trapezoid.
 * @param t
 * @return
 */
Node * createLeafNode(Trapezoid * t)
{
    /* Create a node that point to the trapezoid */
    Node * node = new Node(t);
    /* set the reference to the node in the trapezoid */
    t->setDagRef(node);
    /* return the node just created */
    return node;
}


/* Insertion cases */

/**
 * @brief simpleInsertion: Base case, the new segment is fully contained in a unique trapezoid (or there are not any other segments)
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 */
Node * simpleInsertion(const cg3::Segment2d insertedSegment, Trapezoid * buildArea, DrawableTrapezoid& drawableTrapezoid)
{
    Trapezoid * tLeft = new Trapezoid(buildArea->top(), buildArea->bottom(), buildArea->leftP(), insertedSegment.p1());
    Trapezoid * tCenterTop = new Trapezoid(buildArea->top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2());
    Trapezoid * tCenterBottom = new Trapezoid(insertedSegment, buildArea->bottom(), insertedSegment.p1(), insertedSegment.p2());
    Trapezoid * tRight = new Trapezoid(buildArea->top(), buildArea->bottom(), insertedSegment.p2(), buildArea->rightP());

    #ifdef QT_DEBUG
    // Check coinsistence (it can degrade the performance)
    std::list<Trapezoid *> before = {buildArea};
    std::list<Trapezoid *> after = {tLeft, tCenterTop, tCenterBottom, tRight};

    assert(ConsistenceChecker::equalArea(before, after));

    #endif

    /* Adjacents trapezoid */
    tLeft->setAdjacents(tCenterTop, buildArea->getAdjacent(Trapezoid::upperLeft), buildArea->getAdjacent(Trapezoid::lowerLeft), tCenterBottom);
    tCenterTop->setAdjacents(tRight, tLeft, tLeft, tRight);
    tCenterBottom->setAdjacents(tRight, tLeft, tLeft, tRight);
    tRight->setAdjacents(buildArea->getAdjacent(Trapezoid::upperRight), tCenterTop, tCenterBottom, buildArea->getAdjacent(Trapezoid::lowerRight));

    /* Update adjacency in neighborhood */
    /* left */
    setNeighborOfNeighborLeftSide(tLeft, buildArea);
    /* right */
    //setNeighborOfNeighborRightSide(tRight, buildArea);

    /* Trapezoidal Map */
    drawableTrapezoid.addTrapezoid(tLeft);
    drawableTrapezoid.addTrapezoid(tCenterTop);
    drawableTrapezoid.addTrapezoid(tCenterBottom);
    drawableTrapezoid.addTrapezoid(tRight);


    /* Dag */
    /* root */
    Node * insertionRoot = new Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y()));
    /* root > left */
    insertionRoot->setLeftChild(createLeafNode(tLeft));
     /* root > right */
    insertionRoot->setRightChild(new Node(Node::q, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y())));
    /* root > right > left */
    insertionRoot->rightChild()->setLeftChild(new Node(new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2())));
    /* root > right > right */
    insertionRoot->rightChild()->setRightChild(createLeafNode(tRight));
    /* root > right > left > left */
    insertionRoot->rightChild()->leftChild()->setLeftChild(createLeafNode(tCenterTop));
    /* root > right > left > right */
    insertionRoot->rightChild()->leftChild()->setRightChild(createLeafNode(tCenterBottom));

    assert(insertionRoot->leftChild()->type() == Node::t);


    return insertionRoot;
}

/**
 * @brief twoInterestedTrapezoidInsertion, in this case the inserted Segment cross two trapezoid
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 * @return
 */
Node * twoInterestedTrapezoidInsertion(const cg3::Segment2d insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid)
{
    /* insert the trapezoid at the left, from buildArea[0].leftP to insertedSegment.p1 */
    Trapezoid * tLeft = new Trapezoid(buildArea[0]->top(), buildArea[0]->bottom(), buildArea[0]->leftP(), insertedSegment.p1());
    /* insert the trapezoid at the right, from insertedSegment.p2 to buildArea[1].rightP */
    Trapezoid * tRight = new Trapezoid(buildArea[1]->top(), buildArea[1]->bottom(), insertedSegment.p2(), buildArea[1]->rightP());

    /* center trapezoids */
    Trapezoid * tCenter1 = nullptr;
    Trapezoid * tCenter2 = nullptr;
    Trapezoid * tCenter3 = nullptr;


    /* between tLeft and tRight there are 3 trapezoid. There are 2 possible configuration according to the u of buildArea[0].rightP */
    if(buildArea[0]->rightP().y() <= PointUtils::evaluateYValue(insertedSegment.p1(), insertedSegment.p2(), buildArea[0]->rightP().x())){

        tCenter1 = new Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2());
        tCenter2 = new Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(), buildArea[0]->rightP());
        tCenter3 = new Trapezoid(insertedSegment, buildArea[1]->bottom(), buildArea[1]->leftP(), insertedSegment.p2());

        /* Adjacents */
        tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter1, tCenter3, buildArea[1]->getAdjacent(Trapezoid::lowerRight));

    }
    else {

        tCenter1 = new Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), buildArea[0]->rightP());
        tCenter2 = new Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(),insertedSegment.p2());
        tCenter3 = new Trapezoid(buildArea[1]->top(), insertedSegment, buildArea[1]->leftP(), insertedSegment.p2());

        /* Adjacents */
        tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter3, tCenter2, buildArea[1]->getAdjacent(Trapezoid::lowerRight));

    }

    /* Adjacent  equals in both cases */
    tLeft->setAdjacents(tCenter1, buildArea[0]->getAdjacent(Trapezoid::upperLeft), buildArea[0]->getAdjacent(Trapezoid::lowerLeft), tCenter2);

    /* Trapezoidal Map */
    drawableTrapezoid.addTrapezoid(tLeft);
    drawableTrapezoid.addTrapezoid(tCenter1);
    drawableTrapezoid.addTrapezoid(tCenter2);
    drawableTrapezoid.addTrapezoid(tCenter3);
    drawableTrapezoid.addTrapezoid(tRight);

    /* deactivate other */
    buildArea[0]->deactivate();
    buildArea[1]->deactivate();


}

/* Neighbors adjacency */

/**
 * @brief setNeighborOfNeighborLeftSide
 * @param insertedLeft
 * @param buildArea
 */
void setNeighborOfNeighborLeftSide(Trapezoid * insertedLeft, Trapezoid * buildArea)
{
    Trapezoid * upperLeft = buildArea->getAdjacent(Trapezoid::upperLeft);
    Trapezoid * lowerLeft = buildArea->getAdjacent(Trapezoid::lowerLeft);

    if(upperLeft != nullptr){
        /* resolve upperLeft */
        if (upperLeft->getAdjacent(Trapezoid::upperRight) == buildArea){
            upperLeft->setAdjacent(insertedLeft, Trapezoid::upperRight);
        }
        if (upperLeft->getAdjacent(Trapezoid::lowerRight) == buildArea){
            upperLeft->setAdjacent(insertedLeft, Trapezoid::lowerRight);
        }
    }
    if(lowerLeft != nullptr){
        /* resolve lowerLeft */
        if (lowerLeft->getAdjacent(Trapezoid::upperRight) == buildArea){
            lowerLeft->setAdjacent(insertedLeft, Trapezoid::upperRight);
        }
        if (lowerLeft->getAdjacent(Trapezoid::lowerRight) == buildArea){
            lowerLeft->setAdjacent(insertedLeft, Trapezoid::lowerRight);
        }
    }

}

/**
 * @brief setNeighborOfNeighborRightSide
 * @param insertedRight
 * @param buildArea
 */
void setNeighborOfNeighborRightSide(Trapezoid * insertedRight, Trapezoid * buildArea)
{
    Trapezoid * upperRight = buildArea->getAdjacent(Trapezoid::upperRight);
    Trapezoid * lowerRight = buildArea->getAdjacent(Trapezoid::lowerRight);

    if(upperRight != nullptr){
        /* resolve upperLeft */
        if (upperRight->getAdjacent(Trapezoid::upperLeft) == buildArea){
            upperRight->setAdjacent(insertedRight, Trapezoid::upperLeft);
        }
        if (upperRight->getAdjacent(Trapezoid::lowerLeft) == buildArea){
            upperRight->setAdjacent(insertedRight, Trapezoid::lowerLeft);
        }
    }

    if(lowerRight != nullptr){
        /* resolve lowerLeft */
        if (lowerRight->getAdjacent(Trapezoid::upperLeft) == buildArea){
            lowerRight->setAdjacent(insertedRight, Trapezoid::upperLeft);
        }
        if (lowerRight->getAdjacent(Trapezoid::lowerLeft) == buildArea){
            lowerRight->setAdjacent(insertedRight, Trapezoid::lowerLeft);
        }
    }
}


}
