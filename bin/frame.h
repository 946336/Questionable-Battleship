#ifndef FRAME_H
#define FRAME_H

#include "utilStructures.h"
#include "menu.h"
#include <string>

// Why do I have to forward declare MenuBaseClass?
class MenuBaseClass;
using MBC = MenuBaseClass;

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

		MBC *changeMenu(MenuBaseClass *newMenu);

		// This is going to have to be a wrapper fucntion to properly
		// handle all types of menus
		void update();
		void fillEdge();

		void up();
		void down();
		MBC *getLast();
		bool select();
		void back();

		void disp();
	private:
		Dimensions dims;
		std::string **frame;
		MBC *c;

		// Specialized handling functions for various standard menus
		void updateMain();

		// To allow destructor to not leak
		void deduceTypeAndDelete(MBC *pointer);
};

#endif
