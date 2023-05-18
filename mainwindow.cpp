#include "mainwindow.h"
#include <QKeyEvent>
#include <QTimer>
#include "stick.h"
#include "circle.h"
#include <QRectF>
#include<QPainter>
#include<QPixmap>
#include <stdlib.h>
#include <hpbar.h>

MainWindow::MainWindow(): QGraphicsScene() {

   model = new Model();
   auto* rect = new stick();
   rect->setStick(600,600);
   rect->setDamage(0);
   rect->setPosition(400,400);
   rect->setSpeed(0);
   addItem(rect);
   auto* timer = new QTimer(this);
       connect(timer, &QTimer::timeout, [this]() {
       update();
           model->updateModel();
           if (model->player_->getHealth() <= 0) {
                  views().front() -> close();
           }

       });
   uploadAttack();
       auto* hpbar = new hpBar(model->player_);
       addItem(hpbar);
   timer->start(16);
}
void MainWindow::uploadAttack(){
   model->player_= new player();
   model->player_->setPosition({400,400});
   addItem(model->player_);
   attack1();
}
void MainWindow::attack1(){
    model->setNum(15);
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer]() {
        for (double angle = model->getNum()*10; angle < 360 + model->getNum() * 10 && model->getNum() > 0; angle+=36){
            auto* circle_ = new circle();
            circle_->setRadius(10);
            circle_->setPosition({400 + 400*cos(angle*M_PI/180.), 400 + 400*sin(angle*M_PI/180.)});
            circle_->setDirection({400,400});
            circle_->setSpeed(4);
            addItem(circle_);
            model->vecPushBack(circle_);
        }
        model->setNum(model->getNum() - 1);
        if (model->getNum() == 0) {timer->stop(); model->vecDelete(); attack2();}
        });
    timer->start(800);
}

void MainWindow::attack2(){
    model->setNum(15);
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer]() {
        for (double split = 800; split > 0 && model->getNum() > 0; split-=60){
            auto* stick_ = new stick();
            stick_->setStick(10,100);
            stick_->setPosition({0,split});
            stick_->setDirection({800 + (double)model ->getNum()*20,split + model ->getNum()*5});
            stick_->setSpeed(3);
            addItem(stick_);
            model -> vecPushBack(stick_);
        }
        model->setNum(model->getNum() - 1);
        if (model->getNum() == 0){timer->stop(); model->vecDelete(); attack3();}
    });
    timer->start(800);
}

void MainWindow::attack3(){
    model->setNum(20);
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer](){
        if (model->getNum() == 0){timer->stop(); model->vecDelete();attack4();}
            auto* stickLeft = new stick();
            stickLeft->setStick(10,400);
            stickLeft->setPosition({200,0});
            stickLeft->setDirection({200,800});
            stickLeft->setSpeed(3);
            addItem(stickLeft);
            model -> vecPushBack(stickLeft);
            auto* stickRigth = new stick();
            stickRigth->setStick(10,400);
            stickRigth->setPosition({600,800});
            stickRigth->setDirection({600,0});
            stickRigth->setSpeed(3);
            addItem(stickRigth);
            model -> vecPushBack(stickRigth);

        model->setNum(model->getNum() - 1);
    });
    timer->start(700);
}
void MainWindow::attack4(){
    model->setNum(15);
    srand(time(NULL));
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer](){
        if (model->getNum() == 0){timer->stop(); return;}
        for (int num = 0; num < 10; num++){
            int rnd = (rand() % 20) * 30 + 115;
            auto* circle_ = new circle();
            circle_->setRadius(15);
            circle_->setPosition({(double)rnd,0});
            circle_->setDirection({(double)rnd,800});
            circle_->setSpeed(6);
            addItem(circle_);
            model->vecPushBack(circle_);
        }
        model->setNum(model->getNum() - 1);
    });
    timer->start(900);
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


