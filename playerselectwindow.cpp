#include "playerselectwindow.h"
#include "ui_playerselectwindow.h"
#include "levelselectwindow.h"
#include <QGraphicsPathItem>
#include <QPixmap>
#include "player.h"

PlayerSelectWindow::PlayerSelectWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::PlayerSelectWindow)
{
    ui->setupUi(this);

    connect(ui->player1Button, &QPushButton::clicked, this, &PlayerSelectWindow::selectPlayer1);
    connect(ui->player2Button, &QPushButton::clicked, this, &PlayerSelectWindow::selectPlayer2);
}

PlayerSelectWindow::~PlayerSelectWindow()
{
    delete ui;
}
void PlayerSelectWindow::selectPlayer1()
{
    Player::selectedPlayer = guy;
    this->hide();
    LevelSelectWindow* ls = new LevelSelectWindow();
    ls->show();
}



void PlayerSelectWindow::selectPlayer2()
{
    Player::selectedPlayer = HijabiGirl;
     this->hide();
    LevelSelectWindow* ls = new LevelSelectWindow();
    ls->show();

}



