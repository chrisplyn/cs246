

#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include "block.h"
#include "cell.h"
#include "board.h"
#include <string>

class OBlock : public Block{
    Cell * cells[4];
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
    
    OBlock(Board& board, int level);
    ~OBlock();
    
};

#endif