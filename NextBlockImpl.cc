/*
 * NextBlockImpl.cc
 *
 *  Created on: Mar 27, 2014
 *      Author: Yinuo Liu
 */

#include "NextBlockImpl.h"
#include <cstdlib>
using namespace std;

NextBlockImpl::NextBlockImpl(int level):level(level), input(0){}

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
