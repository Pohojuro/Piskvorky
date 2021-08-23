#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>


class Game: public QGraphicsView{
public:
    //konštruktor
    Game(QWidget* parent=NULL);

    //funkcie
    void start();

    //vlastnosti
    QGraphicsScene* scene;


};

#endif // GAME_H
