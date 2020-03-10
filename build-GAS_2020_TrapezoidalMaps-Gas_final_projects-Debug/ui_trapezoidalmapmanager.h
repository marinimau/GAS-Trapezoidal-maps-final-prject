/********************************************************************************
** Form generated from reading UI file 'trapezoidalmapmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAPEZOIDALMAPMANAGER_H
#define UI_TRAPEZOIDALMAPMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrapezoidalMapManager
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *randomSegmentsButton;
    QLabel *queryTimeDescriptionLabel;
    QLabel *loadSegmentsTimeLabel;
    QPushButton *loadSegmentsButton;
    QLabel *addSegmentTimeLabel;
    QRadioButton *addSegmentRadio;
    QLabel *addSegmentTimeDescriptionLabel;
    QLabel *loadSegmentsTimeDescriptionLabel;
    QRadioButton *queryRadio;
    QLabel *queryTimeLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *saveSegmentsButton;
    QPushButton *clearSegmentsButton;
    QPushButton *resetSceneButton;
    QLabel *numberRandomLabel;
    QSpinBox *numberRandomSpinBox;

    void setupUi(QFrame *TrapezoidalMapManager)
    {
        if (TrapezoidalMapManager->objectName().isEmpty())
            TrapezoidalMapManager->setObjectName(QString::fromUtf8("TrapezoidalMapManager"));
        TrapezoidalMapManager->resize(400, 300);
        TrapezoidalMapManager->setLayoutDirection(Qt::LeftToRight);
        TrapezoidalMapManager->setFrameShape(QFrame::StyledPanel);
        TrapezoidalMapManager->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(TrapezoidalMapManager);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(TrapezoidalMapManager);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        randomSegmentsButton = new QPushButton(frame);
        randomSegmentsButton->setObjectName(QString::fromUtf8("randomSegmentsButton"));

        gridLayout->addWidget(randomSegmentsButton, 0, 1, 1, 1);

        queryTimeDescriptionLabel = new QLabel(frame);
        queryTimeDescriptionLabel->setObjectName(QString::fromUtf8("queryTimeDescriptionLabel"));
        queryTimeDescriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(queryTimeDescriptionLabel, 5, 2, 1, 1);

        loadSegmentsTimeLabel = new QLabel(frame);
        loadSegmentsTimeLabel->setObjectName(QString::fromUtf8("loadSegmentsTimeLabel"));

        gridLayout->addWidget(loadSegmentsTimeLabel, 0, 3, 1, 1);

        loadSegmentsButton = new QPushButton(frame);
        loadSegmentsButton->setObjectName(QString::fromUtf8("loadSegmentsButton"));

        gridLayout->addWidget(loadSegmentsButton, 0, 0, 1, 1);

        addSegmentTimeLabel = new QLabel(frame);
        addSegmentTimeLabel->setObjectName(QString::fromUtf8("addSegmentTimeLabel"));

        gridLayout->addWidget(addSegmentTimeLabel, 4, 3, 1, 1);

        addSegmentRadio = new QRadioButton(frame);
        addSegmentRadio->setObjectName(QString::fromUtf8("addSegmentRadio"));
        addSegmentRadio->setChecked(true);

        gridLayout->addWidget(addSegmentRadio, 4, 0, 1, 2);

        addSegmentTimeDescriptionLabel = new QLabel(frame);
        addSegmentTimeDescriptionLabel->setObjectName(QString::fromUtf8("addSegmentTimeDescriptionLabel"));
        addSegmentTimeDescriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(addSegmentTimeDescriptionLabel, 4, 2, 1, 1);

        loadSegmentsTimeDescriptionLabel = new QLabel(frame);
        loadSegmentsTimeDescriptionLabel->setObjectName(QString::fromUtf8("loadSegmentsTimeDescriptionLabel"));
        loadSegmentsTimeDescriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(loadSegmentsTimeDescriptionLabel, 0, 2, 1, 1);

        queryRadio = new QRadioButton(frame);
        queryRadio->setObjectName(QString::fromUtf8("queryRadio"));
        queryRadio->setChecked(false);

        gridLayout->addWidget(queryRadio, 5, 0, 1, 2);

        queryTimeLabel = new QLabel(frame);
        queryTimeLabel->setObjectName(QString::fromUtf8("queryTimeLabel"));

        gridLayout->addWidget(queryTimeLabel, 5, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 12, 2, 1, 1);

        saveSegmentsButton = new QPushButton(frame);
        saveSegmentsButton->setObjectName(QString::fromUtf8("saveSegmentsButton"));

        gridLayout->addWidget(saveSegmentsButton, 3, 0, 1, 1);

        clearSegmentsButton = new QPushButton(frame);
        clearSegmentsButton->setObjectName(QString::fromUtf8("clearSegmentsButton"));

        gridLayout->addWidget(clearSegmentsButton, 3, 1, 1, 1);

        resetSceneButton = new QPushButton(frame);
        resetSceneButton->setObjectName(QString::fromUtf8("resetSceneButton"));

        gridLayout->addWidget(resetSceneButton, 3, 2, 1, 2);

        numberRandomLabel = new QLabel(frame);
        numberRandomLabel->setObjectName(QString::fromUtf8("numberRandomLabel"));

        gridLayout->addWidget(numberRandomLabel, 9, 0, 1, 2);

        numberRandomSpinBox = new QSpinBox(frame);
        numberRandomSpinBox->setObjectName(QString::fromUtf8("numberRandomSpinBox"));
        numberRandomSpinBox->setMinimum(1);
        numberRandomSpinBox->setMaximum(100000);
        numberRandomSpinBox->setSingleStep(10);
        numberRandomSpinBox->setValue(10);

        gridLayout->addWidget(numberRandomSpinBox, 9, 2, 1, 2);


        verticalLayout->addWidget(frame);


        retranslateUi(TrapezoidalMapManager);

        QMetaObject::connectSlotsByName(TrapezoidalMapManager);
    } // setupUi

    void retranslateUi(QFrame *TrapezoidalMapManager)
    {
        TrapezoidalMapManager->setWindowTitle(QApplication::translate("TrapezoidalMapManager", "Frame", nullptr));
        randomSegmentsButton->setText(QApplication::translate("TrapezoidalMapManager", "Random", nullptr));
        queryTimeDescriptionLabel->setText(QApplication::translate("TrapezoidalMapManager", "Time:", nullptr));
        loadSegmentsTimeLabel->setText(QString());
        loadSegmentsButton->setText(QApplication::translate("TrapezoidalMapManager", "Load", nullptr));
        addSegmentTimeLabel->setText(QString());
        addSegmentRadio->setText(QApplication::translate("TrapezoidalMapManager", "Add segment", nullptr));
        addSegmentTimeDescriptionLabel->setText(QApplication::translate("TrapezoidalMapManager", "Time:", nullptr));
        loadSegmentsTimeDescriptionLabel->setText(QApplication::translate("TrapezoidalMapManager", "Time:", nullptr));
        queryRadio->setText(QApplication::translate("TrapezoidalMapManager", "Query", nullptr));
        queryTimeLabel->setText(QString());
        saveSegmentsButton->setText(QApplication::translate("TrapezoidalMapManager", "Save", nullptr));
        clearSegmentsButton->setText(QApplication::translate("TrapezoidalMapManager", "Clear", nullptr));
        resetSceneButton->setText(QApplication::translate("TrapezoidalMapManager", "Reset scene", nullptr));
        numberRandomLabel->setText(QApplication::translate("TrapezoidalMapManager", "Number random:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrapezoidalMapManager: public Ui_TrapezoidalMapManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAPEZOIDALMAPMANAGER_H
