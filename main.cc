
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
        }
    }
    
    srand(seed);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

