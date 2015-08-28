#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

namespace bship{

	// This needs some work
	struct Frame{
		Frame();
		Frame(int r, int c);
		Frame(const Frame &source);
		~Frame();

		Frame& operator= (const Frame &source);

		int rows, cols;
		std::string** frame;
	};

}

#endif