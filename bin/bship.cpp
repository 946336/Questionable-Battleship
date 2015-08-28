#include <cstdlib>
#include <sstream>
#include <cstdio>

#ifndef BSHIP_H
	#include "bship.h"
#endif
#ifndef STRUCTURES_H
	#include "structures.h"
#endif

int bship::INIT_FAILURE = 1;

bship::Frame* bship::initGame(){
	std::stringstream ss;
	int fHeight, fWidth;

	// open pipe to get terminal dimensions
	string dims = termPipe("stty size");

	// create board of same width, one or two lines less in height
	// dims has format: "$ROWS $COLUMNS"
	ss << dims;
	ss >> fHeight >> fWidth;

	// Create bucket of things to print
	Frame *frame = new Frame(fHeight, fWidth);
	return frame;
}

std::string bship::termPipe(std::string cmd){
	string ret;
	char buf[16];
	FILE *stream = popen(cmd.c_str(), "r");
	if(stream){
		if(!feof(stream)){
			if(fgets(buf, 15, stream) == NULL){
				log("Failed to get response!");
			}
		}
	}
	pclose(stream);
	// I'm not currently familiar with standard c-string handling
	ret = string(buf);
	// You can't return a termporary object
	return ret;
}

void whee(){
	bship::log("Wheeeeeeeee");
	screen_home();
}
void why(){
	bship::log("Whyyyyyyyyyy");
	screen_home();
}
void again(){
	bship::log("Agaaaaaaaaaaaaain");
	screen_home();
}
void Hi(){
	bship::log("Hiiiiiiiiiiiiii");
	screen_home();
}
