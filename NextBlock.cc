#include "NextBlock.h"
#include "NextBlockImpl.h"
using namespace std;

//ctor
NextBlock::NextBlock(int level): pImpl(new NextBlockImpl(level)){}

NextBlock::~NextBlock(){
	delete pImpl;
}

// return current level of block
int NextBlock::getLevel(){
	return pImpl->level;
}

// when level is 0, set blockstream
void NextBlock::setInputStream(istream &blockstream){
	pImpl->input = &blockstream;
}

// when level is 0, block is not randomly generated
string NextBlock::getNonRandomType(){
	string type;
	*(pImpl->input) >> type;
	pImpl->failed = pImpl->input->fail();
	return type;
}

bool NextBlock::noRandomType(){
	return pImpl->failed;
}

//when level is 1 or above, generate a random type of block
string NextBlock::getRandomType(){
	string type;
	int index;
	double distribution[7];
	if (pImpl->level == 1){
		for (int i = 0; i < 7; ++i){
			distribution[i] = (double) 1 / 6;
		}
		distribution[4] = distribution[5] = (double) 1 / 12;
	}
	else if (pImpl->level == 2){
		for (int i = 0; i < 7; ++i){
			distribution[i] = (double) 1 / 7;
		}
	}
	else if (pImpl->level == 3){
		for (int i = 0; i < 7; ++i){
			distribution[i] = (double) 1 / 9;
		}
		distribution[4] = distribution[5] = (double) 2 / 9;
	}

	index = pImpl->generateIndex(distribution);
	type = pImpl->matchType(index);
	return type;
}





