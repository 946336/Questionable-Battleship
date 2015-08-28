#ifndef READASCII_H
#define READASCII_H

#include <vector>
#include <fstream>
#include <map>
#include <string>
#ifndef BSHIP_H
	#include "bship.h"
#endif

namespace bship{

	typedef std::vector<std::string>* pic;
	typedef std::vector<std::string> bmp;
	typedef std::map<std::string, pic> menu;

	struct namedPic{
		std::string name;
		pic img;
	};

	static std::string		ENDPIC 		= "#";
	static char				__attribute__((unused)) ENDPICNAME	= ':';

	namedPic *readImg(std::fstream &f);
	void printImg(std::string name);

}

#endif