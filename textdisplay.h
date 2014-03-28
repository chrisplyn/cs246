/*
 * textdisplay.h
 *
 */

#ifndef TEXTDISPLAY_H_
#define TEXTDISPLAY_H_

#include <string>
#include <iostream>


class TextDisplay{
	char **theDisplay;
	const int row ;
	const int col ;

public:
	TextDisplay(int row, int col);
	~TextDisplay();
	void notify(int r, int c, std::string &type);
	void updateLevel(int);
	void updateScore(int);
	void updateHiScore(int);
	//void updateNextBlock(std::string &);
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

};



#endif /* TEXTDISPLAY_H_ */
