#ifndef KILLABLEOBSTACLE_H
#define KILLABLEOBSTACLE_H

#include "obstacle.h"
#include <QPointF>
class Player;
class KillableObstacle : public Obstacle {
private:
    bool isKilled;
    QString deadImagePath;
   // int rewardPoint;

public:
    KillableObstacle(QString imagePath, QString deadImagePath, QPointF position);
    void updatePosition();
    void onCollision(Player& player) ;
    void update();
    void showKillAnimation();
};

#endif // KILLABLEOBSTACLE_H
