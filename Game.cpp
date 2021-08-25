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

    turn = QString("modrý");
}

void Game::menu(){
    //pridanie nadpisu

    QGraphicsTextItem * nadpis = new QGraphicsTextItem(QString("PISKVORKY"));
    QFont font("times", 50);
    nadpis->setFont(font);
    int x = this->width()/2 - nadpis->boundingRect().width()/2;
    nadpis->setPos(x,50);
    scene->addItem(nadpis);

    //pridanie buttonov
    //PLAY button
    QPushButton * play = new QPushButton();
    play->setText("PLAY");
    play->setStyleSheet("height: 80px;width: 200px");
    play->move(this->width()/2 - 100,150);
    connect(play,SIGNAL(clicked()),this,SLOT(start()),Qt::QueuedConnection);
    scene->addWidget(play);

    //QUIT button
    QPushButton * quit = new QPushButton();
    quit->setText("QUIT");
    quit->setStyleSheet("height: 80px;width: 200px");
    quit->move(this->width()/2 - 100,300);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quit);
}

QString Game::GetTurn(){
    return turn;
}

void Game::SetTurn(QString player){
    turn = player;
    QFont fontPlayer("times",20);
    playerText->setFont(fontPlayer);
    playerText->setPlainText(QString("Na rade je ") + turn + QString(" hráč"));
}


void Game::start(){
    //vykreslenie mriežky
    scene->clear();
    grid = new Grid();
    grid->PlaceSquares(300, 200, 3, 3);
    playerText = new QGraphicsTextItem();
    SetTurn(QString("modrý"));
    scene->addItem(playerText);
}
