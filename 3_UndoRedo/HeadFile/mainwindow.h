#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QAction>
#include<QMainWindow>
#include<QToolBar>
#include<QMenu>
#include<QMenuBar>
#include<QStatusBar>
#include<QLabel>
#include<paintwidget.h>

class Graph;
class UndoManager;
class MyUndoableEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addUndoListener(UndoManager* undomng);

signals:
    void changeCurrentGraph(Graph::Type t);
public slots:
    void drawLineTrigged();
    void drawRectTrigged();
    void undoTrigged();
    void redoTrigged();
    void undoableEditHappened(MyUndoableEdit* mue,int _size);
private:
    UndoManager* undomanager;
    PaintWidget* paintW;
};

#endif // MAINWINDOW_H
