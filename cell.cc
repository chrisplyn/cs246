#include "cell.h"
using namespace std;

Cell::Cell(){
    type = "";
    Level = 0;
    for (int i = 0; i< 3; i++){
        Neighbour[i] = NULL;
    }
    xCoordinate = -1;
    yCoordiante = -1;
}

Cell::Cell(string Type,int level){
    type = Type;
    Level = level;
    for (int i = 0; i< 3; i++){
        Neighbour[i] = NULL;
    }
    xCoordinate = -1;
    yCoordiante = -1;
}

void Cell::addNeighbour(Cell * c){
    for (int i = 0; i < 3; ++i){
        if (Neighbour[i] == NULL){
            Neighbour[i] = c;
        }
    }
}


void Cell::addToNeighbour(Cell * c){
    c->addNeighbour(this);
}

void Cell::deleteNeighbour(Cell * c){
    for (int i = 0; i < 3; ++i){
        if (Neighbour[i] == c){
            Neighbour[i] = NULL;
        }
    }
}


void Cell::deleteFromNeighbour(){
    for (int i = 0; i < 3; ++i){
        Neighbour[i]->deleteNeighbour(this);
    }
}

void Cell::Swap(Cell *c){
    c->setLT(type,Level);
    Level = c->getLevel();
    type = c->getType();
    Cell * neighbour;
    for (int i =0; i < 3; ++i){
        neighbour = this->getNeighbour(i);
        c->addNeighbour(neighbour);
    }
    this->deleteFromNeighbour();
    for (int j = 0; j < 3; ++j){
        neighbour = this->getNeighbour(j);
        c->addToNeighbour(neighbour);
    }
    for (int k =0; k < 3; ++k){
        Neighbour[k] = NULL;
    }
}


Cell* Cell::getNeighbour(int index){
    return Neighbour[index];
}

void Cell::setLT(std::string Type,int level){
    type = Type;
    Level = level;
}

void Cell::toggle(string Type){
    type = Type;
}

bool Cell::isOn(){
    if (type == ""){
        return false;
    }   else {
        return true;
    }
}

string Cell::getType(){
    return type;
}

int Cell::getLevel(){
    return Level;
}

void Cell::setCoordinates(int x, int y){
    xCoordinate = x;
    yCoordiante = y;
}

void Cell::notifyScore(Score *score){
    score->updateScoreBoard(Level);
}


void Cell::notifyDisplay(Display *dp){
    dp->notify(xCoordinate,yCoordiante,Level);
}

int Cell::getX(){
    return xCoordinate;
}

int Cell::getY(){
    return yCoordiante;
}