#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include "block.h"

class ZBlock:public Block{
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
    
    ZBlock(Board& board, int level, int);
    
};
#endif
