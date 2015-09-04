#ifndef MENU_ELEMENT_H
#define MENU_ELEMENT_H

#include <string>

struct MenuElement{
	public:
		typedef void *(*mcb)();

		MenuElement();
		MenuElement(const std::string lbl);
		MenuElement(mcb cbk);
		MenuElement(const std::string lbl, const mcb cbk);
		MenuElement(const mcb cbk, const std::string lbl);
		MenuElement(const MenuElement &source);
		~MenuElement();

		MenuElement& operator= (const MenuElement &source);

		void setLabel(std::string lbl);
		std::string getLabel();

		void setCallback(mcb mcbk);
		mcb callback();

	private:
		mcb cb;				// Callback
		std::string lb;		// Label
};



#endif
