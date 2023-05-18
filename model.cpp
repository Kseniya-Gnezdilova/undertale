#include "model.h"
#include "mainwindow.h"
#include <QLabel>

Model::Model() : player_(new player()){
}
void Model::vecPushBack(bullet* bullet_){
   bullets.push_back(bullet_);
}

 void Model::updateModel() {
   player_ -> move(player_->getDirection());
   for (auto* bullet_: bullets){
      QPointF first = player_->getPosition();
      QPointF second = bullet_->getPosition();
      auto dst = sqrt(pow(first.x() - second.x(),2) + pow(first.y() - second.y(),2));
      if (dst <= 1){
         int dmg = bullet_->getDamage();
         player_->setHealth(player_->getHealth() - dmg);
      }
   }

}
