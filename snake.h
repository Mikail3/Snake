#ifndef SNAKE_H
#define SNAKE_H

#include <QImage>
#include <QRect>
#include <stdio.h>
#include <stdlib.h>
#include <list>

class Snake
{

  public:
    Snake(int,int,int);
    ~Snake(); /* 12 : Deconstructor */

  public:
    enum Direction { UP, DOWN, LEFT, RIGHT }; /* 50 : Enum */
    struct Segment /* 48 : Sruct */
    {
        Segment(QImage image, QRect rect, int x, int y)
                    : image(image)
                    , rect(rect)
                    , x(x)
                    , y(y)
                    { }

        QImage image;
        QRect rect;
        int x, y;
    };


    Direction dir;
    typedef std::list<Segment> SegmentList; /* 32 : Container Class */
    QImage image;
    SegmentList segments;

    void move();
    void putSegmentAt(QImage image, QRect rect, int x, int y);
    void growBy(unsigned int numSegments);



    const Segment & head() const /* 25 : Const Ref 4x */
    {
        return segments.front();
    }
    const Segment & tail() const
    {
        return segments.back();
    }

    typedef SegmentList::const_iterator SegmentIterator; /* 55 : Testing */
    SegmentIterator begin() const
    {
        return segments.begin();
    }

    SegmentIterator end() const
    {
        return segments.end();
    }

  private:
    unsigned int numQueuedSegments;

};

#endif
