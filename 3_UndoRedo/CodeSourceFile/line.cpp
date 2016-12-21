#include<line.h>
Line::Line(){
    _t=Graph::Line;
}
Line::~Line(){

}

void Line::paint(QPainter *painter){
    painter->drawLine(getStart(),getEnd());
}
