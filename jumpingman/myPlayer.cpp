#include "myPlayer.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "board.h"
#include <typeinfo>
#include <QGraphicsScene>
#include "game.h"

myPlayer::myPlayer()  {
        //set dimension
        width =  30;
        height = 30;

        //set graphic
        setPixmap(QPixmap(":/images/img/javaman_s.gif"));

        setPos(WINDOW_WIDTH/2,WINDOW_LENGTH/2);

        //make the item focusable
        setFlag(QGraphicsItem::ItemIsFocusable);
        setFocus();

        //at beginning is always on board
        isOnboard = true;

        // connect
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        //set the timer
        timer->start(20);
}

void myPlayer::keyPressEvent(QKeyEvent *event){
        //player movement
        if (event->key() == Qt::Key_Left) {
            if (pos().x() > 0){
                setPos(x()-9, y());
                setPixmap(QPixmap(":/images/img/javaman_l1.gif"));
            }
        }
        else if (event->key() == Qt::Key_Right) {
            if (pos().x()+width < WINDOW_WIDTH){
                 setPos(x()+9, y());
                 setPixmap(QPixmap(":/images/img/javaman_r1.gif"));
             }
        }
}

void myPlayer::keyReleaseEvent(QKeyEvent *event)
{
        if ((event->key() == Qt::Key_Left) or (event->key() == Qt::Key_Right)){
           setPixmap(QPixmap(":/images/img/javaman_s.gif"));
        }
}

void myPlayer::die() {
        //remove the player
        scene()->removeItem(this);
        delete this;
        game().gameover();
        qDebug() << "Player deleted";

}


void myPlayer::move() {
        //Check if the player has collision with any board
        QList<QGraphicsItem *> colliding_items = collidingItems();
        if ( colliding_items.size() == 0) {
            myPlayer::isOnboard = false;
        }
        else {
            //Some collision happens
            int i = 0;

            //Manage bad collision
            do {
                //identify board
                if (typeid(*(colliding_items[i])) == typeid(board) ) {
                    //bad collision from top
                    if (colliding_items[i]->pos().y() < pos().y()+height){
                        myPlayer::isOnboard = true;
                        setPos(pos().x(), pos().y()+(colliding_items[i]->pos().y()-pos().y()-height+1));
                       }
                    //bad collision from bottom (sticked with "head" of player)
                    else if (colliding_items[i]->pos().y()+16> pos().y()){
                         myPlayer::isOnboard = false;
                         setPos( pos().x(), colliding_items[i]->pos().y()+16);
                     }
                    //bad collision from left
                    else if (colliding_items[i]->pos().x()-width<= pos().x()){
                           myPlayer::isOnboard = false;
                           setPos( colliding_items[i]->pos().x()-width, pos().y());
                     }
                     //bad collision from right
                    else if (colliding_items[i]->pos().x()+96 >= pos().x() ){
                           myPlayer::isOnboard = false;
                           setPos( colliding_items[i]->pos().x()+96, pos().y());
                     }
                 }
                 i++;
             }while ((!myPlayer::isOnboard ) && (i < colliding_items.size()));
        }
        //Clear the colliding_item list
        colliding_items.clear();

        //Move up or move down
        if (myPlayer::isOnboard)
             setPos(pos().x(), pos().y()-1);
        else setPos(pos().x(), pos().y()+4);

        //Check if the player die
        if ((pos().y()+height > WINDOW_LENGTH) || (pos().y()<0)) die();

}

void myPlayer::spawn() {
        //Create a new board
        board * aboard = new board();
        scene()->addItem(aboard);
}
