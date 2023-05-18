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
   void updateModel();

};


