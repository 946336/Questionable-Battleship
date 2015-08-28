#ifndef FRAME_H
#define FRAME_H

#include "utilStructures.h"
#include "menu.h"

#include <string>

class MenuBaseClass;

class Frame{
	public:
		Frame();
		Frame(int i, int j);
		// Z dimension ignored even if present
		Frame(const Dimensions dim);
		Frame(const Frame &source);
		~Frame();

		Frame& operator= (const Frame &source);

		// I feel like you should be allowed to write explicitly
		// to Frames as well
			// Copy contents of char-based container to specified
			// location?

		// This is expensive - use with caution!
		// Also wipes the frame
		void changeDims(int i, int j);
		void changeDims(Dimensions dim);

	private:
		Dimensions dims;
		std::string **frame;
		MenuBaseClass *c;
};

#endif
