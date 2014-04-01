#ifndef __SCORE_H__
#define __SCORE_H__

class Score{
    int curScore;
    int highScore;;
public:
    Score();
    void updateScoreBoard(int level);
    void updateScoreBoard(int level,int rowsDeleted);
    int getCur();
    int gethS();
    void setback();
    ~Score();
};



#endif
