#include <iostream>
#ifndef READASCII_H
	#include "readASCII.h"
#endif

// Reads in a single picture at a time
// I suppose it wouldn't hurt to read character by character for
// efficiency's sake
bship::namedPic* bship::readImg(std::fstream &f){
	namedPic *newButton = new namedPic();
	std::string temp = "";
	if(!f.is_open()){
		bship::log("Failed to read menu button labels!");
		return NULL;
	}

	while(temp != ENDPIC){
		std::getline(f, temp);
		if(temp == std::string()) continue;
		if(temp[temp.size() - 1] == bship::ENDPICNAME){
			temp.pop_back();
			newButton->name = temp;
			continue;
		}
		newButton->img->insert(newButton->img->begin(), temp);
	}
	return newButton;
}

