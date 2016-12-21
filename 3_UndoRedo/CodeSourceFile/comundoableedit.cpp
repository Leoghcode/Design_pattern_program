#include<comundoableedit.h>
#include<absundoableedit.h>
#include<myundoableedit.h>
#include<iostream>
using namespace std;
ComUndoableEdit::ComUndoableEdit()
{

}

ComUndoableEdit::~ComUndoableEdit()
{

}

void ComUndoableEdit::undo()
{
    OpePos--;
    if(OpePos>=0)
        editList.at(OpePos)->undo();
}

void ComUndoableEdit::redo()
{

    if(OpePos<editList.size())
    {
        cout<<"com redo():"<<"Ope:  "<<OpePos<<"editList  "<<editList.size()<<endl;
        editList.at(OpePos)->redo();
        OpePos++;
    }
}


