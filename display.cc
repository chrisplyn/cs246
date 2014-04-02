
#include "display.h"
using namespace std;

//ctor
textDisplay::textDisplay(int row, int col):row(row), col(col){
	theDisplay = new char*[row];

	for(int i=0; i<row; ++i){
		theDisplay[i] = new char[col];
		for(int j=0; j<col; ++j){
			theDisplay[i][j] = ' ';
		}
	}
}

//dtor
textDisplay::~textDisplay(){
	for(int i=0; i<row; ++i){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}

void textDisplay::notify(int r, int c, string type){
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
	}   else if (type == ""){
        theDisplay[r][c] = ' ';
    }   else {
        theDisplay[r][c] = 'X';
    }
}


ostream &operator<<(ostream &out, const textDisplay &td){
	for(int i=0; i<td.row; ++i){
		for(int j=0; j<td.col; ++j){
			out << td.theDisplay[i][j];
		}
		out << endl;
	}
	return out;
}
