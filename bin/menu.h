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

		enum MODE {MAIN, PLAY, OPTIONS, TEXT, GAME, PAUSE, SPLASH};

		// Is this how you typedef a pointer to a void function? 
		typedef void *(*fp)();		// see MenuElement::mcb
		typedef void *(*fap[])();	// top kek

		// Dump the "descriptors" of all menu elements
		dynArray<std::string> vomit();
		int maxLen();

		dynArray<std::string> getLogo();

	protected:
		dynArray<MenuElement> el;
		dynArray<std::string> logo;
		
		MenuBaseClass *last;
		int selected = 0;
		MODE mode;
};

using MBC = MenuBaseClass;

class MainMenu;
class PlayMenu;
class OptionsMenu;
class Creditsmenu;
class ProfileMenu;

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

		static void* goPlay();

	private:
		dynArray<fp> text;		// need to track which buttons have
								// scrollBoxes

		static PlayMenu *play;
};

class PlayMenu : public MenuBaseClass{
	public:
		friend class Frame;

		PlayMenu();
		PlayMenu(const PlayMenu &source);
		PlayMenu(MBC *from);
		~PlayMenu();

		PlayMenu& operator= (const PlayMenu &source);
	private:
		// Handle the LOAD ScrollBox
		dynArray<fp> text;
};

class OptionsMenu : public MenuBaseClass{
	 // 
};

#endif
