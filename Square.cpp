#include "Square.h"
#include "Grid.h"
#include "Game.h"
#include <QBrush>


extern Game* game;


void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(game->GetTurn() == QString("modrý") && this->GetSymbol() == 0){
        this->SetSymbol(1);
        game->SetTurn(QString("červený"));
    }
    else if (game->GetTurn() == QString("červený") && this->GetSymbol() == 0){
        this->SetSymbol(2);
        game->SetTurn(QString("modrý"));
    }
    if (game->grid->CheckWin() == true){
        QGraphicsTextItem * wintext = new QGraphicsTextItem(QString("WIN"));
        wintext->setPos(0,50);
        game->scene->addItem(wintext);
        //exit(0);
    }
}

int Square::GetSymbol(){
    return Symbol;
}

int Square::GetId(){
    return id;
}



void Square::SetSymbol(int symbol)
{
    Symbol = symbol;

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

void Square::SetId(int ID){
    id = ID;
}


