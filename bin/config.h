#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

namespace bship {

	static std::string version = "VER 0.00.001";
	static std::string dev = "(c) 946336";
	static std::string title = "Questionable Battleship";
	static std::string backMessage = "q to go back";

	std::string getRoot();
	void log(std::string message);

	static std::vector<std::string>::iterator it;
	static std::string root = bship::getRoot();
	static std::string logs = bship::getRoot() + "logs/";
}

#endif
