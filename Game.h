#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <Grid.h>


class Game: public QGraphicsView{
    Q_OBJECT
public:
    //konštruktor
    Game(QWidget* parent=NULL);

    //funkcie
    void menu();
    QString GetTurn();
    void SetTurn(QString player);

    //vlastnosti
    QGraphicsScene* scene;
    Grid* grid;
public slots:
    void start();

private:
    QString turn;
    QGraphicsTextItem * playerText;
};

#endif // GAME_H
