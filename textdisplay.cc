/*
 * textdisplay.cc
 *
 */

#include "textdisplay.h"
using namespace std;

//ctor
TextDisplay::TextDisplay(int row, int col):row(row), col(col){
	theDisplay = new char*[row];

	for(int i=0; i<row; ++i){
		theDisplay[i] = new char[col];
		for(int j=0; j<col; ++j){
			theDisplay[i][j] = ' ';
		}
	}
}

//dtor
TextDisplay::~TextDisplay(){
	for(int i=0; i<row; ++i){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}

void TextDisplay::updateLevel(int level){
	cout << "Level:" <<	"        " << level << endl;
}

void TextDisplay::updateScore(int score){
	cout << "Score:" <<	"        " << score << endl;
}

void TextDisplay::updateHiScore(int Hiscore){
	cout << "Hi Score:" << "     " << Hiscore << endl;
}


ostream &operator<<(ostream &out, const TextDisplay &td){
	for(int i=0; i<td.row; ++i){
		for(int j=0; j<td.col; ++j){
			out << td.theDisplay[i][j];
		}
		out << endl;
	}
	return out;
}
