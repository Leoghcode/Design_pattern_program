#ifndef ABSUNDOABLEEDIT_H
#define ABSUNDOABLEEDIT_H
class AbsUndoableEdit{
public:
    AbsUndoableEdit(){
        hasBeenDone=true;
        alive=true;
    }
    ~AbsUndoableEdit(){

    }

    void virtual undo(){}
    void virtual redo(){}
    bool canUndo(){
        return hasBeenDone;
    }

    bool canRedo(){
        return !hasBeenDone;
    }

private:

    bool hasBeenDone;
    bool alive;
};

#endif // ABSUNDOABLEEDIT_H
