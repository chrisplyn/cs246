
#include "board.h"
#include "cell.h"
#include <string>
#include <sstream>

using namespace std;


int main(int argc, const char * argv[])
{
    string commandline;
    string displayMode;
    string filename;
    int seed;
    int startLevel;
    istringstream ss(argv[0]);
    
    while (ss.fail()) {
        ss>>commandline;
        if (commandline=="text")
        {
            displayMode = "text";
        } else if (commandline=="seed") {
            ss>>seed;
        } else if (commandline=="startlevel") {
            ss>>startLevel;
        } else if (commandline=="scriptfile") {
            ss>>filename;
        }
    }

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

