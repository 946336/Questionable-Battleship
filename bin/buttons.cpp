#ifndef BUTTONS_H
	#include "buttons.h"
#endif

#include <iostream>
#include <cstdlib>
#include <cmath>

const std::string		TLC		 = "┌";
const std::string		TRC		 = "┐";
const std::string		LLC		 = "└";
const std::string		LRC		 = "┘";
const std::string		VERT	 = "│";
const std::string		HORZ	 = "─";

bship::Menu::Menu(){
	selected = 0;
}

bship::Menu::Menu(FuncPoint *fp, std::string *entries, int len){
	cb = fList(fp, len);
	items = List(entries, len);
	selected = 0;
}

bship::Menu::Menu(const Menu &source){
	cb = source.cb;
	items = source.items;
	selected = source.selected;
}

bship::Menu& bship::Menu::operator= (const Menu &source){
	if(&source == this){
		return *this;
	}
	cb = source.cb;
	items = source.items;
	selected = source.selected;
	return *this;
}

bship::Menu::~Menu(){
	// stub
}

bool bship::Menu::up(){
	selected = (numButtons() + selected - 1) % numButtons();
	return true;
}

bool bship::Menu::down(){
	selected = (selected + 1) % numButtons();
	return true;
}

bool bship::Menu::add(std::string entry){
	return items.add(entry);
}

inline int bship::Menu::numButtons(){
	return items.getSize();
}

void bship::Menu::vomit(){
	for(int i = 0; i < numButtons(); ++i){
		std::cout << items[i] << std::endl;
	}
}

std::string*** bship::Menu::getButtons(std::string*** buttonList, int w, int h){
	// Clear frames
	clearFrames(buttonList, w, h);

	// Plonk words down
	writeText(buttonList, w, h);

	// Highlight selected button
	highlight(buttonList, w, h);
	return buttonList;
}

void bship::Menu::writeText(string ***buttonList, int w, int h){
	for(int k = 0; k < numButtons(); ++k){
		int start = (w - (int) items[k].length())/2;
		for(int i = 0; i < (int) items[k].length(); ++i){
			buttonList[k][h/2][i + start] = items[k][i];
		}
	}
}

void bship::Menu::highlight(string ***buttonList, int w, int h){
	buttonList[selected][0][0] = TLC;
	buttonList[selected][h - 1][0] = LLC;
	buttonList[selected][0][w - 1] = TRC;
	buttonList[selected][h - 1][w - 1] = LRC;
	for(int i = 1; i < w - 1; ++i){
		buttonList[selected][0][i] = buttonList[selected][h - 1][i] = HORZ;
	}
	for(int i = 1; i < h - 1; ++i){
		buttonList[selected][i][0] = buttonList[selected][i][w - 1] = VERT;
	}
}

void bship::Menu::clearFrames(string ***buttonList, int w, int h){
	for(int k = 0; k < numButtons(); ++k){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				buttonList[k][i][j] = " ";
			}
		}
	}
}

bship::FuncPoint bship::Menu::select(){
	return cb[selected];
}

void bship::dispMenu(bship::Menu menu, std::string oneLineTitle){
	Frame *frame = initGame();

	FuncPoint selection;
	int bWidth = frame->cols / 3;
	int bHeight = 3;

	// Create canvases
	std::string ***buttons = new std::string**[menu.numButtons()];
	for(int k = 0; k < menu.numButtons(); ++k){
		buttons[k] = new std::string*[bHeight];
		for(int i = 0; i < bHeight; ++i){
			buttons[k][i] = new std::string[bWidth];
			for(int j = 0; j < bHeight; ++j){
				buttons[k][i][j] = " ";
			}
		}
	}

	buttons = menu.getButtons(buttons, bWidth, bHeight);

	char action;
	do{
		buttons = menu.getButtons(buttons, bWidth, bHeight);

		screen_home();

		// Write one-liner to top of frame
		// Let's try a default value
		// std::string oneLineTitle("Questionable Battleship!");
		int start = (frame->cols - (int) oneLineTitle.length()) / 2;
		for(int i = 0; i < (int) oneLineTitle.length(); ++i){
			frame->frame[1][start + i] = oneLineTitle[i];
		}

		// Write things to the frame wheeeeeeeeeeeeeee
		for(int k = 0; k < menu.numButtons(); ++k){
			for(int i = 0; i < bHeight; ++i){
				for(int j = 0; j < bWidth; ++j){
					int start = (frame->cols - bWidth) / 2;
					frame->frame[3 + i + k*bHeight][start + j] = buttons[k][i][j];
				}
			}
		}
		// Mark lower-right corner of frame
		// frame->frame[frame->rows - 1][frame->cols - 1] = "#";

		// Display the frame wheeeeeeeeeee
		drawFrame(frame);

		action = std::tolower(getachar());
		switch(action){
		case 0x1B:
		case 'q':
			// screen_clear();
			break;
		case 'w':
			menu.up();
			continue;
		case 's':
			menu.down();
			continue;
		case ' ':
		case '\n':
			selection = menu.select();
			selection();
			screen_home();
			continue;
		default:
			continue;
		}
		break;	
	}while(action != 'q');

	for(int i = 0; i < menu.numButtons(); ++i){
		for(int j = 0; j < bHeight; ++j){
			delete [] buttons[i][j];
		}
		delete [] buttons[i];
	}
	delete [] buttons;

	delete frame;
}

void bship::drawFrame(Frame *frame){
	for(int i = 0; i < frame->rows; ++i){
		for(int j = 0; j < frame->cols; ++j){
			std::cout << frame->frame[i][j];
		}
		if(i != frame->rows - 1) std::cout << std::endl;
	}
}