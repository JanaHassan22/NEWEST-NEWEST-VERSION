#include "gem.h"
#include <QPixmap>

Gem::Gem(qreal x, qreal y)
{
    QPixmap pixmap(":/coin/coin.png"); // make sure to have a gem image in resources
    setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(x, y+120);
}
