# Makefile for testing and building this menu module

CXX = g++
FLAGS = -std=gnu++11 -Wall -Wextra
FLAG_MODULE = -c

menu: test.cpp utilStructures.o dynamicArray.o menuElement.o frame.o \
			config.o menu.o termfuncs.o
	$(CXX) $(FLAGS) $^ -o $@

termfuncs.o: ../termfuncs.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

element.o: menuElement.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

util.o: utilStructures.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

dynamicArray.o: dynamicArray.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

menu.o: menu.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

frame.o: frame.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

config.o: ../config.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

bship.o: ../bship.cpp
	$(CXX) $(FLAGS) $(FLAG_MODULE) $^

clean:
	rm *.o
