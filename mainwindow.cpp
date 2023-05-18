#include "mainwindow.h"
#include <QKeyEvent>
#include <QMap>
#include <QTimer>
#include "stick.h"
#include "circle.h"

MainWindow::MainWindow(): QGraphicsScene() {
   model = new Model();
   addItem(model->player_);
   stick* stick_ = new stick();
   addItem(stick_);
   circle* circle_ = new circle();
   addItem(circle_);
   model ->vecPushBack(stick_);
   auto* timer = new QTimer(this);
       connect(timer, &QTimer::timeout, [this,circle_]() {
          model->updateModel();
          circle_->move();
          if (model->player_->getHealth() == 0) { views().front() -> close(); }
       });
       timer->start(16);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
   QGraphicsScene::keyPressEvent(event);
   auto [x,y] = model->player_ -> getDirection();
   if (event->key() == Qt::Key_W) {
         model->player_ -> setDirection({x,-1});
       } else if (event->key() == Qt::Key_A) {
         model->player_ -> setDirection({-1,y});
       } else if (event->key() == Qt::Key_S) {
         model->player_ -> setDirection({x,1});
       } else if (event->key() == Qt::Key_D) {
         model->player_ -> setDirection({1,y});
       }


}
void MainWindow::keyReleaseEvent(QKeyEvent* event){
      QGraphicsScene::keyReleaseEvent(event);
       auto key = event->key();
       auto [x, y] = model->player_->getDirection();
       if ((key == Qt::Key_W && y == -1) || (key == Qt::Key_S && y == 1))
           y = 0;
       else if ((key == Qt::Key_D && x == 1) || (key == Qt::Key_A && x == -1))
           x = 0;
       else
           return;
      model->player_->setDirection({x, y});
}


