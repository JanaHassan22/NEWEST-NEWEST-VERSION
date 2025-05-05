#include "lifetracker.h"
#include <QGraphicsScene>
#include <QPixmap>

LifeTracker::LifeTracker(QGraphicsScene *scene, int x, int y)
    : lives(3), scene(scene), xStart(x), yStart(y)
{
    for (int i = 0; i < maxLives; ++i) {
        QPixmap originalPixmap(":/heart/HEART.png");
        QPixmap scaledPixmap = originalPixmap.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QGraphicsPixmapItem *heart = new QGraphicsPixmapItem(scaledPixmap);
        int heartWidth = 20; // or whatever size your hearts are
        heart->setPos(scene->width() - (i + 1) * (heartWidth + 5), y);
        scene->addItem(heart);
        heartIcons.append(heart);
    }
}

void LifeTracker::addLife() {
    if (lives < maxLives) {
        ++lives;
        updateHearts();
    }
}

void LifeTracker::loseLife() {
    if (lives > 0) {
        --lives;
        updateHearts();
    }
}

int LifeTracker::getLives() const {
    return lives;
}

void LifeTracker::updateHearts() {
    for (int i = 0; i < maxLives; ++i) {
        heartIcons[i]->setVisible(i < lives);

    }
}
