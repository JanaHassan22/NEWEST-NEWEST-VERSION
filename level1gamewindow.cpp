#include "level1gamewindow.h"
#include "ui_level1gamewindow.h"
#include "scene.h"
#include <QGraphicsView>
#include "playerselectwindow.h"
#include "killableobstacle.h"
#include "badobstacle.h"
#include "noeffectobstacle.h"
#include <QMessageBox>

Level1GameWindow::Level1GameWindow(QWidget *parent)
    : QMainWindow (parent)
    , ui(new Ui::Level1GameWindow), health(3)
{
    ui->setupUi(this);
    scene = nullptr;

    // Initialize health bar
    healthBar = new QProgressBar(this);
    healthBar->setRange(0, 3);
    healthBar->setValue(3);
    healthBar->setTextVisible(false);
    healthBar->setGeometry(10, 10, 100, 20);

    // Initialize the scene here (no need to create another QGraphicsView manually)
    scene = new Scene(this);  // Only initialize the scene once here
    scene->setSceneRect(0, 0, 800, 600); // Ensure this is the correct size for the view

    // Set up the background
    backgroundPixmap = QPixmap(":/auc_Background/Backgrounduni.png");
    backgroundPixmap = backgroundPixmap.scaled(1600, 600, Qt::KeepAspectRatioByExpanding);
    backgroundItem = scene->addPixmap(backgroundPixmap);
    backgroundItem->setZValue(-1);  // So it stays behind player & obstacles
    backgroundItem->setPos(backgroundOffset, 0);

    // Use the UI QGraphicsView to show the scene
    ui->backgroundUNI->setScene(scene);  // Make sure the scene is set to the view
    ui->backgroundUNI->setRenderHint(QPainter::Antialiasing);
    ui->backgroundUNI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->backgroundUNI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Check if background image loaded properly
    if (backgroundPixmap.isNull()) {
        qDebug() << "Error loading background image!";
    }
}

Level1GameWindow::~Level1GameWindow()
{
    delete ui;
}

void Level1GameWindow::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);

    // Set the scene size again to ensure it doesn't change unexpectedly
    scene->setSceneRect(0, 0, 800, 600);  // View size
}

void Level1GameWindow::scrollBackground() {
    backgroundOffset -= 2;  // Scroll speed (2 pixels per frame)

    if (abs(backgroundOffset) >= backgroundPixmap.width() - scene->width()) {
        backgroundOffset = 0;  // Loop back to start
    }

    backgroundItem->setPos(backgroundOffset, 0);  // Move background left
}

void Level1GameWindow::updateGame() {
    player->movePlayer();  // This updates movement based on flags
}

void Level1GameWindow::spawnObstacles()
{
    int obstacleWidth = 50;
    int obstacleHeight = 50;

    // Spawning various obstacles
    KillableObstacle* danny = new KillableObstacle(":/killableObstacles/WalkDany.png", ":/killableObstacles/DanyHit.png", QPointF(30, 1.5));
    danny->setPixmap(danny->pixmap().scaled(obstacleWidth, obstacleHeight, Qt::KeepAspectRatio));
    scene->addItem(danny);

    KillableObstacle* boska = new KillableObstacle(":/killableObstacles/WalkBoska.png", ":/killableObstacles/BoskaHit.png", QPointF(50, 1.5));
    boska->setPixmap(boska->pixmap().scaled(obstacleWidth, obstacleHeight, Qt::KeepAspectRatio));
    scene->addItem(boska);

    KillableObstacle* mohannad = new KillableObstacle(":/killableObstacles/WalkMohan.png", ":/killableObstacles/MohanHit2.png", QPointF(60, 1.5));
    mohannad->setPixmap(mohannad->pixmap().scaled(obstacleWidth, obstacleHeight, Qt::KeepAspectRatio));
    scene->addItem(mohannad);

    KillableObstacle* marawan = new KillableObstacle(":/killableObstacles/WalkMaro.png", ":/killableObstacles/MaroHit.png", QPointF(60, 1.5));
    marawan->setPixmap(marawan->pixmap().scaled(obstacleWidth, obstacleHeight, Qt::KeepAspectRatio));
    scene->addItem(marawan);
}

void Level1GameWindow::decreaseHealth() {
    health--;
    healthBar->setValue(health);

    if (health <= 0) {
        // trigger game over logic
        QMessageBox::information(this, "Game Over", "You lost all lives!");
        // Reset or close level
    }
}
