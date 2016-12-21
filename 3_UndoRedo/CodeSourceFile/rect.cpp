#include<rect.h>
using namespace std;
Rect::Rect(){
    _t=Graph::Rectangle;
}

Rect::~Rect(){

}

void Rect::paint(QPainter *painter){
    painter->drawRect(getStart().x(),getStart().y(),getEnd().x()-getStart().x(),getEnd().y()-getStart().y());
}
