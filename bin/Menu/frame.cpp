#include "frame.h"

Frame::Frame(){
	dims = Dimensions();
	frame = NULL;
}

Frame::Frame(int i, int j){
	dims = Dimensions(i, j);

	frame = new std::string*[i];
	for(int q = 0; q < i; ++q){
		frame[q] = new std::string[j];
		for(int w = 0; w < j; ++w){
			frame[q][w] = " ";
		}
	}
}

Frame::Frame(Dimensions dim){
	dims = dim;

	frame = new std::string*[dims.x];
	for(int q = 0; q < dims.x; ++q){
		frame[q] = new std::string[dims.y];
		for(int w = 0; w < dims.y; ++w){
			frame[q][w] = " ";
		}
	}
}

Frame::Frame(const Frame &source){
	for(int i = 0; i < dims.x; ++i){
		delete [] frame[i];
	}
	delete [] frame;

	dims = source.dims;

	frame = new std::string*[dims.x];
	for(int q = 0; q < dims.x; ++q){
		frame[q] = new std::string[dims.y];
		for(int w = 0; w < dims.y; ++w){
			frame[q][w] = source.frame[q][w];
		}
	}
}

Frame::~Frame(){
	for(int i = 0; i < dims.x; ++i){
		delete [] frame[i];
	}
	delete [] frame;
}

void Frame::changeDims(int i, int j){
	for(int q = 0; q < dims.x; ++q){
		delete [] frame[q];
	}
	delete [] frame;

	dims = Dimensions(i, j);
	frame = new std::string*[dims.x];
	for(int q = 0; q < dims.x; ++q){
		frame[q] = new std::string[dims.y];
		for(int w = 0; w < dims.y; ++w){
			frame[q][w] = " ";
		}
	}
}

void Frame::changeDims(Dimensions dim){
	for(int q = 0; q < dims.x; ++q){
		delete [] frame[q];
	}
	delete [] frame;

	dims = dim;

	frame = new std::string*[dims.x];
	for(int q = 0; q < dims.x; ++q){
		frame[q] = new std::string[dims.y];
		for(int w = 0; w < dims.y; ++w){
			frame[q][w] = " ";
		}
	}
}
