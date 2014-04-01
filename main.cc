#include "board.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "trie.h"

using namespace std;

int repeat(string& command){
	//cout << command << endl;
    string numRepeat = "";
    int num;
    while ((char)command[0]>=48&&(char)command[0]<=57) {
       // cout<<"here"<<endl;
        //cout<<command[0];
        numRepeat.push_back(command[0]);
        command = command.substr(1);
        //cout<<command<<endl;
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
	string filename = "/Users/wangxiangkang/Desktop/cs246/sequence.txt";
	int seed = 0; //default seed to 0
	int startLevel = 0; //default startlevel 0
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
    
	srand(seed);
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
    
	string tmp;
	Board board(startLevel);
	ifstream f(filename.c_str());
    
	if (startLevel == 0){
		board.setInputStream(f);
	}
    
	board.makeBlock();
	board.notifyDisplay();
	board.displayall();
    
	int numRepeat = 1;
	string command;
	string subCommand1;
	string subCommand2;
    
	while (cin >> command) {
		numRepeat = repeat(command);
		//cout << command << "123" << endl;
        
		if (command == "rename") {
			cin >> subCommand1 >> subCommand2;
			tn.insert(subCommand2, subCommand1);
			tn.remove(subCommand1);
		}
        
		command = tn.find(command);
		cout << command << "here" << endl;
        
		for (int i = 0; i < numRepeat; ++i) {
            
			if (command == "left"){
				board.moveCurBlockLeft();
			} else if (command == "right"){
				cout << command << endl;
				board.moveCurBlockRight();
			} else if (command == "down"){
				board.moveCurBlockDown();
			} else if (command == "clockwise"){
				board.rotateClockwise();
			} else if (command == "anticlockwise"){
				board.rotateAntiClockwise();
			} else if (command == "levelup"){
				board.levelUp();
			} else if (command == "leveldown"){
				board.levelDown();
			} else if (command == "drop"){
				board.dropCurBlock();
				int rows = board.deleteRows();
				board.notifyScore(rows);
				board.makeBlock();
			} else if (command == "restart"){
				board.restart(startLevel);
				board.makeBlock();
			} 
			board.notifyDisplay();
			board.displayall();
		}
	}
}