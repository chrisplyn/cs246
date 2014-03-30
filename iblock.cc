
#include "iblock.h"
#include "cell"
using namespace std;

IBlock::IBlock(const Board& board):Block(){
    
    Cell ** grid = board.getGrid();
    
    //-----------------
    //| 0 | 1 | 2 | 3 |
    //-----------------
    
    cells[0] = &grid[0][14];
    cells[1] = &grid[1][14];
    cells[2] = &grid[2][14];
    cells[3] = &grid[3][14];
    
    cells[0]->setType("I");
    cells[1]->setType("I");
    cells[2]->setType("I");
    cells[3]->setType("I");
    
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

//direction
//
//0 :               1:
//-------------      -----
//| 0| 1| 2| 3|      | 3 |
//-------------      -----
//                   | 2 |
//                   -----
//                   | 1 |
//                   -----
//                   | 0 |
//                   -----
int direction(){
    int originX = cells[0].getX();
    int nextX = cells[1].getX();
    if (originX==nextX) {
        return 1;
    } else {
        return false;
    }
}

bool Iblock::canMoveLeft(Board *board){
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
    return true;
}

bool IBlock::canMoveRight(Board *board){
    Cell **grid = board->getGrid();
    
    //check 3
    int xcoordinate = cells[3].getX();
    int ycoordinate = cells[3].getY();
    if (xcoordinate==9) { //at the left edge
        return false;
    }
    if (grid[xcoordinate+1][ycoordinate].isOn()) {
        return false; //the left cell is pre-occupied
    }

}

bool IBlock::canMoveDown(Board **board){
    Cell **grid = board->getGrid();
    
    //check 0
    int xcoordinate = cells[0].getX();
    int ycoordinate = cells[0].getY();
    if (ycoordinate==0) { //at the lower edge
        return false;
    }
    
    for (int i=0; i<4; ++i) {
        int xcoordinate = cells[0].getX();
        int ycoordinate = cells[0].getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false;
        }
    }
    return true;
}


bool IBlock::canRotateClockwise(Board *board){
    Cell **grid = board->getGrid();
    int originX = cells[0].getX();
    int originY = cells[0].getY();
    
    if (direction()==0) { //horizontal to vertical
        for (int i=1; i<=3; ++i) {
            if (grid[originX][originY+i].isOn()) {
                return false;
            }
        }
        
    } else if (direction()==1) { //vertical to horizontal
        for (int i=1; i<=3; ++i) {
            if (grid[originX+i][originY].isOn()) {
                return false;
            }
        }
    }
    return true;
}

bool canRotateAnticlockwise::IBlock(Board *board){
    return canRotateClockwise(board);
}

void IBlock::MoveLeft(Board *board){
    
    int originX = cells[0].getX();
    int originY = cells[0].getY();
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
    if(direction()==0) {
        grid[originX+3][originY] = new Cell();
    } else if (direction()==1){
        for (int i=0; i<4; ++i) {
            grid[origionX][origionY+i] = new Cell();
        }
    }
}

void IBlock::MoveRight(Board *board){
    int originX = cells[0].getX();
    int originY = cells[0].getY();
    if (!canMoveRight()) {
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
    if(diretion()==0) {
        grid[originX][originY] = new Cell();
    } else if (diretion()==1){
        grid[origionX][origionY+i] = new Cell();
    }
}

void IBlock::MoveDown(Board *board){
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
    if (direction()==0) {
        for (int i=0; i<4; ++i) {
            grid[originX+i][originY] = new Cell();
        }
    } else if (direction()==1) {
        grid[originX][originY+3] = new Cell();
    }
}

void IBlock::drop(Board *board){
    while (canMoveDown()) {
        MoveDown();
    }
    return;
}

void IBlock::rotateClockwise(Board *board){
    if (!canRotateClockwise()) {
        return;
    }
    int originX = cells[0].getX();
    int originY = cells[0].getY();
    if (diretion()==0) {
        for (int i=1; i<4; ++i) {
            cells[i].setX(originX);
            cells[i].set
        }
    } else if (diretion()==1){
        
    }
}
