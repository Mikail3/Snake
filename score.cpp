#include "score.h"
#include <QFont> ///The QFont class specifies a query for a font used for drawing text

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score = 0;

    setPos(5,10);
    setFont( QFont("",20));
}

int Score::getScore()
{
    return score;
}

void Score::setScore(int value)
{
    score = value;
    setPlainText("Score: " + QString::number(score));
}
