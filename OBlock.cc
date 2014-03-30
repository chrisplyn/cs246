#include "oblock.h"
#include "cell.h"
using namespace std;

OBlock::OBlock(Board& board, int level):Block(){
    
    Cell **grid = board.getGrid();
    
    //---------
    //| 2 | 3 |
    //---------
    //| 0 | 1 |
    //--------- 
    this->level = level;
    
    cells[0] = &grid[0][13];
    cells[1] = &grid[1][13];
    cells[2] = &grid[0][14];
    cells[3] = &grid[1][14];
    
    //cells are set to corresponding type and level
    cells[0]->setLT("O", level);
    cells[1]->setLT("O", level);
    cells[2]->setLT("O", level);
    cells[3]->setLT("O", level);
    //cell needs to provide addtoneighbour and deletefromneighbour;
    //also notify cell if their coordinates have changed
    cells[0]->addToNeighbour(cells[1]);
    cells[0]->addToNeighbour(cells[2]);
    cells[0]->addToNeighbour(cells[3]);
    
    cells[1]->addToNeighbour(cells[0]);
    cells[1]->addToNeighbour(cells[2]);
    cells[1]->addToNeighbour(cells[3]);
    
    cells[2]->addToNeighbour(cells[0]);
    cells[2]->addToNeighbour(cells[1]);
    cells[2]->addToNeighbour(cells[3]);
    
    cells[3]->addToNeighbour(cells[0]);
    cells[3]->addToNeighbour(cells[1]);
    cells[3]->addToNeighbour(cells[2]);
}

bool OBlock::canMoveLeft(Board *board){
    
    Cell **grid = board->getGrid();

    //check 0
    int xcoordinate = cells[0].getX();
    int ycoordinate = cells[0].getY();
    if (xcoordinate==0) { //at the left edge
        return false;
    }
    if (grid[xcoordinate-1][ycoordinate].isOn()) {
        return false; //the left cell is pre-occupied
    }
    
    //check 2
    xcoordinate = cells[2].getX();
    ycoordinate = cells[2].getY();
    if (grid[xcoordinate-1][ycoordinate].isOn()) {
        return false;
    }
    
    return true;
}

bool OBlock::canMoveRight(Board *board){
    
    Cell **grid = board->getGrid();
    
    //check 1
    int xcoordinate = cells[1].getX();
    int ycoordinate = cells[1].getY();
    if (xcoordinate==9) { //at the left edge
        return false;
    }
    if (grid[xcoordinate+1][ycoordinate].isOn()) {
        return false; //the left cell is pre-occupied
    }
    
    //check 3
    xcoordinate = cells[3].getX();
    ycoordinate = cells[3].getY();
    if (grid[xcoordinate+1][ycoordinate].isOn()) {
        return false;
    }
    
    return true;
}

bool OBlock::canMoveDown(Board *board){
    Cell **grid = board->getGrid();
    
    //check 0
    int xcoordinate = cells[0].getX();
    int ycoordinate = cells[0].getY();
    if (ycoordinate==0) { //at the lower edge
        return false;
    }
    if (grid[xcoordinate][ycoordinate-1].isOn()) {
        return false; //the lower cell is pre-occupied
    }
    //check 1
    int xcoordinate = cells[1].getX();
    int ycoordinate = cells[1].getY();
    if (grid[xcoordinate][ycoordinate-1].isOn()) {
        return false; //the lower cell is pre-occupied
    }
}

bool OBlock::canRotateClockwise(Board *board){
    return true;
}

bool OBlock::canRotateAntiClockwise(Board *board){
    return true;
}

void OBlock::rotateClockwise(Board *board){
    return;
}

void OBlock::rotateAnticlockwise(Board *board){
    return;
}

void OBlock::moveLeft(Board *board){
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    if (!canMoveLeft()) {
        return;
    }
    //cell should provide method to update coordinates
    //and notify their neighbours at the same time
    for (int i =0; i<4; ++i) {
        
        int x = cells[i].getX();
        cells[i].setX(x-1);//move every cell to the left
        cells[i].notifyNeighbour();//notify neighbours that the corrdinates have changed
    }
    Cell ** grid = board->getGrid();
    grid[originX+1][originY] = new Cell;
    grid[originX+1][originY+1] = new Cell();
    
}

void OBlock::moveRight(Board *board){
    int originX = cells[0].getX();
    int originY = cells[0].getY();
    if (!this->canMoveRight()) {
        return;
    }
    //cell should provide method to update coordinates
    //and notify their neighbours at the same time
    for (int i =0; i<4; ++i) {
        int x = cells[i].getX();
        cells[i].setX(x+1);//move every cell to the right
        cells[i].notifyNeighbour();//notify neighbours that the corrdinates have changed
    }
    Cell ** grid = board->getGrid();
    grid[originX][originY] = new Cell();
    grid[originX][originY+1] = new Cell();
}

void OBlock::moveDown(Board *board){
    int originX = cells[0].getX();
    int originY = cells[0].getY();
    if (!this->canMoveDown()) {
        return;
    }
    //cell should provide method to update coordinates
    //and notify their neighbours at the same time
    for (int i =0; i<4; ++i) {
        int y = cells[i].getY();
        cells[i].setY(y-1));//move every cell down
        cells[i].notifyNeighbour();//notify neighbours that the corrdinates have changed
    }
    Cell ** grid = board->getGrid();
    grid[originX][originY+1] = new Cell();
    grid[originX+1][originY+1] = new Cell();
}

void OBlock::drop(Board *board){
    /*
    int originX = cells[0].getX();
    int originY = cells[0].getY();//the original base coordinates
    
    Cell ** grid = board->getGrid();
    
    int posX = cells[0];
    int posY = 0;
    while (true) {
        if ((!grid[posX][posY].isOn())&&
            (!grid[posX+1][posY].isOn())&&
            (!grid[posX][posY+1].isOn())&&
            (!grid[posX+1][posY+1].isOn())) { //break when all four cells can be occupied by the
                                                //new block
            break;
        }
        posY++;
    }
    //update coordinate
    cells[0].setY(posY);
    cells[1].setY(posY);
    cells[2].setY(posY+1);
    cells[3].setY(posY+1);
    
    for (int i =0; i<4; ++i) {
        cells[i].notifyNeighbour();
    }
    
    //change the original cells back to new cells
    grid[originX][originY] = new Cell();
    grid[originX][originY+1] = new Cell();
    grid[originX+1][originY] = new Cell();
    grid[originX+1][originY+1] = new Cell();
     */
    while (canMoveDown()) {
        MoveDown();
    }
    return;
}

