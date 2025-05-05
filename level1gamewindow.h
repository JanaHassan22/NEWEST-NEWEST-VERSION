#ifndef LEVEL1GAMEWINDOW_H
#define LEVEL1GAMEWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "player.h"
#include <QProgressBar>
namespace Ui {
class Level1GameWindow;
}

class Level1GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level1GameWindow(QWidget *parent = nullptr);
    ~Level1GameWindow();
    void updateGame();
    void decreaseHealth();
    void spawnObstacles();
protected: //this is where we tell the compiler about showEvent
    void showEvent(QShowEvent *event) override;

private:
    Ui::Level1GameWindow *ui;
    QGraphicsView* graphicsView;
     QGraphicsScene* scene;
    Player* player;
    QGraphicsPixmapItem* backgroundItem;
    QPixmap backgroundPixmap;
    QTimer* scrollTimer;
    int backgroundOffset = 0;
    void scrollBackground();
    QProgressBar *healthBar;
    int health;
};

#endif
