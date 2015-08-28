#include "readConfig.h"
#include <cctype>

// void bship::readSettings(Settings set){
// 	ifstream f;
// 	f.open(bship::ROOT + "battleship.config");
// }

void bship::parseSetting(std::string line, Settings set){
	if(line.substr(0,1) == bship::COMMENT) return;

	// Remove all spaces, convert all to lowercase
	for(size_t i = 0; i < line.length(); ++i){
		if(line[i] == " "){
			line.erase(i);
			--i;		// Account for the fact that everything
						// was shifted back
		}
		// Convert to lowercase
		line[i] = tolower(line[i]);
	}

	int splitAt = line.find(bship::EQUALS);
	std::string id = line.substr(0 splitAt - 1);
	str::string val = line.substr(splitAt + 1, std::string::npos);

	// Lookup table for settings?
}
