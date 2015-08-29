#ifndef BSHIP_H
#define BSHIP_H

#include "termfuncs.h"
#include "config.h"

namespace bship{
	static std::string	COMMENT		= "//";

	extern int 		INIT_FAILURE;

	std::string termPipe(std::string cmd);
}

// Sample functions
void whee();
void why();
void again();
void Hi();

#endif