#include "circle.h"
#include <QPainter>

circle::circle(){
    radius = 0;
    setSpeed(0);
    setPosition({0,0});
}

void circle::setRadius(double radius_){
   radius = radius_;
}
double circle::getRadius() const{
   return radius;
}
void circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
   painter->setPen({Qt::red, 1});
   painter->drawEllipse(boundingRect());
}

QRectF circle::boundingRect() const {
   return QRectF(-radius, -radius, radius*2, radius*2);
}
