#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "model.h"

class MainWindow : public QGraphicsScene {
public:
   explicit MainWindow();
protected:
   void keyPressEvent(QKeyEvent *event) override;
   void keyReleaseEvent(QKeyEvent *event) override;
   Model *model;
};
