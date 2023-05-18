#include "stick.h"
#include <QPainter>

stick::stick(){
   QPointF left = {512,512};
   QPointF rigth = {612, 550};
   stickRect = QRectF(left, rigth);
   setSpeed(4);
   setDirection({1024,1024});
}
void stick::setRect(QRectF rect){
   stickRect = rect;
}
void stick::setRect(QPointF left, QPointF rigth){
   stickRect = QRectF(left, rigth);
}
QRectF stick::getRect() const{
   return stickRect;
}
void stick::move(){
   move(getSpeed(),getDirection());
}
void stick::move(int speed, const QPointF& direction){
   double length = sqrt(pow(direction.x(),2) + pow(direction.y(),2));
   if (length == 0)
      return;
   setPosition({pos_.x() + speed * direction.x() / length, pos_.y() + speed * direction.y() / length});
}

void stick::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
   painter->setPen({Qt::red, 1});
   painter->drawRect(boundingRect());
}

QRectF stick::boundingRect() const {
   return QRectF(getRect());
}
