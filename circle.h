#pragma once
#include "bullet.h"

class circle: public bullet{
   QRectF circleRect;
public:
   circle();
   void setRect(QRectF rect);
   void setRect(QPointF left, QPointF rigth);
   QRectF getRect() const;
   void move();
   void move(int speed ,const QPointF& direction);
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
   QRectF boundingRect() const override;
};

