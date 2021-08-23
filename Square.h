#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsRectItem>
#include <QMouseEvent>
class Square: public QGraphicsRectItem{
public:

    //getters/setters
    bool GetStatus();
    bool SetStatus();
    int GetSymbol();
    int SetSymbol();

private:
    //vlastnosti
    bool Filled;
    int  Symbol;

};

#endif // SQUARE_H
