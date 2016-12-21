#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include<QtWidgets>
#include<QDebug>
#include<graph.h>
#include<line.h>
#include<rect.h>
#include<QList>

class Graph;
class MyUndoableEdit;
class PaintWidget: public QWidget{
    Q_OBJECT
public:
    PaintWidget(QWidget *parent=0);
    ~PaintWidget();
    void RemoveGraph();
    void AddGraph(Graph* _g);
    int getId(){
        return curId;
    }

signals:
    void releaseAndPaint(MyUndoableEdit* mue,int _size);
public slots:
    void setCurrentGraph(Graph::Type t);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    Graph::Type curGraph;
    QList<Graph*> graphList;
    bool released;
    Graph* graph;
    int curId;
};

#endif // PAINTWIDGET_H
