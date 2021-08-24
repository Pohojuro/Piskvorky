#include "Grid.h"
#include "Game.h"
#include "Square.h"

extern Game* game;

Grid::Grid()
{

}


QList<Square *> Grid::GetSquares(){
    return Squares;
}

void Grid::PlaceSquares(int x, int y, int rows, int cols){
    //druhý cyklus na vykreslenie viacerych stĺpcov
    for (auto i = 0; i < cols; i++){
        CreateCol(x+50*i, y, rows);
    }
}

void Grid::CreateCol(int x, int y, int NumRows){
    //cyklus na vykreslenie stĺpca
    for (auto i = 0; i < NumRows; i++){
        //nastavenie rozmerov a vykreslenie štvorcov
        Square* square = new Square();
        square->setRect(0,0,50,50);
        square->setPos(x, y+50*i);
        Squares.append(square);
        game->scene->addItem(square);
        square->SetSymbol(0);
    }
}
