#include "game.h"
#define WINDOW_WIDTH 384
#define WINDOW_LENGTH  600
 game::game() {
            //create a scene
            scene = new QGraphicsScene();

            //create a board
            first_board = new board();
            first_board->setPos(WINDOW_WIDTH/2-30,WINDOW_LENGTH/2+190);

            //create a player to add to the scene
            Player = new myPlayer();
            Player->setPos(first_board->pos().x()+48,first_board->pos().y()-30);

            //add item to the scene
            scene->addItem(Player);
            scene->addItem(first_board);

            view = new QGraphicsView(scene);
            //set the background
            view->setBackgroundBrush(QPixmap(":/images/img/back2.gif"));

            view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            //set dimension
            view->setFixedSize(WINDOW_WIDTH,WINDOW_LENGTH);
            scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_LENGTH);

            //spawn boards
            QTimer * timer = new QTimer();
            QObject::connect(timer, SIGNAL(timeout()), Player, SLOT(spawn()));
            timer->start(1000);


 }

 void game::show() {
            game::view->show();
 }
