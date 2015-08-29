#include <fstream>
#include <iostream>
#include <unistd.h>
#include "config.h"

// Runs from "ROOT/bin", which is why we discard the last four characters
std::string bship::getRoot(){
	std::string ROOTYO("FUUUUUUUUUUUUUUCK");
	char root[200];
	if(getcwd(root, 200) != NULL){
		ROOTYO = std::string(root);
		ROOTYO.erase(ROOTYO.end() - 4, ROOTYO.end());
		// ROOTYO += "/";
	}
	return ROOTYO;
}

void bship::log(std::string message){
	std::ofstream log((bship::logs + "/log0").c_str(), std::ios_base::app);
	if(log.is_open()){
		log << message << std::endl;
		log.close();
	}
	else {
		// std::cout << "Failed to open " << std::endl;
		printf("Failed to open log file at [%s]\n",
			std::string(bship::logs + "\\log0").c_str());
	}
}
