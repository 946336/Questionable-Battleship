#include <iostream>
#include <unistd.h>
#include <algorithm>
#include "config.h"

using std::string;
using std::pair;

// Runs from "ROOT/bin", which is why we discard the last four characters
string bship::getRoot(){
	string ROOTYO("FUUUUUUUUUUUUUUCK");
	char root[200];
	if(getcwd(root, 200) != NULL){
		ROOTYO = string(root);
		ROOTYO.erase(ROOTYO.end() - 4, ROOTYO.end());
		ROOTYO += "/";
	}
	return ROOTYO;
}

string bship::fromRoot(string path){
	return path.substr(ROOT.length() - 1);
}

void bship::log(string message){
	std::ofstream log((bship::LOGS + "log0").c_str(), std::ios_base::app);
	if(log.is_open()){
		log << message << std::endl;
		log.close();
	}
	else {
		// std::cout << "Failed to open " << std::endl;
		printf("Failed to open log file at [%s]\n",
			string(bship::LOGS + "log0").c_str());
	}
}

dynArray<bship::setPair> bship::readConfig(string path){
	std::ifstream rd(path);
	if(rd.is_open()){
		bship::log("Reading config file at " +
			fromRoot(path));
		// substr defaults to (0, string::npos)

		return parseSettingLines(rd);
	}
	else {
		log("Failed to open file at " + fromRoot(path));
		return dynArray<bship::setPair>();
	}
}

dynArray<bship::setPair> bship::parseSettingLines(std::ifstream &f){
	string line;
	int eq;
	dynArray<setPair> settings;
	setPair pr;

	while(getline(f, line)){
		// remove any whitespace in the line
		line.erase(std::remove_if(line.begin(), line.end(), isspace),
			line.end());
		
		// don't parse if the line is a comment or empty
		if(!line.empty() and
				(line[0] != bship::COMMENT[0] or line[0] != line[1])){

			eq = line.find('=');
			// ignore the '=' sign
			pr.first = line.substr(0, eq);
			pr.second = line.substr(eq + 1);
			settings.add(pr);
		}
	}
	return settings;
}
