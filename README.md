# [GAS] Final project

<br/>

## Repository

https://github.com/marinimau/GAS-Trapezoidal-maps-final-prject
<br/>

## Project Organization
The organization of the project is as follows:
<br/><br/><br/>
### Algorithms
#### TrapezoidalMapBuilder
contains the algorithms for the construction of the trapezoidal
map and the dag.
The flow of construction is as follows:

1. Segment normalization (leftP.x < right.P)
2. FollowSegment
3. Evaluation of the number of trapezoid interested by the insertion:
    a. Simple insertion
    b. Two interested trapezoids insertion
    c. Many: combine methods of a and b.
4. In all three cases the flow of the insertion is:
    a. Create new trapezoids
    b. Update internal and external adjacencies
    c. Update the dag
    d. Deactivate old trapezoids.


#### TrapezoidalMap Query: 
Implements the methods to execute a point query on the dag.
<br/><br/><br/>


### Data Structures
#### Dag
Implements the dag (a pointer to the root, and a list to store the nodes to avoid
dynamic allocation).
<br/>

#### Node
data structure used to save the nodes of the dag. It has an attribute “type” to
specify the type of the node (p, q, segment, trapezoid). Each node has an attribute value
that points at the object linked to the node. Node also has pointers to left and right
childs.
<br/>

#### SegmentIntesectionChecker 
Already implemented.
<br/>

#### Trapezoid
data Structure used to store the single trapezoid using: topSegment,
bottomSegment, leftP and rightP, saves also 4 pointers to manage the adjacency, and a
pointer to the node that saves it in the dag.
<br/>

#### TrapezoidalMap 
data structure used to save all the trapezoids of the trapezoidalMap
(using list). Save also a pointer to the trapezoids resulting from the pointQuery, it is used by the drawable to enhance it.
<br/>

#### TrapezoidalMapDataset 
Already implemented.
<br/>

####  VerticalSegment
used to manage the vertical segment separately in the ui. Vertical
segments are obtained from the list of trapezoids.
<br/><br/><br/>


### Drawables
#### DrawableTrapezoid
drawable for the trapezoids of the trapezoidalMap

#### DrawableVerticalSegment
drawable for the vertical segments of the trapezoidalMap
<br/><br/><br/>

### Managers
#### TrapezoidalMapManager
Already implemented.
<br/><br/><br/>

### Utils
#### ConsistenceChecker
Implements some tests which are executed at each segment
insertion. It is evaluated:
1. The correctness of followSegment output
2. The equality of the sum of the areas of the trapezoids affected by the insertion
    and those inserted in their place.
3. The correctness of adjacencies

**These tests heavily affect performance** , for this reason they are executed only in debug
mode.

#### FileUtils
Already implemented.

#### FillColor
contains a method to calculate the fill color of each trapezoids based on the
value of its vertices.

#### PointUtils 
contains methods for calculate intersections, evaluate if 2 points are
degenerate and others.
<br/><br/><br/>

## Results

Tests are performed with the provided dataset and in release mode (except for 10.000). Time
expressed in seconds

```
random10.txt 	4.4e-05
random20.txt 	9.5e-05
random40.txt 	0.000178
random50.txt 	0.000228
random100.txt 	0.000464
random500.txt 	0.001485
random1000.txt  0.002385
random2000.txt  0.005249
random5000.txt  0.014229
Random 10000 	0.034327
```
<br/><br/><br/>

## Screenshot

![1]()
