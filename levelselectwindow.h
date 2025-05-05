// levelselectwindow.h
#ifndef LEVELSELECTWINDOW_H
#define LEVELSELECTWINDOW_H
#include "levelselectwindow.h"
#include "ui_levelselectwindow.h"
#include "level1gamewindow.h"
#include <QWidget>

class Level1GameWindow; // ✅ Forward declaration

QT_BEGIN_NAMESPACE
namespace Ui {
class LevelSelectWindow;
}
QT_END_NAMESPACE

class LevelSelectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LevelSelectWindow(QWidget *parent = nullptr);
    ~LevelSelectWindow();

private:
    Ui::LevelSelectWindow *ui;
    Level1GameWindow* gameWindow; // ✅ Use correct class name
public slots:
    void goToLevel1();
};

#endif // LEVELSELECTWINDOW_H
