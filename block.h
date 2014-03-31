#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <string>
#include "cell.h"
#include "board.h"


class Block{
protected:
    Cell *cells[4];
    //std::string type;
public:
    //std::string getType();
    virtual bool canMoveLeft(Board *)=0;
    virtual bool canMoveRight(Board *)=0;
    virtual bool canMoveDown(Board *)=0;
    virtual bool canRotateClockwise(Board *)=0;
    virtual bool canRotateAnticlockwise(Board *)=0;
	virtual void rotateClockwise(Board *) = 0;
	virtual void rotateAnticlockwise(Board *) = 0;
	virtual void moveLeft(Board *) = 0;
	virtual void moveRight(Board *) = 0;
	virtual void drop(Board *) = 0;
    
    Block();
};



#endif /* defined(____block__) */
