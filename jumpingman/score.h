#ifndef SCORE_H
#define SCORE_H

#include <QLabel>
#include <QTimer>
#include <QTimeLine>

class score: public QLabel{
        Q_OBJECT
public:
        score();
        int getScore();
private:
        int playerScore;
        QTimer *timer;
public slots:
        void updateScore();
};




#endif // SCORE_H
