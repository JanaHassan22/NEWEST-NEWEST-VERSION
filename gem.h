#ifndef GEM_H
#define GEM_H

#include <QGraphicsPixmapItem>

class Gem : public QGraphicsPixmapItem
{
public:
    Gem(qreal x, qreal y);
    void checkCollision();
};

#endif // GEM_H
