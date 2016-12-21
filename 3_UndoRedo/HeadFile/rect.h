#ifndef RECT_H
#define RECT_H
#include "graph.h"

class Rect : public Graph
{
public:
        Rect();
        ~Rect();
        void paint(QPainter *painter);
};
#endif // RECT_H
