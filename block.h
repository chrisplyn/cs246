
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <string>
#include "cell.h"
#include "board.h"

class Block{
protected:
    Cell * cells;
    std::string type;
public:
    std::string getType();
    bool canMoveLeft(Board * board);
    bool canMoveRight(Board *board);
    bool canRotateClockwise(Board *board);
    bool canRotateAnticlockwise(Board *board);
    void rotateClockwise();
    void rotateAnticlockwise();
    void moveLeft();
    void moveRight();
    void drop();
};



#endif /* defined(____block__) */
