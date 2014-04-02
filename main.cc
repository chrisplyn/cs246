#include "board.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <climits>
#include "trie.h"
#include "window.h"

using namespace std;

int repeat(string& command){
    string numRepeat = "";
    int num;
    while ((char)command[0]>=48&&(char)command[0]<=57) {
        numRepeat.push_back(command[0]);
        command = command.substr(1);
    }
	if (numRepeat == "") return 1;
    istringstream ss(numRepeat);
    ss>>num;
    return num;
}




int main(int argc, const char * argv[])
{

	string commandline;
	string displayMode;

	string filename = "sequence.txt";
	int seed = 0; //default seed to 0
	int startLevel = 2; //default startlevel 0
	int maxBlockAllowed = INT_MAX;


	for (int i = 1; i < argc; ++i) {

		commandline = argv[i];
		if (commandline == "text")
		{
			displayMode = "text";
		}
		else if (commandline == "seed") {
			++i;
			commandline = argv[i];
			istringstream ss(commandline);
			ss >> seed;
		}
		else if (commandline == "startlevel") {
			++i;
			commandline = argv[i];
			istringstream ss(commandline);
			ss >> startLevel;
		}
		else if (commandline == "scriptfile") {
			++i;
			filename = argv[i];
		}
		else if (commandline == "maxBlock") {
			++i;
			commandline = argv[i];
			istringstream ss(commandline);
			ss >> maxBlockAllowed;
		}
	}

	TrieNode tn;
	tn.insert("left", "left");
	tn.insert("right", "right");
	tn.insert("down", "down");
	tn.insert("clockwise", "clockwise");
	tn.insert("anticlockwise", "anticlockwise");
	tn.insert("drop", "drop");
	tn.insert("levelup", "levelup");
	tn.insert("leveldown", "leveldown");
	tn.insert("restart", "restart");

	srand(seed);
	Xwindow *pXw=0;

	if (displayMode != "text"){
		pXw = new Xwindow(570, 580);
		pXw->fillRectangle(20,10,300,4,Xwindow::Black);
		pXw->fillRectangle(20,560,300,4,Xwindow::Black);
		pXw->fillRectangle(16,10,4,554,Xwindow::Black);
		pXw->fillRectangle(320,10,4,554,Xwindow::Black);
	}

	Board *board = Board::getInstance(startLevel,maxBlockAllowed,pXw);	
	ifstream f(filename.c_str());
	board->initialization(f);	//initialize board

	int numRepeat = 1;
	string command;
	string subCommand1;
	string subCommand2;

	while (cin >> command) {

		numRepeat = repeat(command);
		if (command == "rename") {
			cin >> subCommand1 >> subCommand2;
			tn.insert(subCommand2, subCommand1);
			tn.remove(subCommand1);
		}
		command = tn.find(command);
		for (int i = 0; i < numRepeat; ++i) {
			
			if(f.eof()) {
				cout<<"The input file has reached the end."<<endl;
				cout<<"Please submit another file to restart the game."<<endl;
				if (pXw!=0) delete pXw;
				return 0;
			}
			if (command == "left"){
				board->moveCurBlockLeft();
			} else if (command == "right"){
				board->moveCurBlockRight();
			} else if (command == "down"){
				board->moveCurBlockDown();
			} else if (command == "clockwise"){
				board->rotateClockwise();
			} else if (command == "anticlockwise"){
				board->rotateAntiClockwise();
			} else if (command == "levelup"){
				board->levelUp();
			} else if (command == "leveldown"){
				board->levelDown();
				if (board->getLevel() == 0){
					board->setInputStream(f);
				}          
			} else if (command == "drop"){
                board->dropCurBlock();
				int rows = board->deleteRows();
				board->notifyScore(rows);
                if (board->isGameOver()){
					cout  << "You lose!" << endl;
					if (pXw != 0) delete pXw;
                    return 0;
                }
                board->updatecelltimes();
                board->deleteextra();
				rows = board->deleteRows();
                board->notifyScore(rows);
				board->makeBlock();
			} 
			else if(command == "restart"){
				board->restart(startLevel);
				if (board->getLevel() == 0){
					board->setInputStream(f);
				}
				board->makeBlock();
				board->notifyDisplay();
				board->displayall();	
				break;
			} 
			board->notifyDisplay();
			board->displayall();	
		}
	}

	delete pXw;
}
