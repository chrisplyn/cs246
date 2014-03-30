#ifndef __CELL_H__
#define __CELL_H__
#include <string>
#include "score.h"
#include "display.h"
#define NeighbourMax 3

class Cell{
    int Level;
    std::string type;
    Cell * Neighbour[NeighbourMax];
    int xCoordinate;
    int yCoordiante;
public:
    Cell();
    Cell(std::string Type,int level);
    void setLT(std::string Type,int level);
    void toggle(std::string Type);
    bool isOn();
    std::string getType();
    void setCoordinates(int x, int y);
    void notifyScore(Score * score);
    void notifyDisplay(Display * dp);
    int getX();
    int getY();
    ~Cell();
};




#endif
