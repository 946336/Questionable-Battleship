// Sets up the environment for the Questionable Battleship

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "configGen.h"
#include "config.h"
#include "termfuncs.h"
#include "bship.h"
#include "frame.h"

using namespace std;

int main(){
	// Startup checks/maintenance
	bumpLogs();
	if(!checkPermissions()) exit(bship::INIT_FAILURE);
	if(!spawnMainConfig()) exit(bship::INIT_FAILURE);

	auto settings = bship::readConfig();

	bship::log("Game initialized.");

	int x = s2i(bship::termPipe("tput cols"));
	int y = s2i(bship::termPipe("tput lines"));

	Frame frame(x, y - 1);

	char action;
	bool DONE = false;

	// Command loop
	while(!DONE){
		frame.update();
		frame.disp();

		switch (action = std::tolower(getachar())){
			case 'q':
				// bship::log("Going back");
				DONE = true;
				screen_clear();
				break;
			case 'w':
				frame.up();
				break;
			case 's':
				frame.down();
				break;
			case '\n':
				// bship::log("Entering");
				frame.select();
				break;
			default:
				continue;
		}
		// cerr << action;
		screen_home();
	}

	bship::log("Exiting game");
	return 0;
}
