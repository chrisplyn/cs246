
#include "board.h"
#include "cell.h"
#include <cstdlib>
#include <string>
#include <sstream>

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
            seed = atoi(commandline.c_str());
        } else if (commandline=="startlevel") {
            ++i;
            commandline = argv[i];
            startLevel = atoi(commandline.c_str());
        } else if (commandline=="scriptfile") {
            ++i;
            filename = argv[i];
        } else if (commandline=="maxBlock") {
            ++i;
            commandline = argv[i];
            maxBlockAllowed = atoi(commandline.c_str());
        }
    }
    
    srand(seed);
    
    // insert code here...
		
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

