#ifndef GAME_H
#define GAME_H

#include "food.h"
#include "snake.h"
#include <QWidget>
#include <QKeyEvent>

class Game : public QWidget
{
  Q_OBJECT

  public:
    Game(QWidget *parent = nullptr);   ///member function?
    ~Game(); ///decunstroctor

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void pauseGame();
    void stopGame();
    void checkCollision();

  private:
    int x;
    int timerId;
    unsigned char score;
    unsigned char highscore;
    Food *food;
    Snake *snake;
    bool gameOver;
    bool gameStarted;
    bool paused;
    bool newhigh;

};

#endif
