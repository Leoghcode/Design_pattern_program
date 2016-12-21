#include<undomanager.h>
#include<myundoableedit.h>
UndoManager::UndoManager()
{
    OpePos=0;
}

UndoManager::~UndoManager()
{

}

void UndoManager::undoableEditHappened(MyUndoableEdit* mue)
{
    this->editList.push_back(mue);
    OpePos++;
}

void UndoManager::clearUndoEdit()
{
    this->editList.erase(editList.begin()+OpePos,editList.end());
}
