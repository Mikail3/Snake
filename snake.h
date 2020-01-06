#ifndef SNAKE_H
#define SNAKE_H

#include <QImage>
#include <QRect>
#include <stdio.h>
#include <stdlib.h>
#include <list>

class Snake  ///Encapsulation with acces modifier
{

  public:
    Snake(int,int,int);
    ~Snake();

  public:
    enum Direction { UP, DOWN, LEFT, RIGHT }; ///Making the directions
    struct Segment
    {
        Segment(QImage image, QRect rect, int x, int y)
                    : image(image)
                    , rect(rect)
                    , x(x) ///member initialisatie
                    , y(y)
                    { }

        QImage image;
        QRect rect;
        int x, y;
    };


    Direction dir;
    typedef std::list<Segment> SegmentList;
    QImage image;
    SegmentList segments;

    void move();
    void putSegmentAt(QImage image, QRect rect, int x, int y);
    void growBy(unsigned int numSegments);



    const Segment & head() const
    {
        return segments.front();
    }
    const Segment & tail() const
    {
        return segments.back();
    }

    typedef SegmentList::const_iterator SegmentIterator;
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
