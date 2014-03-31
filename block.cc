#include "block.h"
#include <string>
using namespace std;

Block::Block(){
    for (int i=0; i<4; ++i) {
        this->cells[i] = NULL;
    }
}



