#include "Board.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){
	
	Board b;	
	ifstream f("sequence.txt");


	b.setInputStream(f);
	b.makeBlock();
	//moveCurBlockRight();
	b.moveCurBlockDown();
	b.moveCurBlockDown();
	b.moveCurBlockRight();
	//b.dropCurBlock();
	//b.rotateClockwise();
	//b.moveCurBlockRight();
	//b.moveCurBlockLeft();
	b.notifyDisplay();
	//b.makeBlock();
	//b.makeBlock();
	cout << b;
	cin.get();
}