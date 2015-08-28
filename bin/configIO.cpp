#include <fstream>
#include <utility>
#include <map>
#ifndef CONFIGIO_H
	#include "configIO.h"
#endif

using std::string;
using std::vector;
using std::endl;
using std::pair;

pair<string, string> *bship::parseSetting(std::ifstream &f){
	string line, name, value;

	std::getline(f, line);
	if(line.substr(0, 1) == bship::COMMENT) return NULL;

	int splitAt = line.find(bship::EQUALS);

	// pair up the part of the string before and after "="
	pair<string, string>* settingPair = 
		new pair<string, string>(line.substr(0, splitAt - 1),
			line.substr(splitAt + 1, string::npos));

	return settingPair;
}

void bship::writeSettings(std::ofstream &f, vector<pair<string, string> > settingData){
	vector<pair<string, string> >::iterator it = settingData.begin();

	while(it != settingData.end()){
		f << it->first << bship::EQUALS << it->second << endl;
		++it;
	}
}

void bship::writeSetting(std::ofstream &f, pair<string, string> settingPair){
	f << settingPair.first << bship::EQUALS << settingPair.second << endl;
}

void bship::writeSetting(std::ofstream &f, string name, string value){
	f << name << bship::EQUALS << value << endl;
}

void bship::comment(std::ofstream &f, string comment){
	f << bship::COMMENT << comment << endl;
}
