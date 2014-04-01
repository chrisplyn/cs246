#include "board.h"
#include <string>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include "score.h"
#include "cell.h"
#include "display.h"
#include "NextBlock.h"
#include <iomanip>
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


Board::Board(int level,int maxdelete){
    MaxDelete = maxdelete;
    this->level = level;

    currentBlock = NULL;
    nextBlock = new NextBlock(level);
    p = new Display(15,10);
    scoreBoard = new Score;
    grid = new Cell*[15];
    for (int i = 0; i < 15; i++){
        grid[i] = new Cell[10];
        for (int j =0; j < 10;j++){
            grid[i][j].setCoordinates(i, j);
            grid[i][j].setLT("",-1,-1);
        }
    }
}

void Board::setInputStream(istream &input){
	nextBlock->setInputStream(input);
}


// Board *Board::getInstance(int level){
//     if (!instance){
//         instance = new Board(level);
//         atexit(cleanup);
//     }
//     return instance;
// }

// void Board::initialization(std::istream &input){
//     nextBlock->setInputStream(input);
//     this->makeBlock();
//     this->notifyDisplay();
//     this->displayall();
// }


// void Board::cleanup(){
//     delete instance;
// }


void Board::makeBlock(){
	if (level == 0){
		if (nextType == ""){
			if (!nextBlock->noRandomType()){
				nextType = nextBlock->getNonRandomType();
                if(currentBlock !=0 ) delete currentBlock;  //delete previous block
				currentBlock = setCurrentBlock(nextType);
			}
			else{return;}

			nextType = nextBlock->getNonRandomType();
			if (nextType == ""){
				return; //restart
			}
		}
		else{
            if(currentBlock !=0 ) delete currentBlock;
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

            if(currentBlock !=0 ) delete currentBlock;
			currentBlock = setCurrentBlock(nextType);
			nextType = nextBlock->getRandomType();
		}
		else{
            if(currentBlock !=0 ) delete currentBlock;
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
	} else{
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
            grid[numOfRow][i].reset();
        }   else {
            grid[numOfRow][i].reset();
        }
    }
    if (numOfRow != 0){
        for (int j = numOfRow-1; j > 0; --j){
            for (int k = 0; k < 10; ++k){
                grid[j][k].Swap(&grid[j+1][k]);
            }
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


void Board::displayall(){
    cout << "Level:";
    cout << setw(7) << level << endl;
	cout << "Score:";
    cout <<	setw(7) << scoreBoard->getCur() << endl;
    
	cout << "Hi Score:";
    cout << setw(4) << scoreBoard->gethS() << endl;
    cout << "----------" <<endl;
    cout << *p;
    cout << "----------" <<endl;
    cout << "Next:" << endl;
    
    if (nextType == "O"){
        cout << "OO"<< endl << "OO" << endl;
    } else if (nextType == "I") {
        cout << "IIII" << endl;
    } else if (nextType == "L"){
        cout << "  L" << endl << "LLL" << endl;
    } else if (nextType == "J") {
        cout << "J  " << endl << "JJJ" <<endl;
    } else if (nextType == "S") {
        cout << " SS" << endl<<"SS "<<endl;
    } else if (nextType == "Z") {
        cout << "ZZ " << endl << " ZZ" <<endl;
    } else if (nextType == "T") {
        cout << "TTT" << endl << " T " << endl;
    }
}

void Board::restart(int d_level){
    for (int i = 0; i < 15; i++){
        for (int j =0; j < 10;j++){
            grid[i][j].setCoordinates(i, j);
            grid[i][j].setLT("",-1,-1);
        }
    }
    this->notifyDisplay();
    delete nextBlock;
	delete currentBlock;
    currentBlock = 0;   //set currentBlock to null
    level = d_level;
    nextBlock = new NextBlock(d_level);
    scoreBoard->setback();
    nextType = "";
}


void Board::levelUp(){
	if (level <= 2){
		level++;
		delete nextBlock;
		nextBlock = new NextBlock(level);
	}
}

void Board::levelDown(){
	if (level >= 1){
		level--;
		delete nextBlock;
		nextBlock = new NextBlock(level);
	}
}


//extra feature
void Board::setMaxdelete(int maxdelte){
    MaxDelete = maxdelte;
}

void Board::updatecelltimes(){
    for (int i = 0;i < 15;i++){
        for (int j = 0; j < 10; j++){
            if (grid[i][j].isOn()){
                grid[i][j].updatetimes();
            }
        }
    }
}

void Board::deleteextra(){
    for (int i = 0;i < 15;i++){
        for (int j = 0; j < 10; j++){
            if ((grid[i][j].isOn())&&(grid[i][j].getExistime()>= MaxDelete)){
                grid[i][j].reset();
                if (i != 0){
                    for (int k = i-1; k>0;k--){
                        grid[k][j].Swap(&grid[k+1][j]);
                    }
                }
            }
        }
    }
}




bool Board::isGameOver(){
    
    if(nextBlock->noRandomType()) return true;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<10; ++j) {
            if (grid[i][j].isOn()) {
                return true;
            }
        }
    }
    if (nextType == "O") {
        if (grid[4][0].isOn()||grid[4][1].isOn()||grid[3][0].isOn()||grid[3][1].isOn()) {
            return true;
        }
    } else if (nextType == "I") {
        if (grid[3][0].isOn()||grid[3][1].isOn()||grid[3][2].isOn()||grid[3][3].isOn()) {
            return true;
        }
    } else if (nextType == "L") {
        if (grid[4][0].isOn()||grid[4][1].isOn()||grid[4][2].isOn()||grid[3][2].isOn()) {
            return true;
        }
    } else if (nextType == "J") {
        if (grid[4][0].isOn()||grid[4][1].isOn()||grid[4][2].isOn()||grid[3][0].isOn()) {
            return true;
        }
    } else if (nextType == "T") {
        if (grid[3][0].isOn()||grid[3][1].isOn()||grid[3][2].isOn()||grid[4][1].isOn()) {
            return true;
        }
    } else if (nextType == "S") {
        if (grid[4][0].isOn()||grid[4][1].isOn()||grid[3][1].isOn()||grid[3][2].isOn()) {
            return true;
        }
    } else if (nextType == "Z") {
        if (grid[3][0].isOn()||grid[3][1].isOn()||grid[4][1].isOn()||grid[4][2].isOn()) {
            return true;
        }
    }
    return false;
}

