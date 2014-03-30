#ifndef __SCORE_H__
#define __SCORE_H__
#include "display.h"

class Score{
    int curScore;
    int highScore;
    Display *dp;
public:
    Score();
    Score(Display *);
    void updateScoreBoard(int level);
    void updateScoreBoard(int level,int rowsDeleted);
    void notifyDisplay();
    
    ~Score();
};



#endif
