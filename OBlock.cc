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
    
    cells[0] = &grid[4][0];
    cells[1] = &grid[4][1];
    cells[2] = &grid[3][0];
    cells[3] = &grid[3][1];
    
    //cells are set to corresponding type and level
    cells[0]->setLT("O", level);
    cells[1]->setLT("O", level);
    cells[2]->setLT("O", level);
    cells[3]->setLT("O", level);
    
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
    int xcoordinate = cells[0]->getX();
    int ycoordinate = cells[0]->getY();
    if (ycoordinate==0) { //at the left edge
        return false;
    }
    if (grid[xcoordinate][ycoordinate-1].isOn()) {
        return false; //the left cell is pre-occupied
    }
    
    //check 2
    xcoordinate = cells[2]->getX();
    ycoordinate = cells[2]->getY();
    if (grid[xcoordinate][ycoordinate-1].isOn()) {
        return false;
    }
    
    return true;
}

bool OBlock::canMoveRight(Board *board){
    
    Cell **grid = board->getGrid();
    
    //check 1
    int xcoordinate = cells[1]->getX();
    int ycoordinate = cells[1]->getY();
    if (ycoordinate==9) { //at the left edge
        return false;
    }
    if (grid[xcoordinate][ycoordinate+1].isOn()) {
        return false; //the left cell is pre-occupied
    }
    
    //check 3
    xcoordinate = cells[3]->getX();
    ycoordinate = cells[3]->getY();
    if (grid[xcoordinate][ycoordinate+1].isOn()) {
        return false;
    }
    
    return true;
}

bool OBlock::canMoveDown(Board *board){
    Cell **grid = board->getGrid();
    
    //check 0
    int xcoordinate = cells[0]->getX();
    int ycoordinate = cells[0]->getY();
    if (xcoordinate==14) { //at the lower edge
        return false;
    }
    if (grid[xcoordinate+1][ycoordinate].isOn()) {
        return false; //the lower cell is pre-occupied
    }
    //check 1
    xcoordinate = cells[1]->getX();
    ycoordinate = cells[1]->getY();
    if (grid[xcoordinate+1][ycoordinate].isOn()) {
        return false; //the lower cell is pre-occupied
    }
    return true;
}

bool OBlock::canRotateClockwise(Board *board){
    return true;
}

bool OBlock::canRotateAnticlockwise(Board *board){
    return true;
}

void OBlock::rotateClockwise(Board *board){
    return;
}

void OBlock::rotateAnticlockwise(Board *board){
    return;
}

void swap(int x, int y, Board *board){
    
}
void OBlock::moveLeft(Board *board){
    if (!canMoveLeft(board)) {
        return;
    }
    Cell **grid = board->getGrid();
    cells[2] -> Swap(&grid[cells[2]->getX()][cells[2]->getY()-1]);
    cells[0] -> Swap(&grid[cells[0]->getX()][cells[0]->getY()-1]);
    cells[1] -> Swap(&grid[cells[1]->getX()][cells[1]->getY()-1]);
    cells[3] -> Swap(&grid[cells[3]->getX()][cells[3]->getY()-1]);
}

void OBlock::moveRight(Board *board){
    if (!canMoveRight(board)) {
        return;
    }
    Cell **grid = board->getGrid();
    
    cells[1] -> Swap(&grid[cells[1]->getX()][cells[1]->getY()+1]);
    cells[3] -> Swap(&grid[cells[3]->getX()][cells[3]->getY()+1]);
    cells[2] -> Swap(&grid[cells[2]->getX()][cells[2]->getY()+1]);
    cells[0] -> Swap(&grid[cells[0]->getX()][cells[0]->getY()+1]);
    
}

void OBlock::moveDown(Board *board){
    if (!canMoveDown(board)) {
        return;
    }
    
    Cell **grid = board->getGrid();
    
    for (int i =0; i<4; ++i) {
        int coorX = cells[i]->getX();
        int coorY = cells[i]->getY();
        cells[i]->Swap(&grid[coorX+1][coorY]);
    }
}

void OBlock::drop(Board *board){
    while (canMoveDown(board)) {
        moveDown(board);
    }
    return;
}
