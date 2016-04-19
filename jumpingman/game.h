#ifndef GAME_H
#define GAME_H

#include "myPlayer.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "board.h"
#include "window_size.h"
#include <QTimer>

class game  {
public:
     game();
     void show();

private:
     QGraphicsScene *scene;
     myPlayer * Player;
     board * first_board;
     QGraphicsView *view;
};

#endif // GAME_H
