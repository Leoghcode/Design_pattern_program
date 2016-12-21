#include "mainwindow.h"
#include<graph.h>
#include<undomanager.h>
#include<myundoableedit.h>
#include<iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    QToolBar* toolbar=addToolBar(tr("tools"));
    QActionGroup* actionGroup=new QActionGroup(toolbar);

    QAction* action_DrawLine=new QAction(tr("drawLine"),this);
    //action_DrawLine->setIcon(":/");
    action_DrawLine->setToolTip("draw a line");
    action_DrawLine->setStatusTip("Draw a line.");
    actionGroup->addAction(action_DrawLine);
    toolbar->addAction(action_DrawLine);

    QAction* action_DrawRect=new QAction(tr("drawRectangle"),this);
    //action_DrawLine->setIcon(":/");
    action_DrawRect->setToolTip("draw a rectangle");
    action_DrawRect->setStatusTip("Draw a rectangle.");
    actionGroup->addAction(action_DrawRect);
    toolbar->addAction(action_DrawRect);

    QAction* action_Undo=new QAction(tr("undo"),this);
    //action_DrawLine->setIcon(":/");
    action_Undo->setToolTip("Undo");
    action_Undo->setStatusTip("Undo the operation.");
    actionGroup->addAction(action_Undo);
    toolbar->addAction(action_Undo);

    QAction* action_Redo=new QAction(tr("redo"),this);
    //action_DrawLine->setIcon(":/");
    action_Redo->setToolTip("Redo");
    action_Redo->setStatusTip("Redo the operation.");
    actionGroup->addAction(action_Redo);
    toolbar->addAction(action_Redo);


    statusBar()->addWidget(new QLabel("status ozone."));

    paintW=new PaintWidget(this);
    setCentralWidget(paintW);

    connect(action_DrawLine,SIGNAL(triggered(bool)),this,SLOT(drawLineTrigged()));
    connect(action_DrawRect,SIGNAL(triggered(bool)),this,SLOT(drawRectTrigged()));
    connect(this,SIGNAL(changeCurrentGraph(Graph::Type)),paintW,SLOT(setCurrentGraph(Graph::Type)));
    connect(action_Undo,SIGNAL(triggered(bool)),this,SLOT(undoTrigged()));
    connect(action_Redo,SIGNAL(triggered(bool)),this,SLOT(redoTrigged()));
    connect(paintW,SIGNAL(releaseAndPaint(MyUndoableEdit*,int)),this,SLOT(undoableEditHappened(MyUndoableEdit*,int)));
    // this->setFixedHeight(sizeHint().height());
    //this->setFixedSize(sizeHint());


}

MainWindow::~MainWindow()
{

}

void MainWindow::drawLineTrigged()
{
    emit changeCurrentGraph(Graph::Line);
}

void MainWindow::drawRectTrigged()
{
    emit changeCurrentGraph(Graph::Rectangle);
}

void MainWindow::addUndoListener(UndoManager* undomng)
{
    this->undomanager=undomng;
}
void MainWindow::undoTrigged()
{
    this->undomanager->undo();
    cout<<"mainwindow:undo"<<endl;
    this->setWindowTitle("UndoTrigged");
}

void MainWindow::redoTrigged()
{
    cout<<"mainwindow:redo"<<endl;
    this->undomanager->redo();

    this->setWindowTitle("RedoTrigged");
}

void MainWindow::undoableEditHappened(MyUndoableEdit* mue,int _size)
{
    int undoSize=this->undomanager->getLength();
     cout<<"clear? mainwindow"<<"curId"<<" "<<_size<<" "<<"undoSize: "<<undoSize<<endl;
    if(_size!=undoSize)
    {
        this->undomanager->clearUndoEdit();
         cout<<"22clear? mainwindow "<<"curId"<<" "<<_size<<" "<<"undoSize: "<<this->undomanager->getLength()<<endl;
    }
    this->undomanager->undoableEditHappened(mue);
}
