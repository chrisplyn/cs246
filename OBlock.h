

#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include "block.h"
#include "cell.h"
#include "board.h"
#include <string>

class OBlock : public Block{
    Cell *[4] cells;
    int level;
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
    
    OBlock(Board& board, int level);
    ~OBlock();
    
};

#endif