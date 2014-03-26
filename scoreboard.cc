#include "scoreboard.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

ScoreBoard *ScoreBoard::instance = 0;	//must define static member, initialize instance to a null pointer
int ScoreBoard::numGames = 0;

ScoreBoard *ScoreBoard::getInstance(){
	if (!instance){
		instance = new ScoreBoard;
		atexit(cleanup);
	}
	return instance;
}


//ctor of ScoreBoard
ScoreBoard::ScoreBoard(){
	scoreX = 0;
	scoreO = 0;	

	char temp[]="0123456789";
	for(int i=0; i<10; i++){
		square[i] = temp[i];
	}
	square[10] = '\0';
}


void ScoreBoard::cleanup(){
	delete instance;
}


void ScoreBoard::startGame(){	
	++numGames;
}

int ScoreBoard::getNumGames(){
	return numGames;
}


void ScoreBoard::clearBoard(){
	char temp[]="0123456789";
	for(int i=0; i<10; i++){
		square[i] = temp[i];
	}
	square[10] = '\0';
}


//check if a position is occupied
bool ScoreBoard::isOccupied(const string& position){
	if (position == "NW" && square[1] == '1') return false;
	else if (position == "N" && square[2] == '2') return false;
	else if (position == "NE" && square[3] == '3') return false;
	else if (position == "W" && square[4] == '4') return false;
	else if (position == "C" && square[5] == '5') return false;
	else if (position == "E" && square[6] == '6') return false;
	else if (position == "SW" && square[7] == '7') return false;
	else if (position == "S" && square[8] == '8') return false;
	else if (position == "SE" && square[9] == '9') return false;

	else return true;
}


void ScoreBoard::makeMove(const string& position, const char playerMark){
	char mark = playerMark;
	if (position == "NW") square[1] = mark;
	else if (position == "N")  square[2] = mark;
	else if (position == "NE") square[3] = mark;
	else if (position == "W") square[4] = mark;
	else if (position == "C") square[5] = mark;
	else if (position == "E") square[6] = mark;
	else if (position == "SW") square[7] = mark;
	else if (position == "S") square[8] = mark;
	else if (position == "SE") square[9] = mark;
}


char ScoreBoard::checkWinner(){
	if (square[1] == square[2] && square[2] == square[3])
		return square[1];
	else if (square[4] == square[5] && square[5] == square[6])
		return square[4];
	else if (square[7] == square[8] && square[8] == square[9])
		return square[7];
	else if (square[1] == square[4] && square[4] == square[7])
		return square[1];
	else if (square[2] == square[5] && square[5] == square[8])
		return square[2];
	else if (square[3] == square[6] && square[6] == square[9])
		return square[3];
	else if (square[1] == square[5] && square[5] == square[9])
		return square[1];
	else if (square[3] == square[5] && square[5] == square[7])
		return square[3];
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
		square[4] != '4' && square[5] != '5' && square[6] != '6' &&
		square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 'D';
	else return  'C';
}
	

void ScoreBoard::printBoard(){
	for (int i=0; i<3; ++i){
		for(int j=1; j<4; ++j){
			cout << square[3*i+j] << " " << " | ";
		}
		cout << endl;
	}
}





void ScoreBoard::printScore(const char result){
	
	if(result == 'X'){
		++scoreX;
	}
	if(result == 'O'){
		++scoreO;
	}

	if (result != 'D')
	{
		cout << result << " " << "wins" << endl;
	}else{
		cout << "Draw" << endl;
	}
	
	
	cout << "Score is" << endl;
	cout << 'X' << " " << scoreX << endl;
	cout << 'O' << " " << scoreO << endl;
}
