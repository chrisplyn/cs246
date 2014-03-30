#include "tblock.h"
#include "cell.h"
using namespace std;

//direction:
//
// 0:             1:                 2:                  3:
//-------------       -------------      -------------        -------------
//|   |   |   |       | 0 |   |   |      |   |   |   |        |   | 2 |   |
//-------------       -------------      -------------        -------------
//|   | 3 |   |       | 1 | 3 |   |      | 2 | 1 | 0 |        | 3 | 1 |   |
//-------------       -------------      -------------        -------------
//| 0 | 1 | 2 |       | 2 |   |   |      |   | 3 |   |        |   | 0 |   |
//-------------       -------------      -------------        -------------
//

int TBlock::direction(){
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    int nextX = cells[1]->getX();
    int nextY = cells[1]->getY();
    
    if (originX == nextX-1) {
        return 0;
    } else if (originX == nextX+1) {
        return 2;
    } else {
        if (originY == nextY+1) {
            return 1;
        }
        else {
            return 3;
        }
    }
}

TBlock::TBlock(Board &board, int level):Block(){
    
    Cell ** grid = board.getGrid();

    cells[0] = &grid[0][13];
    cells[1] = &grid[1][13];
    cells[2] = &grid[2][13];
    cells[3] = &grid[1][14];
    
    cells[0]->setLT("T", level);
    cells[1]->setLT("T", level);
    cells[2]->setLT("T", level);
    cells[3]->setLT("T", level);
    
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

bool TBlock::canMoveLeft(Board *board){
    Cell **grid = board->getGrid();
    if (direction()==0) {
        //check 2
        int xcoordinate = cells[2]->getX();
        int ycoordinate = cells[2]->getY();
        if (xcoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate-1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate-1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
    } else if (direction()==1) {
        for (int i=0; i<3; ++i) {
            int xcoordinate = cells[0]->getX();
            int ycoordinate = cells[0]->getY();
            if (xcoordinate==0) { //at the left edge
                return false;
            }
            if (grid[xcoordinate-1][ycoordinate].isOn()) {
                return false; //the left cell is pre-occupied
            }
        }
        
    } else if (direction()==2) {
        //check 2
        int xcoordinate = cells[2]->getX();
        int ycoordinate = cells[2]->getY();
        if (xcoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate-1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate-1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
    } else {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (xcoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate-1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate-1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate-1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
        
    }
    return true;
}

bool TBlock::canMoveRight(Board *board){
    Cell **grid = board->getGrid();
    if (direction()==0) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (xcoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the right cell is pre-occupied
        }
    } else if (direction()==3) {
        for (int i=0; i<3; ++i) {
            int xcoordinate = cells[0]->getX();
            int ycoordinate = cells[0]->getY();
            if (xcoordinate==9) { //at the right edge
                return false;
            }
            if (grid[xcoordinate+1][ycoordinate].isOn()) {
                return false; //the right cell is pre-occupied
            }
        }
        
    } else if (direction()==2) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (xcoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the right cell is pre-occupied
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
        if (xcoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the right cell is pre-occupied
        }
        
    }
    return true;
}

bool TBlock::canMoveDown(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==3) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (ycoordinate==0) { //at the lower edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the lower cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the lower cell is pre-occupied
        }
    } else if (direction()==0) {
        for (int i=0; i<3; ++i) {
            int xcoordinate = cells[0]->getX();
            int ycoordinate = cells[0]->getY();
            if (ycoordinate==0) { //at the lower edge
                return false;
            }
            if (grid[xcoordinate][ycoordinate-1].isOn()) {
                return false; //the lower cell is pre-occupied
            }
        }
        
    } else if (direction()==1) {
        //check 2
        int xcoordinate = cells[2]->getX();
        int ycoordinate = cells[2]->getY();
        if (ycoordinate==0) { //at the lower edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the lower cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the lower cell is pre-occupied
        }
    } else {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (ycoordinate==0) { //at the lower edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
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

bool TBlock::canRotateClockwise(Board *board) {
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[1]->getY();
    
    if (direction()==0) {
        if (grid[originX][originY+1].isOn()) return false;
        if (grid[originX][originY+2].isOn()) return false;
    } else if (direction()==1) {
        if (grid[originX+2][originY-1].isOn()) return false;
        if (grid[originX+1][originY-2].isOn()) return false;
    } else if (direction()==2) {
        if (grid[originX-1][originY+1].isOn()) return false;
    } else {
        if (grid[originX-1][originY].isOn()) return false;
        if (grid[originX+1][originY].isOn()) return false;
    }
    return true;
}

bool TBlock::canRotateAnticlockwise(Board *board) {
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[1]->getY();

    if (direction()==0) {
        if (grid[originX][originY+1].isOn()) return false;
        if (grid[originX+1][originY+2].isOn()) return false;
    } else if (direction()==1) {
        if (grid[originX+1][originY-2].isOn()) return false;
        if (grid[originX+2][originY-2].isOn()) return false;
    } else if (direction()==2) {
        if (grid[originX-2][originY+1].isOn()) return false;
        if (grid[originX-2][originY-1].isOn()) return false;
    } else {
        if (grid[originX+1][originY+1].isOn()) return false;
    }
    return true;
}

