/********************************************************************************
** Form generated from reading UI file 'drawable_mesh_drawlist_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWABLE_MESH_DRAWLIST_MANAGER_H
#define UI_DRAWABLE_MESH_DRAWLIST_MANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

namespace cg3 {
namespace viewer {

class Ui_DrawableMeshDrawListManager
{
public:
    QGridLayout *gridLayout;
    QRadioButton *tColorRadioButton;
    QRadioButton *smoothRadioButton;
    QRadioButton *vColorRadioButton;
    QLabel *nFacesLabel;
    QCheckBox *wireframeCheckBox;
    QPushButton *savePushButton;
    QRadioButton *pointsRadioButton;
    QRadioButton *flatRadioButton;
    QSlider *wireframeWidthSlider;
    QLabel *nVerticesLabel;
    QCheckBox *subFrameAxisCheckBox;
    QCheckBox *bboxCheckBox;
    QLabel *label;
    QLabel *label_2;
    QSlider *pointWidthSlider;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QFrame *cg3__viewer__DrawableMeshDrawListManager)
    {
        if (cg3__viewer__DrawableMeshDrawListManager->objectName().isEmpty())
            cg3__viewer__DrawableMeshDrawListManager->setObjectName(QString::fromUtf8("cg3__viewer__DrawableMeshDrawListManager"));
        cg3__viewer__DrawableMeshDrawListManager->resize(400, 190);
        gridLayout = new QGridLayout(cg3__viewer__DrawableMeshDrawListManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(3, 0, 0, 0);
        tColorRadioButton = new QRadioButton(cg3__viewer__DrawableMeshDrawListManager);
        buttonGroup_2 = new QButtonGroup(cg3__viewer__DrawableMeshDrawListManager);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(tColorRadioButton);
        tColorRadioButton->setObjectName(QString::fromUtf8("tColorRadioButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/vcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        tColorRadioButton->setIcon(icon);

        gridLayout->addWidget(tColorRadioButton, 1, 1, 1, 1);

        smoothRadioButton = new QRadioButton(cg3__viewer__DrawableMeshDrawListManager);
        buttonGroup = new QButtonGroup(cg3__viewer__DrawableMeshDrawListManager);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(smoothRadioButton);
        smoothRadioButton->setObjectName(QString::fromUtf8("smoothRadioButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/smooth.png"), QSize(), QIcon::Normal, QIcon::Off);
        smoothRadioButton->setIcon(icon1);

        gridLayout->addWidget(smoothRadioButton, 0, 2, 1, 1);

        vColorRadioButton = new QRadioButton(cg3__viewer__DrawableMeshDrawListManager);
        buttonGroup_2->addButton(vColorRadioButton);
        vColorRadioButton->setObjectName(QString::fromUtf8("vColorRadioButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/tcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        vColorRadioButton->setIcon(icon2);

        gridLayout->addWidget(vColorRadioButton, 1, 0, 1, 1);

        nFacesLabel = new QLabel(cg3__viewer__DrawableMeshDrawListManager);
        nFacesLabel->setObjectName(QString::fromUtf8("nFacesLabel"));

        gridLayout->addWidget(nFacesLabel, 6, 0, 1, 4);

        wireframeCheckBox = new QCheckBox(cg3__viewer__DrawableMeshDrawListManager);
        wireframeCheckBox->setObjectName(QString::fromUtf8("wireframeCheckBox"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/wire.png"), QSize(), QIcon::Normal, QIcon::Off);
        wireframeCheckBox->setIcon(icon3);

        gridLayout->addWidget(wireframeCheckBox, 0, 3, 1, 1);

        savePushButton = new QPushButton(cg3__viewer__DrawableMeshDrawListManager);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        savePushButton->setIcon(icon4);
        savePushButton->setFlat(true);

        gridLayout->addWidget(savePushButton, 1, 3, 1, 1);

        pointsRadioButton = new QRadioButton(cg3__viewer__DrawableMeshDrawListManager);
        buttonGroup->addButton(pointsRadioButton);
        pointsRadioButton->setObjectName(QString::fromUtf8("pointsRadioButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/points.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointsRadioButton->setIcon(icon5);

        gridLayout->addWidget(pointsRadioButton, 0, 0, 1, 1);

        flatRadioButton = new QRadioButton(cg3__viewer__DrawableMeshDrawListManager);
        buttonGroup->addButton(flatRadioButton);
        flatRadioButton->setObjectName(QString::fromUtf8("flatRadioButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/flat.png"), QSize(), QIcon::Normal, QIcon::Off);
        flatRadioButton->setIcon(icon6);

        gridLayout->addWidget(flatRadioButton, 0, 1, 1, 1);

        wireframeWidthSlider = new QSlider(cg3__viewer__DrawableMeshDrawListManager);
        wireframeWidthSlider->setObjectName(QString::fromUtf8("wireframeWidthSlider"));
        wireframeWidthSlider->setMinimum(1);
        wireframeWidthSlider->setMaximum(5);
        wireframeWidthSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(wireframeWidthSlider, 3, 0, 1, 2);

        nVerticesLabel = new QLabel(cg3__viewer__DrawableMeshDrawListManager);
        nVerticesLabel->setObjectName(QString::fromUtf8("nVerticesLabel"));

        gridLayout->addWidget(nVerticesLabel, 5, 0, 1, 4);

        subFrameAxisCheckBox = new QCheckBox(cg3__viewer__DrawableMeshDrawListManager);
        subFrameAxisCheckBox->setObjectName(QString::fromUtf8("subFrameAxisCheckBox"));

        gridLayout->addWidget(subFrameAxisCheckBox, 4, 0, 1, 4);

        bboxCheckBox = new QCheckBox(cg3__viewer__DrawableMeshDrawListManager);
        bboxCheckBox->setObjectName(QString::fromUtf8("bboxCheckBox"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/bbox.png"), QSize(), QIcon::Normal, QIcon::Off);
        bboxCheckBox->setIcon(icon7);

        gridLayout->addWidget(bboxCheckBox, 1, 2, 1, 1);

        label = new QLabel(cg3__viewer__DrawableMeshDrawListManager);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 2);

        label_2 = new QLabel(cg3__viewer__DrawableMeshDrawListManager);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 2, 1, 2);

        pointWidthSlider = new QSlider(cg3__viewer__DrawableMeshDrawListManager);
        pointWidthSlider->setObjectName(QString::fromUtf8("pointWidthSlider"));
        pointWidthSlider->setMinimum(1);
        pointWidthSlider->setMaximum(5);
        pointWidthSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(pointWidthSlider, 3, 2, 1, 2);


        retranslateUi(cg3__viewer__DrawableMeshDrawListManager);

        QMetaObject::connectSlotsByName(cg3__viewer__DrawableMeshDrawListManager);
    } // setupUi

    void retranslateUi(QFrame *cg3__viewer__DrawableMeshDrawListManager)
    {
        cg3__viewer__DrawableMeshDrawListManager->setWindowTitle(QCoreApplication::translate("cg3::viewer::DrawableMeshDrawListManager", "Frame", nullptr));
        tColorRadioButton->setText(QString());
        smoothRadioButton->setText(QString());
        vColorRadioButton->setText(QString());
        nFacesLabel->setText(QString());
        wireframeCheckBox->setText(QString());
        savePushButton->setText(QString());
        pointsRadioButton->setText(QString());
        flatRadioButton->setText(QString());
        nVerticesLabel->setText(QString());
        subFrameAxisCheckBox->setText(QCoreApplication::translate("cg3::viewer::DrawableMeshDrawListManager", "Draw SubFrame Axis", nullptr));
        bboxCheckBox->setText(QString());
        label->setText(QCoreApplication::translate("cg3::viewer::DrawableMeshDrawListManager", "Wireframe Width:", nullptr));
        label_2->setText(QCoreApplication::translate("cg3::viewer::DrawableMeshDrawListManager", "Point Width:", nullptr));
    } // retranslateUi

};

} // namespace viewer
} // namespace cg3

namespace cg3 {
namespace viewer {
namespace Ui {
    class DrawableMeshDrawListManager: public Ui_DrawableMeshDrawListManager {};
} // namespace Ui
} // namespace viewer
} // namespace cg3

#endif // UI_DRAWABLE_MESH_DRAWLIST_MANAGER_H
