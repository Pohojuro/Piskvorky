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
    int GetId();

    //setters
    void SetSymbol(int symbol);
    void SetId(int ID);

private:
    //vlastnosti
    int  Symbol;
    int id;

};

#endif // SQUARE_H
