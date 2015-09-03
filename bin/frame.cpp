#include "frame.h"
#include "bship.h"
#include "menu.h"
#include "configGen.h"
#include "config.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using std::string;

const string VBAR = "│";
const string HBAR = "─";
const string TRC = "┐";
const string LRC = "┘";
const string LLC = "└";
const string TLC = "┌";
const string LEDGE = "┤";
const string REDGE = "├";

Frame::Frame(){
	dims = Dimensions();
	frame = NULL;
	c = new MainMenu;
}

Frame::Frame(int i, int j){
	dims = Dimensions(i, j);

	frame = new std::string*[i];
	for(int q = 0; q < i; ++q){
		frame[q] = new std::string[j];
		for(int w = 0; w < j; ++w){
			// frame[q][w] = i2s(q%10);		// Debug fill
			frame[q][w] = " ";
		}
	}
	c = new MainMenu;
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
	c = new MainMenu;
}

Frame::Frame(const Frame &source){
	if(frame != NULL){
		for(int i = 0; i < dims.x; ++i){
			delete [] frame[i];
		}
		delete [] frame;
	}

	dims = source.dims;

	frame = new std::string*[dims.x];
	for(int q = 0; q < dims.x; ++q){
		frame[q] = new std::string[dims.y];
		for(int w = 0; w < dims.y; ++w){
			frame[q][w] = source.frame[q][w];
		}
	}
	deduceTypeAndDelete(c);
}

Frame::~Frame(){
	if(frame != NULL){
		for(int i = 0; i < dims.x; ++i){
			delete [] frame[i];
		}
		delete [] frame;
	}
	auto d = static_cast<MainMenu*>(c);
	delete d;
}

void Frame::deduceTypeAndDelete(MBC *pointer){
	switch(c->mode){
		case MBC::MODE::MAIN:
		pointer = static_cast<MainMenu*>(pointer);
		delete c;
		break;
	}
}

void Frame::changeDims(int i, int j){
	if(frame != NULL){
		for(int q = 0; q < dims.x; ++q){
			delete [] frame[q];
		}
		delete [] frame;
	}

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
	if(frame != NULL){
		for(int q = 0; q < dims.x; ++q){
			delete [] frame[q];
		}
		delete [] frame;
	}

	dims = dim;

	frame = new std::string*[dims.x];
	for(int q = 0; q < dims.x; ++q){
		frame[q] = new std::string[dims.y];
		for(int w = 0; w < dims.y; ++w){
			frame[q][w] = " ";
		}
	}
}

MBC *Frame::changeMenu(MBC *newMenu){
	if(newMenu == NULL) return NULL;
	if(newMenu == c) return newMenu;

	MBC *temp = c;
	c = newMenu;
	newMenu->last = temp;

	this->disp();

	return temp;
}

void Frame::up(){
	--(c->selected);
	// TODO: Check for scrollBoxes
}

void Frame::down(){
	++(c->selected);
	// TODO: Check for scrollboxes
}

MBC *Frame::getLast(){
	return c->last;
}

void Frame::back(){
	changeMenu(c->last);
}

bool Frame::select(){
	// run the callback, change menus and note last
	std::cerr << "BUTTON HAS BEEN PRESSED";
}

void Frame::disp(){
	int x = dims.x, y = dims.y;
	for(int i = 0; i < y; ++i){
		for(int j = 0; j < x; ++j){
			std::cout << frame[j][i];
		}
		std::cout << std::endl;
	}
}

void Frame::fillEdge(){
	// Fill in the edges, sans corners
	for(int i = 1; i < dims.x - 1; ++i){
		frame[i][0] = frame[i][dims.y - 1] = HBAR;
	}
	for(int i = 1; i < dims.y - 1; ++i){
		frame[0][i] = frame[dims.x - 1][i] = VBAR;
	}
	// Fill in corners
	if(dims.x > 1 and dims.y > 1){
		frame[0][0] = TLC;
		frame[0][dims.y - 1] = LLC;
		frame[dims.x - 1][0] = TRC;
		frame[dims.x - 1][dims.y - 1] = LRC;
	}

	// Fill in verion information
	frame[3][0] = LEDGE;
	frame[4 + (int) bship::VERSION.length()][0] = REDGE;
	for(size_t i = 0; i < bship::VERSION.length(); ++i){
		frame[4 + i][0] = bship::VERSION[i];
	}
	// Fill in back message
	int startFrom = dims.x - 4 - bship::BACKMESSAGE.length();
	frame[startFrom - 1][0] = LEDGE;
	frame[dims.x - 4][0] = REDGE;
	for(size_t i = 0; i < bship::BACKMESSAGE.length(); ++i){
		frame[startFrom + i][0] = bship::BACKMESSAGE[i];
	}
	// Fill in game title
	frame[3][dims.y - 1] = LEDGE;
	frame[4 + (int) bship::TITLE.length()][dims.y - 1] = REDGE;
	for(size_t i = 0; i < bship::TITLE.length(); ++i){
		frame[4 + i][dims.y - 1] = bship::TITLE[i];
	}
	// Fill in dev name
	startFrom = dims.x - 4 - bship::DEV.length();
	frame[startFrom - 1][dims.y - 1] = LEDGE;
	frame[dims.x - 4][dims.y - 1] = REDGE;
	for(size_t i = 0; i < bship::DEV.length(); ++i){
		frame[startFrom + i][dims.y - 1] = bship::DEV[i];
	}
}

// Delegate to specialized display functions.
void Frame::update(){
	// bship::log("Clearing frame");
	for(int i = 0; i < dims.x; ++i){
		for(int j = 0; j < dims.y; ++j){
			frame[i][j] = " ";
		}
	}

	fillEdge();

	switch (c->mode){
		case MBC::MODE::MAIN:
			// bship::log("@Main menu");
			updateMain();
			break;
	}
}

void Frame::updateMain(){
	// Allow access to MainMenu functionality
	MainMenu *d = static_cast<MainMenu*>(c);

	// Ensure menu selection wrapping
	d->selected = (d->selected + c->el.getSize()) % c->el.getSize();

	// bship::log("Printing logo");
	// Print logo
	// Centered horizontally
	int lStart = int (dims.x / 2) - (d->logo[0].length() / 2);
	// Starts a tenth of the way down
	int lVStart = std::max(1, int (0.1 * dims.y));

	int logoLines = d->logo.getSize();
	// Skip /r, /n, and \0 at the end of the string
	int logoLineLength = d->logo[0].length() - 3;
	for(int i = 0; i < logoLines; ++i){
		for(int j = 0; j < logoLineLength; ++j){
			frame[lStart + j][lVStart + i] = d->logo[i][j];
		}
	}

	// bship::log("Printing buttons");
	// Display menu selection elements
	int vStart = 2 * dims.y / 5;
	// int vDim = std::max(2, dims.y / 20);
	int vDim = 2;

	// Print all buttons
	string label;
	int numButtons = c->el.getSize();
	for(int i = 0; i < numButtons; ++i){
		label = c->el[i].getLabel();
		lStart = (dims.x / 2) - (label.length() / 2);
		for(size_t j = 0; j < label.length(); ++j){
			frame[lStart + j][vStart + i * vDim] =
				label[j];
		}
	}

	// bship::log("Highlighting button");
	int hiLen = d->maxLen() + 2;
	// Highlights start offset upwards by one
	--vStart;
	vStart = vStart + d->selected * vDim;
	lStart = (dims.x - hiLen) / 2 - 1;

	// Highlight selected button
	// Regular, no scrollbox behaviour
	if(d->text[d->selected] == NULL){
		// Fill corners
		frame[lStart][vStart] = TLC;
		frame[lStart][vStart + vDim] = LLC;
		frame[dims.x - lStart][vStart] = TRC;
		frame[dims.x - lStart][vStart + vDim] = LRC;

		// Fill edges
		for(int i = lStart + 1; i < dims.x - lStart; ++i){
			frame[i][vStart] = frame[i][vStart + vDim] = HBAR;
		}
		for(int i = vStart + 1; i < vStart + vDim; ++i){
			frame[lStart][i] = frame[dims.x - lStart][i] = VBAR;
		}
	}
	// Display scrollbox if one exists
	else{
		bship::log("Scrollbox detected");
	}
}