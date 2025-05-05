#ifndef LIFETRACKER_H
#define LIFETRACKER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector>

class LifeTracker : public QObject {
    Q_OBJECT
public:
    LifeTracker(QGraphicsScene *scene, int x = 0, int y = 0);

    void addLife();     // Adds a heart (max 3)
    void loseLife();    // Removes a heart (min 0)
    int getLives() const;

private:
    void updateHearts(); // Internal function to update the UI
    int lives;
    const int maxLives = 3;
    QVector<QGraphicsPixmapItem*> heartIcons;
    QGraphicsScene *scene;
    int xStart, yStart;
};

#endif // LIFETRACKER_H
