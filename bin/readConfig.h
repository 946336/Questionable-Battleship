#ifndef READCONFIG_H
#define READCONFIG_H

#include <string>
#include <sstream>
#include <fstream>
#ifndef BSHIP_H
	#include "bship.h"
#endif
#ifndef SETSTRUCT_H
	#include "setStruct.h"
#endif

namespace bship{
	static constexpr std::string	EQUALS		= "=";

	// void readSettings(Settings set);
	void parseSetting(std::string line, Settings set);
	void lookupSetting(std::string name, );

}

#endif