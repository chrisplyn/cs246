#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include "block.h"
#include "board.h"

class LBlock:public Block{
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
    
    LBlock(Board& board, int level);
};
#endif
