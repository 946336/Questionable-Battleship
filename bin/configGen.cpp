// configGen.cpp -- Generates the main config file for questionable
//					battleship if it doesn't already exist

#include <sys/stat.h>
#include <sstream>
#include <ctime>
#include "configGen.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace bship{
	const std::vector<std::string> MAINCONFIG {
		"// Hi! this is the main config file for Questionable Battleship.",
		"// Don't change things here unless you want to change them for all",
		"// players on this machine!",
		"",
		"// Also, we don't do integrity checks here, so if you feel like",
		"// you've screwed something up, just delete this file and it'll",
		"// magically reappear next time you play, albeit with its",
		"// default values.",
		"",
		"menu_animations=false",
		"sound=false",
		"",
		"// options are: none, some, whee, superfluous,",
		"// OHGODWHYWOULDYOUWANTTHISMANY",
		"game_animations=some",
		"",
		"// none, mild, lots, more",
		"// these names will change in game",
		"profanity=none",
		"",
		"// 0-100",
		"// master_volume=100",
		"// menu_volume=100",
		"// game_volume=100",
		"// SFX_volume=100",
		"",
		"// gives the ai an extra patrol boat and aircraft carrier",
		"wait_what=false",
		"// this number isn't the same as the \"name\" of the difficulty level!",
		"// those names are found within the ai config files",
		"default_ai_difficulty_level=3",
		""
	};
}

// write out the contents of the default config file
bool writeFile(string relPathFromRoot, vector<string> source){
	ofstream f(bship::ROOT + relPathFromRoot);
	if(f.is_open()){
		vector<std::string>::iterator it = source.begin();
		while(it != source.end()){
			f << *it++ << endl;
		}
		f.close();
		bship::log("Generated file");
		return true;
	}
	else{
		bship::log("Failed to generate file!");
		return false;
	}
}

// Test ability to read, write, and modify files
// Also initializes the log header
bool canReadWrite(){
	string testFile("configGen.cpp");
	string write("write test\n");

	ifstream f;
	f.open(testFile.c_str());
	if(!f.is_open()){
		return false;
	}
	else {
		f.close();
	}

	ofstream writeTest(write.c_str(), ofstream::trunc);	
	
	if(!writeTest.is_open()){
		cerr << "Write failed!\n";
		return false;
	}
	else {
		writeTest.close();
		remove(write.c_str());
		logHeader();
	}
	return true;
}

void logHeader(){
	time_t currTime = time(NULL);
	bship::log(string(ctime(&currTime)));
	bship::log("Relative paths from: " + bship::ROOT.substr(0,
		bship::ROOT.length() - 1));
}

bool exists(string name){
	struct stat buffer;
	return (stat ((name).c_str(), &buffer) == 0);
}

string i2s(int num){
	stringstream ss;
	ss << num;
	string temp;
	ss >> temp;
	return temp;
}

int s2i(std::string str){
	return atoi(str.c_str());
}

void bumpLogs(){
	// push up all existing log designations, and overwrite the 20th one
	bship::log("------------------------------");
	bship::log("Bumping logs");
	for(int i = 19; i >= 0; --i){
		string postfix = i2s(i);
		string newPostfix = i2s(i + 1);
		if(exists((bship::LOGS + "log" + postfix).c_str())) {
			rename((bship::LOGS + "log" + postfix).c_str(),
					(bship::LOGS + "log" + newPostfix).c_str());
		}
	}
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
	bship::log("Checking for main config at: /battleship.config");
	if(!exists(bship::ROOT + "battleship.config")){
		if(!writeFile("battleship.config", bship::MAINCONFIG)){
			return false;
		}
		return true;
	}
	else {
		bship::log("Main config file detected");
		return true;
	}
}

string bship::findSetting(dynArray<setPair> lib, std::string name){
	int len = lib.getSize();
	for(int i = 0; i < len; ++i){
		if(lib[i].first == name){
			return lib[i].second;
		}
	}
	return string();
}

string bship::findSetting(std::string name, dynArray<setPair> lib){
	int len = lib.getSize();
	for(int i = 0; i < len; ++i){
		if(lib[i].first == name){
			return lib[i].second;
		}
	}
	return string();
}
