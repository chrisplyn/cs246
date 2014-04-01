#include "board.h"
#include <string>
#include <climits>
#include <iostream>
#include "score.h"
#include "cell.h"
#include "display.h"
#include "NextBlock.h"
#include "block.h"
#include "oblock.h"
#include "iblock.h"
#include "tblock.h"
#include "sblock.h"
#include "zblock.h"
#include "lblock.h"
#include "sblock.h"
#include "jblock.h"

using namespace std;


Board::Board(int Level){
    MaxDelete = INT_MAX;
    level = Level;
    currentBlock = NULL;
    nextBlock = new NextBlock(level);
    nextType = "";
    p = new Display(15,10);
    scoreBoard = new Score;
    grid = new Cell*[15];
    for (int i = 0; i < 15; i++){
        grid[i] = new Cell[10];
        for (int j =0; j < 10;j++){
            grid[i][j].setCoordinates(i, j);
            grid[i][j].setLT("",-1);
        }
    }
}

void Board::setInputStream(istream &input){
	nextBlock->setInputStream(input);
}


void Board::makeBlock(){

	if (level == 0){
		if (nextType == ""){
			if (!nextBlock->noRandomType()){
				nextType = nextBlock->getNonRandomType();
				currentBlock = setCurrentBlock(nextType);
			}
			nextType = nextBlock->getNonRandomType();
			if (nextType == ""){
				return; //restart
			}
		}
		else{
			currentBlock = setCurrentBlock(nextType);	
			nextType = nextBlock->getNonRandomType();		
			if (nextType == ""){
				return; //restart
			}
		}
	}
	else{
		if (nextType == ""){
			nextType = nextBlock->getRandomType();
			currentBlock = setCurrentBlock(nextType);
			nextType = nextBlock->getRandomType();
		}
		else{
			currentBlock = setCurrentBlock(nextType);
			nextType = nextBlock->getRandomType();
		}
	}

}


Block * Board::setCurrentBlock(string &type){
	Block *tmp;
	if (type == "O"){
		tmp = new OBlock(*this, level);
	} else if (type == "I"){
		tmp = new IBlock(*this, level);
	} else if (type == "T"){
		tmp = new TBlock(*this, level);
	} else if (type == "S"){
		tmp = new SBlock(*this, level);
	} else if (type == "Z"){
		tmp = new ZBlock(*this, level);
	} else if (type == "J"){
        tmp = new JBlock(*this, level);
    } else if (type == "L"){
        tmp = new LBlock(*this, level);
	}
	else{
		return 0;
	}
	return tmp;
}

void Board::moveCurBlockRight(){
	currentBlock->moveRight(this);
}

void Board::moveCurBlockLeft(){
	currentBlock->moveLeft(this);
}

void Board::rotateClockwise(){
	currentBlock->rotateClockwise(this);
}

void Board::rotateAntiClockwise(){
	currentBlock->rotateAnticlockwise(this);
}

void Board::dropCurBlock(){
	currentBlock->drop(this);
}

void Board::moveCurBlockDown(){
	currentBlock->moveDown(this);
}

Cell ** Board::getGrid(){
    return grid;
}


int Board::getLevel(){
    return level;
}

int Board::getMaxDelete(){
    return MaxDelete;
}

void Board::notifyScore( int RowsDeleted){
    scoreBoard->updateScoreBoard(level,RowsDeleted);
}

void Board::deleteRow(int numOfRow){
    for (int i = 0; i < 10; ++i){
        Cell * c1 = grid[numOfRow][i].getNeighbour(0);
        Cell * c2 = grid[numOfRow][i].getNeighbour(1);
        Cell * c3 = grid[numOfRow][i].getNeighbour(2);
        if ((c1 == NULL) && (c2 == NULL) && (c3 == NULL)){
            scoreBoard->updateScoreBoard(grid[numOfRow][i].getLevel());
    //        scoreBoard->notifyDisplay(); Not sure
            grid[numOfRow][i].reset();
        }   else {
            grid[numOfRow][i].reset();
        }
    }
    for (int j = numOfRow; j < 14; ++j){
        for (int k = 0; k < 10; ++k){
            grid[j][k].Swap(&grid[j+1][k]);
        }
    }
}



bool Board::isRowComplete(int numOfRow){
    bool answer = true;
    for(int i = 0; i < 10; i++){
        answer = (answer && grid[numOfRow][i].isOn());
    }
    return answer;
}


void Board::notifyDisplay(){
    for (int i = 0; i < 15; ++i){
        for (int j = 0; j < 10;++j){
            p->notify(i, j, grid[i][j].getType());
        }
    }
}

int Board::deleteRows(){
    int answer = 0;
    for (int i = 0;i < 15;++i){
        if (isRowComplete(i) == true){
            deleteRow(i);
            answer = answer + 1;
        }
    }
    return answer;
}

Board::~Board(){
    delete scoreBoard;
    delete p;
    for (int i = 0;i<15;++i){
        delete [] grid[i];
    }
    delete [] grid;	
	delete nextBlock;
	delete currentBlock;
}


ostream &operator<<(std::ostream &out, const Board &b){
	out << *b.p;
	return out;
}

void Board::displayall(){
    cout.fill(' ');
    cout.width(7);
	cout << "Level:";
    cout << right << level << endl;
    cout.fill(' ');
    cout.width(7);
	cout << "Score:";
    cout <<	right << scoreBoard->getCur() << endl;
    cout.fill(' ');
    cout.width(4);
	cout << "Hi Score:";
    cout << right << scoreBoard->gethS() << endl;
    cout << "----------" <<endl;
    cout << *p;
    cout << "----------" <<endl;
    cout << "Next:" << endl;
    if (nextType == "O"){
        cout << "OO\nOO" << endl;
    }   else if (nextType == "L"){
        cout << "  L\nLLL" << endl;
    }
}

void Board::restart(int d_level){
    for (int i = 0; i < 15; i++){
        grid[i] = new Cell[10];
        for (int j =0; j < 10;j++){
            grid[i][j].setCoordinates(i, j);
            grid[i][j].setLT("",-1);
        }
    }
    this->notifyDisplay();
    delete nextBlock;
    nextBlock = new NextBlock(d_level);
    scoreBoard->setback();
    nextType = "";
}

void Board::setLevel(int n_level){
    level = n_level;
    delete nextBlock;
    nextBlock = new NextBlock(n_level);
}





