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
    type = Tyep;
    Level = level;
    for (int i = 0; i< 3; i++){
        Neighbour[i] = NULL;
    }
    xCoordinate = -1;
    yCoordiante = -1;
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