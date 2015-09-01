#ifndef BSHIP_H
#define BSHIP_H

#include "termfuncs.h"
#include "config.h"

namespace bship{
	extern int 		INIT_FAILURE;

	static std::string VERSION = "VER 0.00.001";
	static std::string DEV = "(c) 946336";
	static std::string TITLE = "Questionable Battleship";
	static std::string BACKMESSAGE = "'q' to go back";

	std::string termPipe(std::string cmd);
}

// Sample functions
void whee();
void why();
void again();
void Hi();

#endif