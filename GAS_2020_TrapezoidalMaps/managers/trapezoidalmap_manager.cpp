#include "trapezoidalmap_manager.h"
#include "ui_trapezoidalmapmanager.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

#include <ctime>
#include <cg3/data_structures/arrays/arrays.h>
#include <cg3/utilities/timer.h>

#include "utils/fileutils.h"

//Limits for the bounding box
//It defines where points can be added
//Do not change the following line
#define BOUNDINGBOX 1e+6



//----------------------------------------------------------------------------------------------
//                         You have to write your code in the area below.
//----------------------------------------------------------------------------------------------



/* ----- Constructors/Destructors ----- */

/**
 * @brief Default constructor of the manager
 */
TrapezoidalMapManager::TrapezoidalMapManager(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TrapezoidalMapManager),
    mainWindow(static_cast<cg3::viewer::MainWindow&>(*parent)),
    drawableBoundingBox(cg3::Point2d(-BOUNDINGBOX, -BOUNDINGBOX),
                cg3::Point2d(BOUNDINGBOX, BOUNDINGBOX)),
    firstPointSelectedColor(220, 80, 80),
    firstPointSelectedSize(5),
    isFirstPointSelected(false)
{
    //NOTE 1: you probably need to initialize some objects in the constructor. You
    //can see how to initialize an attribute in the lines above. This is C++ style
    //attribute initialization (it is different to write an assignment operator in
    //the constructor). For example, if a variable is const you can only use this
    //syntax to initialize the variable (see the bounding box).

    //NOTE 2: Try to AVOID using dynamic objects whenever it is possible (it will
    //be evaluated!). We remind C++ is not java, objects can be allocated in the
    //stack without dynamic allocation (new), so we suggest to study the slides
    //and see some examples. Avoid pointers, unless it is necessary!

    //UI setup
    ui->setupUi(this);

    //Connect signals
    connect(&mainWindow.canvas, SIGNAL(point2DClicked(cg3::Point2d)),
            this, SLOT(point2DClicked(cg3::Point2d)));

    //Setting options for the canvas (enable picking)
    mainWindow.canvas.set2DMode();
    mainWindow.canvas.setMouseBinding(Qt::NoModifier, Qt::LeftButton, mainWindow.canvas.SELECT);

    //Add the drawable object to the mainWindow.
    //The mainWindow will take care of rendering the bounding box and the selected point
    mainWindow.pushDrawableObject(&drawableBoundingBox, "Bounding box");
    mainWindow.pushDrawableObject(&drawableTrapezoidalMapDataset, "Segments");



    //---------------------------------------------------------------------
    //Add the drawable objects you need. Note that the drawable trapezoidal map could only
    //draw the trapezoids (polygons, see GL_POLYGON!). You have already the segments drawn.
    //If you want to draw points and segments of the trapezoidal map, you should hide
    //drawableTrapezoidalMapDataset
    //
    //Example:
    //      mainWindow.pushDrawableObject(&drawableTrapezoidalMap);
    //
    //Note that you could keep a Drawable trapezoidal map (drawableTrapezoidalMap) object
    //always rendered (even when it is empty), instead of deleting it from the main window
    //and re-drawing it again. See how we implemented the drawing of the bounding box and 
    //the dataset.




    //#####################################################################



    //Fit the scene
    fitScene();

    //This updates the canvas (call it whenever you change or
    //add some drawable object)
    updateCanvas();
}


/**
 * @brief Destructor of the manager
 */
TrapezoidalMapManager::~TrapezoidalMapManager()
{
    //Delete the drawable objects
    mainWindow.deleteDrawableObject(&drawableBoundingBox);
    mainWindow.deleteDrawableObject(&drawableTrapezoidalMapDataset);
    if (isFirstPointSelected) {
        mainWindow.deleteDrawableObject(&firstPointSelected);
    }


    //---------------------------------------------------------------------
    //When the manager is destroyed, the mainWindow should not have any
    //reference to the drawable objects.
    //
    //Example:
    //      mainWindow.deleteDrawableObject(&drawableTrapezoidalMap);
    //
    //Try to AVOID using dynamic objects whenever it is possible (it will
    //be evaluated!)




    //#####################################################################



    //---------------------------------------------------------------------
    //In case you allocated dynamic objects in this manager, you should delete
    //(deallocate) all of them when the application closes.
    //Remember that each class which allocates dynamic objects should implement
    //a destructor which deallocates them.
    //
    //Example:
    //      delete dynamicObject;
    //      dynamicObject = nullptr;
    //
    //Try to AVOID using dynamic objects whenever it is possible (it will
    //be evaluated!)




    //#####################################################################




    delete ui; //Delete interface
}



/* ----- Methods (YOU WILL HAVE TO EDIT THESE METHODS) ----- */

/**
 * @brief Launch the incremental step of the algorithm for a segment.
 * @param[in] segment Segment
 */
void TrapezoidalMapManager::addSegmentToTrapezoidalMap(const cg3::Segment2d& segment)
{


    //---------------------------------------------------------------------
    //Execute the incremental step to add a segment to your output TrapezoidalMap data
    //structure.
    //
    //Obviously, you have to define your algorithms and data structures in separate files.
    //Algorithms must be defined AS A FUNCTION (in a namespace, if you want to hierarchically
    //organize your functions) and NOT IN CLASSES (it is not Java).
    //Data structures have to be defined in classes. Try to define a class for each data
    //structure: each one must implement the methods of their responsibilities.
    //Separate data structures from algorithms!
    //
    //HINT: the trapezoidal map is not a DAG (it uses a DAG as an associated search data structure),
    //the DAG is not a trapezoidal map (and does not contain a trapezoidal map). TrapezoidalMap
    //and DAG are two separate data structures.
    //As example, we show two valid modeling options:
    //  1. TrapezoidalMap could handle the construction and query in its inner methods, so it would
    //contain the DAG and use its methods to perform the operations. It is easy to implement, but a
    //bit less modular and general purpose. However, it is fine: it is not an error to model the
    //TrapezoidalMap to have these responsibilities.
    //  2. You could see construction and query as algorithms working on a TrapezoidalMap (which just
    // handles the geometry of trapezoids and its points/segments) and a DAG (that allows for searching
    //in the structure). This is a bit more complicated, but a better structure, because, in this case
    //TrapezoidalMap and DAG are two separate general purpose data structures that an algorithm uses.
    //THINK ABOUT YOUR STRUCTURE BEFORE WRITING CODE!
    //
    //NOTE: in TrapezoidalMapDataset you can see how we guaranteed no duplicates points.
    //Indeed we use a vector for indexing the points, and a map to check if the point is
    //already in the structure. You could use it for your trapezoidal map to make it more
    //efficient in memory. However, depending on how you implement your algorithms and data 
	//structures, you could save directly the point (Point2d) in each trapezoid (it is fine).




    //#####################################################################



    //You can delete this line after you implement the algorithm: it is
    //just needed to suppress the unused-variable warning
    CG3_SUPPRESS_WARNING(segment);
}

/**
 * @brief Launch the query algorithm. Locate a point in a trapezoidal map
 * @param[in] point Query point
 */
void TrapezoidalMapManager::queryTrapezoidalMap(const cg3::Point2d& queryPoint)
{


    //---------------------------------------------------------------------
    //Execute the point location algorithm of your TrapezoidalMap to locate in which trapezoid
    //the point is contained.
    //
    //Obviously, you have to define your algorithms and data structures in separate files.
    //Algorithms must be defined AS A FUNCTION (in a namespace, if you want to hierarchically
    //organize your functions) and NOT IN CLASSES (it is not Java).
    //Data structures have to be defined in classes. Try to define a class for each data
    //structure: each one must implement the methods of their responsibilities.
    //Separate data structures from algorithms!
    //
    //HINT: the trapezoidal map is not a DAG (it uses a DAG as an associated search data structure),
    //the DAG is not a trapezoidal map (and does not contain a trapezoidal map). TrapezoidalMap
    //and DAG are two separate data structures.
    //You have two options:
    //1) TrapezoidalMap could handle the construction and query in its inner methods, so it would
    //contain the DAG and use its methods to perform the operations. It is easy to implement, but
    //a bit less modular. It is fine anyways, since TrapezoidalMap can have those responsibilities.
    //2) You could see construction and query as algorithms working on a TrapezoidalMap (which just
    //handles the geometry of trapezoids and its points/segments) and a DAG (that allows for searching
    //in the structure). This is a bit more complicated, but a better structure, because, in this case
    //TrapezoidalMap and DAG are two separate general purpose data structures that an algorithm uses.
    //THINK ABOUT YOUR STRUCTURE BEFORE WRITING CODE!




    //#####################################################################



    //---------------------------------------------------------------------
    //When you find the trapezoid in which the point is contained, you should highlight
    //the output trapezoid in the canvas (DrawableTrapezoidMap should implement the method
    //to do that).





    //#####################################################################



    //You can delete this line after you implement the algorithm: it is
    //just needed to suppress the unused-variable warning
    CG3_SUPPRESS_WARNING(queryPoint);
}

/**
 * @brief Clear data of the trapezoidal map
 */
void TrapezoidalMapManager::clearTrapezoidalMap()
{
    //---------------------------------------------------------------------
    //Clear here your trapezoidal map data structure.



    //#####################################################################
}




//---------------------------------------------------------------------
//Define your private methods here if you need some




//#####################################################################






//----------------------------------------------------------------------------------------------
//              You will probably not need to write/edit code in the area below.
//----------------------------------------------------------------------------------------------


/* ----- Private utility methods (DO NOT WRITE CODE IN THESE METHODS) ----- */

/**
 * @brief Launch the method for constructing the trapezoidal map
 * and measure its time efficiency.
 */
void TrapezoidalMapManager::loadSegmentsTrapezoidalMapAndMeasureTime(const std::vector<cg3::Segment2d>& segments) //Do not write code here
{
    //Output message
    std::cout << "Constructing the trapezoidal map for " << segments.size() << " segments..." << std::endl;

    //Timer for evaluating the efficiency of the algorithm
    cg3::Timer t("Trapezoidal map construction");

    //Launch incremental step for each segment
    for (const cg3::Segment2d& segment : segments) {
        addSegmentToTrapezoidalMap(segment);
    }

    //Timer stop and visualization (both on console and UI)
    t.stopAndPrint();
    ui->loadSegmentsTimeLabel->setNum(t.delay());
    ui->addSegmentTimeLabel->setText("");
    ui->queryTimeLabel->setText("");

    std::cout << std::endl;
}

/**
 * @brief Launch the method for adding a segment to the trapezoidal map
 * and measure its time efficiency.
 */
void TrapezoidalMapManager::addSegmentToTrapezoidalMapAndMeasureTime(const cg3::Segment2d& segment) //Do not write code here
{
    //Output message
    std::cout << "Adding a segment to the trapezoidal map using its incremental step..." << std::endl;

    //Timer for evaluating the efficiency of the algorithm
    cg3::Timer t("Trapezoidal map incremental step");

    //Launch incremental step for the segment
    addSegmentToTrapezoidalMap(segment);

    //Timer stop and visualization (both on console and UI)
    t.stopAndPrint();
    ui->loadSegmentsTimeLabel->setText("");
    ui->addSegmentTimeLabel->setNum(t.delay());
    ui->queryTimeLabel->setText("");

    std::cout << std::endl;
}

/**
 * @brief Launch the method for querying the trapezoidal map and measure
 * its time efficiency.
 */
void TrapezoidalMapManager::queryTrapezoidalMapAndMeasureTime(const cg3::Point2d& point) //Do not write code here
{
    //Output message
    std::cout << "Querying the trapezoidal map..." << std::endl;

    //Timer for evaluating the efficiency of the algorithm
    cg3::Timer t("Trapezoidal map query");

    //Launch query algorithm for the query point
    queryTrapezoidalMap(point);

    //Timer stop and visualization (both on console and UI)
    t.stopAndPrint();
    ui->loadSegmentsTimeLabel->setText("");
    ui->addSegmentTimeLabel->setText("");
    ui->queryTimeLabel->setNum(t.delay());

    std::cout << std::endl;
}

/**
 * @brief Generate random non intersecting and non degenerate segments
 * @param n Number of segments
 * @param radius Radius from origin
 * @return Vector of segments
 */
std::vector<cg3::Segment2d> TrapezoidalMapManager::generateRandomNonIntersectingSegments(size_t n, double radius) //Do not write code here
{
    double lower_bound = -radius + 1;
    double upper_bound = radius - 1;

    std::mt19937 rng;
    rng.seed(std::random_device()());

    std::vector<cg3::Point2d> randomPoints;
    for (size_t i = 0; i < n * 10; i++) {
        cg3::Point2d p;

        std::uniform_real_distribution<double> dist(lower_bound,upper_bound);
        p.setXCoord(dist(rng));
        p.setYCoord(dist(rng));

        randomPoints.push_back(p);
    }

    TrapezoidalMapDataset dataset;
    while (dataset.segmentNumber() < n) {
        std::uniform_real_distribution<double> dist(0, randomPoints.size() + 0.9999);

        cg3::Point2d p1 = randomPoints[static_cast<size_t>(dist(rng))];
        cg3::Point2d p2 = randomPoints[static_cast<size_t>(dist(rng))];

        bool insertedSegment;
        dataset.addSegment(cg3::Segment2d(p1, p2), insertedSegment);

    }

    return dataset.getSegments();
}

/**
 * @brief Update the drawing of each drawable object. Call this method whenever a
 * a drawable object is updated.
 */
void TrapezoidalMapManager::updateCanvas()
{ //Do not write code here
    //Canvas update
    mainWindow.updateCanvas();
}

/**
 * @brief Change camera of the canvas to fit the scene
 * on the bounding box in which the segments can be added.
 */
void TrapezoidalMapManager::fitScene()
{ //Do not write code here
    mainWindow.canvas.fitScene2d(cg3::Point2d(0,0), BOUNDINGBOX);
}




/* ----- UI slots ----- */

/**
 * @brief Point 2D clicked handler.
 *
 * This method is called whenever the user clicks the canvas.
 * The coordinates (x and y) of the clicked point are given by
 * the 2D point p.
 *
 * @param[in] p Point clicked
 */
void TrapezoidalMapManager::point2DClicked(cg3::Point2d point) //Do not write code here
{
    if (!drawableBoundingBox.isInside(point)) {
        //Error message if the point is not inside the bounding box
        QMessageBox::warning(this, "Cannot insert point", "Point [" +
             QString::number(point.x()) + "," + QString::number(point.y()) +
             "] is not contained in the bounding box.");
        return;
    }
    else {
        if (ui->queryRadio->isChecked()) {
            //Call query algorithm
            queryTrapezoidalMapAndMeasureTime(point);
        }
        else {
            assert(ui->addSegmentRadio->isChecked());

            //If the first point has been selected
            if (isFirstPointSelected) {
                //Create segment
                cg3::Segment2d segment(firstPointSelected, point);

                //Add to the drawable dataset
                bool segmentInserted;
                drawableTrapezoidalMapDataset.addSegment(segment, segmentInserted);

                if (segmentInserted) {
                    //Call the incremental step algorithm
                    addSegmentToTrapezoidalMapAndMeasureTime(segment);
                }
                else {
                    //Error message cannot add an intersecting segment
                    QMessageBox::warning(this, "Cannot insert segment",
                        "The segment will be ignored because it has intersections with other segments, "
                        "it is degenerate, or a point has the same x-coordinate of another point.");
                }

                isFirstPointSelected = false;
                mainWindow.deleteDrawableObject(&firstPointSelected);
            }
            //Select the first point
            else {
                isFirstPointSelected = true;
                firstPointSelected = cg3::DrawablePoint2(point.x(), point.y(), firstPointSelectedColor, firstPointSelectedSize);
                mainWindow.pushDrawableObject(&firstPointSelected, "First point selected");
            }
        }

        //The trapezoidal map (or the drawable object) has been changed, so we update the canvas for drawing.
        updateCanvas();
    }
}

/**
 * @brief Load segments event handler.
 *
 * Load input segments from a file.
 */
void TrapezoidalMapManager::on_loadSegmentsButton_clicked() //Do not write code here
{
    //File selector
    QString filename = QFileDialog::getOpenFileName(nullptr,
                       "Open segment file",
                       ".",
                       "*.txt");

    if (!filename.isEmpty()) {
        //Cancel first point selected
        if (isFirstPointSelected) {
            isFirstPointSelected = false;
            mainWindow.deleteDrawableObject(&firstPointSelected);
        }

        //Clear current data
        clearTrapezoidalMap();
        drawableTrapezoidalMapDataset.clear();

        //Load input segments in the vector (deleting the previous ones)
        std::vector<cg3::Segment2d> segments = FileUtils::getSegmentsFromFile(filename.toStdString());

        //Add to the dataset
        bool allSegmentInserted = true;
        for (const cg3::Segment2d& segment : segments) {
            bool insertedSegment;
            drawableTrapezoidalMapDataset.addSegment(segment, insertedSegment);

            allSegmentInserted &= insertedSegment;
            if (!insertedSegment) {
                std::cout << "The segment " << segment <<
                    " will be ignored because it has intersections with other segments, "
                    "it is degenerate, or a point has the same x-coordinate of another point." << std::endl;
            }
        }
        if (!allSegmentInserted) {
            //Error message cannot add an intersecting segment
            QMessageBox::warning(this, "Cannot insert all segments",
                "Some segment have be ignored because they have intersections with other segments, "
                "they are degenerate, or a point has the same x-coordinate of another point.");
        }

        //Launch the algorithm on the current vector of segments and measure
        //its efficiency with a timer
        loadSegmentsTrapezoidalMapAndMeasureTime(segments);

        //The trapezoidal map has been changed, so we update the canvas for drawing.
        updateCanvas();
    }
}

/**
 * @brief Generate random segments handler.
 *
 * With this button we can generate files that contains
 * segments which are inside the bounding box.
 */
void TrapezoidalMapManager::on_randomSegmentsButton_clicked() //Do not write code here
{
    int number = ui->numberRandomSpinBox->value();

    std::vector<cg3::Segment2d> segments = generateRandomNonIntersectingSegments(static_cast<size_t>(number), BOUNDINGBOX);

    //Cancel first point selected
    if (isFirstPointSelected) {
        isFirstPointSelected = false;
        mainWindow.deleteDrawableObject(&firstPointSelected);
    }

    //Clear current data
    clearTrapezoidalMap();
    drawableTrapezoidalMapDataset.clear();

    for (const cg3::Segment2d& segment : segments) {
        bool insertedSegment;
        drawableTrapezoidalMapDataset.addSegment(segment, insertedSegment);
        assert(insertedSegment);
    }

    //Launch the algorithm on the current vector of segments and measure
    //its efficiency with a timer
    loadSegmentsTrapezoidalMapAndMeasureTime(segments);

    //The trapezoidal map has been changed, so we update the canvas for drawing.
    updateCanvas();
}

/**
 * @brief Save segments handler.
 *
 * With this button we can save files that contains the current segments
 */
void TrapezoidalMapManager::on_saveSegmentsButton_clicked() //Do not write code here
{
    QString selectedFilter;
    QString filename = QFileDialog::getSaveFileName(nullptr,
                       "File containing segments",
                       ".",
                       "TXT(*.txt)", &selectedFilter);

    if (!filename.isEmpty()){
        //Save segments in the chosen file
        FileUtils::saveSegmentsInFile(filename.toStdString(), drawableTrapezoidalMapDataset.getSegments());
    }
}


/**
 * @brief Clear segments button event handler.
 *
 * It allows us to clear our trapezoidal map input segments.
 */
void TrapezoidalMapManager::on_clearSegmentsButton_clicked() //Do not write code here
{
    //Cancel first point selected
    if (isFirstPointSelected) {
        isFirstPointSelected = false;
        mainWindow.deleteDrawableObject(&firstPointSelected);
    }

    //Clear current data
    clearTrapezoidalMap();
    drawableTrapezoidalMapDataset.clear();

    updateCanvas();

    //Clear timer data
    ui->loadSegmentsTimeLabel->setText("");
    ui->addSegmentTimeLabel->setText("");
    ui->queryTimeLabel->setText("");
}

/**
 * @brief Reset scene event handler.
 *
 * It allows us to reset the camera of the canvas to
 * show/center the scene in the bounding box.
 */
void TrapezoidalMapManager::on_resetSceneButton_clicked() //Do not write code here
{
    fitScene();
}

/**
 * @brief Add segment mode button event handler.
 */
void TrapezoidalMapManager::on_addSegmentRadio_clicked() //Do not write code here
{
    //Cancel first point selected
    if (isFirstPointSelected) {
        isFirstPointSelected = false;
        mainWindow.deleteDrawableObject(&firstPointSelected);

        updateCanvas();
    }
}

/**
 * @brief Query mode button event handler.
 */
void TrapezoidalMapManager::on_queryRadio_clicked() //Do not write code here
{
    //Cancel first point selected
    if (isFirstPointSelected) {
        isFirstPointSelected = false;
        mainWindow.deleteDrawableObject(&firstPointSelected);

        updateCanvas();
    }
}
