#ifndef GRID_H
#define GRID_H

#include <QList>
#include "Square.h"

class Grid{
public:
    //konštruktor
    Grid();

    //getters/setters
    QList<Square*> GetSquares();

    //funkcie
    void PlaceSquares(int x, int y, int rows, int cols);
private:
    void CreateCol(int x, int y, int NumRows);
    QList<Square*> Squares;

};

#endif // GRID_H
