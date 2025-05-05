#ifndef BADOBSTACLE_H
#define BADOBSTACLE_H

#include "obstacle.h"
#include "level1gamewindow.h"
#include <QPointF>
class Level1GameWindow;
class BadObstacle : public Obstacle {
public:
    BadObstacle( QString imagePath, QPointF pos,Level1GameWindow* gameWindow);
    void updatePosition() override;
    void onCollision(Player& player) override;
    void update()override;
    Level1GameWindow* gameWindow;
};

#endif // BADOBSTACLE_H
