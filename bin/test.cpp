#include "menu.h"
#include <iostream>

using std::endl;
using std::cout;

int main(){

	MainMenu menuMain;

	auto list = menuMain.vomit();
	auto logo = menuMain.getLogo();

	for(int i= 0; i < logo.getSize(); ++i){
		cout << logo[i] << endl;
	}

	for(int i = 0; i < list.getSize(); ++i){
		cout << list[i] << endl;
	}

	return 77;
}
