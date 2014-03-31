
#ifndef NEXTBLOCKIMPL_H_
#define NEXTBLOCKIMPL_H_

#include <string>
#include <iostream>

class NextBlockImpl{

public:
	int level;
	bool failed;
	double distribution[7];
	std::istream *input;	// a ptr to the input stream of block
	NextBlockImpl(int );
	double generateUniformRand();	//generate a uniform(0,1) random variable
	int generateIndex(double *);  //based on the distribution of blocks, generate an index corresponding to one block
	std::string matchType(int );
	void setBlockDistribution();
};


#endif 