/*
 * textdisplay.h
 *
 */

#ifndef TEXTDISPLAY_H_
#define TEXTDISPLAY_H_

#include <string>
#include <iostream>


class Display{
	char **theDisplay;
	const int row ;
	const int col ;

public:
	Display(int row, int col);
	~Display();
	void notify(int r, int c, std::string &type);
	void updateLevel(int);
	void updateScore(int);
	void updateHiScore(int);
	//void updateNextBlock(std::string &);
	friend std::ostream &operator<<(std::ostream &out, const Display &td);

};



#endif /* TEXTDISPLAY_H_ */
