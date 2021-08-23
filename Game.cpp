#include "Game.h"
#include "Grid.h"

Game::Game(QWidget *parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //nastavenie pevnej scény
    setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);


}

void Game::start(){
    //vykreslenie mriežky, bude spojené s push buttonom PLAY
    Grid * grid = new Grid();
    grid->PlaceSquares(300, 200, 3, 3);
}
