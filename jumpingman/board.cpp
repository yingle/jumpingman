#include "board.h"

#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int

board::board() {
        //set dimension
        width = 96;
        height = 16;

        //draw the board
        setPixmap(QPixmap(":/images/img/board_a.gif"));

        //set random position
         int random_number = rand() % WINDOW_WIDTH;
         if (random_number<0)
             random_number = 0;
         else if (random_number > (WINDOW_WIDTH-width))
             random_number = rand() % 300;
        setPos(random_number, WINDOW_LENGTH);

        // connect
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));

        //set the timer
        timer->start(10);
}

int board::getWidth()
{
    return board::width;
}

void board::stopTimer()
{
     timer->stop();

}

void board::moveUp() {
        //move board up
        setPos(pos().x(), pos().y()-1);
        if (pos().y() < 0) {
                scene()->removeItem(this);
                delete this;
                qDebug() << "board deleted";
        }
}


