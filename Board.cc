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

Cell **Board::getGrid(){
    return grid;
}

int Board::getLevel(){
    return level;
}

int Board::getMaxDelete(){
    return MaxDelete;
}

void Board::notifyScore(int curLevel, int RowsDeleted){
    score->updateScoreBoard(curLevel,RowsDeleted);
}

bool Board::isRowComplete(int numOfRow){
    bool answer = true;
    for(int i = 0; i < 10; i++){
        answer = (answer && grid[numOfRow][i].isOn());
    }
    return answer;
}








