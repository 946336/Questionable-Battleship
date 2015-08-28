#ifndef MENU_H
#define MENU_H

#include "dynamicArray.h"
#include "menuElement.h"
#include "dynamicArray.h"
#include "frame.h"
#include "../config.h"

#include <string>

/*************************************************************************************/
class MenuBaseClass{
	public:
		friend class Frame;

		enum MODE {NONE, MENU, OPTIONS, TEXT, GAME, PAUSE, SPLASH};
};

typedef MenuBaseClass MBC;

/*************************************************************************************/
class MainMenu : public MenuBaseClass{
	public:
		MainMenu();
		MainMenu(const MainMenu &source);
		MainMenu(const std::string *lb, const MenuElement::MenuCallback *cb,
					const int len);
		MainMenu(const MenuElement::MenuCallback *cb, const std::string *lb,
					const int len);
		~MainMenu();

		MainMenu& operator= (const MainMenu &source);
		MainMenu& operator+ (const MenuElement &source);
		MainMenu& operator+= (const MenuElement &source);

		// Add a menu entry
		void add(MenuElement toAdd);

		// Dump the "descriptors" of all menu elements
		dynArray<std::string> vomit();
		dynArray<std::string> getLogo();

	private:
		dynArray<MenuElement> el;
		dynArray<std::string> logo;
};

class OptionsMenu : public MenuBaseClass{
	 // 
};

#endif
