#ifndef MENU_ELEMENT_H
#define MENU_ELEMENT_H

#include <string>

struct MenuElement{
	public:
		typedef void (*MenuCallback)();

		MenuElement();
		MenuElement(const std::string lbl);
		MenuElement(MenuCallback cbk);
		MenuElement(const std::string lbl, const MenuCallback cbk);
		MenuElement(const MenuCallback cbk, const std::string lbl);
		MenuElement(const MenuElement &source);
		~MenuElement();

		MenuElement& operator= (const MenuElement &source);

		void setLabel(std::string lbl);
		std::string getLabel();

		void setCallback(MenuCallback cbk);
		void callback();

	private:
		MenuCallback cb;	// Callback
		std::string lb;		// Label
};



#endif
