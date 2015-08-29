// Sets up the environment for the Questionable Battleship

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "configGen.h"
#include "config.h"
#include "termfuncs.h"

using namespace std;


int main(){
	// Startup checks/maintenance
	bumpLogs();
	if(!checkPermissions()) exit(bship::INIT_FAILURE);
	if(!spawnMainConfig()) exit(bship::INIT_FAILURE);


	bship::log("Game initialized: Entering Main Menu");

	return 0;
}
