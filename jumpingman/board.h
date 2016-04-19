#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "window_size.h"

//public QObject,
class board : public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
        board();
        int getWidth();
public slots:
        void moveUp();
private:
        int width;
        int height;
        enum type{normal, thorn, slip_left, slip_right};
};

#endif // BOARD_H

