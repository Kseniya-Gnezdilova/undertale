#include "player.h"
#include <QPainter>
player::player(){
   playerHealth = 100;
   playerSpeed = 5;
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
   return QRectF(0, 0, 30, 30);
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
   setPosition({pos_.x() + playerSpeed * direction.x() / length, pos_.y() + playerSpeed * direction.y() / length});
}
