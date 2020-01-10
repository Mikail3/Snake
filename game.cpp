#include "game.h"
#include "food.h"
#include "strawberry.h"
#include "apple.h"
#include "banana.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include <QPainter> ///The QPainter class performs low-level painting on widgets and other paint devices
#include <QApplication> ///The QApplication class manages the GUI application's control flow and main settings
#include <QThread> ///The QThread class provides a platform-independent way to manage threads

Game::Game(QWidget *parent) : QWidget(parent)
{
    x = 0;
    score = 0;
    highscore = 0;
    gameOver = false;
    paused = false;
    gameStarted = false;
    food = new Apple(2*40+27, 2*10+47);
    food = new Strawberry(2*40+27, 2*10+47);
    food = new Banana(2*40+27, 2*10+47); /* 28 : Dynamic memory allocation */
    snake = new Snake(250, 350, 5); ///230 , 355 , 5
}

extern Game::~Game()
{
    delete food; /* 29 : Dynamic memory removing */
    delete snake;
}

void Game::paintEvent(QPaintEvent *event) /* 56 : GUI */
{
    QPainter painter(this);

    if (gameOver)
    {
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Game Over");
        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Game Over");

        if (newhigh == true)
        {
            int textWidth2 = fm.width("New High Score: ");
            int textWidth3 = fm.width(QString::number(highscore));

            painter.drawText(-textWidth2/2, 20, "New High Score: ");
            painter.drawText(-textWidth3/2, 40, QString::number(highscore));
        }
        else
        {
            int textWidth2 = fm.width("Last Score: ");
            int textWidth3 = fm.width(QString::number(score));

            painter.drawText(-textWidth2/2, 20, "Last Score: ");
            painter.drawText(-textWidth3/2, 40, QString::number(score));

            int textWidth4 = fm.width("High Score: ");
            int textWidth5 = fm.width(QString::number(highscore));

            painter.drawText(-textWidth4/2, 60, "High Score: ");
            painter.drawText(-textWidth5/2, 80, QString::number(highscore));
        }
    }
    else
    {
        QFont font("Courier", 10, QFont::DemiBold);
        int w = width();
        
        painter.setFont(font);
        painter.drawText(QPoint(w/2-35, 10), "Score: " + QString::number(score));
        painter.drawImage(food->getRect(), food->getImage());
        
        Snake::SegmentIterator iter;
        for (iter = snake->segments.begin(); iter != snake->segments.end(); ++iter)
        {
            painter.drawImage(iter->rect , iter->image);
        }
    }
}

void Game::timerEvent(QTimerEvent *event)
{
    snake->move();
    checkCollision();
    QThread::msleep(40);
    repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:///Key_Q:
         snake->dir = Snake::LEFT;
       break;
    case Qt::Key_Right: ///Key_D:
          snake->dir = Snake::RIGHT;
        break;
    case Qt::Key_Up: ///Key_Z:
          snake->dir = Snake::UP;
        break;
    case Qt::Key_Down: ///Key_S:
          snake->dir = Snake::DOWN;
        break;
    case Qt::Key_P:
          pauseGame();
        break;
    case Qt::Key_Space:
          startGame();
        break;
    case Qt::Key_Escape:
          qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
    repaint();
}


void Game::startGame()
{
    if (!gameStarted) {
        snake = new Snake(230, 355, 5);
        gameOver = false;
        score = 0;
        newhigh = false;
        gameStarted = true;
        timerId = startTimer(5);
    }
}

void Game::pauseGame()
{
    if (paused)
    {
        timerId = startTimer(5);
        paused = false;
    } else
    {
        paused = true;
        killTimer(timerId);
    }
}

void Game::stopGame()
{
    delete snake;
    killTimer(timerId);
    gameOver = true;
    if (score > highscore)
    {
        highscore = score;
        newhigh = true;
    }
    gameStarted = false;
}

void Game::checkCollision()
{

    if (snake->head().rect.bottom() >= 500 || /* 55 : Testing */
       snake->head().rect.top() <= 0 ||
       snake->head().rect.left() <= 0 ||
       snake->head().rect.right() >= 300)
       stopGame();

    if ((snake->head().rect).intersects(food->getRect()))
    {
        food->setDestroyed(true);
        score += food->eaten(score); /* 8 : Polymorphism */
        delete food;


        switch (rand()%3)

        {


        case 0:
            food = new Apple((1+(rand()%6))*40+27, (1+(rand()%30))*10+47);
            break;

        case 1:
            food = new Strawberry((1+(rand()%3))*40+27, (1+(rand()%30))*10+47);
             break;

        case 2:
            food = new Banana((1+(rand()%3))*40+27, (1+(rand()%30))*10+47);
             break;



        }
        snake->growBy(1);
    }

    Snake::SegmentIterator iter; /* 55 : Testing , this doesn't allow the snake to turn in the opposite direction */
    for (iter = ++snake->segments.begin(); iter != snake->segments.end(); ++iter)
        if (iter->x == snake->head().x && iter->y == snake->head().y)
            stopGame();
}

