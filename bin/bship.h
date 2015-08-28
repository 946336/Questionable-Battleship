#ifndef BSHIP_H
#define BSHIP_H

#include "termfuncs.h"
#include "config.h"
#include "configGen.h"
#include "configIO.h"
#include "readASCII.h"
#include "dynamicArray.h"
#include "buttons.h"
#include "structures.h"

// #include "menu.h"  // Causes compilation error ._.

namespace bship{
	static std::string	COMMENT		= "//";

	extern int 		INIT_FAILURE;

	std::string termPipe(std::string cmd);

	Frame* initGame();
	void drawFrame(Frame *frame);
}

// Sample functions
void whee();
void why();
void again();
void Hi();

#endif