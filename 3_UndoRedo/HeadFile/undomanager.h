#ifndef UNDOMANAGER_H
#define UNDOMANAGER_H
//#include<absundoableedit.h>
#include<comundoableedit.h>
class MyUndoableEdit;
class UndoManager: public ComUndoableEdit{
public:
    UndoManager();
    ~UndoManager();
    void undoableEditHappened(MyUndoableEdit* mue);
    void clearUndoEdit();
    int getLength(){
        return editList.size();
    }
};

#endif // UNDOMANAGER_H
