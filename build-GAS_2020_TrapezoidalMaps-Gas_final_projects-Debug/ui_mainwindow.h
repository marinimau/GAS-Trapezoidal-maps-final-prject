/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cg3/viewer/glcanvas.h"

namespace cg3 {
namespace viewer {

class Ui_MainWindow
{
public:
    QAction *actionSave_Snapshot;
    QAction *actionShow_Axis;
    QAction *actionFull_Screen;
    QAction *actionUpdate_Canvas;
    QAction *actionFit_Scene;
    QAction *actionChange_Background_Color;
    QAction *actionSave_Point_Of_View;
    QAction *actionLoad_Point_of_View;
    QAction *actionShow_Hide_Dock_Widget;
    QAction *actionLoad_Point_Of_View_from;
    QAction *actionSave_Point_Of_View_as;
    QAction *actionShow_Hide_Console;
    QAction *action2D_Mode;
    QAction *action3D_Mode;
    QAction *actionReset_Point_of_View;
    QAction *actionPerspective_Orthographic_Camera_Mode;
    QAction *actionLoad_Mesh;
    QAction *actionToggle_Debug_Objects;
    QAction *actionShow_Unit_Box;
    QAction *actionShow_Hide_DrawList;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    cg3::viewer::GLCanvas *glCanvas;
    QTextEdit *console;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuWindow;
    QMenu *menuFile_2;
    QMenu *menuDebug_Objects;
    QDockWidget *dockToolBox;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *page_2;
    QDockWidget *dockDrawList;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QMainWindow *cg3__viewer__MainWindow)
    {
        if (cg3__viewer__MainWindow->objectName().isEmpty())
            cg3__viewer__MainWindow->setObjectName(QString::fromUtf8("cg3__viewer__MainWindow"));
        cg3__viewer__MainWindow->resize(929, 600);
        cg3__viewer__MainWindow->setMinimumSize(QSize(800, 600));
        cg3__viewer__MainWindow->setBaseSize(QSize(800, 600));
        actionSave_Snapshot = new QAction(cg3__viewer__MainWindow);
        actionSave_Snapshot->setObjectName(QString::fromUtf8("actionSave_Snapshot"));
        actionShow_Axis = new QAction(cg3__viewer__MainWindow);
        actionShow_Axis->setObjectName(QString::fromUtf8("actionShow_Axis"));
        actionFull_Screen = new QAction(cg3__viewer__MainWindow);
        actionFull_Screen->setObjectName(QString::fromUtf8("actionFull_Screen"));
        actionFull_Screen->setCheckable(true);
        actionUpdate_Canvas = new QAction(cg3__viewer__MainWindow);
        actionUpdate_Canvas->setObjectName(QString::fromUtf8("actionUpdate_Canvas"));
        actionFit_Scene = new QAction(cg3__viewer__MainWindow);
        actionFit_Scene->setObjectName(QString::fromUtf8("actionFit_Scene"));
        actionChange_Background_Color = new QAction(cg3__viewer__MainWindow);
        actionChange_Background_Color->setObjectName(QString::fromUtf8("actionChange_Background_Color"));
        actionSave_Point_Of_View = new QAction(cg3__viewer__MainWindow);
        actionSave_Point_Of_View->setObjectName(QString::fromUtf8("actionSave_Point_Of_View"));
        actionLoad_Point_of_View = new QAction(cg3__viewer__MainWindow);
        actionLoad_Point_of_View->setObjectName(QString::fromUtf8("actionLoad_Point_of_View"));
        actionShow_Hide_Dock_Widget = new QAction(cg3__viewer__MainWindow);
        actionShow_Hide_Dock_Widget->setObjectName(QString::fromUtf8("actionShow_Hide_Dock_Widget"));
        actionLoad_Point_Of_View_from = new QAction(cg3__viewer__MainWindow);
        actionLoad_Point_Of_View_from->setObjectName(QString::fromUtf8("actionLoad_Point_Of_View_from"));
        actionSave_Point_Of_View_as = new QAction(cg3__viewer__MainWindow);
        actionSave_Point_Of_View_as->setObjectName(QString::fromUtf8("actionSave_Point_Of_View_as"));
        actionShow_Hide_Console = new QAction(cg3__viewer__MainWindow);
        actionShow_Hide_Console->setObjectName(QString::fromUtf8("actionShow_Hide_Console"));
        action2D_Mode = new QAction(cg3__viewer__MainWindow);
        action2D_Mode->setObjectName(QString::fromUtf8("action2D_Mode"));
        action3D_Mode = new QAction(cg3__viewer__MainWindow);
        action3D_Mode->setObjectName(QString::fromUtf8("action3D_Mode"));
        action3D_Mode->setEnabled(false);
        actionReset_Point_of_View = new QAction(cg3__viewer__MainWindow);
        actionReset_Point_of_View->setObjectName(QString::fromUtf8("actionReset_Point_of_View"));
        actionPerspective_Orthographic_Camera_Mode = new QAction(cg3__viewer__MainWindow);
        actionPerspective_Orthographic_Camera_Mode->setObjectName(QString::fromUtf8("actionPerspective_Orthographic_Camera_Mode"));
        actionLoad_Mesh = new QAction(cg3__viewer__MainWindow);
        actionLoad_Mesh->setObjectName(QString::fromUtf8("actionLoad_Mesh"));
        actionToggle_Debug_Objects = new QAction(cg3__viewer__MainWindow);
        actionToggle_Debug_Objects->setObjectName(QString::fromUtf8("actionToggle_Debug_Objects"));
        actionToggle_Debug_Objects->setCheckable(true);
        actionShow_Unit_Box = new QAction(cg3__viewer__MainWindow);
        actionShow_Unit_Box->setObjectName(QString::fromUtf8("actionShow_Unit_Box"));
        actionShow_Hide_DrawList = new QAction(cg3__viewer__MainWindow);
        actionShow_Hide_DrawList->setObjectName(QString::fromUtf8("actionShow_Hide_DrawList"));
        centralWidget = new QWidget(cg3__viewer__MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        glCanvas = new cg3::viewer::GLCanvas(centralWidget);
        glCanvas->setObjectName(QString::fromUtf8("glCanvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glCanvas->sizePolicy().hasHeightForWidth());
        glCanvas->setSizePolicy(sizePolicy);

        gridLayout->addWidget(glCanvas, 0, 0, 1, 1);

        console = new QTextEdit(centralWidget);
        console->setObjectName(QString::fromUtf8("console"));

        gridLayout->addWidget(console, 1, 0, 1, 1);

        cg3__viewer__MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cg3__viewer__MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 929, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuFile_2 = new QMenu(menuBar);
        menuFile_2->setObjectName(QString::fromUtf8("menuFile_2"));
        menuDebug_Objects = new QMenu(menuBar);
        menuDebug_Objects->setObjectName(QString::fromUtf8("menuDebug_Objects"));
        cg3__viewer__MainWindow->setMenuBar(menuBar);
        dockToolBox = new QDockWidget(cg3__viewer__MainWindow);
        dockToolBox->setObjectName(QString::fromUtf8("dockToolBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockToolBox->sizePolicy().hasHeightForWidth());
        dockToolBox->setSizePolicy(sizePolicy1);
        dockToolBox->setMinimumSize(QSize(300, 138));
        dockToolBox->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolBox = new QToolBox(dockWidgetContents_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy2);
        toolBox->setMinimumSize(QSize(280, 0));
        toolBox->setLayoutDirection(Qt::LeftToRight);
        toolBox->setFrameShape(QFrame::StyledPanel);
        toolBox->setFrameShadow(QFrame::Raised);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 280, 508));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));

        verticalLayout->addWidget(toolBox);

        dockToolBox->setWidget(dockWidgetContents_2);
        cg3__viewer__MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockToolBox);
        dockDrawList = new QDockWidget(cg3__viewer__MainWindow);
        dockDrawList->setObjectName(QString::fromUtf8("dockDrawList"));
        dockDrawList->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea = new QScrollArea(dockWidgetContents_5);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy3);
        scrollArea->setMinimumSize(QSize(250, 0));
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 250, 541));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        dockDrawList->setWidget(dockWidgetContents_5);
        cg3__viewer__MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockDrawList);

        menuBar->addAction(menuFile_2->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDebug_Objects->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuFile->addAction(actionChange_Background_Color);
        menuFile->addAction(actionFit_Scene);
        menuFile->addAction(actionReset_Point_of_View);
        menuFile->addAction(actionPerspective_Orthographic_Camera_Mode);
        menuFile->addAction(actionShow_Axis);
        menuFile->addAction(actionShow_Unit_Box);
        menuFile->addAction(actionUpdate_Canvas);
        menuFile->addSeparator();
        menuFile->addAction(action2D_Mode);
        menuFile->addAction(action3D_Mode);
        menuWindow->addAction(actionFull_Screen);
        menuWindow->addAction(actionShow_Hide_Dock_Widget);
        menuWindow->addAction(actionShow_Hide_Console);
        menuWindow->addAction(actionShow_Hide_DrawList);
        menuFile_2->addSeparator();
        menuFile_2->addAction(actionLoad_Mesh);
        menuFile_2->addSeparator();
        menuFile_2->addAction(actionLoad_Point_of_View);
        menuFile_2->addAction(actionLoad_Point_Of_View_from);
        menuFile_2->addAction(actionSave_Point_Of_View);
        menuFile_2->addAction(actionSave_Point_Of_View_as);
        menuFile_2->addSeparator();
        menuFile_2->addAction(actionSave_Snapshot);
        menuDebug_Objects->addSeparator();
        menuDebug_Objects->addAction(actionToggle_Debug_Objects);

        retranslateUi(cg3__viewer__MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(cg3__viewer__MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *cg3__viewer__MainWindow)
    {
        cg3__viewer__MainWindow->setWindowTitle(QString());
        actionSave_Snapshot->setText(QApplication::translate("cg3::viewer::MainWindow", "Save Snapshot", nullptr));
        actionShow_Axis->setText(QApplication::translate("cg3::viewer::MainWindow", "Show Axis", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_Axis->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "A", nullptr));
#endif // QT_NO_SHORTCUT
        actionFull_Screen->setText(QApplication::translate("cg3::viewer::MainWindow", "Full Screen", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFull_Screen->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        actionUpdate_Canvas->setText(QApplication::translate("cg3::viewer::MainWindow", "Update Canvas", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUpdate_Canvas->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "U", nullptr));
#endif // QT_NO_SHORTCUT
        actionFit_Scene->setText(QApplication::translate("cg3::viewer::MainWindow", "Fit Scene", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFit_Scene->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "F", nullptr));
#endif // QT_NO_SHORTCUT
        actionChange_Background_Color->setText(QApplication::translate("cg3::viewer::MainWindow", "Change Background Color", nullptr));
        actionSave_Point_Of_View->setText(QApplication::translate("cg3::viewer::MainWindow", "Save Point Of View", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_Point_Of_View->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad_Point_of_View->setText(QApplication::translate("cg3::viewer::MainWindow", "Load Point Of View", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad_Point_of_View->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionShow_Hide_Dock_Widget->setText(QApplication::translate("cg3::viewer::MainWindow", "Show/Hide Dock Widget", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_Hide_Dock_Widget->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad_Point_Of_View_from->setText(QApplication::translate("cg3::viewer::MainWindow", "Load Point Of View from...", nullptr));
        actionSave_Point_Of_View_as->setText(QApplication::translate("cg3::viewer::MainWindow", "Save Point Of View as...", nullptr));
        actionShow_Hide_Console->setText(QApplication::translate("cg3::viewer::MainWindow", "Show/Hide Console", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_Hide_Console->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "C", nullptr));
#endif // QT_NO_SHORTCUT
        action2D_Mode->setText(QApplication::translate("cg3::viewer::MainWindow", "2D Mode", nullptr));
#ifndef QT_NO_SHORTCUT
        action2D_Mode->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "2", nullptr));
#endif // QT_NO_SHORTCUT
        action3D_Mode->setText(QApplication::translate("cg3::viewer::MainWindow", "3D Mode", nullptr));
#ifndef QT_NO_SHORTCUT
        action3D_Mode->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "3", nullptr));
#endif // QT_NO_SHORTCUT
        actionReset_Point_of_View->setText(QApplication::translate("cg3::viewer::MainWindow", "Reset Point of View", nullptr));
#ifndef QT_NO_SHORTCUT
        actionReset_Point_of_View->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "R", nullptr));
#endif // QT_NO_SHORTCUT
        actionPerspective_Orthographic_Camera_Mode->setText(QApplication::translate("cg3::viewer::MainWindow", "Perspective/Orthographic Camera Mode", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPerspective_Orthographic_Camera_Mode->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "O", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad_Mesh->setText(QApplication::translate("cg3::viewer::MainWindow", "Load Mesh", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad_Mesh->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionToggle_Debug_Objects->setText(QApplication::translate("cg3::viewer::MainWindow", "Toggle Debug Objects", nullptr));
#ifndef QT_NO_SHORTCUT
        actionToggle_Debug_Objects->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "D", nullptr));
#endif // QT_NO_SHORTCUT
        actionShow_Unit_Box->setText(QApplication::translate("cg3::viewer::MainWindow", "Show Unit Box", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_Unit_Box->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "B", nullptr));
#endif // QT_NO_SHORTCUT
        actionShow_Hide_DrawList->setText(QApplication::translate("cg3::viewer::MainWindow", "Show/Hide DrawList", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_Hide_DrawList->setShortcut(QApplication::translate("cg3::viewer::MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile->setTitle(QApplication::translate("cg3::viewer::MainWindow", "Rendering", nullptr));
        menuWindow->setTitle(QApplication::translate("cg3::viewer::MainWindow", "Window", nullptr));
        menuFile_2->setTitle(QApplication::translate("cg3::viewer::MainWindow", "File", nullptr));
        menuDebug_Objects->setTitle(QApplication::translate("cg3::viewer::MainWindow", "Debug Objects", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("cg3::viewer::MainWindow", "Page 2", nullptr));
    } // retranslateUi

};

} // namespace viewer
} // namespace cg3

namespace cg3 {
namespace viewer {
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui
} // namespace viewer
} // namespace cg3

#endif // UI_MAINWINDOW_H
