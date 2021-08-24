#include "Square.h"
#include "Grid.h"
#include "Game.h"
#include <QBrush>

extern Game* game;

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(game->GetTurn() == QString("modrý")){
        this->SetSymbol(1);
        game->SetTurn(QString("červený"));
    }
    else if (game->GetTurn() == QString("červený")){
        this->SetSymbol(2);
        game->SetTurn(QString("modrý"));
    }
}



void Square::SetSymbol(int symbol)
{
    if(symbol == 0){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::lightGray);
        setBrush(brush);
    }
    if(symbol == 1){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::blue);
        setBrush(brush);
    }
    if(symbol == 2){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
    }

}


