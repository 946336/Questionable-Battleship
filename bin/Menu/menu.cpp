#include "menu.h"
#include "dynamicArray.h"

#include <fstream>
#include <iostream>

void whee(){
	bship::log("Wheeeeeeeee");
	screen_home();
}

MainMenu::MainMenu(){
	std::ifstream readLogo;
	std::string path = bship::root + "resources/ASCII/menu/main/splash.txt";
	std::cerr << path << std::endl;
	readLogo.open(path.c_str());
	if(readLogo.is_open()){
		std::string temp;
		while(getline(readLogo, temp)){
			std::cerr << temp << std::endl;
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
}

MainMenu::MainMenu(const MainMenu &source){
	el = source.el;
	logo = source.logo;
}

MainMenu::MainMenu(const std::string *lb,
		const MenuElement::MenuCallback *cb, const int len){

	std::ifstream readLogo;
	std::string path = bship::root + "resources/ASCII/menu/main/splash";
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
}

MainMenu::MainMenu(const MenuElement::MenuCallback *cb,
			const std::string *lb, const int len){
	
	std::ifstream readLogo;
	std::string path = bship::root + "resources/ASCII/menu/main/splash";
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
}

MainMenu::~MainMenu(){
	// Nothing to do here
}

MainMenu& MainMenu::operator= (const MainMenu &source){
	if(this != &source){
		el = source.el;
		logo = source.logo;
	}
	return *this;
}

MainMenu& MainMenu::operator+ (const MenuElement &source){
	el += source;
	return *this;
}

MainMenu& MainMenu::operator+= (const MenuElement &source){
	el += source;
	return *this;
}

void MainMenu::add(MenuElement toAdd){
	el += toAdd;
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
