#include "algorithms/trapezoidalmap_builder.h"

#define BOUNDINGBOX 1e+6

namespace TrapezoidalMapBuilder {


/*-------------------------------------------------------------------------*
 *
 * Initialization
 *
 *-------------------------------------------------------------------------*/
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
    if(interestedTrapezoid.size() == 1){
        simpleInsertion(normalizedSegment, interestedTrapezoid, drawableTrapezoid, dag);
    }

    /* 2.b the new segment intersects more than one trapezoid */
    else {
        if(interestedTrapezoid.size() == 2){

            twoInterestedTrapezoidsInsertion(normalizedSegment, interestedTrapezoid, drawableTrapezoid, dag);
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


/*-------------------------------------------------------------------------*
 *
 * Insertion Cases
 *
 *-------------------------------------------------------------------------*/

/**
 * @brief simpleInsertion: Base case, the new segment is fully contained in a unique trapezoid (or there are not any other segments)
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 */
void simpleInsertion(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{
    /* center trapezoids */
    Trapezoid * tCenterTop = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2()));
    Trapezoid * tCenterBottom = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(), insertedSegment.p2()));

    /* left and right trapezoids */
    std::tuple<Trapezoid *, Trapezoid *> leftAndRightTrapezoid = addLeftAndRightTrapezoid(insertedSegment, buildArea, drawableTrapezoid);
    Trapezoid * tLeft = std::get<0>(leftAndRightTrapezoid);
    Trapezoid * tRight = std::get<1>(leftAndRightTrapezoid);


    #ifdef QT_DEBUG
    // Check coinsistence (it can degrade the performance)
    std::list<Trapezoid> before = {*(buildArea[0])};
    std::list<Trapezoid> after = {*(tCenterTop), *(tCenterBottom)};

    if(tLeft != nullptr){
        after.push_back(*(tLeft));
    }
    if(tRight != nullptr){
        after.push_back(*(tRight));
    }
    assert(ConsistenceChecker::equalArea(before, after));

    #endif

    /* Set adjacents trapezoid */
    simpleCaseBuildAdjacency(tLeft, tRight, tCenterTop, tCenterBottom, *(buildArea[0]));

    /* update dag */
    simpleCaseDagUpdate(insertedSegment, tLeft, tRight, tCenterTop, tCenterBottom, buildArea[0], dag);

}


/**
 * @brief twoInterestedTrapezoidsInsertion, in this case the inserted Segment cross two trapezoid
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 * @return
 */
void twoInterestedTrapezoidsInsertion(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{    
    bool segmentAboveRightP = false;

    /* Trapezoid insertion */

    /* left and right trapezoids */
    std::tuple<Trapezoid *, Trapezoid *> leftAndRightTrapezoid = addLeftAndRightTrapezoid(insertedSegment, buildArea, drawableTrapezoid);
    Trapezoid * tLeft = std::get<0>(leftAndRightTrapezoid);
    Trapezoid * tRight = std::get<1>(leftAndRightTrapezoid);

    /* center trapezoids */
    std::tuple<Trapezoid *, Trapezoid *, Trapezoid *> centerTrapezoids = twoInterestedTrapezoidsBuldCenterTrapezoids(insertedSegment, buildArea, drawableTrapezoid, segmentAboveRightP);
    Trapezoid * tCenter1 = std::get<0>(centerTrapezoids);
    Trapezoid * tCenter2 = std::get<1>(centerTrapezoids);
    Trapezoid * tCenter3 = std::get<2>(centerTrapezoids);

    #ifdef QT_DEBUG
    // Check coinsistence (it can degrade the performance)
    std::list<Trapezoid> before = {*(buildArea[0]), *(buildArea[1])};
    std::list<Trapezoid> after = {*(tCenter1), *(tCenter2), *(tCenter3)};

    if(tLeft != nullptr){
        after.push_back(*(tLeft));
    }
    if(tRight != nullptr){
        after.push_back(*(tRight));
    }
    assert(ConsistenceChecker::equalArea(before, after));

    #endif

    /* Adjacency update */
    twoInterestedTrapezoidsBuildAdjacency(tLeft, tRight, tCenter1, tCenter2, tCenter3, buildArea, segmentAboveRightP);

    /* Dag update */
    twoInterestedTrapezoidsDagUpdate(insertedSegment, tLeft, tRight, tCenter1, tCenter2, tCenter3, buildArea, dag, segmentAboveRightP);
}


/*-------------------------------------------------------------------------*
 *
 * Trapezoid creation step
 *
 *-------------------------------------------------------------------------*/

/* general */

/**
 * @brief addLeftAndRightTrapezoid: create left and right trapezoids, works for all the insertion cases
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 * @return
 */
std::tuple<Trapezoid *, Trapezoid *> addLeftAndRightTrapezoid(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid)
{
    assert(buildArea.size() > 0);

    /* left and right trapezoids, not always needed */
    Trapezoid * tLeft = nullptr;
    Trapezoid * tRight = nullptr;

    /* if inserted segment.p1.x != buildArea.leftP.x build left trapezoid */
    if(!PointUtils::checkDegenere(insertedSegment.p1(), buildArea[0]->leftP())){
        tLeft = addLeftTrapezoid(insertedSegment, *buildArea[0], drawableTrapezoid);
    }
    /* if inserted segment.p2.x != buildArea.rightP.x build right trapezoid */
    if(!PointUtils::checkDegenere(insertedSegment.p2(), buildArea[buildArea.size()-1]->rightP())){
        tRight = addRightTrapezoid(insertedSegment, *buildArea[buildArea.size()-1], drawableTrapezoid);
    }
    return {tLeft, tRight};
}


/**
 * @brief addLeftTrapezoid: left step
 * @param insertedSegment
 * @param buildArea
 * @return
 */
Trapezoid * addLeftTrapezoid(const cg3::Segment2d& insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid)
{
    return drawableTrapezoid.addTrapezoid(Trapezoid(buildArea.top(), buildArea.bottom(), buildArea.leftP(), insertedSegment.p1()));
}

/**
 * @brief addRightTrapezoid: right step
 * @param insertedSegment
 * @param buildArea
 * @return
 */
Trapezoid * addRightTrapezoid(const cg3::Segment2d& insertedSegment, const Trapezoid& buildArea, DrawableTrapezoid& drawableTrapezoid)
{
    return drawableTrapezoid.addTrapezoid(Trapezoid(buildArea.top(), buildArea.bottom(), insertedSegment.p2(), buildArea.rightP()));
}

/* Center trapezoids in 2 interested trapezoid insertion case */

/**
 * @brief twoInterestedTrapezoidsBuldCenterTrapezoids: create central trapezoid for 2 interested trapezoids insertion case,
 * (only central because left and right trapezoids are created using the function above)
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 * @param yAboveRightP
 * @return
 */
std::tuple<Trapezoid *, Trapezoid *, Trapezoid *> twoInterestedTrapezoidsBuldCenterTrapezoids(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, bool& segmentAboveRightP)
{
    Trapezoid * tCenter1 = nullptr;
    Trapezoid * tCenter2 = nullptr;
    Trapezoid * tCenter3 = nullptr;

    /* between tLeft and tRight there are 3 trapezoid. There are 2 possible configuration according to the u of buildArea[0].rightP */
    segmentAboveRightP = buildArea[0]->rightP().y() <= PointUtils::evaluateYValue(insertedSegment.p1(), insertedSegment.p2(), buildArea[0]->rightP().x());

    if(segmentAboveRightP){
        tCenter1 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), insertedSegment.p2()));
        tCenter2 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(), buildArea[0]->rightP()));
        tCenter3 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[1]->bottom(), buildArea[1]->leftP(), insertedSegment.p2()));
    }
    else {
        tCenter1 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), buildArea[0]->rightP()));
        tCenter2 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(),insertedSegment.p2()));
        tCenter3 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[1]->top(), insertedSegment, buildArea[1]->leftP(), insertedSegment.p2()));
    }
    return {tCenter1, tCenter2, tCenter3};

}


/*-------------------------------------------------------------------------*
 *
 * Adjacency update step
 *
 *-------------------------------------------------------------------------*/

/* simple case */

/**
 * @brief simpleCaseBuildAdjacency: build the adjacency for the simple insertion case
 * @param tLeft
 * @param tRight
 * @param tCenterTop
 * @param tCenterBottom
 * @param buildArea
 */
void simpleCaseBuildAdjacency(Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenterTop, Trapezoid * tCenterBottom, const Trapezoid& buildArea)
{
    /* left step */
    simpleCaseAdjacencyLeft(tLeft, tCenterBottom, tCenterTop, buildArea);
    /* right step */
    simpleCaseAdjacencyRight(tRight, tCenterBottom, tCenterTop, buildArea);
}


/**
 * @brief simpleCaseAdjacencyLeft build the adjacency for the simple insertion case: left step
 * @param tLeft
 * @param tCenterBottom
 * @param tCenterTop
 * @param buildArea
 */
void simpleCaseAdjacencyLeft(Trapezoid * tLeft, Trapezoid * tCenterBottom, Trapezoid * tCenterTop, const Trapezoid& buildArea)
{
    if(tLeft != nullptr){
        tLeft->setAdjacents(tCenterTop, buildArea.getAdjacent(Trapezoid::upperLeft), buildArea.getAdjacent(Trapezoid::lowerLeft), tCenterBottom);
        tCenterTop->setAdjacent(tLeft, Trapezoid::upperLeft);
        tCenterTop->setAdjacent(tLeft, Trapezoid::lowerLeft);
        tCenterBottom->setAdjacent(tLeft, Trapezoid::upperLeft);
        tCenterBottom->setAdjacent(tLeft, Trapezoid::lowerLeft);
        setNeighborOfNeighborLeftSide(tLeft, tLeft, buildArea);
    }
    else {
        tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperLeft), Trapezoid::upperLeft);
        tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperLeft), Trapezoid::lowerLeft);
        tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerLeft), Trapezoid::upperLeft);
        tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerLeft), Trapezoid::lowerLeft);
        /* check if it is degenere because chain or triangle */
        if(PointUtils::checkDegenere(buildArea.top().p1(), tCenterTop->getVertex(Trapezoid::topLeft))){
              setNeighborOfNeighborLeftSide(nullptr, tCenterBottom, buildArea);
        }
        else {
            setNeighborOfNeighborLeftSide(tCenterTop, tCenterBottom, buildArea);
        }
    }
}


/**
 * @brief simpleCaseAdjacencyRight build the adjacency for the simple insertion case: right step
 * @param tRight
 * @param tCenterBottom
 * @param tCenterTop
 * @param buildArea
 */
void simpleCaseAdjacencyRight(Trapezoid * tRight, Trapezoid * tCenterBottom, Trapezoid * tCenterTop, const Trapezoid& buildArea)
{
    if(tRight != nullptr){
        tRight->setAdjacents(buildArea.getAdjacent(Trapezoid::upperRight), tCenterTop, tCenterBottom, buildArea.getAdjacent(Trapezoid::lowerRight));
        tCenterTop->setAdjacent(tRight, Trapezoid::upperRight);
        tCenterTop->setAdjacent(tRight, Trapezoid::lowerRight);
        tCenterBottom->setAdjacent(tRight, Trapezoid::upperRight);
        tCenterBottom->setAdjacent(tRight, Trapezoid::lowerRight);
        setNeighborOfNeighborRightSide(tRight, tRight, buildArea);
    }
    else {
        tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperRight), Trapezoid::upperRight);
        tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperRight), Trapezoid::lowerRight);
        tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerRight), Trapezoid::upperRight);
        tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerRight), Trapezoid::lowerRight);
        /* check if it is degenere because chain or triangle */
        if(PointUtils::checkDegenere(buildArea.top().p2(), tCenterBottom->getVertex(Trapezoid::topRight))){
              setNeighborOfNeighborRightSide(nullptr, tCenterBottom, buildArea);
        }
        else {
            setNeighborOfNeighborRightSide(tCenterTop, tCenterBottom, buildArea);
        }
    }
}


/* twoIntewrestedTrapezoids Adjacency */

/**
 * @brief twoInterestedTrapezoidsBuildAdjacency build the adjacency for the twoInterestedTrapezoids insertion case
 * @param tLeft
 * @param tRight
 * @param tCenter1
 * @param tCenter2
 * @param tCenter3
 * @param buildArea
 * @param segmentAboveRightP
 */
void twoInterestedTrapezoidsBuildAdjacency(Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenter1, Trapezoid * tCenter2, Trapezoid * tCenter3, const std::vector<Trapezoid*>& buildArea, const bool& segmentAboveRightP)
{

    assert(tLeft != nullptr && tRight != nullptr);

    switch(twoInterestedTrapezoidsEvaluateAdjacencyCase(buildArea, segmentAboveRightP)){
        case 1:
            tLeft->setAdjacents(tCenter1, buildArea[0]->getAdjacent(Trapezoid::upperLeft), buildArea[0]->getAdjacent(Trapezoid::lowerLeft), tCenter2);
            tCenter1->setAdjacents(tRight, tLeft, tLeft, tRight);
            tCenter2->setAdjacents(tCenter3, tLeft, tLeft, buildArea[0]->getAdjacent(Trapezoid::lowerRight));
            tCenter3->setAdjacents(tRight, tCenter2, tCenter2, tRight);
            tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter1, tCenter3, buildArea[1]->getAdjacent(Trapezoid::lowerRight));
        break;

        case 2:
            tLeft->setAdjacents(tCenter1, buildArea[0]->getAdjacent(Trapezoid::upperLeft), buildArea[0]->getAdjacent(Trapezoid::lowerLeft), tCenter2);
            tCenter1->setAdjacents(buildArea[0]->getAdjacent(Trapezoid::upperRight), tLeft, tLeft, tCenter3);
            tCenter2->setAdjacents(tRight, tLeft, tLeft, tRight);
            tCenter3->setAdjacents(tRight, tCenter1, tCenter1, tRight);
            tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter3, tCenter2, buildArea[1]->getAdjacent(Trapezoid::lowerRight));
        break;

        case 3:
            tLeft->setAdjacents(tCenter1, buildArea[0]->getAdjacent(Trapezoid::upperLeft), buildArea[0]->getAdjacent(Trapezoid::lowerLeft), tCenter2);
            tCenter1->setAdjacents(tRight, tLeft, tLeft, tRight);
            tCenter2->setAdjacents(tCenter3, tLeft, tLeft, tCenter3);
            tCenter3->setAdjacents(tRight, tCenter2, buildArea[1]->getAdjacent(Trapezoid::lowerLeft), tRight);
            tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter1, tCenter3, buildArea[1]->getAdjacent(Trapezoid::lowerRight));
            /* The lower left neighbor of buildArea [1] is not an interested trapezoid but is needed to update adjacency, if not followSegment doesn't work properly  */
            if(buildArea[1]->getAdjacent(Trapezoid::lowerLeft)->getAdjacent(Trapezoid::upperRight) == buildArea[1]){
                buildArea[1]->getAdjacent(Trapezoid::lowerLeft)->setAdjacent(tCenter3, Trapezoid::upperRight);
            }
            if(buildArea[1]->getAdjacent(Trapezoid::lowerLeft)->getAdjacent(Trapezoid::lowerRight) == buildArea[1]){
                buildArea[1]->getAdjacent(Trapezoid::lowerLeft)->setAdjacent(tCenter3, Trapezoid::lowerRight);
            }
        break;

        case 4:
            tLeft->setAdjacents(tCenter1, buildArea[0]->getAdjacent(Trapezoid::upperLeft), buildArea[0]->getAdjacent(Trapezoid::lowerLeft), tCenter2);
            tCenter1->setAdjacents(tCenter3, tLeft, tLeft, tCenter3);
            tCenter2->setAdjacents(tRight, tLeft, tLeft, tRight);
            tCenter3->setAdjacents(tRight, buildArea[1]->getAdjacent(Trapezoid::upperLeft), tCenter1, tRight);
            tRight->setAdjacents(buildArea[1]->getAdjacent(Trapezoid::upperRight), tCenter3, tCenter2, buildArea[1]->getAdjacent(Trapezoid::lowerRight));
            /* The upperRight neighbor of buildArea [1] is not an interested trapezoid but is needed to update adjacency, if not followSegment doesn't work properly  */
            if(buildArea[1]->getAdjacent(Trapezoid::upperLeft)->getAdjacent(Trapezoid::upperRight) == buildArea[1]){
                buildArea[1]->getAdjacent(Trapezoid::upperLeft)->setAdjacent(tCenter3, Trapezoid::upperRight);
            }
            if(buildArea[1]->getAdjacent(Trapezoid::upperLeft)->getAdjacent(Trapezoid::lowerRight) == buildArea[1]){
                buildArea[1]->getAdjacent(Trapezoid::upperLeft)->setAdjacent(tCenter3, Trapezoid::lowerRight);
            }
        break;
    }

    setNeighborOfNeighborLeftSide(tLeft, tLeft, *buildArea[0]);
    setNeighborOfNeighborRightSide(tRight, tRight, *buildArea[1]);
}


/**
 * @brief twoInterestedTrapezoidsEvaluateAdjacencyCase: there are 4 possible variants of case 2
 *  this function evaluates in which case we are.
 * @param buildArea
 * @param segmentAboveRightP
 * @return
 */
inline int twoInterestedTrapezoidsEvaluateAdjacencyCase(const std::vector<Trapezoid*>& buildArea, const bool& segmentAboveRightP)
{
    if(segmentAboveRightP){
        if(buildArea[0]->bottom().p2().y() < buildArea[1]->bottom().p1().y()){
            return 1;
        }
        else {
            return 3;
        }
    }
    else {
        if(buildArea[0]->top().p2().y() > buildArea[1]->top().p1().y()){
            return 2;
        }
        else {
            return 4;
        }
    }
}


/* Neighbors adjacency */

/**
 * @brief setNeighborOfNeighborLeftSide
 * @param insertedLeft
 * @param buildArea
 */
void setNeighborOfNeighborLeftSide(Trapezoid * insertedLeftUpper, Trapezoid * insertedLeftLower, const Trapezoid& buildArea)
{
    Trapezoid * upperLeft = buildArea.getAdjacent(Trapezoid::upperLeft);
    Trapezoid * lowerLeft = buildArea.getAdjacent(Trapezoid::lowerLeft);

    if(upperLeft != nullptr && insertedLeftUpper != nullptr){
        /* resolve upperLeft */
        if (*(upperLeft->getAdjacent(Trapezoid::upperRight)) == buildArea){
            upperLeft->setAdjacent(insertedLeftUpper, Trapezoid::upperRight);
        }
        if (*(upperLeft->getAdjacent(Trapezoid::lowerRight)) == buildArea){
            upperLeft->setAdjacent(insertedLeftUpper, Trapezoid::lowerRight);
        }
    }
    if(lowerLeft != nullptr && insertedLeftLower != nullptr){
        /* resolve lowerLeft */
        if (*(lowerLeft->getAdjacent(Trapezoid::upperRight)) == buildArea && lowerLeft != upperLeft){
            lowerLeft->setAdjacent(insertedLeftLower, Trapezoid::upperRight);
        }
        if (*(lowerLeft->getAdjacent(Trapezoid::lowerRight)) == buildArea){
            lowerLeft->setAdjacent(insertedLeftLower, Trapezoid::lowerRight);
        }
    }

}


/**
 * @brief setNeighborOfNeighborRightSide
 * @param insertedRight
 * @param buildArea
 */
void setNeighborOfNeighborRightSide(Trapezoid * insertedRightUpper, Trapezoid * insertedRightLower, const Trapezoid& buildArea)
{
    Trapezoid * upperRight = buildArea.getAdjacent(Trapezoid::upperRight);
    Trapezoid * lowerRight = buildArea.getAdjacent(Trapezoid::lowerRight);

    if(upperRight != nullptr && insertedRightUpper != nullptr){
        /* resolve upperLeft */
        if (*(upperRight->getAdjacent(Trapezoid::upperLeft)) == buildArea){
            upperRight->setAdjacent(insertedRightUpper, Trapezoid::upperLeft);
        }
        if (*(upperRight->getAdjacent(Trapezoid::lowerLeft)) == buildArea){
            upperRight->setAdjacent(insertedRightUpper, Trapezoid::lowerLeft);
        }
    }

    if(lowerRight != nullptr && insertedRightLower != nullptr){
        /* resolve lowerLeft */
        if (*(lowerRight->getAdjacent(Trapezoid::upperLeft)) == buildArea && lowerRight != upperRight){
            lowerRight->setAdjacent(insertedRightLower, Trapezoid::upperLeft);
        }
        if (*(lowerRight->getAdjacent(Trapezoid::lowerLeft)) == buildArea){
            lowerRight->setAdjacent(insertedRightLower, Trapezoid::lowerLeft);
        }
    }
}


/*-------------------------------------------------------------------------*
 *
 * Dag update step
 *
 *-------------------------------------------------------------------------*/

/**
 * @brief simpleCaseDagUpdate: dag update for the simple case insertion, only a leaf is substituted
 * @param insertedSegment
 * @param tLeft
 * @param tRight
 * @param tCenterTop
 * @param tCenterBottom
 * @param buildArea
 * @param dag
 */
void simpleCaseDagUpdate(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenterTop, Trapezoid * tCenterBottom, Trapezoid * buildArea, Dag * dag)
{
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
    *(buildArea->dagRef()) = *(insertionRoot);
    buildArea->deactivate();
}


/**
 * @brief twoInterestedTrapezoidsDagUpdate: update the dag for twoInterestedTrapezoidsInsertion case (2 leaf interested)
 * @param insertedSegment
 * @param tLeft
 * @param tRight
 * @param tCenter1
 * @param tCenter2
 * @param tCenter3
 * @param buildArea
 * @param dag
 * @param segmentAboveRightP
 */
void twoInterestedTrapezoidsDagUpdate(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenter1, Trapezoid * tCenter2, Trapezoid * tCenter3, std::vector<Trapezoid *>& buildArea, Dag * dag, const bool& segmentAboveRightP)
{
    /* Dag */

    /* leaf nodes, I declare they now because it is important to use the same node and not a same value node */
    Node * node_tLeft = createLeafNode(tLeft, dag);
    Node * node_tCenter1 = createLeafNode(tCenter1, dag);
    Node * node_tCenter2 = createLeafNode(tCenter2, dag);
    Node * node_tCenter3 = createLeafNode(tCenter3, dag);
    Node * node_tRight = createLeafNode(tRight, dag);

    /* Substitute buildArea[0]->dagRef() */
    /* root: substitute trapezoid with insertedSegment.p1 */
    Node * insertionRoot1 = dag->addNode(Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y())));
    /* root > left_child: tLeft */
    insertionRoot1->setLeftChild(node_tLeft);
    /* root > right_child: inserted_segment */
    insertionRoot1->setRightChild(dag->addNode(Node(new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2()))));
    /* root > right_child > left_child > tCenter1 */
    insertionRoot1->rightChild()->setLeftChild(node_tCenter1);
    /* root > right_child > right_child > tCenter2 */
    insertionRoot1->rightChild()->setRightChild(node_tCenter2);

    // replace node
    buildArea[0]->deactivate();
    *(buildArea[0]->dagRef()) = *(insertionRoot1);


    /* Substitute buildArea[1]->dagRef() */
    /* root: substitute trapezoid with insertedSegment.p2 */
    Node * insertionRoot2 = dag->addNode(Node(Node::p, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y())));
    /* root > right_child: tRight */
    insertionRoot2->setRightChild(node_tRight);
    /* root > left_child: inserted_segment */
    insertionRoot2->setLeftChild(dag->addNode(Node(new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2()))));

    if(segmentAboveRightP){
        /* root > left_child > left_child > tCenter1 */
        insertionRoot2->leftChild()->setLeftChild(node_tCenter1);
        /* root > left_child > right_child > tCenter3 */
        insertionRoot2->leftChild()->setRightChild(node_tCenter3);
    }
    else {
        /* root > left_child > left_child > tCenter3 */
        insertionRoot2->leftChild()->setLeftChild(node_tCenter3);
        /* root > left_child > right_child > tCenter2 */
        insertionRoot2->leftChild()->setRightChild(node_tCenter2);
    }

    buildArea[1]->deactivate();
   *(buildArea[1]->dagRef()) = *(insertionRoot2);
}

}
