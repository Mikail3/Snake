#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>



class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent = nullptr);
    int getScore() ;
    void setScore(int value);
    bool Score();

    ///Score();
   ///~Score();

private:
    int core;
};

#endif // SCORE_H
