/********************************************************************************
** Form generated from reading UI file 'playscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYSCREEN_H
#define UI_PLAYSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayScreen
{
public:
    QPushButton *playButton;

    void setupUi(QWidget *PlayScreen)
    {
        if (PlayScreen->objectName().isEmpty())
            PlayScreen->setObjectName("PlayScreen");
        PlayScreen->resize(822, 679);
        PlayScreen->setAutoFillBackground(false);
        PlayScreen->setStyleSheet(QString::fromUtf8(""));
        playButton = new QPushButton(PlayScreen);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(-20, 0, 851, 681));
        playButton->setAutoFillBackground(true);
        playButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PlayWindowBackground/PlayBackground.jpeg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        playButton->setIcon(icon);
        playButton->setIconSize(QSize(641, 1850));

        retranslateUi(PlayScreen);

        QMetaObject::connectSlotsByName(PlayScreen);
    } // setupUi

    void retranslateUi(QWidget *PlayScreen)
    {
        PlayScreen->setWindowTitle(QCoreApplication::translate("PlayScreen", "Form", nullptr));
        playButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayScreen: public Ui_PlayScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYSCREEN_H
