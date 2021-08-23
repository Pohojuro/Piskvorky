#include "Game.h"
#include "Grid.h"
#include <QPushButton>

Game::Game(QWidget *parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //nastavenie pevnej scény
    setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

}

void Game::menu(){
    //pridanie nadpisu

    QGraphicsTextItem * nadpis = new QGraphicsTextItem(QString("PISKVORKY"));
    nadpis->setPos(300,50);
    scene->addItem(nadpis);

    //pridanie buttonov
    //PLAY button
    QPushButton * play = new QPushButton();
    play->setText("PLAY");
    play->setStyleSheet("height: 80px;width: 200px");
    play->move(300,100);
    connect(play,SIGNAL(clicked()),this,SLOT(start()),Qt::QueuedConnection);
    scene->addWidget(play);

    //QUIT button
    QPushButton * quit = new QPushButton();
    quit->setText("QUIT");
    quit->setStyleSheet("height: 80px;width: 200px");
    quit->move(300,300);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quit);
}


void Game::start(){
    //vykreslenie mriežky
    scene->clear();
    Grid * grid = new Grid();
    grid->PlaceSquares(300, 200, 3, 3);
}
