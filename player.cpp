#include "player.h"
#include <QPainter>
player::player(){
   playerHealth = 1000;
   playerSpeed = 5;
   //setHitBox({0,0},{30,30});
   setPosition({0,0});
   setDirection({0, 0});
}
void player::setHealth(const int health){
   playerHealth = health;
}
int player::getHealth() const{
   return playerHealth;
}
void player::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
   painter->setPen({Qt::black, 2});
   painter->drawRect(boundingRect());
}

QRectF player::boundingRect() const {
   return QRectF(-10, -10, 20, 20);
}

const int& player::getSpeed() const{
   return playerSpeed;
}

void player::setDirection(const QPointF& direction){
   playerDirection = direction;
}
const QPointF& player:: getDirection() const{
   return playerDirection;
}
void player::move(const QPointF& direction){
   double length = sqrt(pow(direction.x(),2) + pow(direction.y(),2));
   if (length == 0)
      return;
   setPosition({std::max(std::min(pos_.x() + playerSpeed * direction.x() / length, 690.),110.), std::max(std::min(pos_.y() + playerSpeed * direction.y() / length, 690.),110.)});
}
