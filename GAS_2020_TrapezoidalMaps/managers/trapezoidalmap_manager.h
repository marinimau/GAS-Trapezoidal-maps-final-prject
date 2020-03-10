#ifndef VORONOIMANAGER_H
#define VORONOIMANAGER_H

#include <QFrame>

#include <cg3/viewer/mainwindow.h>

#include <cg3/viewer/drawable_objects/drawable_bounding_box2.h>
#include <cg3/viewer/drawable_objects/drawable_point2.h>

#include <cg3/geometry/segment2.h>

#include "drawables/drawable_trapezoidalmap_dataset.h"

namespace Ui {
    class TrapezoidalMapManager;
}

/**
 * @brief The manager which gives you all the functionalities needed by
 * the project.
 */
class TrapezoidalMapManager : public QFrame {
    Q_OBJECT

public:

    /* ----- Constructors/destructors ----- */

    explicit TrapezoidalMapManager(QWidget *parent = nullptr);
    ~TrapezoidalMapManager();


private:

    /* ----- Private fields ----- */

    //UI fields
    Ui::TrapezoidalMapManager *ui;
    cg3::viewer::MainWindow& mainWindow;    

    //It is const because, once defined and initialized, it will never change!
    const cg3::DrawableBoundingBox2 drawableBoundingBox;

    //Drawable dataset for the trapezoidal map. Each segment is consistent:
    //points in general position, no segment duplicates, non-intersecting segments
    DrawableTrapezoidalMapDataset drawableTrapezoidalMapDataset;

    //Variables to allow to select a segment clicking on the canvas
    cg3::DrawablePoint2 firstPointSelected;
    cg3::Color firstPointSelectedColor;
    unsigned int firstPointSelectedSize;
    bool isFirstPointSelected;
	
	

    //---------------------------------------------------------------------
    //Declare your attributes here




    //#####################################################################



    /* ----- Methods (YOU WILL HAVE TO EDIT THESE METHODS) ----- */

    void addSegmentToTrapezoidalMap(const cg3::Segment2d& segment);
    void queryTrapezoidalMap(const cg3::Point2d& point);
    void clearTrapezoidalMap();



    //---------------------------------------------------------------------
    //Declare your private methods here if you need some




    //#####################################################################



    /* ----- Private utility methods (DO NOT WRITE CODE IN THESE METHODS) ----- */

    void loadSegmentsTrapezoidalMapAndMeasureTime(const std::vector<cg3::Segment2d>& segments);
    void addSegmentToTrapezoidalMapAndMeasureTime(const cg3::Segment2d& segment);
    void queryTrapezoidalMapAndMeasureTime(const cg3::Point2d& point);
    std::vector<cg3::Segment2d> generateRandomNonIntersectingSegments(size_t n, double radius);

    void fitScene();
    void updateCanvas();


private slots:

    /* ----- UI slots ----- */

    void point2DClicked(cg3::Point2d p);

    void on_loadSegmentsButton_clicked();
    void on_randomSegmentsButton_clicked();
    void on_saveSegmentsButton_clicked();
    void on_addSegmentRadio_clicked();
    void on_queryRadio_clicked();
    void on_clearSegmentsButton_clicked();
    void on_resetSceneButton_clicked();
};

#endif // VORONOIMANAGER_H
