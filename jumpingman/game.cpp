#include "game.h"
#include <QGraphicsProxyWidget>
#include <QDebug>
#include <QDialog>
#define WINDOW_WIDTH 384
#define WINDOW_LENGTH  600

game::game() {  

    this->state = game_not_start;

    //create a scene
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

    //set the background
    view->setBackgroundBrush(QPixmap(":/images/img/back2.gif"));

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set dimension
    view->setFixedSize(WINDOW_WIDTH,WINDOW_LENGTH);
    scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_LENGTH);

    //set the messageboxes
    welcome.setText("Welcome! Want to start the game?");
    welcome.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    welcome.setDefaultButton(QMessageBox::Yes);

 }

 void game::show()
 {
     game::view->show();
     int ret = welcome.exec();
     switch (ret) {
     case QMessageBox::Yes:
         // Yes was clicked
         start_game();
         break;
     case QMessageBox::No:
         // No was clicked
         end_game();
     default:
         break;
     }

 }

 void game::start_game()
 {
     this->state = game_ing;

     //create a board
     first_board = new board();
     first_board->setPos(WINDOW_WIDTH/2-30,WINDOW_LENGTH/2+190);

     //create a player to add to the scene
     Player = new myPlayer();
     Player->setPos(first_board->pos().x()+48,first_board->pos().y()-30);

     //create a score object
     my_label = new QLabel();
     my_label->setGeometry(QRect(0,0,50,15));
     my_label->setText(QString("Score:"));

     my_score = new score();
     my_score->setGeometry(QRect(50,0,70,15));

     QGraphicsProxyWidget *proxy1 = scene->addWidget(my_label);
     QGraphicsProxyWidget *proxy2 = scene->addWidget(my_score);

     //add item to the scene
     scene->addItem(Player);
     scene->addItem(first_board);

     //spawn boards
     timer = new QTimer();
     QObject::connect(timer, SIGNAL(timeout()), Player, SLOT(spawn()));
     timer->start(1000);
 }

 void game::end_game()
 {
     if (this->state == game_over)
         game::view->close();

 }

 void game::gameover()
 {
    qDebug() << "Game Over";

    //endofgame.setText(QString().number(my_score->getScore()));
    int ret = endofgame.exec();
    switch (ret) {
    case QMessageBox::Ok:
        // No was clicked
        end_game();
    default:
        end_game();
    }
    this->state = game_over;
}

