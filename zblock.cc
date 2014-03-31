#include "zblock.h"
#include "cell.h"

//direction:
// 0:             1:               2:
// -------------   -------------    -------------
// |   |   |   |   |   | 0 |   |    |   |   |   |
// -------------   -------------    -------------
// | 0 | 1 |   |   | 2 | 1 |   |    |   |   |   |
// -------------   -------------    -------------
// |   | 2 | 3 |   | 3 |   |   |    |   |   |   |
// -------------   -------------    -------------

int ZBlock::direction(){
    int originX = cells[0]->getX();
    int nextX = cells[1]->getX();
    if (originX==nextX) {
        return 0;
    } else {
        return 1;
    }
}

ZBlock::ZBlock(Board &board, int level){
    Cell **grid = board.getGrid();
    
    cells[0] = &grid[3][0];
    cells[1] = &grid[3][1];
    cells[2] = &grid[4][1];
    cells[3] = &grid[4][2];
    
    cells[0]->setLT("Z", level);
    cells[1]->setLT("Z", level);
    cells[2]->setLT("Z", level);
    cells[3]->setLT("Z", level);
    
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

bool ZBlock::canMoveLeft(Board *board){
    Cell **grid = board->getGrid();
    if (direction()==0) {
        //check0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (ycoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }

    } else {
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
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
    }
    return true;
}

bool ZBlock::canMoveRight(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==0) {
        //check3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (ycoordinate==9) {
            return false; // right edge
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check1
        xcoordinate = cells[1]->getX();
        ycoordinate = cells[1]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
    } else {
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
        //check 1
        xcoordinate = cells[1]->getX();
        ycoordinate = cells[1]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
    }
    return true;
}

bool ZBlock::canMoveDown(Board *board) {
    Cell **grid = board->getGrid();
    
    if (direction()==0) {
        //check 2
        int xcoordinate = cells[2]->getX();
        int ycoordinate = cells[2]->getY();
        if (xcoordinate==14) {
            return false; // bottom edge
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
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
    } else {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (xcoordinate==14) {
            return false; // bottom edge
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
    }
    return true;
}

bool ZBlock::canRotateClockwise(Board *board){
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    if (direction()==0) {
        if (grid[originX-1][originY+1].isOn()) return false;
        if (grid[originX+1][originY].isOn()) return false;
    } else {
        if (grid[originX+2][originY].isOn()) return false;
        if (grid[originX+2][originY+1].isOn()) return false;
    }
    return true;
}

bool ZBlock::canRotateAnticlockwise(Board *board) {
    return canRotateClockwise(board);
}

void ZBlock::moveLeft(Board *board) {
    
    if (!canMoveLeft(board)) return;
    Cell **grid = board->getGrid();
    
    if (direction()==0) {
        for (int i =0; i<4; ++i) {
            int coorX = cells[i]->getX();
            int coorY = cells[i]->getY();
            cells[i]->Swap(&grid[coorX][coorY-1]);
            cells[i] = &grid[coorX][coorY-1];
        }
    } else {
        for (int i =3; i>=0; --i) {
            int coorX = cells[i]->getX();
            int coorY = cells[i]->getY();
            cells[i]->Swap(&grid[coorX][coorY-1]);
            cells[i] = &grid[coorX][coorY-1];
        }
    }
}

void ZBlock::moveRight(Board *board) {
    if (!canMoveRight(board)) return;
    Cell **grid = board->getGrid();
    
    if (direction()==1) {
        for (int i =0; i<4; ++i) {
            int coorX = cells[i]->getX();
            int coorY = cells[i]->getY();
            cells[i]->Swap(&grid[coorX][coorY+1]);
            cells[i] = &grid[coorX][coorY+1];
        }
    } else {
        for (int i =3; i>=0; --i) {
            int coorX = cells[i]->getX();
            int coorY = cells[i]->getY();
            cells[i]->Swap(&grid[coorX][coorY+1]);
            cells[i] = &grid[coorX][coorY+1];

        }
    }
}

void ZBlock::moveDown(Board *board) {
    if (!canMoveDown(board)) return;
    Cell **grid = board->getGrid();
    for (int i =3; i>=0; --i) {
        int coorX = cells[i]->getX();
        int coorY = cells[i]->getY();
        cells[i]->Swap(&grid[coorX+1][coorY]);
        cells[i] = &grid[coorX+1][coorY];
    }
}

void ZBlock::drop(Board *board) {
    while (canMoveDown(board)) {
        moveDown(board);
    }
}

void ZBlock::rotateClockwise(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==0) {
        cells[0]->Swap(&grid[cells[0]->getX()-1][cells[0]->getY()+1]);
        cells[2]->Swap(&grid[cells[2]->getX()-1][cells[2]->getY()-1]);
        cells[3]->Swap(&grid[cells[3]->getX()][cells[3]->getY()-2]);
        cells[0] = &grid[cells[0]->getX()-1][cells[0]->getY()+1];
        cells[2] = &grid[cells[2]->getX()-1][cells[2]->getY()-1];
        cells[3] = &grid[cells[3]->getX()][cells[3]->getY()-2];
    } else {
        cells[3]->Swap(&grid[cells[3]->getX()][cells[3]->getY()+2]);
        cells[2]->Swap(&grid[cells[2]->getX()+1][cells[2]->getY()+1]);
        cells[0]->Swap(&grid[cells[0]->getX()+1][cells[0]->getY()-1]);
        cells[3] = &grid[cells[3]->getX()][cells[3]->getY()+2];
        cells[2] = &grid[cells[2]->getX()+1][cells[2]->getY()+1];
        cells[0] = &grid[cells[0]->getX()+1][cells[0]->getY()-1];

    }
}

void ZBlock::rotateAnticlockwise(Board *board) {
    rotateClockwise(board);
}