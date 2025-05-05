#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <QWidget>

namespace Ui {
class PlayScreen;
}

class PlayScreen : public QWidget
{
    Q_OBJECT

public:
    explicit PlayScreen(QWidget *parent = nullptr);
    ~PlayScreen();

private slots:
    void onPlayClicked();
private:
    Ui::PlayScreen *ui;
};

#endif // PLAYSCREEN_H


