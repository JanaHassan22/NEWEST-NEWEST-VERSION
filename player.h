#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QVector>
#include <QPixmap>
#include <QImage>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "obstacle.h"
#include "killableobstacle.h"
class Scene;
class KillableObstacle;
enum Role {
    guy,
    HijabiGirl
};

enum PlayerState {
    Idle,
    Running,
    Jumping
};

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT  // This line is critical for Qt's meta-object system

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;





public:
    static Role selectedPlayer;
    Player(Role role, double x, double y, Scene* scene);
    void movePlayer();
    void setMoveRight(bool move);
    void setMoveLeft(bool move);
    double getX() const;
    double getY() const;
    QImage getImage() const;
 void checkGemCollision();
    void checkCollisions();
 Role role;
    void loadFrames();
 //*******************************
 int health = 100;  // Player health (100%)
 int lives = 3;     // Player's lives
 void decreaseHealth();  // Function to decrease health
 void loseLife();   // Function to lose a life
private slots:
    void advanceFrame();
    void jumpUp();
    void fallDown();


private:
    double positionX;
    double positionY;
     Scene* myscene;


    bool jumping;
    int jumpHeight;
    int currentJump;

    bool moveLeft;
    bool moveRight;


    QTimer* animationTimer;
    QTimer* jumpTimer;
    QTimer* movementTimer;

    QVector<QPixmap> runningFrames;
    QVector<QPixmap> jumpFrames;
    QVector<QPixmap> idleFrames;


    int currentFrameIndex = 0;
    PlayerState state = Idle;

signals:
    void requestScroll(int dx);



};

#endif
