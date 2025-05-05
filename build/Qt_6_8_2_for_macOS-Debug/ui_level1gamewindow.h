/********************************************************************************
** Form generated from reading UI file 'level1gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL1GAMEWINDOW_H
#define UI_LEVEL1GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Level1GameWindow
{
public:
    QGraphicsView *backgroundUNI;

    void setupUi(QWidget *Level1GameWindow)
    {
        if (Level1GameWindow->objectName().isEmpty())
            Level1GameWindow->setObjectName("Level1GameWindow");
        Level1GameWindow->resize(709, 633);
        backgroundUNI = new QGraphicsView(Level1GameWindow);
        backgroundUNI->setObjectName("backgroundUNI");
        backgroundUNI->setGeometry(QRect(0, -50, 1001, 691));

        retranslateUi(Level1GameWindow);

        QMetaObject::connectSlotsByName(Level1GameWindow);
    } // setupUi

    void retranslateUi(QWidget *Level1GameWindow)
    {
        Level1GameWindow->setWindowTitle(QCoreApplication::translate("Level1GameWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Level1GameWindow: public Ui_Level1GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL1GAMEWINDOW_H
