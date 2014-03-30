#include "score.h"

Score::Score(){
    curScore = 0;
    highScore = 0;
    dp = NULL;
}

Score::Score(Display * display){
    curScore = 0;
    highScore = 0;
    dp = display;
}

void Score::updateScoreBoard(int level){
    curScore = (level + 1) * (level + 1) + curScore;
    if (curScore >= highScore){
        highScore = curScore;
    }
}

void Score::updateScoreBoard(int level, int rowsDeleted){
    curScore = rowsDeleted * (level + 1) * (level + 1) + curScore;
    if (curScore >= highScore){
        highScore = curScore;
    }
}

void Score::notifyDisplay(){
    dp->updateLevel(curScore);
    dp->updateHiScore(highScore);
}

Score::~Score(){}