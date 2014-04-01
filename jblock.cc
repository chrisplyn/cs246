
#include "jblock.h"
#include "cell.h"
using namespace std;

//direction:
// 0:              1:               2:               3:
// -------------    -------------    -------------    -------------
// |   |   |   |    | 1 | 0 |   |    |   |   |   |    |   | 3 |   |
// -------------    -------------    -------------    -------------
// | 0 |   |   |    | 2 |   |   |    | 3 | 2 | 1 |    |   | 2 |   |
// -------------    -------------    -------------    -------------
// | 1 | 2 | 3 |    | 3 |   |   |    |   |   | 0 |    | 0 | 1 |   |
// -------------    -------------    -------------    -------------

int JBlock::direction() {
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    int nextX = cells[1]->getX();
    int nextY = cells[1]->getY();
    
    if (originX == nextX) {
        if (originY == nextY-1) {
            return 3;
        } else {
            return 1;
        }
    } else if (originX == nextX-1) {
        return 0;
    } else {
        return 2;
    }
}

JBlock::JBlock(Board &board, int level):Block() {
    Cell **grid = board.getGrid();
    
    cells[0] = &grid[3][0];
    cells[1] = &grid[4][0];
    cells[2] = &grid[4][1];
    cells[3] = &grid[4][2];
    
    cells[0]->setLT("J", level,1);
    cells[1]->setLT("J", level,1);
    cells[2]->setLT("J", level,1);
    cells[3]->setLT("J", level,1);
    
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

bool JBlock::canMoveLeft(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==2) {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (ycoordinate==0) { //at the left edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
    } else if (direction()==1) {
        //check 1
        int xcoordinate = cells[1]->getX();
        int ycoordinate = cells[1]->getY();
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
            return false; //the left cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
        
    } else if (direction()==0) {
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
    } else {
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
            return false; //the left cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate-1].isOn()) {
            return false; //the left cell is pre-occupied
        }
    }
    return true;
}

bool JBlock::canMoveRight(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==0) {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (ycoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
    } else if (direction()==3) {
        //check 1
        int xcoordinate = cells[1]->getX();
        int ycoordinate = cells[1]->getY();
        if (ycoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        
    } else if (direction()==2) {
        //check 1
        int xcoordinate = cells[1]->getX();
        int ycoordinate = cells[1]->getY();
        if (ycoordinate==9) { //at the right edge
            return false;
        }
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
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
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate][ycoordinate+1].isOn()) {
            return false; //the right cell is pre-occupied
        }
    }
    return true;
    
}

bool JBlock::canMoveDown(Board *board) {
    Cell **grid = board->getGrid();
    if (direction()==1) {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
        if (xcoordinate==14) { //at the bottom edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
        //check 0
        xcoordinate = cells[0]->getX();
        ycoordinate = cells[0]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
    } else if (direction()==0) {
        //check 3
        int xcoordinate = cells[3]->getX();
        int ycoordinate = cells[3]->getY();
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
        
    } else if (direction()==3) {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (xcoordinate==14) { //at the bottom edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
        //check 1
        xcoordinate = cells[1]->getX();
        ycoordinate = cells[1]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the left cell is pre-occupied
        }
    } else {
        //check 0
        int xcoordinate = cells[0]->getX();
        int ycoordinate = cells[0]->getY();
        if (xcoordinate==14) { //at the lower edge
            return false;
        }
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
        //check 2
        xcoordinate = cells[2]->getX();
        ycoordinate = cells[2]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
        //check 3
        xcoordinate = cells[3]->getX();
        ycoordinate = cells[3]->getY();
        if (grid[xcoordinate+1][ycoordinate].isOn()) {
            return false; //the lower cell is pre-occupied
        }
    }
    return true;
}

bool JBlock::canRotateClockwise(Board *board) {
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    if (direction()==0) {
        if (grid[originX-1][originY+1].isOn()) return false;
        if (grid[originX-1][originY].isOn()) return false;
    } else if (direction()==1) {
        if (originY==9) return false;
        if (grid[originX+1][originY].isOn()) return false;
        if (grid[originX+1][originY+1].isOn()) return false;
        if (grid[originX+2][originY+1].isOn()) return false;
    } else if (direction()==2) {
        if (grid[originX-2][originY-1].isOn()) return false;
        if (grid[originX][originY-1].isOn()) return false;
        if (grid[originX][originY-2].isOn()) return false;
    } else {
        if (originY==8) return false;
        if (grid[originX-1][originY].isOn()) return false;
        if (grid[originX][originY+2].isOn()) return false;
    }
    return true;
}

bool JBlock::canRotateAnticlockwise(Board *board) {
    Cell **grid = board->getGrid();
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    
    if (direction()==0) {
        if (grid[originX][originY+1].isOn()) return false;
        if (grid[originX-1][originY+1].isOn()) return false;
    } else if (direction()==1) {
        if (originY==9) return false;
        if (grid[originX+2][originY].isOn()) return false;
        if (grid[originX+2][originY+1].isOn()) return false;
    } else if (direction()==2) {
        if (grid[originX][originY-2].isOn()) return false;
        if (grid[originX-2][originY-2].isOn()) return false;
        if (grid[originX-2][originY-1].isOn()) return false;
    } else {
        if (originY==8) return false;
        if (grid[originX][originY+2].isOn()) return false;
        if (grid[originX-1][originY].isOn()) return false;
        if (grid[originX-1][originY+2].isOn()) return false;
    }
    return true;
}

void JBlock::moveLeft(Board *board) {
    if (!canMoveLeft(board)) return;
    Cell **grid = board->getGrid();
    
    if (direction()==0 || direction()==3) {
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

void JBlock::moveRight(Board *board){
    if (!canMoveRight(board)) return;
    Cell **grid = board->getGrid();
    
    if (direction()==1 || direction()==2) {
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

void JBlock::moveDown(Board *board ) {
    if (!canMoveDown(board)) return;
    Cell **grid = board->getGrid();

    if (direction()==2 || direction()==3) {
   
        if (direction()==2 || direction()==3) {

        for (int i =0; i<4; ++i) {
            int coorX = cells[i]->getX();
            int coorY = cells[i]->getY();
            cells[i]->Swap(&grid[coorX+1][coorY]);
            cells[i] = &grid[coorX+1][coorY];
        }
    } else {
        for (int i = 3; i>=0; --i) {
            int coorX = cells[i]->getX();
            int coorY = cells[i]->getY();
            cells[i]->Swap(&grid[coorX+1][coorY]);
            cells[i] = &grid[coorX+1][coorY];
        }
    }
    }
}
void JBlock::drop(Board *board) {
    while (canMoveDown(board)) {
        moveDown(board);
    }
}

void JBlock::rotateClockwise(Board *board) {
    if (!canRotateClockwise(board)) return;
    Cell **grid = board->getGrid();
    
    if (direction()==0) {
        cells[0]->Swap(&grid[cells[0]->getX()-1][cells[0]->getY()+1]);
        cells[1]->Swap(&grid[cells[1]->getX()-2][cells[1]->getY()]);
        cells[2]->Swap(&grid[cells[2]->getX()-1][cells[2]->getY()-1]);
        cells[3]->Swap(&grid[cells[3]->getX()][cells[3]->getY()-2]);
        
        cells[0] = &grid[cells[0]->getX()-1][cells[0]->getY()+1];
        cells[1] = &grid[cells[1]->getX()-2][cells[1]->getY()];
        cells[2] = &grid[cells[2]->getX()-1][cells[2]->getY()-1];
        cells[3] = &grid[cells[3]->getX()][cells[3]->getY()-2];

    } else if (direction()==1) {
        cells[0]->Swap(&grid[cells[0]->getX()+2][cells[0]->getY()+1]);
        cells[1]->Swap(&grid[cells[1]->getX()+1][cells[1]->getY()+2]);
        cells[2]->Swap(&grid[cells[2]->getX()][cells[2]->getY()+1]);
        cells[3]->Swap(&grid[cells[3]->getX()-1][cells[3]->getY()]);
        
        cells[0] = &grid[cells[0]->getX()+2][cells[0]->getY()+1];
        cells[1] = &grid[cells[1]->getX()+1][cells[1]->getY()+2];
        cells[2] = &grid[cells[2]->getX()][cells[2]->getY()+1];
        cells[3] = &grid[cells[3]->getX()-1][cells[3]->getY()];
        
    } else if (direction()==2) {
        cells[0]->Swap(&grid[cells[0]->getX()][cells[0]->getY()-2]);
        cells[1]->Swap(&grid[cells[1]->getX()+1][cells[1]->getY()-1]);
        cells[3]->Swap(&grid[cells[3]->getX()-1][cells[3]->getY()+1]);
        
        cells[0] = &grid[cells[0]->getX()][cells[0]->getY()-2];
        cells[1] = &grid[cells[1]->getX()+1][cells[1]->getY()-1];
        cells[3] = &grid[cells[3]->getX()-1][cells[3]->getY()+1];
        
    } else {
        cells[0]->Swap(&grid[cells[0]->getX()-1][cells[0]->getY()]);
        cells[1]->Swap(&grid[cells[1]->getX()][cells[1]->getY()-1]);
        cells[2]->Swap(&grid[cells[2]->getX()+1][cells[2]->getY()]);
        cells[3]->Swap(&grid[cells[3]->getX()+2][cells[3]->getY()+1]);
        
        cells[0] = &grid[cells[0]->getX()-1][cells[0]->getY()];
        cells[1] = &grid[cells[1]->getX()][cells[1]->getY()-1];
        cells[2] = &grid[cells[2]->getX()+1][cells[2]->getY()];
        cells[3] = &grid[cells[3]->getX()+2][cells[3]->getY()+1];
    }
}

void JBlock::rotateAnticlockwise(Board *board) {
    if (!canRotateAnticlockwise(board)) return;
    Cell **grid = board->getGrid();
    
    if (direction()==0) {
        cells[3]->Swap(&grid[cells[3]->getX()-2][cells[3]->getY()-1]);
        cells[2]->Swap(&grid[cells[2]->getX()-1][cells[2]->getY()]);
        cells[1]->Swap(&grid[cells[1]->getX()][cells[1]->getY()+1]);
        cells[0]->Swap(&grid[cells[0]->getX()+1][cells[0]->getY()]);
        
        cells[3] = &grid[cells[3]->getX()-2][cells[3]->getY()-1];
        cells[2] = &grid[cells[2]->getX()-1][cells[2]->getY()];
        cells[1] = &grid[cells[1]->getX()][cells[1]->getY()+1];
        cells[0] = &grid[cells[0]->getX()+1][cells[0]->getY()];
    } else if (direction()==1) {
        cells[3]->Swap(&grid[cells[3]->getX()][cells[3]->getY()+2]);
        cells[2]->Swap(&grid[cells[2]->getX()+1][cells[2]->getY()+1]);
        cells[1]->Swap(&grid[cells[1]->getX()+2][cells[1]->getY()]);
        cells[0]->Swap(&grid[cells[0]->getX()+1][cells[0]->getY()-1]);
        
        cells[3] = &grid[cells[3]->getX()][cells[3]->getY()+2];
        cells[2] = &grid[cells[2]->getX()+1][cells[2]->getY()+1];
        cells[1] = &grid[cells[1]->getX()+2][cells[1]->getY()];
        cells[0] = &grid[cells[0]->getX()+1][cells[0]->getY()-1];
        
    } else if (direction()==2) {
        cells[3]->Swap(&grid[cells[3]->getX()+1][cells[3]->getY()]);
        cells[2]->Swap(&grid[cells[2]->getX()][cells[2]->getY()-1]);
        cells[1]->Swap(&grid[cells[1]->getX()-1][cells[1]->getY()-2]);
        cells[0]->Swap(&grid[cells[0]->getX()-2][cells[0]->getY()-1]);
        
        cells[3] = &grid[cells[3]->getX()+1][cells[3]->getY()];
        cells[2] = &grid[cells[2]->getX()][cells[2]->getY()-1];
        cells[1] = &grid[cells[1]->getX()-1][cells[1]->getY()-2];
        cells[0] = &grid[cells[0]->getX()-2][cells[0]->getY()-1];

    } else {
        cells[3]->Swap(&grid[cells[3]->getX()+1][cells[3]->getY()-1]);
        cells[1]->Swap(&grid[cells[1]->getX()-1][cells[1]->getY()+1]);
        cells[0]->Swap(&grid[cells[0]->getX()][cells[0]->getY()+2]);
        
        cells[3] = &grid[cells[3]->getX()+1][cells[3]->getY()-1];
        cells[1] = &grid[cells[1]->getX()-1][cells[1]->getY()+1];
        cells[0] = &grid[cells[0]->getX()][cells[0]->getY()+2];
    }
}
