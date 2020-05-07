#include "algorithms/trapezoidalmap_builder.h"

#define BOUNDINGBOX 1e+6

namespace TrapezoidalMapBuilder {


/* Initializaiton */
/**
 * @brief boundingBox() return the boundingBox
 * @return
 */
Trapezoid boundingBox()
{
    cg3::Point2d topLeft = cg3::Point2d(-BOUNDINGBOX, BOUNDINGBOX);
    cg3::Point2d topRight = cg3::Point2d(BOUNDINGBOX, BOUNDINGBOX);
    cg3::Point2d bottomLeft = cg3::Point2d(-BOUNDINGBOX, -BOUNDINGBOX);
    cg3::Point2d bottomRight = cg3::Point2d(BOUNDINGBOX, -BOUNDINGBOX);
    return Trapezoid(cg3::Segment2d(topLeft, topRight), cg3::Segment2d(bottomLeft, bottomRight), topLeft, bottomRight);
}

/**
 * @brief init: setup of dag and trapezoidal map
 * @param drawableTrapezoid
 * @param dag
 */
void init(DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{
    /* create bounding box trapezoid */
    Trapezoid bBox = boundingBox();
    /* add the trapezoid to the trapezoidal map */
    Trapezoid * bBoxRef = drawableTrapezoid.addTrapezoid(bBox);
    dag->setRoot(createLeafNode(bBoxRef, dag));
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
        *(insertionRoot) = *(simpleInsertion(normalizedSegment, interestedTrapezoid[0], drawableTrapezoid, dag));


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
    if(insertedSegment.p1().x() > insertedSegment.p2().x()){
        return cg3::Segment2d(insertedSegment.p2(), insertedSegment.p1());
    }
    return insertedSegment;
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
    bool isDegenere = false;
    Trapezoid * t = TrapezoidalmapQuery::pointQuery(p, dag->root(), isDegenere);
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

    if(isDegenere && interestedTrapezoids.size() == 1){
        /* this solve some anomalies */
        interestedTrapezoids[0] = TrapezoidalmapQuery::pointQuery(q, dag->root(), isDegenere);
    }


    return interestedTrapezoids;

}


/**
 * @brief createLeafNode: create a leaf node and set the reference to the node just created on trapezoid.
 * @param t
 * @return
 */
Node * createLeafNode(Trapezoid * t, Dag * dag)
{
    /* Create a node that point to the trapezoid */
    Node * node = dag->addNode(Node(t));
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
Node * simpleInsertion(const cg3::Segment2d insertedSegment, Trapezoid * buildArea, DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{

    /* center trapezoids */
    Trapezoid * tCenterTop = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea->top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2()));
    Trapezoid * tCenterBottom = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea->bottom(), insertedSegment.p1(), insertedSegment.p2()));


    /* left and right trapezoids, not always needed */
    Trapezoid * tLeft = nullptr;
    Trapezoid * tRight = nullptr;

    /* if inserted segment.p1.x != buildArea.leftP.x build left trapezoid */
    if(!PointUtils::checkDegenere(insertedSegment.p1(), buildArea->leftP())){
        tLeft = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea->top(), buildArea->bottom(), buildArea->leftP(), insertedSegment.p1()));
    }
    /* if inserted segment.p2.x != buildArea.rightP.x build right trapezoid */
    if(!PointUtils::checkDegenere(insertedSegment.p2(), buildArea->rightP())){
        tRight = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea->top(), buildArea->bottom(), insertedSegment.p2(), buildArea->rightP()));
    }


    #ifdef QT_DEBUG
    // Check coinsistence (it can degrade the performance)
    std::list<Trapezoid> before = {*(buildArea)};
    std::list<Trapezoid> after = {*(tCenterTop), *(tCenterBottom)};

    if(tLeft != nullptr){
        after.push_back(*(tLeft));
    }
    if(tRight != nullptr){
        after.push_back(*(tRight));
    }

    assert(ConsistenceChecker::equalArea(before, after));

    #endif

    /* Adjacents trapezoid */
    if(tLeft != nullptr){

        tLeft->setAdjacents(tCenterTop, buildArea->getAdjacent(Trapezoid::upperLeft), buildArea->getAdjacent(Trapezoid::lowerLeft), tCenterBottom);


        tCenterTop->setAdjacent(tLeft, Trapezoid::upperLeft);
        tCenterTop->setAdjacent(tLeft, Trapezoid::lowerLeft);

        tCenterBottom->setAdjacent(tLeft, Trapezoid::upperLeft);
        tCenterBottom->setAdjacent(tLeft, Trapezoid::lowerLeft);

        setNeighborOfNeighborLeftSide(tLeft, tLeft, buildArea);

    }
    else {

        tCenterTop->setAdjacent(buildArea->getAdjacent(Trapezoid::upperLeft), Trapezoid::upperLeft);
        tCenterTop->setAdjacent(buildArea->getAdjacent(Trapezoid::upperLeft), Trapezoid::lowerLeft);

        tCenterBottom->setAdjacent(buildArea->getAdjacent(Trapezoid::lowerLeft), Trapezoid::upperLeft);
        tCenterBottom->setAdjacent(buildArea->getAdjacent(Trapezoid::lowerLeft), Trapezoid::lowerLeft);

        setNeighborOfNeighborLeftSide(tCenterTop, tCenterBottom, buildArea);
    }
    if(tRight != nullptr){

        tRight->setAdjacents(buildArea->getAdjacent(Trapezoid::upperRight), tCenterTop, tCenterBottom, buildArea->getAdjacent(Trapezoid::lowerRight));

        tCenterTop->setAdjacent(tRight, Trapezoid::upperRight);
        tCenterTop->setAdjacent(tRight, Trapezoid::lowerRight);

        tCenterBottom->setAdjacent(tRight, Trapezoid::upperRight);
        tCenterBottom->setAdjacent(tRight, Trapezoid::lowerRight);

        setNeighborOfNeighborRightSide(tRight, tRight, buildArea);

    }
    else {

        tCenterTop->setAdjacent(buildArea->getAdjacent(Trapezoid::upperRight), Trapezoid::upperRight);
        tCenterTop->setAdjacent(buildArea->getAdjacent(Trapezoid::upperRight), Trapezoid::lowerRight);

        tCenterBottom->setAdjacent(buildArea->getAdjacent(Trapezoid::lowerRight), Trapezoid::upperRight);
        tCenterBottom->setAdjacent(buildArea->getAdjacent(Trapezoid::lowerRight), Trapezoid::lowerRight);

        setNeighborOfNeighborRightSide(tCenterTop, tCenterBottom, buildArea);


    }

    /* Dag */
    /* root */
    Node * insertionRoot = dag->addNode(Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y())));
    /* root > left */
    if(tLeft != nullptr){
        insertionRoot->setLeftChild(createLeafNode(tLeft, dag));
    }
     /* root > right */
    insertionRoot->setRightChild(dag->addNode(Node(Node::q, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y()))));
    /* root > right > left */
    insertionRoot->rightChild()->setLeftChild(dag->addNode(Node(new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2()))));
    /* root > right > right */
    if(tRight != nullptr){
        insertionRoot->rightChild()->setRightChild(createLeafNode(tRight, dag));
    }
    /* root > right > left > left */
    insertionRoot->rightChild()->leftChild()->setLeftChild(createLeafNode(tCenterTop, dag));
    /* root > right > left > right */
    insertionRoot->rightChild()->leftChild()->setRightChild(createLeafNode(tCenterBottom, dag));



    /* deactivate old trapezoid */
    buildArea->deactivate();

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
    Trapezoid * tLeft = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), buildArea[0]->bottom(), buildArea[0]->leftP(), insertedSegment.p1()));
    /* insert the trapezoid at the right, from insertedSegment.p2 to buildArea[1].rightP */
    Trapezoid * tRight = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[1]->top(), buildArea[1]->bottom(), insertedSegment.p2(), buildArea[1]->rightP()));

    /* center trapezoids */
    Trapezoid * tCenter1 = nullptr;
    Trapezoid * tCenter2 = nullptr;
    Trapezoid * tCenter3 = nullptr;


    /* between tLeft and tRight there are 3 trapezoid. There are 2 possible configuration according to the u of buildArea[0].rightP */
    bool segmentAboveRightP = buildArea[0]->rightP().y() <= PointUtils::evaluateYValue(insertedSegment.p1(), insertedSegment.p2(), buildArea[0]->rightP().x());

    if(segmentAboveRightP){
        tCenter1 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2()));
        tCenter2 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(), buildArea[0]->rightP()));
        tCenter3 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[1]->bottom(), buildArea[1]->leftP(), insertedSegment.p2()));

        /* Adjacents */
        tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter1, tCenter3, buildArea[1]->getAdjacent(Trapezoid::lowerRight));

    }
    else {

        tCenter1 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), buildArea[0]->rightP()));
        tCenter2 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(),insertedSegment.p2()));
        tCenter3 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[1]->top(), insertedSegment, buildArea[1]->leftP(), insertedSegment.p2()));

        /* Adjacents */
        tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter3, tCenter2, buildArea[1]->getAdjacent(Trapezoid::lowerRight));

    }

    /* Adjacent  equals in both cases */
    tLeft->setAdjacents(tCenter1, buildArea[0]->getAdjacent(Trapezoid::upperLeft), buildArea[0]->getAdjacent(Trapezoid::lowerLeft), tCenter2);

    /* Dag */

    /* Substitute buildArea[0]->dagRef() */

    /* root: substitute trapezoid with insertedSegment.p1 */

    /* root > left_child: tLeft */

    /* root > right_child: inserted_segment */

    /* root > right_child > left_child > tCenter1 */

    /* root > right_child > right_child > tCenter2 */


    /* Substitute buildArea[1]->dagRef() */

    /* root: substitute trapezoid with insertedSegment.p2 */

    /* root > right_child: tRight */

    /* root > left_child: inserted_segment */

    if(segmentAboveRightP){
        /* root > left_child > left_child > tCenter1 */

        /* root > left_child > right_child > tCenter3 */
    }
    else {
        /* root > left_child > left_child > tCenter3 */

        /* root > left_child > right_child > tCenter2 */
    }


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
void setNeighborOfNeighborLeftSide(Trapezoid * insertedLeftUpper, Trapezoid * insertedLeftLower, Trapezoid * buildArea)
{
    Trapezoid * upperLeft = buildArea->getAdjacent(Trapezoid::upperLeft);
    Trapezoid * lowerLeft = buildArea->getAdjacent(Trapezoid::lowerLeft);

    if(upperLeft != nullptr){
        /* resolve upperLeft */
        if (upperLeft->getAdjacent(Trapezoid::upperRight) == buildArea){
            upperLeft->setAdjacent(insertedLeftUpper, Trapezoid::upperRight);
        }
        if (upperLeft->getAdjacent(Trapezoid::lowerRight) == buildArea){
            upperLeft->setAdjacent(insertedLeftUpper, Trapezoid::lowerRight);
        }
    }
    if(lowerLeft != nullptr){
        /* resolve lowerLeft */
        if (lowerLeft->getAdjacent(Trapezoid::upperRight) == buildArea && lowerLeft != upperLeft){
            lowerLeft->setAdjacent(insertedLeftLower, Trapezoid::upperRight);
        }
        if (lowerLeft->getAdjacent(Trapezoid::lowerRight) == buildArea){
            lowerLeft->setAdjacent(insertedLeftLower, Trapezoid::lowerRight);
        }
    }

}

/**
 * @brief setNeighborOfNeighborRightSide
 * @param insertedRight
 * @param buildArea
 */
void setNeighborOfNeighborRightSide(Trapezoid * insertedRightUpper, Trapezoid * insertedRightLower, Trapezoid * buildArea)
{
    Trapezoid * upperRight = buildArea->getAdjacent(Trapezoid::upperRight);
    Trapezoid * lowerRight = buildArea->getAdjacent(Trapezoid::lowerRight);

    if(upperRight != nullptr){
        /* resolve upperLeft */
        if (upperRight->getAdjacent(Trapezoid::upperLeft) == buildArea){
            upperRight->setAdjacent(insertedRightUpper, Trapezoid::upperLeft);
        }
        if (upperRight->getAdjacent(Trapezoid::lowerLeft) == buildArea){
            upperRight->setAdjacent(insertedRightUpper, Trapezoid::lowerLeft);
        }
    }

    if(lowerRight != nullptr){
        /* resolve lowerLeft */
        if (lowerRight->getAdjacent(Trapezoid::upperLeft) == buildArea && lowerRight != upperRight){
            lowerRight->setAdjacent(insertedRightLower, Trapezoid::upperLeft);
        }
        if (lowerRight->getAdjacent(Trapezoid::lowerLeft) == buildArea){
            lowerRight->setAdjacent(insertedRightLower, Trapezoid::lowerLeft);
        }
    }
}


}
