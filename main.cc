#include "board.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "trie.h"

using namespace std;

int repeat(const string& command){
    string numRepeat = "";
    int num;
    while ((char)command[0]>=48||(char)command[0]<=57) {
        numRepeat.push_back(command[0]);
        command.substr(1);
    }
    istringstream ss(numRepeat);
    ss>>num;
    return num;
}





int main(int argc, const char * argv[])
{
    string commandline;
    string displayMode;
    string filename;
    int seed = 0; //default seed to 0
    int startLevel=0; //default startlevel 0
    int maxBlockAllowed = INT_MAX;
    
    
    for (int i=1; i<argc ; ++i) {
        
        commandline = argv[i];
        if (commandline=="text")
        {
            displayMode = "text";
        } else if (commandline=="seed") {
            ++i;
            commandline = argv[i];
			istringstream ss(commandline);
            ss >> seed;
        } else if (commandline=="startlevel") {
            ++i;
            commandline = argv[i];
			istringstream ss(commandline);
			ss >> startLevel;
        } else if (commandline=="scriptfile") {
            ++i;
            filename = argv[i];
        } else if (commandline=="maxBlock") {
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
    

	Board b;
	ifstream f("/Users/wangxiangkang/Desktop/cs246/sequence.txt");
    
    int numRepeat = 0;
    string command;
    string subCommand1;
    string subCommand2;
    
    while (cin>>command) {
        
        numRepeat = repeat(command);
        
        if (command == "rename") {
            cin>>subCommand1>>subCommand2;
            tn.insert(subCommand2, subCommand1);
            tn.remove(subCommand1);
        } else {
            command = tn.find(command);
        }
        
        
    }
    
    b.setInputStream(f);

    // insert code here...
		
	Board b(startLevel);
	ifstream f("sequence.txt");
    //string temp;
    //while (!f.eof()) {
    //    f>>temp;
     //   cout<<temp<<endl;
    //}

   // cout<<f.is_open()<<endl;
	if (b.getLevel() == 0){
		b.setInputStream(f);
	}
>>>>>>> 244952987f6a322989b918ca6e8db3fceccbf41f
	b.makeBlock();
<<<<<<< HEAD
	b.dropCurBlock();
	b.makeBlock();
	b.dropCurBlock();
	b.makeBlock();
	b.moveCurBlockRight();
	//b.rotateClockwise();
	//b.rotateClockwise();
	//b.rotateClockwise();
	
	//moveCurBlockRight();
	//b.moveCurBlockDown();
    
	
   
	//b.moveCurBlockRight();
	//b.moveCurBlockLeft();
	////b.dropCurBlock();
	//b.rotateClockwise();
	//b.moveCurBlockRight();
	//b.moveCurBlockDown();
 //   b.dropCurBlock();
 //   //b.moveCurBlockLeft();
	//b.notifyDisplay();
	////b.makeBlock();
	////b.makeBlock();
 //   
 //   b.makeBlock();
 //   b.moveCurBlockRight();
 //   b.rotateAntiClockwise();
 //   b.dropCurBlock();
 //   b.notifyDisplay();
 //   
 //   b.makeBlock();
 //   b.dropCurBlock();
 //   b.notifyDisplay();
 //   
 //   b.makeBlock();
 //   b.rotateAntiClockwise();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.dropCurBlock();
 //   b.rotateAntiClockwise();
 //   b.rotateAntiClockwise();
 //   b.notifyDisplay();
 //   
 //   b.makeBlock();
 //   b.rotateAntiClockwise();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();b.moveCurBlockRight();b.moveCurBlockRight();
 //   b.moveCurBlockRight();b.moveCurBlockRight();b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockLeft();
 //   b.moveCurBlockRight();
 //   b.dropCurBlock();
 //   b.notifyDisplay();
 //   
 //   b.makeBlock();
 //   b.moveCurBlockDown();
 //   b.rotateAntiClockwise();
 //   b.rotateAntiClockwise();
 //   b.rotateAntiClockwise();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.dropCurBlock();
 //   b.notifyDisplay();
 //   
 //   b.makeBlock();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockLeft();
 //   b.moveCurBlockDown();
 //   b.rotateClockwise();
 //   b.rotateClockwise();
 //   b.rotateClockwise();
 //   b.rotateAntiClockwise();
 //   b.rotateAntiClockwise();
 //   b.rotateAntiClockwise();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.dropCurBlock();
 //   b.moveCurBlockRight();
 //   b.dropCurBlock();
 //   b.notifyDisplay();
=======

	//b.dropCurBlock();
	b.rotateClockwise();
	b.moveCurBlockRight();
	b.moveCurBlockDown();
    b.dropCurBlock();
    //b.moveCurBlockLeft();
	b.notifyDisplay();
	//b.makeBlock();
	//b.makeBlock();
    
    b.makeBlock();
    b.moveCurBlockRight();
    b.rotateAntiClockwise();
    b.dropCurBlock();
    b.notifyDisplay();
    
    b.makeBlock();
    b.dropCurBlock();
    b.notifyDisplay();
    
    b.makeBlock();
    b.rotateAntiClockwise();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.dropCurBlock();
    b.rotateAntiClockwise();
    b.rotateAntiClockwise();
    b.notifyDisplay();
    
    b.makeBlock();
    b.rotateAntiClockwise();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockRight();b.moveCurBlockRight();b.moveCurBlockRight();
    b.moveCurBlockRight();b.moveCurBlockRight();b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockLeft();
    b.moveCurBlockRight();
    b.dropCurBlock();
    b.notifyDisplay();
    
    b.makeBlock();
    b.moveCurBlockDown();
    b.rotateAntiClockwise();
    b.rotateAntiClockwise();
    b.rotateAntiClockwise();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.dropCurBlock();
    b.notifyDisplay();
    
    b.makeBlock();
    b.moveCurBlockRight();
    b.moveCurBlockLeft();
    b.moveCurBlockDown();
    b.rotateClockwise();
    b.rotateClockwise();
    b.rotateClockwise();
    b.rotateAntiClockwise();
    b.rotateAntiClockwise();
    b.rotateAntiClockwise();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.dropCurBlock();
    b.moveCurBlockRight();
    b.dropCurBlock();
    b.notifyDisplay();
>>>>>>> e4c5f8966d83b3c1dbe8109b2396cd2f0163512e

 //   b.makeBlock();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockLeft();
 //   b.moveCurBlockRight();
 //   b.moveCurBlockRight();
 //   b.rotateAntiClockwise();
 //   b.rotateAntiClockwise();
 //   b.dropCurBlock();
    //b.moveCurBlockDown();
    //b.moveCurBlockDown();
    b.notifyDisplay();
	cout << b;
	cin.get();

}

