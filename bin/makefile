# Makefile for the contents of Battleship/bin/

CXX = g++
FLAGS = -Wall -Wextra -g -std=gnu++11
UNUSED = -Wno-unused-function
O = -c

default:
	$(CXX) $(FLAGS) $(O) $^ -o bship

config.o: config.cpp
	$(CXX) $(FLAGS) $(O) $^

configGen.o: configGen.cpp config.cpp
	$(CXX) $(FLAGS) $(O) $^

bship.o: bship.cpp termfuncs.cpp config.cpp
	$(CXX) $(FLAGS) $(O) $^

clean:
	rm *.o
