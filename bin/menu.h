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
		MainMenu& operator+ (const MenuElement &source);
		MainMenu& operator+= (const MenuElement &source);
		MainMenu& operator++ (); // Prefix
		MainMenu operator++ (int dummy); // Postfix
		MainMenu& operator-- (); // Prefix
		MainMenu operator-- (int dummy); // Postfix

		// Add a menu entry
		void add(MenuElement toAdd);

		// Dump the "descriptors" of all menu elements
		dynArray<std::string> vomit();
		dynArray<std::string> getLogo();

	private:
		dynArray<MenuElement> el;
		dynArray<std::string> logo;
		dynArray<fp> text;		// need to track which buttons have
								// scrollBoxes
};

class OptionsMenu : public MenuBaseClass{
	 // 
};

#endif
