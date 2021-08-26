#include "Game.h"
#include "Grid.h"
#include <QPushButton>
#include <QFont>

Game::Game(QWidget *parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //nastavenie pevnej scény
    setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    turn = QString("X");
}

void Game::menu(){
    //pridanie nadpisu

    QGraphicsTextItem * nadpis = new QGraphicsTextItem(QString("PIŠKVORKY"));
    QFont font("times", 50);
    nadpis->setFont(font);
    int x = this->width()/2 - nadpis->boundingRect().width()/2;
    nadpis->setPos(x,50);
    scene->addItem(nadpis);

    //pridanie buttonov
    //PLAY button
    QPushButton * play = new QPushButton();
    play->setText("HRAJ");
    play->setStyleSheet("height: 80px;width: 200px");
    play->move(this->width()/2 - 100,150);
    connect(play,SIGNAL(clicked()),this,SLOT(start()),Qt::QueuedConnection);
    scene->addWidget(play);

    //QUIT button
    QPushButton * quit = new QPushButton();
    quit->setText("KONIEC");
    quit->setStyleSheet("height: 80px;width: 200px");
    quit->move(this->width()/2 - 100,300);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quit);
}

QString Game::GetTurn(){
    return turn;
}

void Game::SetTurn(QString player){
    //nastaví kto je práve na rade
    turn = player;
    QFont fontPlayer("times",20);
    playerText->setFont(fontPlayer);
    playerText->setPlainText(QString("Na rade je hráč so symbolom ") + turn);
    playerText->setPos(this->width()/2 - playerText->boundingRect().width()/2, 180);
}

void Game::GameOver(QString whoWon){
    //vykreslenie textu kto vyhral
    this->playerText->hide();
    QGraphicsTextItem * endText = new QGraphicsTextItem(whoWon);
    QFont fontEnd("times",20);
    endText->setFont(fontEnd);
    endText->setPos(this->width()/2 - endText->boundingRect().width()/2,75);
    scene->addItem(endText);

    //PushButton na replay
    QPushButton * replay = new QPushButton();
    replay->setText("HRAJ ZNOVU");
    replay->setStyleSheet("height: 40px;width: 100px");
    replay->move(this->width()/2 - 50, 110);
    connect(replay,SIGNAL(clicked()),this,SLOT(restart()),Qt::QueuedConnection);
    scene->addWidget(replay);

    //PushButton na koniec hry
    QPushButton * quit2 = new QPushButton();
    quit2->setText("KONIEC");
    quit2->setStyleSheet("height: 40px;width: 100px");
    quit2->move(this->width()/2 - 50, 165);
    connect(quit2,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quit2);
}


void Game::start(){
    //vykreslenie mriežky
    scene->clear();
    grid = new Grid();
    grid->PlaceSquares(325, 225, 3, 3);
    playerText = new QGraphicsTextItem();
    SetTurn(QString("X"));
    scene->addItem(playerText);
}

void Game::restart(){
    grid->GetSquares().clear();
    scene->clear();
    start();
}
