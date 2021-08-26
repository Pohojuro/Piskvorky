#include "Square.h"
#include "Grid.h"
#include "Game.h"


extern Game* game;


void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //ak je na rade X, nastaví X
    if(game->GetTurn() == QString("X") && this->GetSymbol() == 0 && game->grid->CheckWin() == false){
        this->SetSymbol(1);
        game->SetTurn(QString("O"));
    }
    //ak je na rade O, nastaví O
    else if (game->GetTurn() == QString("O") && this->GetSymbol() == 0 && game->grid->CheckWin() == false){
        this->SetSymbol(2);
        game->SetTurn(QString("X"));
    }
    //skontroluje či niekto vyhral
    if (game->grid->CheckWin() == true){
        if (game->GetTurn() == QString("O")){
            game->GameOver(QString("Vyhral hráč so znakom X"));
        }
        else if (game->GetTurn() == QString("X")){
            game->GameOver(QString("Vyhral hráč so znakom O"));
        }
    }
    if (game->grid->CheckDraw() == true && game->grid->CheckWin() == false){
        game->GameOver(QString("REMÍZA"));
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
    //nastaví symbol pre konkrétny square
    Symbol = symbol;

    if(symbol == 0){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::lightGray);
        setBrush(brush);
    }
    if(symbol == 1){
        QPen pen;
        pen.setWidth(4);
        QGraphicsLineItem * line1 = new QGraphicsLineItem(this);
        line1->setLine(8,8,42,42);
        line1->setPen(pen);
        QGraphicsLineItem * line2 = new QGraphicsLineItem(this);
        line2->setLine(42,8,8,42);
        line2->setPen(pen);
    }
    if(symbol == 2){
        QGraphicsEllipseItem * kruh = new QGraphicsEllipseItem(this);
        kruh->setRect(7,7,35,35);
        QPen pen;
        pen.setWidth(4);
        kruh->setPen(pen);
    }

}

void Square::SetId(int ID){
    id = ID;
}


