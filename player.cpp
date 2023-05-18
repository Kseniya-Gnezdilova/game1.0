#pragma once
#include "gameobject.h"
#include <vector>
#include <QWidget>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPoint>
#include <QGraphicsView>

class player : public GameObject {
protected:
   int playerHealth;
   int playerDamage = 1;
   int playerSpeed;
   std::vector<int> inventory;
   QPointF playerDirection;
 public:
   void setHealth(const int health);
   int getHealth() const;
   void setDirection(const QPointF& direction);
   const QPointF& getDirection() const;
   void move(const QPointF& direction);
   player();
   const int& getSpeed() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
   QRectF boundingRect() const override;
};


