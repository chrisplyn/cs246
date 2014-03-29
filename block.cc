#include "block.h"
#include <string>
using namespace std;

Block::Block(string type){
    this->type = type;
    for (i=0; i<4; ++i) {
        this->cells[i] = NULL;
    }
}

Block::~Block(){}

string getType::Block(){
    return type;
}