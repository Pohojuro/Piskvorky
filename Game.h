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
    void GameOver(QString whoWon);

    //vlastnosti
    QGraphicsScene* scene;
    Grid* grid;
public slots:
    //slot na odštartovanie hry
    void start();
    void restart();

private:
    //vlastnosti
    QString turn;
    QGraphicsTextItem * playerText;
};

#endif // GAME_H
