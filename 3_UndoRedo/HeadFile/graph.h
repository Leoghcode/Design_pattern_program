#ifndef GRAPH_H
#define GRAPH_H
#include<QPainter>
#include<QPoint>
class Graph{
public:
    enum Type{Point,Line,Rectangle};
    Graph(){}
    ~Graph(){}
    void virtual paint(QPainter* painter){}
    void setStart(QPoint qpoint){
         startP=qpoint;
    }
    void setEnd(QPoint qpoint){
        endP=qpoint;
    }
    QPoint getStart(){
        return startP;
    }
    QPoint getEnd(){
        return endP;
    }
    void setId(int _id){
        id=_id;
    }
    int getId(){
        return id;
    }
    Graph::Type getType(){
        return _t;
    }

    void setType(Graph::Type t){
        _t=t;
    }

protected:
    QPoint startP;
    QPoint endP;
    Graph::Type _t;
    int id;
};

#endif // GRAPH_H
