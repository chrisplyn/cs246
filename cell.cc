#include "cell.h"
#include "display.h"
using namespace std;

Cell::Cell(){
    type = "";
    Level = 0;
    for (int i = 0; i< 3; i++){
        Neighbour[i] = NULL;
    }
    xCoordinate = -1;
    yCoordiante = -1;
    existtime = -1;
    xGraphic = 0;
    yGraphic = 0;
    width = 0;
    height = 0;
    w = 0;
}

Cell::Cell(string Type,int level){
    type = Type;
    Level = level;
    for (int i = 0; i< 3; i++){
        Neighbour[i] = NULL;
    }
    xCoordinate = -1;
    yCoordiante = -1;
    existtime = -1;
}

void Cell::addNeighbour(Cell * c){
    if (this != NULL){
        for (int i = 0; i < 3; ++i){
            if (Neighbour[i] == NULL){
                Neighbour[i] = c;
                break;//change here ***************************
            }
        }
    }
}


void Cell::addToNeighbour(Cell * c){
    c->addNeighbour(this);
}

void Cell::deleteNeighbour(Cell * c){
    if ((c != NULL) &&(this != NULL)){//change here (c != NULL) &&
        for (int i = 0; i < 3; ++i){
            if (Neighbour[i] == c){
                Neighbour[i] = NULL;
                break;//change here ****************************
            }
        }
    }
}


void Cell::deleteFromNeighbour(){
    for (int i = 0; i < 3; ++i){
        Neighbour[i]->deleteNeighbour(this);
    }
}

void Cell::Swap(Cell *c){
    //swap level and type
    
    string tempType = c->getType();
    int tempLevel = c->getLevel();
    int temexist = c->getExistime();
    c->setLT(type,Level,existtime);
    type = tempType;
    Level = tempLevel;
    existtime = temexist;
    
    //swap neighbours
    
    Cell * neighbour;
    for (int i =0; i < 3; ++i){
        neighbour = this->getNeighbour(i);
        if (neighbour != NULL){//change here
            c->addNeighbour(neighbour);
        }
    }
    this->deleteFromNeighbour();
    for (int j = 0; j < 3; ++j){
        neighbour = this->getNeighbour(j);
        neighbour->addNeighbour(c);
    }
    for (int k =0; k < 3; ++k){
        Neighbour[k] = NULL;
    }
    
}

void Cell::reset(){
    this->deleteFromNeighbour();
    for (int i = 0; i < 3;++i){
        Neighbour[i] = NULL;
    }
    type = "";
    Level = -1;
}


Cell* Cell::getNeighbour(int index){
    return Neighbour[index];
}

void Cell::setLT(std::string Type,int level,int Existime){
    type = Type;
    Level = level;
    existtime = Existime;
}

void Cell::toggle(string Type){
    type = Type;
}

bool Cell::isOn(){
    if (type == ""){
        return false;
    }  else {
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

void Cell::setCoordinates(int x, int y, int xGraphic, int yGraphic, int width, int height, Xwindow *w) {
    xCoordinate = x;
    yCoordiante = y;
    this->xGraphic = xGraphic;
    this->yGraphic = yGraphic;
    this->width = width;
    this->height = height;
    this->w = w;
}

void Cell::draw(){
    if (type == "O"){
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::Red);
    } else if (type == "I") {
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::Green);
    } else if (type == "L") {
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::Blue);
    } else if (type == "J") {
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::Cyan);
    } else if (type == "S") {
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::Yellow);
    } else if (type == "Z") {
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::Magenta);
    } else if (type == "T") {
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::Orange);
    } else {
        w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::White);
    }
}

void Cell::undraw() {
    w->fillRectangle(xGraphic, yGraphic, width, height, Xwindow::White);
}

void Cell::notifyScore(Score *score){
    //score->updateScoreBoard(Level);
}


void Cell::notifyDisplay(textDisplay *dp){
    dp->notify(xCoordinate,yCoordiante,type);
    //dp->notify(xCoordinate,yCoordiante,Level);
}

int Cell::getX(){
    return xCoordinate;
}

int Cell::getY(){
    return yCoordiante;
}



Cell::~Cell(){}


//add
int Cell::getExistime(){
    return existtime;
}

void Cell::updatetimes(){
    existtime = existtime + 1;
}


