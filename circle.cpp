#include "circle.h"
#include <QPainter>

circle::circle(){
   QPointF left = {256,256};
   QPointF rigth = {256 + 25, 256 + 25};
   circleRect = QRectF(left, rigth);
   setSpeed(3);
   setDirection({1024,1024});
}
void circle::setRect(QRectF rect){
   circleRect = rect;
}
void circle::setRect(QPointF left, QPointF rigth){
   circleRect = QRectF(left, rigth);
}
QRectF circle::getRect() const{
   return circleRect;
}
void circle::move(){
   move(getSpeed(),getDirection());
}
void circle::move(int speed, const QPointF& direction){
   double length = sqrt(pow(direction.x(),2) + pow(direction.y(),2));
   if (length == 0)
      return;
   setPosition({pos_.x() + speed * direction.x() / length, pos_.y() + speed * direction.y() / length});
}

void circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
   painter->setPen({Qt::red, 1});
   painter->drawEllipse(boundingRect());
}

QRectF circle::boundingRect() const {
   return QRectF(getRect());
}
