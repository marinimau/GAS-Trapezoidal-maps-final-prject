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
    Trapezoid first = Trapezoid(cg3::Segment2d(topLeft, topRight), cg3::Segment2d(bottomLeft, bottomRight), topLeft, bottomRight);
    return first;
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
    cg3::Segment2d normalizedSegment = normalizeSegment(insertedSegment);

    /* First Segment */
    if(drawableTrapezoid.trapezoidNumber()==0){
        // simple insertion
        assert(dag != NULL);
        dag->setRoot(simpleInsertion(normalizedSegment, boundingBox(), drawableTrapezoid));
    }
    else {
        /* 1. check interested trapezoids */
        std::list<Trapezoid *> interestedTrapezoid = followSegment(normalizedSegment, dag);
        printf("\ninterest trapezoids count: %lu\n", interestedTrapezoid.size());

        /* 2. for each trapezoid in interest trapezoid */

            // 2.1. interested_points = get point extension
            // 2.2  delete trapezoid from map

        /* 4. edit point extensions per i punti selezionati */
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
std::list<Trapezoid *> followSegment(const cg3::Segment2d& normalizedSegment,  Dag * dag)
{
    cg3::Point2d p = normalizedSegment.p1(), q = normalizedSegment.p2();
    std::list<Trapezoid *> interestedTrapezoids;

    /* Search with p in the search strucutre D to find T */
    Trapezoid * t = TrapezoidalmapQuery::pointQuery(p, dag);

    /* while q lies to the right of rightp */
    while (t->rightP() != NULL && q.x() > t->rightP().x()){

        /* insert the first trapezoid */
        interestedTrapezoids.push_back(t);

        double yAtRightP = PointUtils::evaluateYValue(p, q, t->rightP().x());
        if (t->rightP().y() > yAtRightP){
            t = t->getdAjacent(Trapezoid::lowerRight);
        }
        else {
            t = t->getdAjacent(Trapezoid::lowerRight);
        }
    }

    return interestedTrapezoids;

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
    insertionRoot->setLeftChild(new Node(t1));
     /* root > right */
    insertionRoot->setRightChild(new Node(Node::q, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y())));
    /* root > right > left */
    insertionRoot->rightChild()->setLeftChild(new Node(new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2())));
    /* root > right > right */
    insertionRoot->rightChild()->setRightChild(new Node(t4));
    /* root > right > left > left */
    insertionRoot->rightChild()->leftChild()->setLeftChild(new Node(t2));
    /* root > right > left > right */
    insertionRoot->rightChild()->leftChild()->setRightChild(new Node(t3));

    assert(insertionRoot->leftChild()->type() == Node::t);


    return insertionRoot;
}


}
