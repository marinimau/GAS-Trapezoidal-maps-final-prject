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
void evaluateSegmentInserted(const cg3::Segment2d& insertedSegment, DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{
    assert(dag->root() != nullptr);

    /* segment normalization p1.x < p2.x */
    cg3::Segment2d normalizedSegment = normalizeSegment(insertedSegment);

    /* 1. check interested trapezoids */
    std::vector<Trapezoid *> interestedTrapezoids = followSegment(normalizedSegment, dag);

    /* check for correctness followsegment output */
    assert(ConsistenceChecker::checkForWrongBuildArea(normalizedSegment, interestedTrapezoids));

    switch(interestedTrapezoids.size()){
        case 1:
            /* 2.a Simple insertion */
            oneInterestedTrapezoid(normalizedSegment, interestedTrapezoids, drawableTrapezoid, dag);
        break;
        case 2:
            /* 2.b the new segment intersects 2 trapezoids */
           twoInterestedTrapezoidsInsertion(normalizedSegment, interestedTrapezoids, drawableTrapezoid, dag);
        break;
        default:
            /* 2.c the new segment intersects more than two trapezoid */
           manyInterestedTrapezoidsInsertion(normalizedSegment, interestedTrapezoids, drawableTrapezoid, dag);
    }

    /* check adjacence consistency */
    assert(ConsistenceChecker::adjacencyOk(drawableTrapezoid.getTrapezoids()));

    // if debug, print dag nodes (inorder)
    #ifdef QT_DEBUG
    //dag->inOrderVisit(dag->root());
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
    const cg3::Point2d *p = &normalizedSegment.p1(), *q = &normalizedSegment.p2();
    std::vector<Trapezoid *> interestedTrapezoids;

    /* Search with p in the search strucutre D to find T */
    bool isDegenere = false;
    Trapezoid * t = TrapezoidalmapQuery::pointQuery(*p, dag->root(), isDegenere, q);

    assert(t != nullptr);

    /* insert the first trapezoid */
    interestedTrapezoids.push_back(t);

    /* while q lies to the right of rightp */
    while (t != nullptr && q->x() > t->rightP().x()){

        double yAtRightP = PointUtils::evaluateYValue(*p, *q, t->rightP().x());

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


/*-------------------------------------------------------------------------*
 *
 * Insertion Cases
 *
 *-------------------------------------------------------------------------*/

/**
 * @brief oneInterestedTrapezoidInsertion: Base case, the new segment is fully contained in a unique trapezoid (or there are not any other segments)
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 */
void oneInterestedTrapezoid(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, Dag * dag)
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
    simpleCaseBuildAdjacency(insertedSegment, tLeft, tRight, tCenterTop, tCenterBottom, *(buildArea[0]));

    /* update dag */
    simpleCaseDagUpdate(insertedSegment, tLeft, tRight, tCenterTop, tCenterBottom, buildArea[0], dag);

    /* delet old trapezoid */
    buildArea[0]->deactivate();

}


/**
 * @brief twoInterestedTrapezoidsInsertion, in this case the inserted Segment cross two trapezoids
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
    std::tuple<Trapezoid *, Trapezoid *, Trapezoid *> centerTrapezoids = twoInterestedTrapezoidsBuildCenterTrapezoids(insertedSegment, buildArea, drawableTrapezoid, segmentAboveRightP);
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
    twoInterestedTrapezoidsBuildAdjacency(insertedSegment, tLeft, tRight, tCenter1, tCenter2, tCenter3, buildArea, segmentAboveRightP);

    /* Dag update */
    twoInterestedTrapezoidsDagUpdate(insertedSegment, tLeft, tRight, tCenter1, tCenter2, tCenter3, buildArea, dag, segmentAboveRightP);

    /* Delete old trapezoids */
    buildArea[0]->deactivate();
    buildArea[1]->deactivate();
}


/**
 * @brief manyInterestedTrapezoidsInsertion, in this case the inserted Segment cross more than two trapezoids
 * @param insertedSegment
 * @param buildArea
 * @param drawableTrapezoid
 * @param dag
 */
void manyInterestedTrapezoidsInsertion(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, Dag * dag)
{
    /* left and right trapezoids */
    std::tuple<Trapezoid *, Trapezoid *> leftAndRightTrapezoid = addLeftAndRightTrapezoid(insertedSegment, buildArea, drawableTrapezoid);
    Trapezoid * tLeft = std::get<0>(leftAndRightTrapezoid);
    Trapezoid * tRight = std::get<1>(leftAndRightTrapezoid);

    Node *node_tLeft = createLeafNode(tLeft, dag);
    Node *node_tRight = createLeafNode(tRight, dag);

    /* contains the leftP */
    cg3::Point2d leftSplit = insertedSegment.p1();
    /* flags for intermediate trapezoids creation */
    bool createTop = true, createBottom = true;

    Trapezoid *tTop = nullptr, *tBottom = nullptr, *previous_tTop = nullptr, *previous_tBottom = nullptr;
    Node *node_tTop = nullptr, *node_tBottom = nullptr;

    bool segmentAboveRightP = false;

    for(size_t i = 0; i < buildArea.size(); i++){

        if(i != 0){
            /* update leftSplit */
            leftSplit = buildArea[i]->leftP();
        }
        /* if tTop must be created, create it and its dag node */
        if(createTop){
            tTop = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[i]->top(), insertedSegment, leftSplit, buildArea[i]->rightP()));
            node_tTop = createLeafNode(tTop, dag);
            createTop = false;
        }
        /* if tBottom must be created, create it and its dag node */
        if(createBottom){
            tBottom = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[i]->bottom(), leftSplit, buildArea[i]->rightP()));
            node_tBottom = createLeafNode(tBottom, dag);
            createBottom = false;
        }

        /* evaluate segment position with respect to rightP */
        segmentAboveRightP = buildArea[i]->rightP().y() <= PointUtils::evaluateYValue(insertedSegment.p1(), insertedSegment.p2(), buildArea[i]->rightP().x());

        if(segmentAboveRightP){
            /* tBottom must be closed and a new tBottom is created */
            tBottom->setRightP(buildArea[i]->rightP());
            createBottom = true;
        }
        else{
            /* tTop must be closed and a new tTop is created */
            tTop->setRightP(buildArea[i]->rightP());
            createTop = true;
        }

        if(i == buildArea.size() - 1){
            tTop->setRightP(insertedSegment.p2());
            tBottom->setRightP(insertedSegment.p2());

        }

        /* call adjacency update */
        manyInterestedTrapezoidsBuildAdjacency(insertedSegment, tLeft, tRight, tTop, tBottom, previous_tTop, previous_tBottom, buildArea, i);

        if(previous_tTop == nullptr || previous_tTop->leftP() != tTop->leftP()){
            previous_tTop = tTop;
        }
        if(previous_tBottom == nullptr || previous_tBottom->leftP() != tBottom->leftP()){
            previous_tBottom = tBottom;
        }

        /* call dag update */
        manyInterestedTrapezoidsDagUpdateStep(insertedSegment, node_tLeft, node_tRight, node_tTop, node_tBottom, buildArea, dag, i);

        /* deactivate the old trapezoid */
        buildArea[i]->deactivate();

    }
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

    /* In the following lines i have checked a lot of cases instead of check only x value, this because round of xcordinates can introduce points in generic positionS */

    /* if inserted segment.p1.x != buildArea.leftP.x build left trapezoid */
    if(
            !(PointUtils::checkDegenerate(insertedSegment.p1(), buildArea[0]->getVertex(Trapezoid::topLeft)) ||
              PointUtils::checkDegenerate(insertedSegment.p1(), buildArea[0]->getVertex(Trapezoid::bottomLeft)) ||
              (buildArea[0]->getAdjacent(Trapezoid::upperLeft) != nullptr && PointUtils::checkDegenerate(insertedSegment.p1(), buildArea[0]->getAdjacent(Trapezoid::upperLeft)->getVertex(Trapezoid::bottomRight))) ||
              (buildArea[0]->getAdjacent(Trapezoid::lowerLeft) != nullptr && PointUtils::checkDegenerate(insertedSegment.p1(), buildArea[0]->getAdjacent(Trapezoid::lowerLeft)->getVertex(Trapezoid::topRight))))){
        tLeft = addLeftTrapezoid(insertedSegment, *buildArea[0], drawableTrapezoid);
    }
    /* if inserted segment.p2.x != buildArea.rightP.x build right trapezoid */
    if(
            !(PointUtils::checkDegenerate(insertedSegment.p2(), buildArea[buildArea.size()-1]->getVertex(Trapezoid::topRight)) ||
              PointUtils::checkDegenerate(insertedSegment.p2(), buildArea[buildArea.size()-1]->getVertex(Trapezoid::bottomRight)) ||
              (buildArea[buildArea.size()-1]->getAdjacent(Trapezoid::upperRight) != nullptr && PointUtils::checkDegenerate(insertedSegment.p2(), buildArea[buildArea.size()-1]->getAdjacent(Trapezoid::upperRight)->getVertex(Trapezoid::bottomLeft))) ||
              (buildArea[buildArea.size()-1]->getAdjacent(Trapezoid::lowerRight) != nullptr && PointUtils::checkDegenerate(insertedSegment.p2(), buildArea[buildArea.size()-1]->getAdjacent(Trapezoid::lowerRight)->getVertex(Trapezoid::topLeft))))){
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
std::tuple<Trapezoid *, Trapezoid *, Trapezoid *> twoInterestedTrapezoidsBuildCenterTrapezoids(const cg3::Segment2d& insertedSegment, std::vector<Trapezoid *>& buildArea, DrawableTrapezoid& drawableTrapezoid, bool& segmentAboveRightP)
{
    /* pointers for center trapezoids */
    Trapezoid * tCenter1 = nullptr;
    Trapezoid * tCenter2 = nullptr;
    Trapezoid * tCenter3 = nullptr;

    /* between tLeft and tRight there are 3 trapezoid. There are 2 possible configuration according to the u of buildArea[0].rightP */
    segmentAboveRightP = buildArea[0]->rightP().y() <= PointUtils::evaluateYValue(insertedSegment.p1(), insertedSegment.p2(), buildArea[0]->rightP().x());

    /* the positions of center trapezoids may change, there are two cases and they are managed separately */
    /* case 1 */
    if(segmentAboveRightP){
        tCenter1 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(), buildArea[0]->rightP()));
        tCenter2 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(),insertedSegment.p2()));
        tCenter3 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[1]->bottom(), buildArea[1]->leftP(), insertedSegment.p2()));
    }
    /* case 2 */
    else {
        tCenter1 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[0]->top(), insertedSegment, insertedSegment.p1(), buildArea[0]->rightP()));
        tCenter2 = drawableTrapezoid.addTrapezoid(Trapezoid(insertedSegment, buildArea[0]->bottom(), insertedSegment.p1(), insertedSegment.p2()));
        tCenter3 = drawableTrapezoid.addTrapezoid(Trapezoid(buildArea[1]->top(), insertedSegment, buildArea[1]->leftP(), insertedSegment.p2()));
    }
    return {tCenter1, tCenter2, tCenter3};

}


/*-------------------------------------------------------------------------*
 *
 * Adjacency update step
 *
 *-------------------------------------------------------------------------*/

/* general */

/**
 * @brief buildAdjacencyLeft build the adjacency for the simple insertion case: left step
 * @param insertedSegment
 * @param tLeft
 * @param tCenterBottom
 * @param tCenterTop
 * @param buildArea
 */
void buildAdjacencyLeft(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tCenterBottom, Trapezoid * tCenterTop, const Trapezoid& buildArea)
{
    /*
     * There are 4 possible cases:
     * 1. base case, p1 is not a degenerate point
     * 2. p1 is a degenerate point and it is a triangle vertex in the topLeft vertex of buildArea
     * 3. p1 is a degenerate point and it is a triangle vertex in the bottomLeft vertex of buildArea
     * 4. p1 is a degenerate point but its position isn't in a vertex of build area
     */
    if(tLeft != nullptr){
        /* insertedsSegment.p1 not degnerate */
        tLeft->setAdjacents(tCenterTop, buildArea.getAdjacent(Trapezoid::upperLeft), buildArea.getAdjacent(Trapezoid::lowerLeft), tCenterBottom);
        setNeighborOfNeighborLeftSide(tLeft, tLeft, buildArea);
    }
    else {
        if(PointUtils::checkDegenerate(insertedSegment.p1(), buildArea.getVertex(Trapezoid::topLeft))){
            /* triangle 1 */
            tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::upperLeft), Trapezoid::upperLeft);
            tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerLeft), Trapezoid::lowerLeft);
            setNeighborOfNeighborLeftSide(tCenterBottom, tCenterBottom, buildArea);
        }
        else {
            if(PointUtils::checkDegenerate(insertedSegment.p1(), buildArea.getVertex(Trapezoid::bottomLeft))) {
                /* triangle 2 */
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperLeft), Trapezoid::upperLeft);
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerLeft), Trapezoid::lowerLeft);
                setNeighborOfNeighborLeftSide(tCenterTop, tCenterTop, buildArea);
            }
            else {
                /* segment chain */
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperLeft), Trapezoid::upperLeft);
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperLeft), Trapezoid::lowerLeft);
                tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerLeft), Trapezoid::upperLeft);
                tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerLeft), Trapezoid::lowerLeft);
                setNeighborOfNeighborLeftSide(tCenterTop, tCenterBottom, buildArea);
            }
        }
    }
}


/**
 * @brief buildAdjacencyRight build the adjacency for the simple insertion case: right step
 * @param insertedSegment
 * @param tRight
 * @param tCenterBottom
 * @param tCenterTop
 * @param buildArea
 */
void buildAdjacencyRight(const cg3::Segment2d& insertedSegment, Trapezoid * tRight, Trapezoid * tCenterBottom, Trapezoid * tCenterTop, const Trapezoid& buildArea)
{
    /*
     * There are 4 possible cases:
     * 1. base case, p2 is not a degenerate point
     * 2. p2 is a degenerate point and it is a triangle vertex in the topRight vertex of buildArea
     * 3. p2 is a degenerate point and it is a triangle vertex in the bottomRight vertex of buildArea
     * 4. p2 is a degenerate point but its position isn't in a vertex of build area
     */
    if(tRight != nullptr){
        /* insertedsSegment.p2 not degnere */
        tRight->setAdjacents(buildArea.getAdjacent(Trapezoid::upperRight), tCenterTop, tCenterBottom, buildArea.getAdjacent(Trapezoid::lowerRight));
        setNeighborOfNeighborRightSide(tRight, tRight, buildArea);
    }
    else {
        if(PointUtils::checkDegenerate(insertedSegment.p2(), buildArea.getVertex(Trapezoid::topRight))){
            /* triangle 1 */
            tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::upperRight), Trapezoid::upperRight);
            tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerRight), Trapezoid::lowerRight);
            setNeighborOfNeighborRightSide(tCenterBottom, tCenterBottom, buildArea);
        }
        else {
            if(PointUtils::checkDegenerate(insertedSegment.p2(), buildArea.getVertex(Trapezoid::bottomRight))) {
                /* triangle 2 */
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperRight), Trapezoid::upperRight);
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerRight), Trapezoid::lowerRight);
                setNeighborOfNeighborRightSide(tCenterTop, tCenterTop, buildArea);
            }
            else {
                /* segment chain */
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperRight), Trapezoid::upperRight);
                tCenterTop->setAdjacent(buildArea.getAdjacent(Trapezoid::upperRight), Trapezoid::lowerRight);
                tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerRight), Trapezoid::upperRight);
                tCenterBottom->setAdjacent(buildArea.getAdjacent(Trapezoid::lowerRight), Trapezoid::lowerRight);
                setNeighborOfNeighborRightSide(tCenterTop, tCenterBottom, buildArea);
            }
        }
    }
}


/* simple case */

/**
 * @brief simpleCaseBuildAdjacency: build the adjacency for the simple insertion case
 * @param insertedSegment
 * @param tLeft
 * @param tRight
 * @param tCenterTop
 * @param tCenterBottom
 * @param buildArea
 */
void simpleCaseBuildAdjacency(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenterTop, Trapezoid * tCenterBottom, const Trapezoid& buildArea)
{
    /* only one possible case */
    tCenterTop->setAdjacents(tRight, tLeft, tLeft, tRight);
    tCenterBottom->setAdjacents(tRight, tLeft, tLeft, tRight);
    /* left step */
    buildAdjacencyLeft(insertedSegment, tLeft, tCenterBottom, tCenterTop, buildArea);
    /* right step */
    buildAdjacencyRight(insertedSegment, tRight, tCenterBottom, tCenterTop, buildArea);
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
void twoInterestedTrapezoidsBuildAdjacency(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenter1, Trapezoid * tCenter2, Trapezoid * tCenter3, const std::vector<Trapezoid*>& buildArea, const bool& segmentAboveRightP)
{
    /* internal */
    twoInterestedTrapezoidsAdjacencyInternal(tLeft, tRight, tCenter1, tCenter2, tCenter3, segmentAboveRightP);
    /* exceptions */
    handleAdjacencyExceptions(tCenter1, tCenter3, buildArea, 0, evaluateExternalNeighboors(buildArea, segmentAboveRightP, 0));
    /* external */
    twoInterestedTrapezoidsAdjacencyExternal(insertedSegment, tLeft, tRight, tCenter1, tCenter2, tCenter3, buildArea, segmentAboveRightP);
}


/**
 * @brief twoInterestedTrapezoidsAdjacencyInternal: resolve internal adjacency
 * @param tLeft
 * @param tRight
 * @param tCenter1
 * @param tCenter2
 * @param tCenter3
 * @param segmentAboveRightP
 */
void twoInterestedTrapezoidsAdjacencyInternal(Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenter1, Trapezoid * tCenter2, Trapezoid * tCenter3, const bool& segmentAboveRightP)
{
    /* internals */
    tCenter1->setAdjacents(tCenter3, tLeft, tLeft, tCenter3);
    tCenter2->setAdjacents(tRight, tLeft, tLeft, tRight);
    tCenter3->setAdjacents(tRight, tCenter1, tCenter1, tRight);

    Trapezoid *aUR = nullptr, *aLR = nullptr, *eUL = nullptr, *eLL = nullptr;

    /* 2 possible cases based on the position of insertedSegment respect to buildArea[0].rightP */
    if(segmentAboveRightP){
        aUR = tCenter2;
        aLR = tCenter1;
        eUL = tCenter2;
        eLL = tCenter3;
    }
    else {
        aUR = tCenter1;
        aLR = tCenter2;
        eUL = tCenter3;
        eLL = tCenter2;
    }

    assert(aUR != nullptr && aLR != nullptr && eUL != nullptr && eLL != nullptr);

    /* set adjacents for left and right trapezoids (only internals) */
    if(tLeft != nullptr){
        tLeft->setAdjacents(aUR, nullptr, nullptr, aLR);
    }
    if(tRight != nullptr){
        tRight->setAdjacents(nullptr, eUL, eLL, nullptr);
    }
}


/**
 * @brief twoInterestedTrapezoidsAdjacencyExternal: set the external adjacency
 * @param insertedSegment
 * @param tLeft
 * @param tRight
 * @param tCenter1
 * @param tCenter2
 * @param tCenter3
 * @param buildArea
 * @param segmentAboveRightP
 */
void twoInterestedTrapezoidsAdjacencyExternal(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tCenter1, Trapezoid * tCenter2, Trapezoid * tCenter3, const std::vector<Trapezoid*>& buildArea, const bool& segmentAboveRightP)
{
    Trapezoid *aUR = nullptr, *aLR = nullptr, *eUL = nullptr, *eLL = nullptr;

    /* resolve difference in position before set adjacents left and right trapezoid */
    if(segmentAboveRightP){
        aUR = tCenter2;
        aLR = tCenter1;
        eUL = tCenter2;
        eLL = tCenter3;
    }
    else {
        aUR = tCenter1;
        aLR = tCenter2;
        eUL = tCenter3;
        eLL = tCenter2;
    }

    assert(aUR != nullptr && aLR != nullptr && eUL != nullptr && eLL != nullptr);

    buildAdjacencyLeft(insertedSegment, tLeft, aLR, aUR, *buildArea[0]);
    buildAdjacencyRight(insertedSegment, tRight, eLL, eUL, *buildArea[1]);

}


/* more than 2 interestedTrapezoids Adjacency */

/**
 * @brief manyInterestedTrapezoidsBuildAdjacency
 * @param insertedSegment
 * @param tLeft
 * @param tRight
 * @param tTop
 * @param tBottom
 * @param previous_tTop
 * @param previous_tBottom
 * @param buildArea
 * @param buildAreaIndex
 */
void manyInterestedTrapezoidsBuildAdjacency(const cg3::Segment2d& insertedSegment, Trapezoid * tLeft, Trapezoid * tRight, Trapezoid * tTop, Trapezoid * tBottom, Trapezoid * previous_tTop, Trapezoid * previous_tBottom, const std::vector<Trapezoid *>& buildArea, const size_t& buildAreaIndex)
{
    /* build adjacency for the first of the interested trapezoids */
    if(buildAreaIndex == 0){
        tTop->setAdjacents(nullptr, tLeft, tLeft, nullptr);
        tBottom->setAdjacents(nullptr, tLeft, tLeft, nullptr);
        buildAdjacencyLeft(insertedSegment, tLeft, tBottom, tTop, *buildArea[buildAreaIndex]);
    }
    /* build adjacency for the last of the interested trapezoids */
    if(buildAreaIndex == (buildArea.size() -1)){
        tTop->setAdjacent(tRight, Trapezoid::upperRight);
        tTop->setAdjacent(tRight, Trapezoid::lowerRight);
        tBottom->setAdjacent(tRight, Trapezoid::upperRight);
        tBottom->setAdjacent(tRight, Trapezoid::lowerRight);
        buildAdjacencyRight(insertedSegment, tRight, tBottom, tTop, *buildArea[buildAreaIndex]);
    }

    if(buildAreaIndex > 0){

        if(tTop != previous_tTop){
            tTop->setAdjacent(previous_tTop, Trapezoid::upperLeft);
            tTop->setAdjacent(previous_tTop, Trapezoid::lowerLeft);
            if(previous_tTop->getAdjacent(Trapezoid::upperRight) == nullptr){
                previous_tTop->setAdjacent(tTop, Trapezoid::upperRight);
            }
            if(previous_tTop->getAdjacent(Trapezoid::lowerRight) == nullptr){
                previous_tTop->setAdjacent(tTop, Trapezoid::lowerRight);
            }
            /* set adjacency with external trapezoids */
            manyInterestedTrapezoidsExternalAdjacencyTop(tTop, previous_tTop, buildArea, buildAreaIndex);
        }

        if(tBottom != previous_tBottom){
            tBottom->setAdjacent(previous_tBottom, Trapezoid::upperLeft);
            tBottom->setAdjacent(previous_tBottom, Trapezoid::lowerLeft);

            if(previous_tBottom->getAdjacent(Trapezoid::upperRight) == nullptr){
                previous_tBottom->setAdjacent(tBottom, Trapezoid::upperRight);
            }
            if(previous_tBottom->getAdjacent(Trapezoid::lowerRight) == nullptr){
                previous_tBottom->setAdjacent(tBottom, Trapezoid::lowerRight);
            }
            /* set adjacency with external trapezoids */
            manyInterestedTrapezoidsExternalAdjacencyBottom(tBottom, previous_tBottom, buildArea, buildAreaIndex);
        }
    }
}


/**
 * @brief manyInterestedTrapezoidsExternalAdjacencyTop: set the adjacency between tTop and the non-interested trapezoids
 * @param tTop
 * @param previous_tTop
 * @param buildArea
 * @param buildAreaIndex
 */
void manyInterestedTrapezoidsExternalAdjacencyTop(Trapezoid * tTop, Trapezoid * previous_tTop, const std::vector<Trapezoid *>& buildArea, const size_t& buildAreaIndex)
{
    /* if an adjacency points outside of buildArea, resolve it in the new inserted trapezoids also (top trapezoids) */

    if(buildArea[buildAreaIndex - 1]->getAdjacent(Trapezoid::upperRight) != buildArea[buildAreaIndex]){
        handleAdjacencyExceptions(previous_tTop, previous_tTop, buildArea, buildAreaIndex - 1, 1);
    }
    if(buildArea[buildAreaIndex]->getAdjacent(Trapezoid::upperLeft) != buildArea[buildAreaIndex - 1]){
        handleAdjacencyExceptions(tTop, tTop, buildArea, buildAreaIndex - 1 , 2);
    }
}


/**
 * @brief manyInterestedTrapezoidsExternalAdjacencyBottom: set the adjacency between tBottom and the non-interested trapezoids
 * @param tBottom
 * @param previous_tBottom
 * @param buildArea
 * @param buildAreaIndex
 */
void manyInterestedTrapezoidsExternalAdjacencyBottom(Trapezoid * tBottom, Trapezoid * previous_tBottom, const std::vector<Trapezoid *>& buildArea, const size_t& buildAreaIndex)
{
    /* if an adjacency points outside of buildArea, resolve it in the new inserted trapezoids also (bottom trapezoids) */

    if(buildArea[buildAreaIndex - 1]->getAdjacent(Trapezoid::lowerRight) != buildArea[buildAreaIndex]){
        handleAdjacencyExceptions(previous_tBottom, previous_tBottom, buildArea, buildAreaIndex - 1, 3);
    }
    if(buildArea[buildAreaIndex]->getAdjacent(Trapezoid::lowerLeft) != buildArea[buildAreaIndex - 1]){
        handleAdjacencyExceptions(tBottom, tBottom, buildArea, buildAreaIndex - 1, 4);
    }
}


/* Adjacency exception */

/**
 * @brief handleAdjacencyExceptions: handle the external adjacency given the adjacency case
 * @param tCenter1
 * @param tCenter2
 * @param buildArea
 * @param startIndex
 * @param adjacencyCase
 */
void handleAdjacencyExceptions(Trapezoid * tCenter1, Trapezoid * tCenter3, const std::vector<Trapezoid*>& buildArea, size_t startIndex, const int& adjacencyCase)
{
    assert(adjacencyCase > 0 && adjacencyCase < 5);

    /*
     * This function is called for the 2-interested trapezoids insertion and for the many-interested trapezoid insertion. In the second case
     * tCenter1 and tCenter3 always have equal value to each other.
     */

    switch(adjacencyCase){
        case 1:
            tCenter1->setAdjacent(buildArea[startIndex]->getAdjacent(Trapezoid::upperRight), Trapezoid::upperRight);
            setNeighborOfNeighborRightSide(tCenter1, tCenter1, *buildArea[startIndex]);
            break;
        case 2:
            tCenter3->setAdjacent(buildArea[startIndex + 1]->getAdjacent(Trapezoid::upperLeft), Trapezoid::upperLeft);
            setNeighborOfNeighborLeftSide(tCenter3, tCenter3, *buildArea[startIndex + 1]);
            break;
        case 3:
            tCenter1->setAdjacent(buildArea[startIndex]->getAdjacent(Trapezoid::lowerRight), Trapezoid::lowerRight);
            setNeighborOfNeighborRightSide(tCenter1, tCenter1, *buildArea[startIndex]);
            break;
        case 4:
            tCenter3->setAdjacent(buildArea[startIndex + 1]->getAdjacent(Trapezoid::lowerLeft), Trapezoid::lowerLeft);
            setNeighborOfNeighborLeftSide(tCenter3, tCenter3, *buildArea[startIndex + 1]);
            break;
    }
}


/* Neighbors adjacency */

/**
 * @brief evaluateExternalNeighboors: there are 4 possible variants of case 2
 *  this function evaluates in which case we are.
 * @param buildArea
 * @param segmentAboveRightP
 * @param startIndex
 * @return
 */
inline int evaluateExternalNeighboors(const std::vector<Trapezoid*>& buildArea, const bool& segmentAboveRightP, const size_t startIndex)
{
    if(segmentAboveRightP){
        if(buildArea[startIndex]->getVertex(Trapezoid::bottomRight).y() < buildArea[startIndex + 1]->getVertex(Trapezoid::bottomLeft).y()){
            return 3;
        }
        else {
            return 4;
        }
    }
    else {
        if(buildArea[startIndex]->getVertex(Trapezoid::topRight).y() > buildArea[startIndex + 1]->getVertex(Trapezoid::topLeft).y()){
            return 1;
        }
        else {
            return 2;
        }
    }
}


/**
 * @brief setNeighborOfNeighborLeftSide: makes external adjacencies 2-way for the left side
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
 * @brief setNeighborOfNeighborRightSide: makes external adjacencies 2-way for the right side
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
 * @brief createLeafNode: create a leaf node and set the reference to the node just created on trapezoid.
 * @param t
 * @return
 */
Node * createLeafNode(Trapezoid * t, Dag * dag)
{
    if(t == nullptr){
        return nullptr;
    }
    /* Create a node that point to the trapezoid */
    Node * node = dag->addNode(Node(t));
    /* set the reference to the node in the trapezoid */
    t->setDagRef(node);
    /* return the node just created */
    return node;
}


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
    //Node * insertionRoot = dag->addNode(Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y())));
    Node insertionRoot = Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y()));
    /* root > left */
    if(tLeft != nullptr){
        insertionRoot.setLeftChild(createLeafNode(tLeft, dag));
    }
     /* root > right */
    insertionRoot.setRightChild(dag->addNode(Node(Node::q, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y()))));
    /* root > right > left */
    insertionRoot.rightChild()->setLeftChild(dagSegmentSplit(insertedSegment, createLeafNode(tCenterTop, dag), createLeafNode(tCenterBottom, dag), dag));
    /* root > right > right */
    if(tRight != nullptr){
        insertionRoot.rightChild()->setRightChild(createLeafNode(tRight, dag));
    }

    /* replace node */
    *(buildArea->dagRef()) = insertionRoot;
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

   // left step
    dagUpdateLeftStep(insertedSegment, node_tLeft, node_tCenter1, node_tCenter2, buildArea[0], dag, segmentAboveRightP);
    // right step
    dagUpdateRightStep(insertedSegment, node_tRight, node_tCenter2, node_tCenter3, buildArea[1], dag, segmentAboveRightP);
}


/**
 * @brief manyInterestedTrapezoidsDagUpdateStep: dag update for more than 2 interested trapezoids. This function is called at each step and not once like the 2 functions before.
 * @param insertedSegment
 * @param node_tLeft
 * @param node_tRight
 * @param node_tTop
 * @param node_tBottom
 * @param buildArea
 * @param dag
 * @param insertionCase
 */
void manyInterestedTrapezoidsDagUpdateStep(const cg3::Segment2d& insertedSegment, Node * node_tLeft, Node * node_tRight, Node * node_tTop, Node * node_tBottom, std::vector<Trapezoid *>& buildArea, Dag * dag, const size_t& buildAreaIndex)
{
    if(buildAreaIndex == 0){
        /* the same left insertion used in 2InterestedTrapezoids case */
        dagUpdateLeftStep(insertedSegment, node_tLeft, node_tTop, node_tBottom, buildArea[0], dag, false);
    }
    else {
        /* the same right insertion used in 2InterestedTrapezoids case */
        if(buildAreaIndex == (buildArea.size() - 1)){
            dagUpdateRightStep(insertedSegment, node_tRight, node_tTop, node_tBottom, buildArea[buildArea.size()-1], dag, true);
        }
        /* intermediate case,  the interested trapezoid is substituted by the segment split with tTop and tBottom as childs */
        else {
            /* replace node */
            *(buildArea[buildAreaIndex]->dagRef()) = *( dagSegmentSplit(insertedSegment, node_tTop, node_tBottom, dag));
        }
    }

}


/**
 * @brief dagUpdateLeftStep
 * @param insertedSegment
 * @param tLeft
 * @param tCenterTop
 * @param tCenterBottom
 * @param buildArea
 */
void dagUpdateLeftStep(const cg3::Segment2d& insertedSegment, Node * node_tLeft, Node * node_tCenter1,Node * node_tCenter2, Trapezoid * buildArea, Dag * dag, const bool& segmentAboveRightP)
{
    /* Substitute buildArea[0]->dagRef() */
    /* root: substitute trapezoid with insertedSegment.p1 */
    Node insertionRoot1 = Node(Node::p, new cg3::Point2d(insertedSegment.p1().x(), insertedSegment.p1().y()));
    /* root > left_child: tLeft */
    if(node_tLeft != nullptr){
        insertionRoot1.setLeftChild(node_tLeft);
    }
    if(segmentAboveRightP){
        insertionRoot1.setRightChild(dagSegmentSplit(insertedSegment, node_tCenter2, node_tCenter1, dag));
    }
    else {
        insertionRoot1.setRightChild(dagSegmentSplit(insertedSegment, node_tCenter1, node_tCenter2, dag));
    }

    /* replace node */
    *(buildArea->dagRef()) = insertionRoot1;
}


/**
 * @brief dagUpdateRightStep
 * @param insertedSegment
 * @param node_tRight
 * @param node_tCenter2
 * @param node_tCenter3
 * @param buildArea
 * @param dag
 * @param segmentAboveRightP
 */
void dagUpdateRightStep(const cg3::Segment2d& insertedSegment, Node * node_tRight, Node * node_tCenter2, Node * node_tCenter3, Trapezoid * buildArea, Dag * dag, const bool& segmentAboveRightP)
{
    /* Substitute buildArea[1]->dagRef() */
    /* root: substitute trapezoid with insertedSegment.p2 */
    Node insertionRoot2 = Node(Node::p, new cg3::Point2d(insertedSegment.p2().x(), insertedSegment.p2().y()));
    /* root > right_child: tRight */
    if( node_tRight != nullptr){
        insertionRoot2.setRightChild(node_tRight);
    }
    if(segmentAboveRightP){
        insertionRoot2.setLeftChild(dagSegmentSplit(insertedSegment, node_tCenter2, node_tCenter3, dag));
    }
    else {
        insertionRoot2.setLeftChild(dagSegmentSplit(insertedSegment, node_tCenter3, node_tCenter2, dag));
    }

   /* replace node */
   *(buildArea->dagRef()) = insertionRoot2;
}


/**
 * @brief dagSegmentSplit: given a segment and the 2 childs, returns the sub-tree
 * @param insertedSegment
 * @param node_leftChild
 * @param node_rightChild
 * @param dag
 * @return
 */
Node * dagSegmentSplit(const cg3::Segment2d& insertedSegment, Node * node_leftChild, Node * node_rightChild, Dag * dag)
{
    Node * root = dag->addNode(Node(new cg3::Segment2d(insertedSegment.p1(), insertedSegment.p2())));
    root->setLeftChild(node_leftChild);
    root->setRightChild(node_rightChild);

    return root;
}

}
