#include "menu.h"
#include "dynamicArray.h"
#include "termfuncs.h"
#include "bship.h"

#include <fstream>
#include <iostream>

MainMenu::MainMenu(){
	last = NULL;
	selected = 0;
	mode = MBC::MAIN;

	std::ifstream readLogo;
	std::string path = bship::ROOT + "resources/ASCII/menu/main/splash";
	readLogo.open(path.c_str());
	if(readLogo.is_open()){
		std::string temp;
		while(getline(readLogo, temp)){
			logo += temp;
		}
	}
	else {std::cerr << "Failed to open file\n";}
	el += MenuElement("PLOY", whee);
	el += MenuElement("CONTINUE", whee);
	el += MenuElement("OPTIONS", whee);
	el += MenuElement("PROFILE", whee);
	el += MenuElement("CREDITS", whee);
	el += MenuElement("QUIT", whee);

	size_t numEl = el.getSize();
	for(size_t i = 0; i < numEl; ++i){
		text += NULL;
	}
}

MainMenu::MainMenu(const MainMenu &source){
	el = source.el;
	logo = source.logo;
	selected = source.selected;
	text = source.text;
}

MainMenu::MainMenu(const std::string *lb,
		const MenuElement::mcb *cb, const int len){

	selected = 0;
	mode = MBC::MAIN;
	std::ifstream readLogo;
	std::string path = bship::ROOT + "resources/ASCII/menu/main/splash";
	readLogo.open(path.c_str());
	if(readLogo.is_open()){
		std::string temp;
		while(getline(readLogo, temp)){
			logo += temp;
		}
	}

	for(int i = 0; i < len; ++i){
		el += MenuElement(lb[i], cb[i]);
	}

	size_t numEl = el.getSize();
	for(size_t i = 0; i < numEl; ++i){
		text += NULL;
	}
}

MainMenu::MainMenu(const MenuElement::mcb *cb,
			const std::string *lb, const int len){
	
	selected = 0;
	mode = MBC::MAIN;
	std::ifstream readLogo;
	std::string path = bship::ROOT + "resources/ASCII/menu/main/splash";
	readLogo.open(path.c_str());
	if(readLogo.is_open()){
		std::string temp;
		while(getline(readLogo, temp)){
			logo += temp;
		}
	}

	for(int i = 0; i < len; ++i){
		el += MenuElement(lb[i], cb[i]);
	}

	size_t numEl = el.getSize();
	for(size_t i = 0; i < numEl; ++i){
		text += NULL;
	}
}

MainMenu::~MainMenu(){
	// Nothing to do here
}

MainMenu& MainMenu::operator= (const MainMenu &source){
	if(this != &source){
		el = source.el;
		logo = source.logo;
		selected = source.selected;
		text = source.text;
	}
	return *this;
}

dynArray<std::string> MainMenu::vomit(){
	dynArray<std::string> newList;

	for(int i = 0; i < el.getSize(); ++i){
		newList += el.arr[i].getLabel();
	}
	return newList;
}

dynArray<std::string> MainMenu::getLogo(){
	return logo;
}

int MainMenu::maxLen(){
	int lim = el.getSize();
	int len = -1;

	for(int i = 0 ; i < lim; ++i){
		if((int) el[i].getLabel().length() > len){
			len = (int) el[i].getLabel().length();
		}
	}
	return len;
}

/*
Menus:
	Main
	Options
	Login
	Credits
	Profile
	CreateProfile
	Play
	NewGame

Screens:
	Game Over
	You Win
	Splash
	"Loading"
	Custom
	
Other:
	Popup
	Dialog Box (The pause menu is technically a dialog box)

*/
