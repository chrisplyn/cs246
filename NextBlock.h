#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <string>
#include <iostream>

class Board;
class NextBlock
{
public:
	NextBlock(int level);	//ctor
	~NextBlock();	//dtor
	int getLevel();	// return level of next block
	std::string getRandomType();	//return the type of next block, randomly
	std::string getNonRandomType(std::istream &blockstream);	//when level is 0, next block is determined by a stream
	void updateLevel();		

private:
	int level;		
	std::istream *input;	// a ptr to the input stream of block
	double generateUniformRand(double min, double max);	//generate a uniform(min, max) random variable
	int generateIndex(int *distribution);  //based on the distribution of blocks, generate an index corresponding to one block

};

#endif 