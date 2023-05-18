#include "stick.h"
#include <QPainter>

stick::stick(){
   height = 0;
   width = 0;
   setSpeed(0);
   setPosition({0,0});
}

void stick::setStick(double height_, double width_){
   height = height_;
   width = width_;
}
double stick::getHeight() const{
   return height;
}
double stick::getWidth() const{
   return width;
}
void stick::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
   painter->setPen({Qt::red, 1});
   painter->drawRect(boundingRect());
}

QRectF stick::boundingRect() const {
   return QRectF(-width/2, -height/2, width, height);
}
