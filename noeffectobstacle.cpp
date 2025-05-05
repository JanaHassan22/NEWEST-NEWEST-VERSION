#include "noeffectobstacle.h"
#include <QGraphicsScene>
#include "player.h"
NoEffectObstacle::NoEffectObstacle(QString imagePath, QPoint pos)
    : Obstacle(imagePath, pos), interacted(false) {}

void NoEffectObstacle::updatePosition() {
    moveBy(-2, 0); // Scroll to the left
}

void NoEffectObstacle::onCollision(Player& player) {
    int playerBottom = player.y() + player.pixmap().height();
    int playerLeft = player.x();
    int playerRight = player.x() + player.pixmap().width();

    int obstacleTop = this->y();
    int obstacleLeft = this->x();
    int obstacleRight = this->x() + this->pixmap().width();

    if (playerBottom <= obstacleTop + 5 &&
        playerRight > obstacleLeft &&
        playerLeft < obstacleRight) {
        interacted = true;
    }
    // No damage or score added
}
void NoEffectObstacle::update(){}
