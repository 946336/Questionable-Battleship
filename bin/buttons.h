#ifndef BUTTONS_H
#define BUTTONS_H

#ifndef BSHIP_H
	#include "bship.h"
#endif
#ifndef STRUCTURES_H
	#include "structures.h"
#endif

namespace bship{

	typedef void (*FuncPoint)();

	class Menu{
	public:
		Menu();
		Menu(const Menu &source);
		Menu(FuncPoint *fp, std::string *entries, int len);
		~Menu();
		Menu &operator= (const Menu &source);

			using List = dynArray<std::string>;
			using fList = dynArray<FuncPoint>;

		bool up();
		bool down();
		// So how should this work?
		FuncPoint select();

		bool add(std::string entry);
		int numButtons();
		
		std::string*** getButtons(std::string ***buttonList, int w, int h);
			void clearFrames(std::string ***buttonList, int w, int h);
			void writeText(std::string ***buttonList, int w, int h);
			void highlight(std::string ***buttonList, int w, int h);

		void vomit();
	private:
		List items;
		int selected;
		fList cb;
	};

/*--------------------------------------------------------------------------*/

	// This needs some work, along with the contents of a frame
	void dispMenu(bship::Menu menu, std::string oneLineTitle =
				 "Questionable Battleship!");
	void drawFrame(Frame *frame);
}




#endif
