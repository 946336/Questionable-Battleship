# Makefile for the contents of Battleship/bin/

CXX = g++
FLAGS = -Wall -Wextra -g -std=gnu++11 -Wno-unused-function
O = -c
ALLFILES = bship.cpp config.cpp configGen.cpp configIO.cpp readASCII.cpp \
			dynamicArray.cpp buttons.cpp termfuncs.cpp menu.cpp \
			structures.cpp

bship: initialize.cpp
	$(CXX) $(FLAGS) $^ $(ALLFILES) -o $@

test:
	$(CXX) $(FLAGS) test.cpp $(ALLFILES) $^ -o $@

mconf: configGen.cpp initialize.cpp config.cpp
	$(CXX) $(FLAGS) $^ -o $@

conf: config.cpp
	$(CXX) $(FLAGS) $(O) $^

confh: config.h
	$(CXX) $(FLAGS) $(O) $^

confgen: configGen.h
	$(CXX) $(FLAGS) $(O) $^

ascread: config.cpp readASCII.cpp 
	$(CXX) $(FLAGS) $(O) $^

dynArr: dynamicArray.h
	$(CXX) $(FLAGS) $^ $(O)

buttons: dynamicArray.h buttons.cpp bship.h
	$(CXX) $(FLAGS) $^ $(O)

clean:
	rm mconf test conf confh confgen ascread bship dynArr buttons