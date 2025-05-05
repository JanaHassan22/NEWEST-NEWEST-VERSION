

#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "scene.h"
#include "obstacle.h"
#include "gem.h"
Role Player::selectedPlayer = HijabiGirl;
Player::Player(Role role, double x, double y, Scene* scene)
    : role(role), positionX(x), positionY(y)
{
    qDebug() << "Creating Player at position: (" << positionX << "," << positionY << ")";  // Debug line
    myscene = scene;
    this->role = role;
    loadFrames();
    setPixmap(idleFrames[0]);
    QPixmap scaledPixmap = idleFrames[0].scaled(25, 50, Qt::KeepAspectRatio);  // Example: scaling to 50x100
    setPixmap(scaledPixmap);

    setPos(positionX, positionY);

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Player::advanceFrame);
    animationTimer->start(100);


    // Jumping
    jumping = false;
    jumpHeight = 300;
    currentJump = 0;

    jumpTimer = new QTimer(this);
    connect(jumpTimer, &QTimer::timeout, this, &Player::jumpUp);

    // Horizontal movement
    moveLeft = false;
    moveRight = false;

    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &Player::movePlayer);
    movementTimer->start(10); // Continuous movement
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        moveLeft = true;
        checkGemCollision();
        state = Running;
    } else if (event->key() == Qt::Key_Right) {
        moveRight = true;
        checkGemCollision();
        state = Running;  // ✅ Again
    } else if (event->key() == Qt::Key_Space && !jumping) {
        jumping = true;
        checkGemCollision();
        currentJump = 0;
        state = Jumping;
        currentFrameIndex = 0;  // restart jump animation
        jumpTimer->start(10);
    }
}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        moveLeft = false;
    } else if (event->key() == Qt::Key_Right) {
        moveRight = false;
    }
}

/*void Player::movePlayer()
{
    if (!scene()) return;

    qreal playerWidth = pixmap().width();
    qreal sceneWidth = scene()->width();

    if (moveLeft && x() > 0) {
        setX(x() - 5);  // move left
    }

    if (moveRight && x() + playerWidth < sceneWidth) {
        setX(x() + 5);  // move right
    }

    // If not moving, switch to idle state
    if (!moveLeft && !moveRight) {
        state = Idle;
    }
}*/
void Player::movePlayer()
{
    if (!scene()) return;

    qreal playerWidth = pixmap().width();
    qreal sceneWidth = scene()->width();
    qreal leftMargin = 200;  // Space before player starts moving left
    qreal rightMargin =  200; // Space before player starts moving right

    if (moveLeft && x() > leftMargin) {
        setX(x() - 5);
    } else if (moveLeft) {
        emit requestScroll(-5);  // Tell the scene to scroll background
    }

    if (moveRight && x() + playerWidth < rightMargin) {
        setX(x() + 5);
    } else if (moveRight) {
        emit requestScroll(5);  // Tell the scene to scroll background
    }

    if (!moveLeft && !moveRight) {
        state = Idle;
    }
}


void Player::jumpUp()
{
    if (currentJump < jumpHeight) {
        setY(y() - 7);  // Move up
        currentJump += 7;
        checkGemCollision();
    } else {
        jumpTimer->stop();
        disconnect(jumpTimer, &QTimer::timeout, this, &Player::jumpUp);
        connect(jumpTimer, &QTimer::timeout, this, &Player::fallDown);
        jumpTimer->start(10); // Start falling
    }
}

void Player::fallDown()
{
    if (currentJump > 0) {

        setY(y() + 7);
        currentJump -= 7;
        checkGemCollision();
    } else {
        jumpTimer->stop();
        disconnect(jumpTimer, &QTimer::timeout, this, &Player::fallDown);
        connect(jumpTimer, &QTimer::timeout, this, &Player::jumpUp);
        jumping = false;
        if (moveLeft || moveRight) {
            state = Running;
        } else {
            state = Idle;
        }
    }
}


double Player::getX() const { return positionX; }
double Player::getY() const { return positionY; }


void Player::setMoveLeft(bool move) {
    moveLeft = move;
    if (move) state = Running;
}

void Player::setMoveRight(bool move) {
    moveRight = move;
    if (move) state = Running;
}



void Player::loadFrames(){
    QSize targetSize(400, 600);
    if (role==guy){
        runningFrames ={
            QPixmap(":/abdoRunningFrames/arun1.png"),
            QPixmap(":/abdoRunningFrames/arun2.png"),
            QPixmap(":/abdoRunningFrames/arun3.png"),
            QPixmap(":/abdoRunningFrames/arun4.png"),
            QPixmap(":/abdoRunningFrames/arun5.png"),
            QPixmap(":/abdoRunningFrames/arun6.png"),
            QPixmap(":/abdoRunningFrames/arun7.png"),
            QPixmap(":/abdoRunningFrames/arun8.png"),
            QPixmap(":/abdoRunningFrames/arun9.png")
        };
        jumpFrames = {
            QPixmap(":/abdoJumpingFrames/ajump1.png"),
            QPixmap(":/abdoJumpingFrames/ajump2.png"),
            QPixmap(":/abdoJumpingFrames/ajump3.png"),
            QPixmap(":/abdoJumpingFrames/ajump4.png"),
            QPixmap(":/abdoJumpingFrames/ajump5.png"),
            QPixmap(":/abdoJumpingFrames/ajump6.png"),
            QPixmap(":/abdoJumpingFrames/ajump7.png")

        };
        idleFrames = {
            QPixmap(":/abdoIdle/trialIdle1.png")
    };
} else if(role==HijabiGirl){
    runningFrames ={
        QPixmap(":/GannaRunFrames/IMG_3265-removebg-preview.png"),
        QPixmap(":/GannaRunFrames/IMG_3266-removebg-preview.png"),
        QPixmap(":/GannaRunFrames/IMG_3267-removebg-preview.png"),
        QPixmap(":/GannaRunFrames/IMG_3268-removebg-preview.png")
    };
    jumpFrames = {
        QPixmap(":/GannaJump/1GJump.png"),
        QPixmap(":/GannaJump/2GJump.png"),
        QPixmap(":/GannaJump/3GJump.png"),
        QPixmap(":/GannaJump/4GJump.png"),
        QPixmap(":/GannaJump/5GJump.png"),
        QPixmap(":/GannaJump/6GJump.png")
    };
    qDebug() << "Loading pixmap from: " << ":/GannaIdle/1GIdle.png";
    idleFrames = {
        QPixmap(":/GannIdle/2GIdle.png")
};
}
for (auto& frame : idleFrames)
    frame = frame.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

for (auto& frame : runningFrames)
    frame = frame.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

for (auto& frame : jumpFrames)
    frame = frame.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}


void Player::advanceFrame() {
    QVector<QPixmap>* currentFrames = nullptr;

    switch (state) {
    case Idle:
        currentFrames = &idleFrames;
        break;
    case Running:
        currentFrames = &runningFrames;
        break;
    case Jumping:
        currentFrames = &jumpFrames;
        break;
    }

    if (currentFrames && !currentFrames->isEmpty()) {
        currentFrameIndex = (currentFrameIndex + 1);
        if (currentFrameIndex >= currentFrames->size())
        {
            if (state == Jumping) {
                // jumpFrames animation ends, but we're still mid-air
                currentFrameIndex = currentFrames->size() - 1; // hold last frame
            } else {
                currentFrameIndex = 0;
            }
        }

        setPixmap(currentFrames->at(currentFrameIndex));
    }
}
void Player::checkCollisions() {
    QList<QGraphicsItem*> colliding = this->collidingItems(); // inside Player::keyPressEvent
    for (QGraphicsItem* item : colliding) {
        KillableObstacle* obstacle = dynamic_cast<KillableObstacle*>(item);
        if (obstacle) {
            obstacle->onCollision(*this);
        }
    }
}
void Player::checkGemCollision()
{
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    for (QGraphicsItem* item : collidingItemsList) {
        Gem* gem = dynamic_cast<Gem*>(item);
        if (gem) {
            // Remove the gem from the scene and delete it
            scene()->removeItem(gem);
            delete gem;

            // Increment the score
            Scene* scene = static_cast<Scene*>(this->scene());  // Get the scene from the player
            scene->incrementScore();  // Increment score using a function in Scene class
        }
    }
}
//*********************************
void Player::decreaseHealth() {
    health -= 10;  // Decrease health by 10 (or adjust based on the obstacle hit)
    if (health <= 0) {
        loseLife();
    }
}

void Player::loseLife() {
    lives--;
    health = 100;  // Reset health when losing a life
    if (lives <= 0) {
        // Game over logic (show game over screen or stop the game)
        qDebug() << "Game Over!";
        // You can add a method to end the game, like calling gameWindow->gameOver();
    }
}


