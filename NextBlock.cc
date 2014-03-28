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

// return true if input block stream is exhausted
bool NextBlock::noRandomType(){
	return pImpl->failed;
}

//when level is 1 or above, generate a random type of block
string NextBlock::getRandomType(){
	string type;
	int index;	
	pImpl->setBlockDistribution();
	index = pImpl->generateIndex(pImpl->distribution);
	type = pImpl->matchType(index);
	return type;
}





