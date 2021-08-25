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
        CreateCol(x, y, i, rows);
    }
}

bool Grid::CheckWin(){
    //check na riadky
    for (auto i = 0; i < 3; i++){
        if(Squares[i+0]->GetSymbol() == Squares[3+i]->GetSymbol() && Squares[i+0]->GetSymbol() == Squares[6+i]->GetSymbol() && Squares[i+0]->GetSymbol() != 0){
            return true;
        }
    }
    //check na stlpce
    for (auto i = 0; i < 3; i++){
        if(Squares[3*i+0]->GetSymbol() == Squares[3*i+1]->GetSymbol() && Squares[3*i+0]->GetSymbol() == Squares[3*i+2]->GetSymbol() && Squares[3*i+0]->GetSymbol() != 0){
            return true;
        }
    }
    //check na diagonaly
    if(Squares[0]->GetSymbol() == Squares[4]->GetSymbol() && Squares[0]->GetSymbol() == Squares[8]->GetSymbol() && Squares[0]->GetSymbol() != 0){
        return true;
    }
    if(Squares[6]->GetSymbol() == Squares[4]->GetSymbol() && Squares[6]->GetSymbol() == Squares[2]->GetSymbol() && Squares[6]->GetSymbol() != 0){
        return true;
    }
    return false;
}

void Grid::CreateCol(int x, int y, int j, int NumRows){
    x+=50*j;
    //cyklus na vykreslenie stĺpca
    for (auto i = 0; i < NumRows; i++){        
        //nastavenie rozmerov a vykreslenie štvorcov
        Square* square = new Square();
        square->setRect(0,0,50,50);
        square->setPos(x, y+50*i);
        Squares.append(square);
        game->scene->addItem(square);
        square->SetSymbol(0);
        square->SetId(i*3+j);
    }
}
