
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <string>
#include "cell.h"
#include "board.h"

class Block{
protected:
<<<<<<< HEAD
    Cell *cells[4];
=======
>>>>>>> 4b5b46fdde35fb040b9c1b5a7cc237b2c7b24fd5
    std::string type;
public:
    std::string getType();
    virtual bool canMoveLeft(Board *board);
    virtual bool canMoveRight(Board *board);
    virtual bool canMoveDown(Board *board);
    virtual bool canRotateClockwise(Board *board);
    virtual bool canRotateAnticlockwise(Board *board);
    virtual void rotateClockwise();
    virtual void rotateAnticlockwise();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void drop();
    
    Block(std::string type);
    virtual ~Block()=0;
};



#endif /* defined(____block__) */
