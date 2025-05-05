#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include "player.h"
#include <QGraphicsTextItem>
#include "level1gamewindow.h"

extern QGraphicsTextItem* scoreText;
class Player;
class Scene : public QGraphicsScene {
    Q_OBJECT
public:
    Scene( QObject *parent=nullptr);
    void incrementScore();
    Level1GameWindow* gameWindow;
    void spawnObstacles(int count);
    void updateHealthAndLives();
    void gameOver();
private:

    QGraphicsPixmapItem* healthBar;
    Player* player;
    int score = 0;
public slots:
    void scrollScene(int dx);
    void spawnGems(int count);


};

#endif
