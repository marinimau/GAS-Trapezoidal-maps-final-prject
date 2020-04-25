#include "algorithms/trapezoidal_map_builder.h"

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

/**
 * @brief initDag: initialize the dag
 * @param dag
 */
void initDag(Dag * dag)
{
    Trapezoid t = boundingBox();
    Node root = Node(Node::t, &t);
    Dag d = Dag(root);
    dag = &d;
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

    if(drawableTrapezoid.trapezoidNumber()==0){
        // simple insertion
        initDag(dag);
        simpleInsertion(normalizedSegment, boundingBox(), drawableTrapezoid, dag->rootRef());
    }


    std::vector<cg3::Point2d> interestedPoints;

    /* 1. check interested trapezoids */

    /* 2. for each trapezoid in interest trapezoid */

        // 2.1. interested_points = get point extension
        // 2.2  delete trapezoid from map

    /* 4. edit point extensions per i punti selezionati */

    interestedPoints.push_back(insertedSegment.p1());
    interestedPoints.push_back(insertedSegment.p2());

    for (cg3::Point2d& p : interestedPoints){
        createPointExtension(p, drawableVerticalSegment);
    }

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
std::vector<Trapezoid *> followSegment(const cg3::Segment2d& insertedSegment,  Trapezoid * t)
{
    cg3::Point2d p = insertedSegment.p1(), q = insertedSegment.p2();
    std::vector<Trapezoid *> interestedTrapezoids;

    while (q.x() < t->rightP().x()){

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

/**
 * @brief findTrapezoidThatContainsPoint: given a point, returns the trapezoid that contains it.
 * @param point
 * @param drawableTrapezoid
 * @return
 */
Trapezoid* findTrapezoidThatContainsPoint(cg3::Point2d point, Dag * dag)
{
    return (Trapezoid *)((dag->find(dag->rootRef(), point))->value());
}


/* Insertion cases */

/**
 * @brief simpleInsertion: Base case, the new segment is fully contained in a unique trapezoid (or there are not any other segments
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 */
void simpleInsertion(const cg3::Segment2d insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid, Node * insertionRoot)
{
    Trapezoid t1 = Trapezoid(buildArea.top(), buildArea.bottom(), buildArea.leftP(), insertedSegment.p1());
    Trapezoid t2 = Trapezoid(buildArea.top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2());
    Trapezoid t3 = Trapezoid(insertedSegment, buildArea.bottom(), insertedSegment.p1(), insertedSegment.p2());
    Trapezoid t4 = Trapezoid(buildArea.top(), buildArea.bottom(), insertedSegment.p2(), buildArea.rightP());

    #ifdef QT_DEBUG
    // Check coinsistence (it can degrade the performance)
    Trapezoid b = buildArea;
    std::list<Trapezoid *> before = {&b};
    std::list<Trapezoid *> after = {&t1, &t2, &t3, &t4};

    assert(ConsistenceChecker::equalArea(before, after));

    #else
    #endif

    /* Adjacents trapezoid */
    t1.setAdjacents(&t2, nullptr, nullptr, &t3);
    t2.setAdjacents(&t4, &t1, &t1, &t4);
    t3.setAdjacents(&t4, &t1, &t1, &t4);
    t4.setAdjacents(nullptr, &t2, &t3, nullptr);

    /* Trapezoidal Map */
    drawableTrapezoid.addTrapezoid(t1);
    drawableTrapezoid.addTrapezoid(t2);
    drawableTrapezoid.addTrapezoid(t3);
    drawableTrapezoid.addTrapezoid(t4);

    /* Dag */

    /* root */
    insertionRoot = new Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y()));
    /* root > left */
    insertionRoot->setLeftChild(new Node(Node::t, &t1));
     /* root > right */
    insertionRoot->setRightChild(new Node(Node::q, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y())));
    /* root > right > left */
    insertionRoot->rightChild()->setLeftChild(new Node(Node::s, new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2())));
    /* root > right > right */
    insertionRoot->rightChild()->setRightChild(new Node(Node::t, &t4));
    /* root > right > left > left */
    insertionRoot->rightChild()->leftChild()->setLeftChild(new Node(Node::t, &t2));
    /* root > right > left > right */
    insertionRoot->rightChild()->leftChild()->setRightChild(new Node(Node::t, &t3));



}


/* Point extensions */

/**
 * @brief createPointExtension: given a point create the 2 extensions associated with that point.
 * @param point
 * @param drawableVerticalSegment
 */
void createPointExtension(const cg3::Point2d point, DrawableVerticalSegment& drawableVerticalSegment)
{
    //find upper intersection
    double upper = BOUNDINGBOX;
    double lower = -BOUNDINGBOX;
    TrapezoidalMap::PointExtension pointExtension = {upper, point, lower};
    drawableVerticalSegment.addPointExtension(pointExtension);
}

}
