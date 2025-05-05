#include "scene.h"
#include "player.h"
#include "obstacle.h"
#include "killableobstacle.h"
#include "gem.h"
#include <QRandomGenerator>
#include "badobstacle.h"
QGraphicsTextItem* scoreText = nullptr;
Scene::Scene(QObject *parent) : QGraphicsScene(parent) {
    setSceneRect(0, 0, 800, 600);

    Player* p = new Player(Player::selectedPlayer, 0, 150, this);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    spawnGems(20);
    spawnObstacles(5);
    healthBar = new QGraphicsPixmapItem(QPixmap(":/assets/health.png"));
    addItem(healthBar);  // not scene()->addItem(...); unless you're in another class
    healthBar->setPos(10, 10);
    healthBar->setZValue(10);  // Ensure it's on top of player/background

    // Connect the signal from player to the scene's scroll function
    connect(p, &Player::requestScroll, this, &Scene::scrollScene);

    qDebug() << "Player created at position:" << p->pos();
    this->addItem(p);
    p->setZValue(2);


    BadObstacle* danny = new BadObstacle(":/killableObstacles/WalkDany.png", QPointF(300, 250), gameWindow);
    danny->setZValue(1);  // Ensure obstacles are below the player
    this->addItem(danny);

   // KillableObstacle* boska = new KillableObstacle(":/killableObstacles/WalkBoska.png", ":/killableObstacles/BoskaHit.png", QPointF(500, 250));
   // boska->setZValue(1);  // Ensure obstacles are below the player
  //  this->addItem(boska);
    scoreText = new QGraphicsTextItem();
    scoreText->setDefaultTextColor(Qt::white); // Or any color
    scoreText->setFont(QFont("Arial", 16, QFont::Bold));
    scoreText->setPlainText("GemScore: 0"); //****
    scoreText->setZValue(10); // Always on top
    scoreText->setPos(10, 10); // Top-left corner
    addItem(scoreText);



}


void Scene::scrollScene(int dx) {
    QList<QGraphicsItem *> itemsList = items();
    for (auto item : itemsList) {
        if (item != nullptr && item->zValue() < 2) {
            item->moveBy(-dx, 0);  // Scroll everything left or right
        }
    }
}
void Scene::spawnGems(int count)
{
    for (int i = 0; i < count; ++i) {
        qreal x = QRandomGenerator::global()->bounded(500, 5000);  // spread across the scene
        qreal y = 300;  // Adjust based on jump height

        Gem* gem = new Gem(x, y-180);
        this->addItem(gem);
    }
}
void Scene::incrementScore()
{
    score++;  // Increment the score
    scoreText->setPlainText(QString("GemScore: %1").arg(score));  // ******** Update the displayed score text
}
//*********************************************************
void Scene::spawnObstacles(int count) {
    for (int i = 0; i < count; ++i) {
        qreal x = QRandomGenerator::global()->bounded(500, 5000);  // Random X position
        qreal y = QRandomGenerator::global()->bounded(150, 450);   // Random Y position for vertical variation

        BadObstacle* badObstacle = new BadObstacle(":/killableObstacles/Obstacle.png", QPointF(x, y), gameWindow);
        this->addItem(badObstacle);
        badObstacle->setZValue(1);  // Place obstacle behind player
    }
}

void Scene::updateHealthAndLives() {
    // Update health bar position or representation
    healthBar->setPixmap(QPixmap(":/assets/health.png").scaled(player->health, 10));

    // Display the lives
    QGraphicsTextItem* livesText = new QGraphicsTextItem();
    livesText->setDefaultTextColor(Qt::white);
    livesText->setFont(QFont("Arial", 16, QFont::Bold));
    livesText->setPlainText(QString("Lives: %1").arg(player->lives));
    livesText->setZValue(10);  // Always on top
    livesText->setPos(10, 40); // Adjust position as needed
    addItem(livesText);
}
void Scene::gameOver() {
    // Stop the game and show game over message
    qDebug() << "Game Over!";
    // Example: you can stop the movement or open a new window showing the game over state
}

