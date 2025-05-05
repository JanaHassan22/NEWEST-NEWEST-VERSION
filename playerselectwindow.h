#ifndef PLAYERSELECTWINDOW_H
#define PLAYERSELECTWINDOW_H

#include <QWidget>

namespace Ui {
class PlayerSelectWindow;
}

class PlayerSelectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerSelectWindow(QWidget *parent = nullptr);
    ~PlayerSelectWindow();


private slots:
    void selectPlayer1();
    void selectPlayer2();


private:
    Ui::PlayerSelectWindow *ui;
};

#endif // PLAYERSELECTWINDOW_H


