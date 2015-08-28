#ifndef CONFIGGEN_H
#define CONFIGGEN_H

#include <string>
#ifndef BSHIP_H
	#include "bship.h"
#endif

bool canReadWrite();
bool writeFile(std::string relPathFromRoot, std::vector<std::string> source);
bool exists(std::string name);
std::string i2s(int num);
void bumpLogs();

#endif
