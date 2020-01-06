#include "snake.h"
#include <iostream>
#include <QRect>


Snake::Snake(int x, int y, int growToSize): numQueuedSegments(growToSize)
{
    image.load(":/images/snake.png");

    QRect head;
    head = image.rect();
    head.moveTo(x, y);
    putSegmentAt(image, head, x, y);
}

void Snake::putSegmentAt(QImage image, QRect rect, int x, int y)
{
    segments.push_front(Segment(image, rect, x, y));
    if (numQueuedSegments > 0)
        --numQueuedSegments;
    else
        segments.pop_back();
}

void Snake::growBy(unsigned int numSegments)
{
    numQueuedSegments += numSegments;
}

Snake::~Snake()
{
    std::cout << ("Snake deleted\n");
}

void Snake::move()
{
    QRect rect;
    rect = image.rect();
    int x = head().x;
    int y = head().y;
    switch (dir)
    {
        case Snake::DOWN:
            y += 7;
        break;
        case Snake::UP:
            y -= 7;
        break;
        case Snake::LEFT:
            x -= 7;
        break;
        case Snake::RIGHT:
            x += 7;
        break;
    }
    rect.moveTo(x, y);
    putSegmentAt(image, rect, x, y);
}



