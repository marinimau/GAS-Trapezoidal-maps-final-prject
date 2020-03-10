/********************************************************************************
** Form generated from reading UI file 'drawable_object_drawlist_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWABLE_OBJECT_DRAWLIST_MANAGER_H
#define UI_DRAWABLE_OBJECT_DRAWLIST_MANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "cg3/viewer/widgets/qclickablelabel.h"

namespace cg3 {
namespace viewer {

class Ui_DrawableObjectDrawListManager
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCheckBox *subFrameCheckBox;
    QCheckBox *checkBox;
    QClickableLabel *objectName;
    QClickableLabel *objectType;
    QPushButton *closePushButton;

    void setupUi(QFrame *cg3__viewer__DrawableObjectDrawListManager)
    {
        if (cg3__viewer__DrawableObjectDrawListManager->objectName().isEmpty())
            cg3__viewer__DrawableObjectDrawListManager->setObjectName(QString::fromUtf8("cg3__viewer__DrawableObjectDrawListManager"));
        cg3__viewer__DrawableObjectDrawListManager->resize(400, 76);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cg3__viewer__DrawableObjectDrawListManager->sizePolicy().hasHeightForWidth());
        cg3__viewer__DrawableObjectDrawListManager->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(cg3__viewer__DrawableObjectDrawListManager);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 0, 0, 0);
        frame = new QFrame(cg3__viewer__DrawableObjectDrawListManager);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        subFrameCheckBox = new QCheckBox(frame);
        subFrameCheckBox->setObjectName(QString::fromUtf8("subFrameCheckBox"));
        subFrameCheckBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(subFrameCheckBox->sizePolicy().hasHeightForWidth());
        subFrameCheckBox->setSizePolicy(sizePolicy1);
        subFrameCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    image: url(:/triangle_closed.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/triangle_opened.png)\n"
"}"));
        subFrameCheckBox->setChecked(false);

        horizontalLayout->addWidget(subFrameCheckBox);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(checkBox);

        objectName = new QClickableLabel(frame);
        objectName->setObjectName(QString::fromUtf8("objectName"));
        objectName->setMargin(0);

        horizontalLayout->addWidget(objectName);

        objectType = new QClickableLabel(frame);
        objectType->setObjectName(QString::fromUtf8("objectType"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(objectType->sizePolicy().hasHeightForWidth());
        objectType->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(objectType);

        closePushButton = new QPushButton(frame);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        sizePolicy2.setHeightForWidth(closePushButton->sizePolicy().hasHeightForWidth());
        closePushButton->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closePushButton->setIcon(icon);
        closePushButton->setFlat(true);

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addWidget(frame);


        retranslateUi(cg3__viewer__DrawableObjectDrawListManager);

        QMetaObject::connectSlotsByName(cg3__viewer__DrawableObjectDrawListManager);
    } // setupUi

    void retranslateUi(QFrame *cg3__viewer__DrawableObjectDrawListManager)
    {
        cg3__viewer__DrawableObjectDrawListManager->setWindowTitle(QApplication::translate("cg3::viewer::DrawableObjectDrawListManager", "Frame", nullptr));
        subFrameCheckBox->setText(QString());
        checkBox->setText(QString());
        objectName->setText(QString());
        objectType->setText(QString());
        closePushButton->setText(QString());
    } // retranslateUi

};

} // namespace viewer
} // namespace cg3

namespace cg3 {
namespace viewer {
namespace Ui {
    class DrawableObjectDrawListManager: public Ui_DrawableObjectDrawListManager {};
} // namespace Ui
} // namespace viewer
} // namespace cg3

#endif // UI_DRAWABLE_OBJECT_DRAWLIST_MANAGER_H
