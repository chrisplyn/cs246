
#include "lblock.h"

//direction:
// 0:              1:               2:               3:
// -------------    -------------    -------------    -------------
// |   |   |   |    | 0 |   |   |    |   |   |   |    | 3 | 2 |   |
// -------------    -------------    -------------    -------------
// |   |   | 3 |    | 1 |   |   |    | 2 | 1 | 0 |    |   | 1 |   |
// -------------    -------------    -------------    -------------
// | 0 | 1 | 2 |    | 2 | 3 |   |    | 3 |   |   |    |   | 0 |   |
// -------------    -------------    -------------    -------------

int LBlock::direction() {
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    int nextX = cells[1]->getX();
    int nextY = cells[1]->getY();
    
    if (originX == nextX) {
        if (originY == nextY-1) {
            return 0;
        } else {
            return 2;
        }
    } else if (originX == nextX-1) {
        return 1;
    } else {
        return 3;
    }
}

LBlock::LBlock(Board &board, int level):Block() {
    Cell **grid = board.getGrid();
    
    cells[0] = &grid[4][0];
    cells[1] = &grid[4][1];
    cells[2] = &grid[4][2];
    cells[3] = &grid[3][2];
    
    cells[0]->setLT("L", level);
    cells[1]->setLT("L", level);
    cells[2]->setLT("L", level);
    cells[3]->setLT("L", level);
    
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

bool LBlock::canMoveLeft(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==0) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (ycoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
    } else if (direction()==1) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (ycoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 1
        xcoordinate = cells[1]->getX();
        ycoordinate = cells[1]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        
    } else if (direction()==2) {
        //check 2
        int xcoordinate = cells[2]->getX();
        int ycoordinate = cells[2]->getY();
        if (ycoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
    } else {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (ycoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 1
        xcoordinate = cells[1]->getX();
        ycoordinate = cells[1]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
    }
    return true;
}

bool LBlock::canMoveRight(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==2) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (ycoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
    } else if (direction()==3) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (ycoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 1
        xcoordinate = cells[1]->getX();
        ycoordinate = cells[1]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        
    } else if (direction()==0) {
        //check 2
        int xcoordinate = cells[2]->getX();
        int ycoordinate = cells[2]->getY();
        if (ycoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
    } else {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (ycoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 1
        xcoordinate = cells[1]->getX();
        ycoordinate = cells[1]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
    }
    return true;

}

bool LBlock::canMoveDown(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==3) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (xcoordinate==14) { //at the bottom edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
    } else if (direction()==0) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (xcoordinate==14) { //at the bottom edge
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
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
        
    } else if (direction()==1) {
        //check 2
        int xcoordinate = cells[2]->getX();
        int ycoordinate = cells[2]->getY();
        if (xcoordinate==14) { //at the bottom edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
    } else {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
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
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
    }
    return true;
}

bool LBlock::canRotateClockwise(Board *board) {
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    
    if (direction()==0) {
        if (grid[originX-2][originY].isOn()) return false;
        if (grid[originX-1][originY].isOn()) return false;
    } else if (direction()==1) {
        if (grid[originX-1][originY+1].isOn()) return false;
        if (grid[originX-1][originY+2].isOn()) return false;
    } else if (direction()==2) {
        if (grid[originX-1][originY-2].isOn()) return false;
        if (grid[originX-1][originY-1].isOn()) return false;
        if (grid[originX+1][originY-1].isOn()) return false;
    } else {
        if (grid[originX][originY-1].isOn()) return false;
        if (grid[originX][originY+1].isOn()) return false;
        if (grid[originX-1][originY+1].isOn()) return false;
    }
    return true;
}

bool LBlock::canRotateAnticlockwise(Board *board) {
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    
    if (direction()==0) {
        if (grid[originX-2][originY].isOn()) return false;
        if (grid[originX-2][originY+1].isOn()) return false;
        if (grid[originX-1][originY+1].isOn()) return false;
    } else if (direction()==1) {
        if (grid[originX+2][originY+2].isOn()) return false;
        if (grid[originX+1][originY+2].isOn()) return false;
    } else if (direction()==2) {
        if (grid[originX-1][originY-2].isOn()) return false;
        if (grid[originX+1][originY-2].isOn()) return false;
    } else {
        if (grid[originX-1][originY+1].isOn()) return false;
        if (grid[originX-1][originY-1].isOn()) return false;
        if (grid[originX-2][originY].isOn()) return false;
    }
    return true;
}