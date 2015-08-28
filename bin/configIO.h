#ifndef CONFIGIO_H
#define CONFIGIO_H

#include <fstream>
#include <utility>
#include <map>
#ifndef BSHIP_H
	#include "bship.h"
#endif

using std::string;
using std::vector;
using std::pair;

namespace bship{
	static string	EQUALS		= "=";

	pair<string, string> *parseSetting(std::ifstream &f);

	// holy shit what the fuck plswhy
	void writeSettings(std::ofstream &f, vector<pair<string, string> > settingData);
	void writeSetting(std::ofstream &f, pair<string, string> settingPair);
	void writeSetting(std::ofstream &f, string name, string value);

	void comment(std::ofstream &f, string comment);
}

#endif