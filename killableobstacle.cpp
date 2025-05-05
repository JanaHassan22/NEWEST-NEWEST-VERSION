
#include "killableobstacle.h"
#include <QTimer>
#include <QGraphicsScene>
#include "scene.h"
#include "lifetracker.h"
KillableObstacle::KillableObstacle(QString imagePath, QString deadImagePath, QPointF position)
    : Obstacle(imagePath, position), isKilled(false), deadImagePath(deadImagePath) {
    int width = 300;  // width in pixels 200
    int height = 600; // height in pixels 500

    // Load the image and scale it to the desired size
    QPixmap pixmap(imagePath);
    pixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio);

    // Set the scaled pixmap to the obstacle
    setPixmap(pixmap);
}
void KillableObstacle::updatePosition() {
    moveBy(-2, 0); // scroll to the left
}

void KillableObstacle::onCollision(Player& player) {
    qDebug() << "Checking collision for player at" << player.pos() << "with obstacle at" << this->pos();

    // Get the bounding rectangle for the player and the obstacle
    QRectF playerRect = player.boundingRect();
    QRectF obstacleRect = this->boundingRect();

    // Check for overlap between player and obstacle using QRectF's intersects method
    if (playerRect.intersects(obstacleRect)) {
        qDebug() << "Collision detected!";
        if (!isKilled) {
            isKilled = true;
            qDebug() << "Kill animation triggered!";
            showKillAnimation();
        }
    }else{
        //player.loseLife();
    }
}
void KillableObstacle::showKillAnimation() {
    qDebug() << "Kill animation triggered for obstacle!";
    setPixmap(QPixmap(deadImagePath).scaled(size, size));

    QTimer::singleShot(800, [this]() {
        if (scene()) scene()->removeItem(this);
        delete this;
    });
}


void KillableObstacle::update() {
    updatePosition();
}
