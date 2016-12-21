#include<myundoableedit.h>
#include<mainwindow.h>
#include<absundoableedit.h>
#include<graph.h>
#include<paintwidget.h>
#include<iostream>
using namespace std;
MyUndoableEdit::MyUndoableEdit(Graph *_g,PaintWidget* _pw)
{
    Graph* newg=new Graph();
    newg->setStart(_g->getStart());
    newg->setEnd(_g->getEnd());
    newg->setType(_g->getType());
    newg->setId(_g->getId());
    g=newg;

    pw=_pw;
    cout<<pw->getId()<<endl;
   // cout<<"muundoableedit:    "<<g->getId()<<" "<<g->getType();
}

MyUndoableEdit::~MyUndoableEdit()
{

}

void MyUndoableEdit::undo()
{
    oldg=g;
    g=NULL;

    pw->RemoveGraph();

    cout<<"My undo"<<pw->getId()<<"  "<<oldg->getId()<<endl;

}

void MyUndoableEdit::redo()
{

    pw->AddGraph(oldg);
    g=oldg;
    oldg=NULL;

    cout<<"OK"<<endl;
   // cout<<"My Redo"<<pw->getId()<<"  "<<oldg->getId()<<endl;
}
