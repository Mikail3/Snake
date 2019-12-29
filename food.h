#ifndef FOOD_H
#define FOOD_H

#include <QImage>
#include <QRect>

class Food
{

  public: ///protected;
    Food(int, int); ///specific?
    ~Food();

    virtual int eaten(int oldScore) = 0;

  public:
    void resetState();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect(); ///getting the X and Y axis definitions and using
    void setRect(QRect);
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
    unsigned char points;
    bool destroyed;

};

#endif
