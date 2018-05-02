/********************************************************************************
** Form generated from reading UI file 'RoiWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROIWINDOW_H
#define UI_ROIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <roilabel.h>

QT_BEGIN_NAMESPACE

class Ui_RoiWindow
{
public:
    RoiLabel *labelROIVideo;
    QPushButton *SaveROIButton;
    QPushButton *ClearPointButton;

    void setupUi(QWidget *RoiWindow)
    {
        if (RoiWindow->objectName().isEmpty())
            RoiWindow->setObjectName(QStringLiteral("RoiWindow"));
        RoiWindow->resize(1140, 720);
        labelROIVideo = new RoiLabel(RoiWindow);
        labelROIVideo->setObjectName(QStringLiteral("labelROIVideo"));
        labelROIVideo->setGeometry(QRect(0, 0, 960, 720));
        labelROIVideo->setCursor(QCursor(Qt::ArrowCursor));
        labelROIVideo->setMouseTracking(true);
        labelROIVideo->setAutoFillBackground(true);
        labelROIVideo->setAlignment(Qt::AlignCenter);
        SaveROIButton = new QPushButton(RoiWindow);
        SaveROIButton->setObjectName(QStringLiteral("SaveROIButton"));
        SaveROIButton->setGeometry(QRect(970, 200, 111, 41));
        ClearPointButton = new QPushButton(RoiWindow);
        ClearPointButton->setObjectName(QStringLiteral("ClearPointButton"));
        ClearPointButton->setGeometry(QRect(970, 260, 111, 41));

        retranslateUi(RoiWindow);

        QMetaObject::connectSlotsByName(RoiWindow);
    } // setupUi

    void retranslateUi(QWidget *RoiWindow)
    {
        RoiWindow->setWindowTitle(QApplication::translate("RoiWindow", "RoiWindow", 0));
        labelROIVideo->setText(QString());
        SaveROIButton->setText(QApplication::translate("RoiWindow", "Save ROI", 0));
        ClearPointButton->setText(QApplication::translate("RoiWindow", "Clear point", 0));
    } // retranslateUi

};

namespace Ui {
    class RoiWindow: public Ui_RoiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROIWINDOW_H
