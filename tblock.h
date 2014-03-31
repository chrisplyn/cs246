
#ifndef __TBLOCK_H__
#define __TBLOCK_H__

#include "block.h"
#include "board.h"

class TBlock:public Block{
    Cell * cells[4];
    int direction();
public:
    bool canMoveLeft(Board * board);
    bool canMoveRight(Board *board);
    bool canMoveDown(Board *board);
    bool canRotateClockwise(Board *board);
    bool canRotateAnticlockwise(Board *board);
    void rotateClockwise(Board *board);
    void rotateAnticlockwise(Board *board);
    void moveLeft(Board *board);
    void moveRight(Board *board);
    void moveDown(Board *board);
    void drop(Board *board);
    
    TBlock(Board& board, int level);
    //~TBlock();
    
};

#endif
