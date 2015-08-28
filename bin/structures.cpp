#ifndef STRUCTURES_H
	#include "structures.h"
#endif
#include <iostream>

bship::Frame::Frame(){
	rows = cols = 0;
	frame = NULL;
}

bship::Frame::Frame(int r, int c){
	rows = r;
	cols = c;
	frame = new std::string*[r];
	for(int i = 0; i < r; ++i){
		frame[i] = new std::string[c];
		for(int j = 0; j < c; ++j){
			frame[i][j] = " ";
		}
	}
}

bship::Frame::Frame(const bship::Frame &source){
	rows = source.rows;
	cols = source.cols;

	frame = new std::string*[rows];
	for(int i = 0; i < rows; ++i){
		frame[i] = new std::string[cols];
		for(int j = 0; j < cols; ++j){
			frame[i][j] = source.frame[i][j];
		}
	}
}

bship::Frame& bship::Frame::operator= (const bship::Frame &source){
	if(this == &source){
		return *this;
	}
	rows = source.rows;
	cols = source.cols;
	if(frame != NULL){
		frame = new std::string*[rows];
		for(int i = 0; i < rows; ++i){
			frame[i] = new std::string[cols];
			for(int j = 0; j < cols; ++j){
				frame[i][j] = source.frame[i][j];
			}
		}
	}
	return *this;
}

bship::Frame::~Frame(){
	for(int i = 0; i < rows; ++i){
		delete [] frame[i];
	}
	delete [] frame;
}