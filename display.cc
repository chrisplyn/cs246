
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

void Display::notify(int r, int c, string type){
	if (type == "O"){
		theDisplay[r][c] = 'O';
	}
	else if (type == "I"){
		theDisplay[r][c] = 'I';
	}
	else if (type == "L"){
		theDisplay[r][c] = 'L';
	}
	else if (type == "S"){
		theDisplay[r][c] = 'S';
	}
	else if (type == "Z"){
		theDisplay[r][c] = 'Z';
	}
	else if (type == "T"){
		theDisplay[r][c] = 'T';
	}
	else if (type == "J"){
		theDisplay[r][c] = 'J';
	}
}


void Display::updateLevel(int level){
    cout.fill(' ');
    cout.width(7);
	cout << "Level:";
    cout << right << level << endl;
}

void Display::updateScore(int score){
    cout.fill(' ');
    cout.width(7);
	cout << "Score:";
    cout <<	right << score << endl;
}

void Display::updateHiScore(int Hiscore){
    cout.fill(' ');
    cout.width(4);
	cout << "Hi Score:";
    cout << right << Hiscore << endl;
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
