#include "OBlock.h"

OBlock::OBlock(const Board& board){
    Cell *[4] cells;
    Cell ** grid = board.getGrid();
    
    //---------
    //| 2 | 3 |
    //---------
    //| 0 | 1 |
    //---------
    
    cells[0] = grid[0][13];
    cells[1] = grid[1][13];
    cells[2] = grid[0][14];
    cells[3] = grid[1][14];
    //cell should provide function setType
    cells[0].setType("O");
    cells[1].setType("O");
    cells[2].setType("O");
    cells[3].setType("O");
    //cell needs to provide addtoneighbour and deletefromneighbour;
    //also notify cell if their coordinates have changed
    cells[0].addToNeighbour(grid[1]);
    cells[0].addToNeighbour(grid[2]);
    cells[0].addToNeighbour(grid[3]);
    
    cells[1].addToNeighbour(grid[0]);
    cells[1].addToNeighbour(grid[2]);
    cells[1].addToNeighbour(grid[3]);
    
    cells[2].addToNeighbour(grid[0]);
    cells[2].addToNeighbour(grid[1]);
    cells[2].addToNeighbour(grid[3]);
    
    cells[3].addToNeighbour(grid[0]);
    cells[3].addToNeighbour(grid[1]);
    cells[3].addToNeighbour(grid[2]);
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
    if (ycoordinate==0) { //at the left edge
        return false;
    }
    if (grid[xcoordinate][ycoordinate-1].isOn()) {
        return false; //the left cell is pre-occupied
    }
    //check 1
    int xcoordinate = cells[1].getX();
    int ycoordinate = cells[1].getY();
    if (grid[xcoordinate][ycoordinate-1].isOn()) {
        return false; //the left cell is pre-occupied
    }
}

bool OBlock::canRotateClockwise(Board *board){
    return true;
}

bool OBlock::canRotateAntiClockwise(Board *board){
    return true;
}
