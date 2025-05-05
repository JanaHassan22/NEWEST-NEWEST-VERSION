#include "playscreen.h"
#include "ui_playscreen.h"
#include "playerselectwindow.h"

PlayScreen::PlayScreen(QWidget *parent)
    : QWidget(parent), ui(new Ui::PlayScreen)
{
    ui->setupUi(this);
    connect(ui->playButton, &QPushButton::clicked, this, &PlayScreen::onPlayClicked);
}

PlayScreen::~PlayScreen()
{
    delete ui;
}

void PlayScreen::onPlayClicked()
{
    this->hide();
    PlayerSelectWindow *ps = new PlayerSelectWindow();
    ps->show();
}
