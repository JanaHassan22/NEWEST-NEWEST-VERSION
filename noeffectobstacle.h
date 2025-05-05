#ifndef NOEFFECTOBSTACLE_H
#define NOEFFECTOBSTACLE_H
#include "obstacle.h"
class NoEffectObstacle : public Obstacle {
private:
    bool interacted;

public:
    NoEffectObstacle(QString imagePath, QPoint pos);
    void updatePosition() override;
    void onCollision(Player& player) override;
    void update() override;
};
#endif // NOEFFECTOBSTACLE_H
