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
	std::string nextType;
	Block * setCurrentBlock(std::string &);

   public:
    Board();
    Board(int Level);
    Cell ** getGrid();
    int getLevel();
    int getMaxDelete();

	void setInputStream(std::istream &input);
	void makeBlock();//change here
    //Board * getInstance();//not

	void moveCurBlockRight();
	void moveCurBlockLeft();
	void rotateClockwise();
	void rotateAntiClockwise();
	void dropCurBlock();
	void moveCurBlockDown();
	
    void notifyScore(int RowsDeleted);
    void deleteRow(int numOfRow);
    bool isRowComplete(int numOfRow);
    
    void notifyDisplay();
    int deleteRows();
	friend std::ostream &operator<<(std::ostream &out, const Board &b);
    //new added
    void displayall();
    void restart(int d_level);
    void setLevel(int n_level);
    ~Board();//not
};



#endif
