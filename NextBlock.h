#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <string>
#include <iostream>

class NextBlockImpl;
class NextBlock
{
public:
	NextBlock(int level);	//ctor param: level
	~NextBlock();			//dtor
	int getLevel();	// return level of next block
	std::string getRandomType();	//return the type of next block, randomly
	std::string getNonRandomType();	//when level is 0, next block is determined by a stream
	bool noRandomType();
	void setInputStream(std::istream &);	//set input block stream when level is 0

private:
	NextBlockImpl *pImpl; //use bridge pattern, if a new level is introduced, only NextBlock.cc needs
						  //to be recompiled.
};

#endif 
