#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>


class Game: public QGraphicsView{
    Q_OBJECT
public:
    //konštruktor
    Game(QWidget* parent=NULL);

    //funkcie
    void menu();

    //vlastnosti
    QGraphicsScene* scene;
public slots:
    void start();

};

#endif // GAME_H
