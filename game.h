#ifndef GAME_H
#define GAME_H

#include "apple.h"
#include "snake.h"
#include <QWidget>
#include <QKeyEvent>



class Game : public QWidget /* 3 : Useful encapsulation */
{
  Q_OBJECT

  public:
    Game(QWidget *parent = nullptr); /* 14 : useful member function , 44 : NULLPTR */
    ~Game(); /* 12 : Decunstructor */



  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event); /* 52 : useful usage of signals/slots , timer = function from a class this is called everywhere */
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void startGame(int);
    void pauseGame();
    void stopGame();
    void checkCollision();

  private:
    int x;
    int timerId;
    unsigned char score; /* 24 : Unsinged char */
    unsigned char highscore;
    Food *food;
    Snake *snake;
    bool gameOver; /* 26 : 4 Usefull BOOL */
    bool gameStarted;
    bool paused;
    bool newhigh;

};

#endif
