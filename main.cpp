#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
     MainWindow scene;
     QGraphicsView view(&scene);
     scene.setSceneRect(0,0,1024,1024);
     view.show();
     a.exec();
     return QApplication::exec();
}
