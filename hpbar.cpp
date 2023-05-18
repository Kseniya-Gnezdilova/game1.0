#include "hpbar.h"


void hpBar::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
    painter->setBrush(Qt::red);
    painter->drawRect(-100, 100, boundingRect().width() * player_->getHealth() / 1000.,boundingRect().height());
}

QRectF hpBar::boundingRect() const {
    return QRectF(-100, 100, 100, 20);
}

