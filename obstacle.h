#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QString>
class Player;
class Obstacle : public QGraphicsPixmapItem {
protected:
    QPointF position;
    int size;
    QString imagePath;

public:
    Obstacle(QString imagePath, QPointF position, int size=32);
    virtual ~Obstacle() {}

    // Pure virtual methods that must be implemented by derived classes
    virtual void updatePosition() = 0;
    virtual void onCollision(Player& player) = 0;
    virtual void update()=0;

};
#endif
