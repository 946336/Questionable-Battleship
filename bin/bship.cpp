#include <cstdlib>
#include <cstdio>
#include <string>

#include "bship.h"

int bship::INIT_FAILURE = 1;

std::string bship::termPipe(std::string cmd){
	std::string ret;
	char buf[256];
	FILE *stream = popen(cmd.c_str(), "r");
	if(stream){
		if(!feof(stream)){
			if(fgets(buf, 255, stream) == NULL){
				log("Failed to get response for the following command:");
				log(cmd);
			}
		}
	}
	pclose(stream);

	log("Command: " + cmd);
	log("Response: " + std::string(buf));

	// I'm not currently familiar with standard c-string handling
	ret = std::string(buf);
	// You can't return a termporary object, but how is ret less
	// temporary than buf?
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
