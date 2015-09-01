#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <fstream>
#include <tuple>
#include <string>
#include "dynamicArray.h"

namespace bship {

	using setPair = std::pair<std::string, std::string>;

	static std::string	COMMENT		= "//";

	std::string getRoot();
	std::string fromRoot(std::string path);

	void log(std::string message);

	static std::string ROOT = bship::getRoot();
	static std::string LOGS = bship::getRoot() + "logs/";

	dynArray<setPair> readConfig(std::string path = ROOT +
		"battleship.config");
	dynArray<setPair> parseSettingLines(std::ifstream &f);

	std::string findSetting(dynArray<setPair> lib, std::string name);
	std::string findSetting(std::string name, dynArray<setPair> lib);
}

#endif
