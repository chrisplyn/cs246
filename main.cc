#include "board.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "trie.h"

using namespace std;


int main(int argc, const char * argv[])
{
    string commandline;
    string displayMode;
    string filename;
    int seed = 0; //default seed to 0
    int startLevel;
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
    
    // insert code here...
		
	Board b;
	ifstream f("/Users/wangxiangkang/Desktop/cs246/sequence.txt");
    //string temp;
    //while (!f.eof()) {
    //    f>>temp;
     //   cout<<temp<<endl;
    //}

   // cout<<f.is_open()<<endl;
    b.setInputStream(f);
	b.makeBlock();

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

    b.makeBlock();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.moveCurBlockLeft();
    b.moveCurBlockRight();
    b.moveCurBlockRight();
    b.rotateAntiClockwise();
    b.rotateAntiClockwise();
    b.dropCurBlock();
    //b.moveCurBlockDown();
    //b.moveCurBlockDown();
    b.notifyDisplay();
	cout << b;

}

