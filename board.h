#ifndef __BOARD_H__
#define __BOARD_H__



#include <iostream>
#include "window.h"

class Cell;
class Block;
class textDisplay;
class NextBlock;
class Score;

class Board{
    Xwindow *w;
    textDisplay *p;
    Cell ** grid;
    Block * currentBlock;
    Score * scoreBoard ;
    int level;
    NextBlock * nextBlock;
    int MaxDelete;
	std::string nextType;
	Block * setCurrentBlock(std::string &, int);
    void deleteRow(int numOfRow);
    bool isRowComplete(int numOfRow);
    int getMaxDelete();
    int isSpecial();

    Board(int ,int , Xwindow *w);
    static Board * instance;
    static void cleanup();


   public:
    Cell ** getGrid();
    void initialization(std::istream &);
    int getLevel();
    void notifyScore(int RowsDeleted);
    int deleteRows();
	void setInputStream(std::istream &input);
	void makeBlock();
    static Board * getInstance(int, int, Xwindow *); 
    bool isGameOver();  //return true if gameover, false otherwise
	void moveCurBlockRight();
	void moveCurBlockLeft();
	void rotateClockwise();
	void rotateAntiClockwise();
	void dropCurBlock();
	void moveCurBlockDown();
	
    void notifyDisplay();
    void displayall();
    void restart(int d_level);
	void levelUp();
	void levelDown();
    ~Board();
    //extrafeature
    void setMaxdelete(int maxdelte);
    void updatecelltimes();
    void deleteextra();
};



#endif
