#include "bullet.h"

bullet::bullet(){
   bulletSpeed = 8;
   bulletDamage = 1;
}

void bullet::setSpeed(int speed){
   bulletSpeed = speed;
}
int bullet::getSpeed() const{
   return bulletSpeed;
}
void bullet::setDirection(const QPointF& direction_){
   direction = direction_;
}
QPointF bullet::getDirection() const{
   return direction;
}
int bullet::getDamage() const{
   return bulletDamage;
}
