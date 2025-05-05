#include "badobstacle.h"
#include <QGraphicsScene>
#include "level1gamewindow.h"
#include <QPointF>
BadObstacle::BadObstacle(QString imagePath, QPointF pos,  Level1GameWindow* gameWindow)
    : Obstacle(imagePath, pos), gameWindow(gameWindow){}

void BadObstacle::updatePosition() {
    moveBy(-2, 0); // Scroll to the left like other obstacles
}


void BadObstacle::update(){}

void BadObstacle::onCollision(Player& player) {
    gameWindow->decreaseHealth();  // Decreases health of the player
}
