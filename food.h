#ifndef FOOD_H
#define FOOD_H

#include <QImage> /* 33 : QT*/
#include <QRect>

class Food /* 5 : Base class */
{

    public:
    Food(int, int); /* 10 : Specific Constructor */
    ~Food(); /* 12 : Deconstructor */

  virtual int eaten(int oldScore) = 0; /* 7 : Virtual Function */ /// This makes is abstract Modifier that defines polymorphic behavior , using this to override in other classses.

  public:
    void resetState();
    bool isDestroyed();
    void setDestroyed(bool); /* 14 : Member Function */
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

  protected: /* 18 : Protection */
    QImage image; /* 16 : Member Variabel */
    QRect rect;

  private:
    unsigned char points; /* 24 : Unsigned Char */
    bool destroyed;


};

#endif
