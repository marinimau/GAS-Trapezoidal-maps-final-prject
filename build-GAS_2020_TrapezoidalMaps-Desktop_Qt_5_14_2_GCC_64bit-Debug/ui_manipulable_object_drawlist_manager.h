/********************************************************************************
** Form generated from reading UI file 'manipulable_object_drawlist_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANIPULABLE_OBJECT_DRAWLIST_MANAGER_H
#define UI_MANIPULABLE_OBJECT_DRAWLIST_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>

namespace cg3 {
namespace viewer {

class Ui_ManipulableFormDrawlistManager
{
public:
    QGridLayout *gridLayout;
    QCheckBox *subFrameAxisCheckBox;

    void setupUi(QFrame *cg3__viewer__ManipulableFormDrawlistManager)
    {
        if (cg3__viewer__ManipulableFormDrawlistManager->objectName().isEmpty())
            cg3__viewer__ManipulableFormDrawlistManager->setObjectName(QString::fromUtf8("cg3__viewer__ManipulableFormDrawlistManager"));
        cg3__viewer__ManipulableFormDrawlistManager->resize(400, 60);
        gridLayout = new QGridLayout(cg3__viewer__ManipulableFormDrawlistManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        subFrameAxisCheckBox = new QCheckBox(cg3__viewer__ManipulableFormDrawlistManager);
        subFrameAxisCheckBox->setObjectName(QString::fromUtf8("subFrameAxisCheckBox"));

        gridLayout->addWidget(subFrameAxisCheckBox, 0, 0, 1, 1);


        retranslateUi(cg3__viewer__ManipulableFormDrawlistManager);

        QMetaObject::connectSlotsByName(cg3__viewer__ManipulableFormDrawlistManager);
    } // setupUi

    void retranslateUi(QFrame *cg3__viewer__ManipulableFormDrawlistManager)
    {
        cg3__viewer__ManipulableFormDrawlistManager->setWindowTitle(QCoreApplication::translate("cg3::viewer::ManipulableFormDrawlistManager", "Frame", nullptr));
        subFrameAxisCheckBox->setText(QCoreApplication::translate("cg3::viewer::ManipulableFormDrawlistManager", "Draw SubFrame Axis", nullptr));
    } // retranslateUi

};

} // namespace viewer
} // namespace cg3

namespace cg3 {
namespace viewer {
namespace Ui {
    class ManipulableFormDrawlistManager: public Ui_ManipulableFormDrawlistManager {};
} // namespace Ui
} // namespace viewer
} // namespace cg3

#endif // UI_MANIPULABLE_OBJECT_DRAWLIST_MANAGER_H
