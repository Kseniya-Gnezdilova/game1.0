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
   void uploadAttack();
   void attack1();
   void attack2();
   void attack3();
   void attack4();
   Model *model;
};
