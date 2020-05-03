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
    /* segment normalization p1.x < p2.x */
    cg3::Segment2d normalizedSegment = normalizeSegment(insertedSegment);

    /* 1. check interested trapezoids */
    std::vector<Trapezoid *> interestedTrapezoid = followSegment(normalizedSegment, dag);

    /* Simple insertion */
    if(interestedTrapezoid.size()==1){

        assert(dag->root() != nullptr);

        Node * insertionRoot = interestedTrapezoid[0]->dagRef();
        delete insertionRoot;
         interestedTrapezoid[0]->deactivate();
        *(insertionRoot) = *(simpleInsertion(normalizedSegment, *(interestedTrapezoid[0]), drawableTrapezoid));

    }
    else {

        /* 2. for each trapezoid in interest trapezoid */

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
    Trapezoid * t = TrapezoidalmapQuery::pointQuery(p, dag);
    /* insert the first trapezoid */
    interestedTrapezoids.push_back(t);

    /* while q lies to the right of rightp */
    while (t != nullptr && q.x() > t->rightP().x()){

        double yAtRightP = PointUtils::evaluateYValue(p, q, t->rightP().x());
        if (t->rightP().y() > yAtRightP){
            t = t->getdAjacent(Trapezoid::lowerRight);
        }
        else {
            t = t->getdAjacent(Trapezoid::lowerRight);
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
 * @brief simpleInsertion: Base case, the new segment is fully contained in a unique trapezoid (or there are not any other segments
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 */
Node * simpleInsertion(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid)
{
    Trapezoid * t1 = new Trapezoid(buildArea.top(), buildArea.bottom(), buildArea.leftP(), insertedSegment.p1());
    Trapezoid * t2 = new Trapezoid(buildArea.top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2());
    Trapezoid * t3 = new Trapezoid(insertedSegment, buildArea.bottom(), insertedSegment.p1(), insertedSegment.p2());
    Trapezoid * t4 = new Trapezoid(buildArea.top(), buildArea.bottom(), insertedSegment.p2(), buildArea.rightP());

    #ifdef QT_DEBUG
    // Check coinsistence (it can degrade the performance)
    Trapezoid b = buildArea;
    std::list<Trapezoid *> before = {&b};
    std::list<Trapezoid *> after = {t1, t2, t3, t4};

    assert(ConsistenceChecker::equalArea(before, after));

    #endif

    /* Adjacents trapezoid */
    t1->setAdjacents(t2, nullptr, nullptr, t3);
    t2->setAdjacents(t4, t1, t1, t4);
    t3->setAdjacents(t4, t1, t1, t4);
    t4->setAdjacents(nullptr, t2, t3, nullptr);

    /* Trapezoidal Map */
    drawableTrapezoid.addTrapezoid(t1);
    drawableTrapezoid.addTrapezoid(t2);
    drawableTrapezoid.addTrapezoid(t3);
    drawableTrapezoid.addTrapezoid(t4);


    /* Dag */
    /* root */
    Node * insertionRoot = new Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y()));
    /* root > left */
    insertionRoot->setLeftChild(createLeafNode(t1));
     /* root > right */
    insertionRoot->setRightChild(new Node(Node::q, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y())));
    /* root > right > left */
    insertionRoot->rightChild()->setLeftChild(new Node(new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2())));
    /* root > right > right */
    insertionRoot->rightChild()->setRightChild(createLeafNode(t4));
    /* root > right > left > left */
    insertionRoot->rightChild()->leftChild()->setLeftChild(createLeafNode(t2));
    /* root > right > left > right */
    insertionRoot->rightChild()->leftChild()->setRightChild(createLeafNode(t3));

    assert(insertionRoot->leftChild()->type() == Node::t);


    return insertionRoot;
}


}
