#ifndef __CELL_H__
#define __CELL_H__

#include <string>
#include "window.h"
#define NeighbourMax 3

class Score;
class textDisplay;
class Cell{
    int Level;
    std::string type;
    Cell * Neighbour[NeighbourMax];
    int xCoordinate;
    int yCoordiante;
    int existtime;

    //for graphic presentation
    Xwindow *w;
    int xGraphic; //xcoordinate
    int yGraphic; //ycoordinate
    int width;
    int height;

public:
    Cell();
    Cell(std::string Type,int level);
    void storeTemp(Cell * tmp[3]);
    void addToNeighbour(Cell *);
    void addNeighbour(Cell *);
    void deleteFromNeighbour();
    void deleteNeighbour(Cell *);    
    void Swap(Cell *c);
    void reset();   
    Cell * getNeighbour(int index);
    void setLT(std::string Type,int level,int Existime);//change here
    void toggle(std::string Type);
    bool isOn();
    std::string getType();
    int getLevel();

    void setCoordinates(int x, int y);
    void setCoordinates(int x, int y, int xGraphic, int yGraphic, int width, int height, Xwindow *w);
    void draw();
    void undraw();

    void notifyScore(Score * score);
    void notifyDisplay(textDisplay * dp);
    int getX();
    int getY();
    ~Cell();
    //add new
    int getExistime();
    void updatetimes();
};




#endif
