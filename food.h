#ifndef FOOD_H
#define FOOD_H

#include <QImage>
#include <QRect>

class Food
{

  public: ///protected;
    Food(int, int); ///specific?
    ~Food(); ///Deconstructor

  virtual int eaten(int oldScore) = 0; ///Modifier that defines polymorphic behavior.

  public:
    void resetState(); ///Member function?
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect(); ///getting the X and Y axis definitions and using.
    void setRect(QRect);
    QImage & getImage();

  private:
    QImage image; ///Member variabele?
    QRect rect;
    unsigned char points;
    bool destroyed;

};

#endif
