#ifndef GAME_H
#define GAME_H

#include "myPlayer.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "board.h"
#include "window_size.h"
#include <QTimer>
#include "score.h"
#include <QLabel>
#include <QMessageBox>

enum State {game_not_start, game_ing, game_over};

class game  {
public:
     game();
     void show();
     void start_game();
     void end_game();
     void gameover();


private:
     State state;
     QMessageBox welcome, endofgame;
     QGraphicsScene *scene;
     myPlayer * Player;
     board * first_board;
     QLabel * my_label;
     score * my_score;
     QGraphicsView *view;
     QTimer * timer;


};

#endif // GAME_H
