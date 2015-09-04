#include "menu.h"
#include "dynamicArray.h"
#include "termfuncs.h"
#include "bship.h"

#include <fstream>
#include <iostream>

/**************************************************************/

namespace {
	void* menuPlay(){
		auto cb = &MainMenu::goPlay;
		return cb;
	}
}

/*******************************************************************/

dynArray<std::string> MenuBaseClass::vomit(){
	dynArray<std::string> newList;

	for(int i = 0; i < el.getSize(); ++i){
		newList += el[i].getLabel();
	}
	return newList;
}

int MenuBaseClass::maxLen(){
	int lim = el.getSize();
	int len = -1;

	for(int i = 0 ; i < lim; ++i){
		if((int) el[i].getLabel().length() > len){
			len = (int) el[i].getLabel().length();
		}
	}
	return len;
}

dynArray<std::string> MenuBaseClass::getLogo(){
	return logo;
}

/******************************************************************/

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
	el += MenuElement("PLOY", menuPlay);
	el += MenuElement("CONTINUE", whee);
	el += MenuElement("OPTIONS", whee);
	el += MenuElement("PROFILE", whee);
	el += MenuElement("CREDITS", whee);
	el += MenuElement("QUIT", whee);

	size_t numEl = el.getSize();
	for(size_t i = 0; i < numEl; ++i){
		text += NULL;
	}

	// initialize all second-level menus
	play = new PlayMenu(this);
}

MainMenu::MainMenu(const MainMenu &source){
	el = source.el;
	logo = source.logo;
	selected = source.selected;
	text = source.text;

	play = source.play;
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

	play = new PlayMenu(this);
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

	play = new PlayMenu(this);
}

MainMenu::~MainMenu(){
	delete play;
}

MainMenu& MainMenu::operator= (const MainMenu &source){
	if(this != &source){
		el = source.el;
		logo = source.logo;
		selected = source.selected;
		text = source.text;

		play = source.play;
	}
	return *this;
}

void *MainMenu::goPlay(){
	return static_cast<void*> (&play);
}

/*************************************************************/

PlayMenu::PlayMenu(){
	mode = MBC::PLAY;

	el += MenuElement("NEW", whee);
	el += MenuElement("LOAD", whee);

	last = NULL;

	std::ifstream readLogo;
	std::string path = bship::ROOT + "resources/ASCII/menu/play/splash";
	readLogo.open(path.c_str());
	if(readLogo.is_open()){
		std::string temp;
		while(getline(readLogo, temp)){
			logo += temp;
		}
	}

	int len = el.getSize();
	for(int i = 0; i < len; ++i){
		text += NULL;
	}
}

PlayMenu::PlayMenu(const PlayMenu &source){
	mode = source.mode;
	el = source.el;
	last = source.last;
	text = source.text;
	logo = source.logo;
}

PlayMenu::PlayMenu(MBC *from){
	mode = MBC::PLAY;

	el += MenuElement("NEW", whee);
	el += MenuElement("LOAD", whee);

	last = from;

	std::ifstream readLogo;
	std::string path = bship::ROOT + "resources/ASCII/menu/play/splash";
	readLogo.open(path.c_str());
	if(readLogo.is_open()){
		std::string temp;
		while(getline(readLogo, temp)){
			logo += temp;
		}
	}

	int len = el.getSize();
	for(int i = 0; i < len; ++i){
		text += NULL;
	}
}

PlayMenu& PlayMenu::operator= (const PlayMenu &source){
	if(this != &source){
		mode = source.mode;
		el = source.el;
		last = source.last;
		text = source.text;
		logo = source.logo;
	}
	return *this;
}

PlayMenu::~PlayMenu(){
	// Nothing to do here
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
