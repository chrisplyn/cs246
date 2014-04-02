
#ifndef __textDisplay_H__
#define __textDisplay_H__

#include <string>
#include <iostream>


class textDisplay{
	char **theDisplay;
	const int row ;
	const int col ;

public:
	textDisplay(int row, int col);
	~textDisplay();
	void notify(int r, int c, std::string type);
	//void updateLevel(int);
	//void updateScore(int);
	//void updateHiScore(int);
	//void updateNextBlock(std::string &);
	friend std::ostream &operator<<(std::ostream &out, const textDisplay &td);

};



#endif
