/********************************************************************************
** Form generated from reading UI file 'playerselectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSELECTWINDOW_H
#define UI_PLAYERSELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerSelectWindow
{
public:
    QPushButton *player1Button;
    QPushButton *player2Button;
    QLabel *label;

    void setupUi(QWidget *PlayerSelectWindow)
    {
        if (PlayerSelectWindow->objectName().isEmpty())
            PlayerSelectWindow->setObjectName("PlayerSelectWindow");
        PlayerSelectWindow->resize(592, 396);
        player1Button = new QPushButton(PlayerSelectWindow);
        player1Button->setObjectName("player1Button");
        player1Button->setGeometry(QRect(110, 100, 161, 181));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/playersSelect/AbdoGuy.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        player1Button->setIcon(icon);
        player1Button->setIconSize(QSize(190, 180));
        player2Button = new QPushButton(PlayerSelectWindow);
        player2Button->setObjectName("player2Button");
        player2Button->setGeometry(QRect(320, 100, 161, 191));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/playersSelect/gannaHijabiGirl.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        player2Button->setIcon(icon1);
        player2Button->setIconSize(QSize(190, 180));
        label = new QLabel(PlayerSelectWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 40, 171, 41));

        retranslateUi(PlayerSelectWindow);

        QMetaObject::connectSlotsByName(PlayerSelectWindow);
    } // setupUi

    void retranslateUi(QWidget *PlayerSelectWindow)
    {
        PlayerSelectWindow->setWindowTitle(QCoreApplication::translate("PlayerSelectWindow", "Form", nullptr));
        player1Button->setText(QString());
        player2Button->setText(QString());
        label->setText(QCoreApplication::translate("PlayerSelectWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">Select a player!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerSelectWindow: public Ui_PlayerSelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSELECTWINDOW_H
