#ifndef CONFIGGEN_H
#define CONFIGGEN_H

#include <string>
#include <cstdlib>
#include <cstdio>
#include "config.h"

bool checkPermissions();
bool spawnMainConfig();
bool canReadWrite();
bool writeFile(std::string relPathFromRoot, std::vector<std::string> source);
bool exists(std::string name);
std::string i2s(int num);
void bumpLogs();

namespace bship{
	static std::vector<std::string> mainConfig {
		"// Hi! this is the main config file for Questionable Battleship.",
		"// Don't change things here unless you want to change them for all",
		"// players on this machine!",
		"",
		"Menu Animations=false",
		"Sound=false",
		"",
		"// options are: none, some, whee, superfluous,",
		"// OHGODWHYWOULDYOUWANTTHISMANY",
		"Game Animations=some",
		"",
		"// none, mild, lots, more",
		"// these names will change in game",
		"Profanity=none",
		"",
		"// 0-100",
		"Master Volume=100",
		"Menu Volume=100",
		"Game Volume=100",
		"SFX Volume=100",
		"",
		"// gives the ai an extra patrol boat and aircraft carrier",
		"WaitWhat=false",
		"// this number isn't the same as the \"name\" of the difficulty level!",
		"// those names are found within the ai config files",
		"Default Ai Difficulty Level=3",
		""
	};
}

#endif
