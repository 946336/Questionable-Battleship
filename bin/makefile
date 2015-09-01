# Makefile for the contents of Battleship/bin/

CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=gnu++11
UNUSED = -Wno-unused-function
O = -c

default: main.cpp config.o configGen.o bship.o termfuncs.o menuElement.o \
	utilStructures.o dynamicArray.o menu.o frame.o scrollBox.o
	$(CXX) $(CXXFLAGS) $^ -o bship

menu: test.cpp utilStructures.o dynamicArray.o menuElement.o frame.o \
			config.o menu.o termfuncs.o bship.o
	$(CXX) $(CXXFLAGS) $^ -o $@

configGen.o: configGen.cpp config.cpp

bship.o: bship.cpp termfuncs.cpp config.cpp

clean:
	rm *.o
