#pragma once
#include <QGraphicsItem>
#include "player.h"
class hpBar: public QGraphicsItem{
    player* player_;
public:
    explicit hpBar(player* player_): player_(player_){}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

};
