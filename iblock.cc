
#include "iblock.h"
#include "cell.h"
using namespace std;

IBlock::IBlock(Board& board, int level):Block(){
    
    Cell ** grid = board.getGrid();
    
    //-----------------
    //| 0 | 1 | 2 | 3 |
    //-----------------
    
    cells[0] = &grid[3][0];
    cells[1] = &grid[3][1];
    cells[2] = &grid[3][2];
    cells[3] = &grid[3][3];
    
    cells[0]->setLT("I", level);
    cells[1]->setLT("I", level);
    cells[2]->setLT("I", level);
    cells[3]->setLT("I", level);
    
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
int IBlock::direction(){
    int originX = cells[0]->getX(); //number of row
    int nextX = cells[1]->getX();
    if (originX==nextX) {
        return 0;
    } else {
        return 1;
    }
}

bool IBlock::canMoveLeft(Board *board){
    Cell **grid = board->getGrid();
    
    //check 0
    int xcoordinate = cells[0]->getX();
    int ycoordinate = cells[0]->getY();
    if (ycoordinate==0) { //at the left edge
        return false;
    }
    if (grid[xcoordinate][ycoordinate-1].isOn()) {
        return false; //the left cell is pre-occupied
    }
    return true;
}

bool IBlock::canMoveRight(Board *board){
    Cell **grid = board->getGrid();
    
    //check 3
    int xcoordinate = cells[3]->getX();
    int ycoordinate = cells[3]->getY();
    if (ycoordinate==9) { //at the left edge
        return false;
    }
    if (grid[xcoordinate][ycoordinate+1].isOn()) {
        return false; //the left cell is pre-occupied
    }
    return true;
}

bool IBlock::canMoveDown(Board *board){
    Cell **grid = board->getGrid();
    
    //check 0
    int xcoordinate = cells[0]->getX();
    int ycoordinate = cells[0]->getY();
    if (xcoordinate==14) { //at the lower edge
        return false;
    }
    
    for (int i=0; i<4; ++i) {
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false;
        }
    }
    return true;
}

bool IBlock::canRotateClockwise(Board *board){
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    
    if (direction()==0) { //horizontal to vertical
        for (int i=1; i<=3; ++i) {
            if (grid[originX-i][originY].isOn()) {
                return false;
            }
        }
        
    } else if (direction()==1) { //vertical to horizontal
        for (int i=1; i<=3; ++i) {
            if (grid[originX][originY+i].isOn()) {
                return false;
            }
        }
    }
    return true;
}

bool IBlock::canRotateAnticlockwise(Board *board){
    return canRotateClockwise(board);
}

void IBlock::moveLeft(Board *board){
    
    if (!canMoveLeft(board)) {
        return;
    }
    
    Cell **grid = board->getGrid();
    for (int i =0; i<4; ++i) {
        int coorX = cells[i]->getX();
        int coorY = cells[i]->getY();
        cells[i]->Swap(&grid[coorX][coorY-1]);
    }
}

void IBlock::moveRight(Board *board){
    
    if (!canMoveRight(board)) {
        return;
    }
    
    Cell **grid = board->getGrid();
    for (int i =3; i>=0; ++i) {
        int coorX = cells[i]->getX();
        int coorY = cells[i]->getY();
        cells[i]->Swap(&grid[coorX][coorY+1]);
    }
}

void IBlock::moveDown(Board *board){
    if (!Block::canMoveDown(board)) {
        return;
    }
    Cell **grid = board->getGrid();
    for (int i =0; i<4; ++i) {
        int coorX = cells[i]->getX();
        int coorY = cells[i]->getY();
        cells[i]->Swap(&grid[coorX+1][coorY]);
    }
}

void IBlock::drop(Board *board){
    while (canMoveDown(board)) {
        moveDown(board);
    }
    return;
}

void IBlock::rotateClockwise(Board *board){
    if (!canRotateClockwise(board)) {
        return;
    }
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    Cell **grid = board->getGrid();
    for (int i=1; i<4; ++i) {
        int diffX = cells[i]->getX()-originX;
        int diffY = cells[i]->getY()-originY;
        cells[i]->Swap(&grid[originX-diffY][originY-diffX]);
    }
}

void IBlock::rotateAnticlockwise(Board *board){
    rotateClockwise(board);
}
