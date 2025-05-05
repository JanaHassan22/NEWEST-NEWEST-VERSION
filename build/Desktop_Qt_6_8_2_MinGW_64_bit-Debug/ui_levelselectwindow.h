/********************************************************************************
** Form generated from reading UI file 'levelselectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELSELECTWINDOW_H
#define UI_LEVELSELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelSelectWindow
{
public:
    QPushButton *level2pushButton;
    QPushButton *level1pushButton;
    QPushButton *level3pushButton;
    QPushButton *level4pushButton;
    QPushButton *level5pushButton;
    QLabel *label;

    void setupUi(QWidget *LevelSelectWindow)
    {
        if (LevelSelectWindow->objectName().isEmpty())
            LevelSelectWindow->setObjectName("LevelSelectWindow");
        LevelSelectWindow->resize(664, 392);
        level2pushButton = new QPushButton(LevelSelectWindow);
        level2pushButton->setObjectName("level2pushButton");
        level2pushButton->setGeometry(QRect(150, 130, 111, 101));
        level1pushButton = new QPushButton(LevelSelectWindow);
        level1pushButton->setObjectName("level1pushButton");
        level1pushButton->setGeometry(QRect(10, 130, 121, 101));
        level3pushButton = new QPushButton(LevelSelectWindow);
        level3pushButton->setObjectName("level3pushButton");
        level3pushButton->setGeometry(QRect(280, 130, 111, 101));
        level4pushButton = new QPushButton(LevelSelectWindow);
        level4pushButton->setObjectName("level4pushButton");
        level4pushButton->setGeometry(QRect(410, 130, 111, 101));
        level5pushButton = new QPushButton(LevelSelectWindow);
        level5pushButton->setObjectName("level5pushButton");
        level5pushButton->setGeometry(QRect(540, 130, 111, 101));
        label = new QLabel(LevelSelectWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 60, 191, 41));

        retranslateUi(LevelSelectWindow);

        QMetaObject::connectSlotsByName(LevelSelectWindow);
    } // setupUi

    void retranslateUi(QWidget *LevelSelectWindow)
    {
        LevelSelectWindow->setWindowTitle(QCoreApplication::translate("LevelSelectWindow", "Form", nullptr));
        level2pushButton->setText(QCoreApplication::translate("LevelSelectWindow", "2", nullptr));
        level1pushButton->setText(QCoreApplication::translate("LevelSelectWindow", "1", nullptr));
        level3pushButton->setText(QCoreApplication::translate("LevelSelectWindow", "3", nullptr));
        level4pushButton->setText(QCoreApplication::translate("LevelSelectWindow", "4", nullptr));
        level5pushButton->setText(QCoreApplication::translate("LevelSelectWindow", "5", nullptr));
        label->setText(QCoreApplication::translate("LevelSelectWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">choose your level</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelSelectWindow: public Ui_LevelSelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELSELECTWINDOW_H
