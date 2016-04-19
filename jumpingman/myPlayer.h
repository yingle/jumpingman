#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "window_size.h"

//public  QObject,
class myPlayer : public  QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
        myPlayer();
        void keyPressEvent(QKeyEvent * event);
        void keyReleaseEvent(QKeyEvent * event);
        void die();

public slots:
        void move();
        void spawn();
private:
        bool isOnboard;
        int width;
        int height;

};

#endif // MYRECT_H
