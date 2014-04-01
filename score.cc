#include "score.h"

Score::Score(){
    curScore = 0;
    highScore = 0;
}


void Score::updateScoreBoard(int level){
    curScore = (level + 1) * (level + 1) + curScore;
    if (curScore >= highScore){
        highScore = curScore;
    }
}

void Score::updateScoreBoard(int level, int rowsDeleted){
    curScore = (level + rowsDeleted) * (level + rowsDeleted) + curScore;
    if (curScore >= highScore){
        highScore = curScore;
    }
}

int Score::getCur(){
    return curScore;
}

int Score::gethS(){
    return highScore;
}

void Score::setback(){
    curScore = 0;
}

Score::~Score(){}