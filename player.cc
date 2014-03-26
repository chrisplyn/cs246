#include <string>
#include "player.h"
#include "scoreboard.h"
using namespace std;

Player *Player::twoPlayers[2] = {0,0};

void Player::createPlayer(char name){
	for (int i = 0; i < 2; ++i){
		if (!twoPlayers[i]){
			twoPlayers[i] = new Player(name);
			break;			
		}
	}
}

Player *Player::getPlayer(char name){
	if(name == 'X'){
		return twoPlayers[0];
	}
	return twoPlayers[1];
}

// ctor of player class
Player::Player(char name):name(name), input(0), flag(true){
	ptrToBoard = ScoreBoard::getInstance();
}


// dtor of player class
void Player::DestroyPlayer(){
	for(int i=0; i<2; ++i){
		delete twoPlayers[i];
	}
}


void Player::receiveInput(istream &in, string& source){
	input = &in;
	if(source == "stdin"){
		flag = false;
	}else{
		flag = true;
	}
}


void Player::makeMove(){

	string move;
	*input >> move;
	bool isOccupied;

	if(!flag){
		cout << name << "'s move" << endl;
		ptrToBoard->makeMove(move, name);
	}

	else{
		isOccupied = ptrToBoard->isOccupied(move);

		if(!isOccupied){
			cout << name << "'s move" << endl;
			cout << "(plays " << move << ")"<< endl;
			ptrToBoard->makeMove(move, name);
		}
	    else{
			while(isOccupied){
				*input >> move;
				isOccupied = ptrToBoard->isOccupied(move);
			}
			cout << name << "'s move" << endl;
			cout << "(plays " << move << ")"<< endl;
			ptrToBoard->makeMove(move, name);
		}
	}	
}