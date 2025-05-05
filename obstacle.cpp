#include "obstacle.h"
#include <QPixmap>

Obstacle::Obstacle(QString imagePath, QPointF position, int size)
    : QGraphicsPixmapItem(QPixmap(imagePath)), position(position), size(size){
    setPos(position);
}
