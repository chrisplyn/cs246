#include "Board.h"
#include <string>
#include <climits>
#include "score.h"
#include "cell.h"


using namespace std;

Board::Board(){
    MaxDelete = INT_MAX;
    level = 0;
    currentBlock = NULL;
    nextBlock = NULL;
    p = new Display(15,10);
    scoreBoard = new Score(p);
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


Board::Board(int Level){
    MaxDelete = INT_MAX;
    level = Level;
    currentBlock = NULL;
    nextBlock = NULL;
    p = new Display(15,10);
    scoreBoard = new Score(p);
    grid = new Cell*[15];
    for (int i = 0; i < 15; i++){
        grid[i] = new Cell[10];
        for (int j =0; j < 10;j++){
            grid[i][j].setCoordinates(i, j);
            grid[i][j].setLT("",-1);
        }
    }
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

void Board::notifyScore(int curLevel, int RowsDeleted){
    scoreBoard->updateScoreBoard(curLevel,RowsDeleted);
}

void Board::deleteRow(int numOfRow){
    for (int i = 0; i < 10; ++i){
        Cell * c1 = grid[numOfRow][i].getNeighbour(0);
        Cell * c2 = grid[numOfRow][i].getNeighbour(1);
        Cell * c3 = grid[numOfRow][i].getNeighbour(2);
        if ((c1 == NULL) && (c2 == NULL) && (c3 == NULL)){
            scoreBoard->updateScoreBoard(grid[numOfRow][i].getLevel());
            //scoreBoard->notifyDisplay(); Not sure
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
            p->notify(i, j, grid[i][j].getType());//wrong with display
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
    delete currentBlock;
    delete p;
    for (int i = 0;i<15;++i){
        delete [] grid[i];
    }
    delete [] grid;
}













