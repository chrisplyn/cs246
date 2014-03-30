
#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include "board.h"

class IBlock:public Block{
    Cell * cells[3];
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
    
    IBlock(Board& board, int level);
    ~IBlock();

};

#endif 