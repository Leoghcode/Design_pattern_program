#include<paintwidget.h>
#include<undomanager.h>
#include<myundoableedit.h>
#include<iostream>
using namespace std;
/*PaintWidget::PaintWidget(QWidget *parent)
        : QWidget(parent), curGraph(Graph::Line), graph(NULL), released(false)
{
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
*/
PaintWidget::PaintWidget(QWidget *parent)
        : QWidget(parent),curGraph(Graph::Line),graph(NULL),released(false)
{
        curId=-1;
        setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

PaintWidget::~PaintWidget()
{

}

void PaintWidget::setCurrentGraph(Graph::Type t){
    if(curGraph!=t)
    {
        curGraph=t;
    }
}

void PaintWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
            painter.setBrush(Qt::white);
            painter.drawRect(0, 0, size().width(), size().height());
            foreach(Graph * graph, graphList) {
                    graph->paint(&painter);
            }
            if(graph) {
                    graph->paint(&painter);
            }
}


void PaintWidget::mousePressEvent(QMouseEvent *event)
{
        switch(curGraph)
        {
        case Graph::Line:
                {
                        graph = new Line;

                        break;
                }
        case Graph::Rectangle:
                {
                        graph = new Rect;

                        break;
                }
        }
        if(graph != NULL) {
                released = false;
                graphList<<graph;
                graph->setId(++curId);
                graph->setStart(event->pos());
                graph->setEnd(event->pos());
        }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
        if(graph && !released) {
                graph->setEnd(event->pos());
                update();
        }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
        released = true;
        MyUndoableEdit* mue=new MyUndoableEdit(graph,this);
        emit releaseAndPaint(mue,curId);
}

void PaintWidget::RemoveGraph()
{
    if(!graphList.isEmpty())
   {
        this->graphList.pop_back();
        curId--;
        graph=NULL;
        update();
    }
}

void PaintWidget::AddGraph(Graph* _g)
{
    Graph* g;
    if(_g->getType()==Graph::Line)
        g=new Line;
    else if(_g->getType()==Graph::Rectangle)
        g=new Rect;
    else
        return;
    g->setStart(_g->getStart());
    g->setEnd(_g->getEnd());
    g->setType(_g->getType());
    g->setId(_g->getId());
    graphList.append(g);
    g->setId(curId++);
    cout<<"painter::add"<<endl;
    update();

}
