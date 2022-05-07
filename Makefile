FLAGS = -pedantic-errors -std=c++11

main.o : main.cpp events.h equipments.h
	g++ -c main.cpp

main: main.o
	g++ main.o -o main

tar:
	tar -czvf main.tgz *.cpp *.h
