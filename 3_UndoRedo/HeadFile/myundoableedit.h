#ifndef MYUNDOABLEEDIT_H
#define MYUNDOABLEEDIT_H
#include<absundoableedit.h>
class PaintWidget;

class Graph;
class MyUndoableEdit: public AbsUndoableEdit{
public:
    MyUndoableEdit(Graph* _g,PaintWidget* _pw);
    ~MyUndoableEdit();
    void undo();
    void redo();
private:
    PaintWidget* pw;
    Graph* g;
    Graph* oldg;
};

#endif // MYUNDOABLEEDIT_H
