#ifndef CONFIGGEN_H
#define CONFIGGEN_H

#include <string>
#include <cstdlib>
#include <cstdio>
#include "config.h"

bool checkPermissions();
bool canReadWrite();

bool exists(std::string name);
bool spawnMainConfig();
bool writeFile(std::string relPathFromRoot, std::vector<std::string> source);

std::string i2s(int num);
int s2i(std::string str);

void bumpLogs();
void logHeader();

#endif
