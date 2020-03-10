/********************************************************************************
** Form generated from reading UI file 'drawable_container_drawlist_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWABLE_CONTAINER_DRAWLIST_MANAGER_H
#define UI_DRAWABLE_CONTAINER_DRAWLIST_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace cg3 {
namespace viewer {

class Ui_DrawableContainerDrawListManager
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *layout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *visibleButton;
    QPushButton *hiddenButton;
    QFrame *line;

    void setupUi(QFrame *cg3__viewer__DrawableContainerDrawListManager)
    {
        if (cg3__viewer__DrawableContainerDrawListManager->objectName().isEmpty())
            cg3__viewer__DrawableContainerDrawListManager->setObjectName(QString::fromUtf8("cg3__viewer__DrawableContainerDrawListManager"));
        cg3__viewer__DrawableContainerDrawListManager->resize(400, 86);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cg3__viewer__DrawableContainerDrawListManager->sizePolicy().hasHeightForWidth());
        cg3__viewer__DrawableContainerDrawListManager->setSizePolicy(sizePolicy);
        cg3__viewer__DrawableContainerDrawListManager->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(cg3__viewer__DrawableContainerDrawListManager);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, 0);
        scrollArea = new QScrollArea(cg3__viewer__DrawableContainerDrawListManager);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        layout = new QWidget();
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setGeometry(QRect(0, 0, 391, 86));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(layout->sizePolicy().hasHeightForWidth());
        layout->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(layout);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 0, 0);
        frame = new QFrame(layout);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, 0);
        visibleButton = new QPushButton(frame);
        visibleButton->setObjectName(QString::fromUtf8("visibleButton"));

        horizontalLayout_2->addWidget(visibleButton);

        hiddenButton = new QPushButton(frame);
        hiddenButton->setObjectName(QString::fromUtf8("hiddenButton"));

        horizontalLayout_2->addWidget(hiddenButton);


        verticalLayout->addWidget(frame);

        line = new QFrame(layout);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        scrollArea->setWidget(layout);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(cg3__viewer__DrawableContainerDrawListManager);

        QMetaObject::connectSlotsByName(cg3__viewer__DrawableContainerDrawListManager);
    } // setupUi

    void retranslateUi(QFrame *cg3__viewer__DrawableContainerDrawListManager)
    {
        cg3__viewer__DrawableContainerDrawListManager->setWindowTitle(QApplication::translate("cg3::viewer::DrawableContainerDrawListManager", "Frame", nullptr));
        visibleButton->setText(QApplication::translate("cg3::viewer::DrawableContainerDrawListManager", "All Visible", nullptr));
        hiddenButton->setText(QApplication::translate("cg3::viewer::DrawableContainerDrawListManager", "All Hidden", nullptr));
    } // retranslateUi

};

} // namespace viewer
} // namespace cg3

namespace cg3 {
namespace viewer {
namespace Ui {
    class DrawableContainerDrawListManager: public Ui_DrawableContainerDrawListManager {};
} // namespace Ui
} // namespace viewer
} // namespace cg3

#endif // UI_DRAWABLE_CONTAINER_DRAWLIST_MANAGER_H
