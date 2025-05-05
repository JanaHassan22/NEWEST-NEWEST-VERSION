QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    badobstacle.cpp \
    gem.cpp \
    killableobstacle.cpp \
    level1gamewindow.cpp \
    levelselectwindow.cpp \
    lifetracker.cpp \
    main.cpp \
    mainwindow.cpp \
    noeffectobstacle.cpp \
    obstacle.cpp \
    player.cpp \
    playerselectwindow.cpp \
    playscreen.cpp \
    scene.cpp \
    scoretracker.cpp

HEADERS += \
    badobstacle.h \
    gem.h \
    killableobstacle.h \
    level1gamewindow.h \
    levelselectwindow.h \
    lifetracker.h \
    mainwindow.h \
    noeffectobstacle.h \
    obstacle.h \
    player.h \
    playerselectwindow.h \
    playscreen.h \
    scene.h \
    scoretracker.h

FORMS += \
    level1gamewindow.ui \
    levelselectwindow.ui \
    mainwindow.ui \
    playerselectwindow.ui \
    playscreen.ui

TRANSLATIONS += \
    EscapeThePROFESSOR_en_EG.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    AUC_background.qrc \
    AbdoMovements.qrc \
    ESCAPEPROFESSORBUTTONIMAGE.qrc \
    GannaRunning.qrc \
    KILLABLEOBSTACLES.qrc \
    PlayWindowBackground.qrc \
    PlayerSlectionImages.qrc \
    UniBackground.qrc \
    coins.qrc \
    heartImage.qrc \
    resources.qrc \
    selectplayerg.qrc

DISTFILES += \
    Backgrounduni.png
