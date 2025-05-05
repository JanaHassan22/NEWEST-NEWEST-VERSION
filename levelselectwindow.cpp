//levelselectwindow.cpp
#include "levelselectwindow.h"
#include "ui_levelselectwindow.h"
#include "player.h"
#include "level1gamewindow.h"
#include "scene.h"

LevelSelectWindow::LevelSelectWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LevelSelectWindow)
{
    ui->setupUi(this);
    connect(ui->level1pushButton, &QPushButton::clicked, this, &LevelSelectWindow::goToLevel1);
}

LevelSelectWindow::~LevelSelectWindow()
{
    delete ui;
}

void LevelSelectWindow::goToLevel1()
{
    this->hide();
    gameWindow = new Level1GameWindow();
    gameWindow->show();
}
