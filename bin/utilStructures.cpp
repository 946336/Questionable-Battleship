#ifndef UTILSTRUCTURES_H
	#include "utilStructures.h"
#endif

/*******************************DIMENSIONS*************************************/
Dimensions::Dimensions(){
	x = y = z = Dimensions::NO_DIM;
}

Dimensions::Dimensions(int i){
	x = i;
	y = z = Dimensions::NO_DIM;
}

Dimensions::Dimensions(int i, int j){
	x = i;
	y = j;
	z = Dimensions::NO_DIM;
}

Dimensions::Dimensions(int i, int j, int k){
	x = i;
	y = j;
	z = k;
}

Dimensions::Dimensions(const Dimensions &source){
	x = source.x;
	y = source.y;
	z = source.z;
}

Dimensions::~Dimensions(){
	// stub
}

Dimensions& Dimensions::operator= (const Dimensions &source){
	if(this != &source){
		x = source.x;
		y = source.y;
		z = source.z;
	}
	return *this;
}
/*************************************************************************************/
