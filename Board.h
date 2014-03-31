#ifndef __BOARD_H__
#define __BOARD_H__



#include <iostream>
class Cell;
class Block;
class Display;
class NextBlock;
class Score;

class Board{
    Display *p;
    Cell ** grid;
    Block * currentBlock;
    Score * scoreBoard ;
    int level;
    NextBlock * nextBlock;
    int MaxDelete;
	Block * setCurrentBlock(std::string &);

   public:
    Board();
    Board(int Level);
    Cell ** getGrid();
    int getLevel();
    int getMaxDelete();

	void setInputStream(std::istream &input);
	void makeBlock();
    //Board * getInstance();//not

	void moveCurBlockRight();
	void moveCurBlockLeft();
	void rotateClockwise();
	void rotateAntiClockwise();
	void dropCurBlock();
	void moveCurBlockDown();
	
    void notifyScore(int curLevel,int RowsDeleted);
    void deleteRow(int numOfRow);
    bool isRowComplete(int numOfRow);
    
    void notifyDisplay();
    int deleteRows();
    void changeBlock();
	friend std::ostream &operator<<(std::ostream &out, const Board &b);

    ~Board();//not
};



#endif
