// Sets up the environment for the Questionable Battleship

#include <iostream>
#include <cstdio>
#ifndef BSHIP_H
	#include "bship.h"
#endif
#include "menu.h"
#include <cstdlib>

using namespace std;

bool checkPermissions();
bool spawnMainConfig();

int main(){
	// Startup checks/maintenance
	bumpLogs();
	if(!checkPermissions()) exit(bship::INIT_FAILURE);
	if(!spawnMainConfig()) exit(bship::INIT_FAILURE);

	bship::Menu menuMain = bship::makeMainMenu();

	bship::log("Game initialized: Entering Main Menu");

	screen_clear();
	bship::dispMenu(menuMain);
	screen_clear();

	return 0;
}

bool checkPermissions(){
	if(!canReadWrite()){
		// Possibly the most redundant line of code I've seen in my life
		// bship::log("Need read/write/modify permissions!");
		cerr << "Lack read/write/modify permissions in current directory. "
			 << "Questionable Battleship may not function correctly or at all."
			 << endl << std::flush;
		return false;
	}
	else return true;
}

bool spawnMainConfig(){
	if(!exists(bship::root + "battleship.config")){
		if(!writeFile("battleship.config", bship::mainConfig)){
			return false;
		}
		return true;
	}
	else {
		bship::log("Main config file detected, no write necessary");
		return true;
	}
}
