#include "menu.h"
#include "bship.h"
#include <iostream>
#include <string>

bship::Menu bship::makeMainMenu(){
	// Set up menu layers from the bottom up
	// We'll test the idea by starting with just two layers

	std::string splash[] = {"Ploy", "Load", "Settings", "Credits"};
	void (*fSplash[])() = {ployMenu, loadMenu, settingsMenu, creditsMenu};
	
	bship::Menu mainMenu = bship::Menu(fSplash, splash, 4);

	return mainMenu;
}

void ployMenu(){
	bship::log("Entering Play Menu");
	// Ploy menu
	std::string ploy[] = {"Forever Alone", "Absentee"};
	void (*fPloy[])() = {whee, why};
	bship::dispMenu(bship::Menu(fPloy, ploy, 2));
}

void loadMenu(){
	bship::log("Entering Load Menu");
	// Load menu
	std::string load[] = {"Load", "Delete"};
	void (*fLoad[])() = {again, Hi};
	bship::dispMenu(bship::Menu(fLoad, load, 2));
}

void settingsMenu(){
	bship::log("Entering Settings Menu");
	// Settings
	std::string settings[] = {"Volume", "Profanity", "Language"};
	void (*fSettings[])() = {whee, why, again};
	bship::dispMenu(bship::Menu(fSettings, settings, 3));
}

void creditsMenu(){
	bship::log("Entering Credits Menu");
	// Credits
	std::string credits[] = {"Moar"};
	void (*fCredits[])() = {whee};
	bship::dispMenu(bship::Menu(fCredits, credits, 1));
}
