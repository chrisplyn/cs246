
#include "display.h"
using namespace std;

//ctor
Display::Display(int row, int col):row(row), col(col){
	theDisplay = new char*[row];

	for(int i=0; i<row; ++i){
		theDisplay[i] = new char[col];
		for(int j=0; j<col; ++j){
			theDisplay[i][j] = ' ';
		}
	}
}

//dtor
Display::~Display(){
	for(int i=0; i<row; ++i){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}

void Display::updateLevel(int level){
	cout << "Level:" <<	"        " << level << endl;
}

void Display::updateScore(int score){
	cout << "Score:" <<	"        " << score << endl;
}

void Display::updateHiScore(int Hiscore){
	cout << "Hi Score:" << "     " << Hiscore << endl;
}


ostream &operator<<(ostream &out, const Display &td){
	for(int i=0; i<td.row; ++i){
		for(int j=0; j<td.col; ++j){
			out << td.theDisplay[i][j];
		}
		out << endl;
	}
	return out;
}
