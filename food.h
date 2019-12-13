#ifndef FOOD_H
#define FOOD_H

#include <QImage>
#include <QRect>

class Food
{

  public:
    Food(int, int);
    ~Food();

  public:
    void resetState();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
    unsigned char points;
    bool destroyed;

};

#endif
