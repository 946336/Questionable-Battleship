#include "menuElement.h"

MenuElement::MenuElement(){
	lb = std::string();
	cb = NULL;
}

MenuElement::MenuElement(const MenuElement &source){
	cb = source.cb;
	lb = source.lb;
}

MenuElement::MenuElement(const std::string lbl){
	lb = lbl;
	cb = NULL;
}

MenuElement::MenuElement(MenuElement::mcb cbk){
	lb = std::string();
	cb = cbk;
}

MenuElement::MenuElement(const std::string lbl, const MenuElement::mcb cbk){
	lb = lbl;
	cb = cbk;
}

MenuElement::MenuElement(const MenuElement::mcb cbk, const std::string lbl){
	lb = lbl;
	cb = cbk;
}

MenuElement::~MenuElement(){
	// stub
}

MenuElement& MenuElement::operator=(const MenuElement &source){
	if(this == &source){
		return *this;
	}
	cb = source.cb;
	lb = source.lb;
	return *this;
}

void MenuElement::setLabel(std::string lbl){
	lb = lbl;
}

std::string MenuElement::getLabel(){
	return lb;
}

void MenuElement::setCallback(MenuElement::mcb cbk){
	cb = cbk;
}

void MenuElement::callback(){
	cb();
}
