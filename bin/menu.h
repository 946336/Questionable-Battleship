#ifndef MENU_H
#define MENU_H

#include "dynamicArray.h"
#include "menuElement.h"
#include "dynamicArray.h"
#include "frame.h"
#include "config.h"

#include <string>

/*************************************************************************************/
class MenuBaseClass{
	public:
		friend class Frame;

		enum MODE {NONE, MAIN, OPTIONS, TEXT, GAME, PAUSE, SPLASH};

		// Is this how you typedef a pointer to a void function? 
		typedef void (*fp)();		// see MenuElement::mcb
		typedef void (*fap[])();	// top kek

	protected:
		dynArray<MenuElement> el;
		
		MenuBaseClass *last;
		int selected = 0;
		MODE mode;
};

using MBC = MenuBaseClass;

/*************************************************************************************/
class MainMenu : public MenuBaseClass{
	public:
		// Friendship is not inherited for complex reasons. :P
		friend class Frame;

		MainMenu();
		MainMenu(const MainMenu &source);
		MainMenu(const std::string *lb, const MenuElement::mcb *cb,
					const int len);
		MainMenu(const MenuElement::mcb *cb, const std::string *lb,
					const int len);
		~MainMenu();

		MainMenu& operator= (const MainMenu &source);

		// Dump the "descriptors" of all menu elements
		dynArray<std::string> vomit();
		dynArray<std::string> getLogo();

	private:
		dynArray<std::string> logo;
		dynArray<fp> text;		// need to track which buttons have
								// scrollBoxes
		int maxLen();
};

class OptionsMenu : public MenuBaseClass{
	 // 
};

#endif
