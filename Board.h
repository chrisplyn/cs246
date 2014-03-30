#ifndef __Board_H__
#define __Board_H__
#include "cell.h"

class Board{
    Display *p;
    Cell ** grid;
    Block * currentBlock;
    Score * scoreBoard ;
    int level;
    NextBlock * nextBlock;
    int MaxDelete;
   public:
    Board();
    Board(int Level);
    Cell **getGrid();
    int getLevel();
    int getMaxDelete();
    Board * getInstance();
    void notifyScore(int curLevel,int RowsDeleted);
    void deleteRow(int numOfRow);
    bool isRowComplete(int numOfRow);
    void notifyDisplay();
    int deleteRows();
    void deleteBlock();
    ~Board();
};



#endif
