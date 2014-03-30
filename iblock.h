
#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"

class IBlock:public Block{
    Cell *[4] cells;
public:
    bool canMoveLeft(Board * board);
    bool canMoveRight(Board *board);
    bool canMoveDown(Board *board);
    bool canRotateClockwise(Board *board);
    bool canRotateAnticlockwise(Board *board);
    void rotateClockwise();
    void rotateAnticlockwise();
    void moveLeft();
    void moveRight();
    void drop();
    
    IBlock(const Board& board);
    ~IBlock();

};

#endif 