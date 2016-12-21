#ifndef LINE_H
#define LINE_H
#include<graph.h>
class Line:public Graph{
public:
    Line();
    ~Line();
    void paint(QPainter *painter);
};

#endif // LINE_H
