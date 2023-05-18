#pragma once;
#include "player.h"
#include <vector>
#include "bullet.h"

class Model {
public:
   Model();
   player *player_;
   std::vector<bullet*> bullets;
   void vecPushBack(bullet* bullet_);
   void vecDelete();
   void updateModel();
   bool intersection(QRectF first, QRectF second);
   int numAttack;
   void setNum(const int num);
   int getNum() const;
};


