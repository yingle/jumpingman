#include "score.h"
#include <QDebug>

score::score(){
        playerScore = 0;
        setAlignment(Qt::AlignRight);
        setNum(playerScore);

        timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(updateScore()));
        timer->start(4000);
}


int score::getScore()
{
    return this->playerScore;
}


void score::updateScore(){
        this->playerScore++;
        setNum(this->playerScore);
}

