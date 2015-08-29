// configGen.cpp -- Generates the main config file for questionable
//					battleship if it doesn't already exist

#include <sys/stat.h>
#include <sstream>
#include <ctime>
#include "configGen.h"
#include <iostream>
#include <fstream>

using namespace std;

// write out the contents of the default config file
bool writeFile(string relPathFromRoot, vector<string> source){
	ofstream f(bship::root + relPathFromRoot, ios_base::trunc);
	if(f.is_open()){
		bship::it = source.begin();
		while(bship::it != source.end()){
			f << *bship::it++ << endl;
		}
		f.close();
		bship::log("Generated main config file");
		return true;
	}
	else{
		bship::log("Failed to create config file!");
		return false;
	}
}

// Test ability to read, write, and modify files
bool canReadWrite(){
	string testFile("configGen.cpp");
	string write("log");

	ifstream f;
	f.open(testFile.c_str());
	if(!f.is_open()){
		return false;
	}
	else {
		f.close();
	}

	ofstream writeTest(write.c_str(), ofstream::trunc);

	time_t currTime = time(NULL);
	bship::log(string(ctime(&currTime)));
	
	if(!writeTest.is_open()){
		cerr << "Write failed!\n";
		return false;
	}
	else {
		writeTest.close();
		remove(write.c_str());
	}
	return true;
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

void bumpLogs(){
	// push up all existing log designations, and overwrite the 20th one
	bship::log("Bumping logs");
	for(int i = 19; i >= 0; --i){
		string postfix = i2s(i);
		string newPostfix = i2s(i + 1);
		if(exists((bship::logs + "log" + postfix).c_str())) {
			rename((bship::logs + "log" + postfix).c_str(),
					(bship::logs + "log" + newPostfix).c_str());
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
