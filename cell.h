#ifndef __CELL_H__
#define __CELL_H__
#include <string>

#define NeighbourMax 3

class Display;
class Score;
class Cell{
    int Level;
    std::string type;
    Cell * Neighbour[NeighbourMax];
    int xCoordinate;
    int yCoordiante;
public:
    Cell();
    Cell(std::string Type,int level);
    void storeTemp(Cell * tmp[3]);
    void addToNeighbour(Cell *);
    void addNeighbour(Cell *);
    void deleteFromNeighbour();
    void deleteNeighbour(Cell *);
    
    void Swap(Cell *c);
    
    Cell * getNeighbour(int index);
    void setLT(std::string Type,int level);
    void toggle(std::string Type);
    bool isOn();
    std::string getType();
    int getLevel();
    void setCoordinates(int x, int y);
    void notifyScore(Score * score);
    void notifyDisplay(Display * dp);
    int getX();
    int getY();
    ~Cell();
};




#endif
