#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#ifndef BSHIP_H
	#include "bship.h"
#endif

namespace bship {

	static std::string version = "VER 0.00.001";
	static std::string dev = "(c) 946336";
	static std::string title = "Questionable Battleship";
	static std::string backMessage = "q to go back";

	std::string getRoot();
	void log(std::string message);

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

	static std::vector<std::string>::iterator it;
	static std::string root = bship::getRoot();
	static std::string logs = bship::getRoot() + "logs/";
}

#endif