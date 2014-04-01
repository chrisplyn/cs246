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
    void deleteRow(int numOfRow);
    bool isRowComplete(int numOfRow);
    int getMaxDelete();
    Board(int);
    static Board * instance;
    static void cleanup();


   public:
<<<<<<< HEAD:Board.h
    //Board();
    Board(int Level,int maxdelte);
=======
>>>>>>> FETCH_HEAD:board.h
    Cell ** getGrid();
    void initialization(std::istream &);
    int getLevel();
    void notifyScore(int RowsDeleted);
    int deleteRows();
	void setInputStream(std::istream &input);
	void makeBlock();
    static Board * getInstance(int); 
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
<<<<<<< HEAD:Board.h
    bool isGameOver();
    //void setLevel(int n_level);
=======
>>>>>>> FETCH_HEAD:board.h
	void levelUp();
	void levelDown();
    ~Board();
    //extrafeature
    void setMaxdelete(int maxdelte);
    void updatecelltimes();
    void deleteextra();
};



#endif
