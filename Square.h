#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
class Square: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    //reakcia na kliknutie
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //getters
    int GetSymbol();

    //setters
    void SetSymbol(int symbol);

private:
    //vlastnosti
    int  Symbol;

};

#endif // SQUARE_H
