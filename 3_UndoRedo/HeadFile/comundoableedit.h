#ifndef COMUNDOABLEEDIT_H
#define COMUNDOABLEEDIT_H
#include<vector>
#include<absundoableedit.h>
using namespace std;

class ComUndoableEdit : public AbsUndoableEdit{
public:
    ComUndoableEdit();
    ~ComUndoableEdit();
    void undo();
    void redo();
protected:
    vector<AbsUndoableEdit *> editList;
    int OpePos;
};

#endif // COMUNDOABLEEDIT_H
