#include <QApplication>
#include <QGraphicsView>
#include "game.h"

game * main_game;

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);

        main_game = new game();

        main_game->show();

        return a.exec();
}
