/*
 * NextBlockImpl.cc
 *
 */

#include "NextBlockImpl.h"
#include <cstdlib>
using namespace std;

NextBlockImpl::NextBlockImpl(int level):level(level), input(0){
	failed = false;
}

double NextBlockImpl::generateUniformRand(){
	return rand() / double(RAND_MAX);
}

int NextBlockImpl::generateIndex(double *distribution){
	double unifRand = generateUniformRand();
	double flag = 0;

	for (unsigned i = 0; i < 7; ++i){
		flag += distribution[i];
		if (unifRand <= flag){
			return i;
		}
	}
	return -1;
}

void NextBlockImpl::setBlockDistribution(){
	if (level == 1){
		for (int i = 0; i < 7; ++i){
			distribution[i] = (double)1 / 6;
		}
		distribution[4] = distribution[5] = (double)1 / 12;
	}
	else if (level == 2){
		for (int i = 0; i < 7; ++i){
			distribution[i] = (double)1 / 7;
		}
	}
	else if (level == 3){
		for (int i = 0; i < 7; ++i){
			distribution[i] = (double)1 / 9;
		}
		distribution[4] = distribution[5] = (double)2 / 9;
	}
}


string NextBlockImpl::matchType(int index){
	string type;
	if (index == 0){
		type = "I";
	}
	else if (index == 1){
		type = "J";
	}
	else if (index == 2){
		type = "L";
	}
	else if (index == 3){
		type = "O";
	}
	else if (index == 4){
		type = "S";
	}
	else if (index == 5){
		type = "Z";
	}
	else{
		type = "T";
	}
	return type;
}
