#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Screen.h"
#include "player.h"
#include "Equipments.h"
#include "calGPA.h"
#include "save_load.h"

//to implement system function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

//a dynamic array that stores the marks of random quizes
//since quizes are random events, the size of the array that stores marks can not be fixed
//start with 5, expand the array if necessary
int* marks = new int[5];

//size is the current size of the array
//iter is the index of the last element in marks dynamic array
void add_mark(int* &marks, int mark, int &size, int &iter) {

	//extend the dynamic array if the current array do not allow addition of mark
	if (size + 1 > 5) {

		//initialize a new, temporary dynamic array whose size is doubled
		int* temp = new int[size * 2];

		//copy old array content into new temp array
		for (int i = 0; i < iter + 1; i++) {
			temp[i] = marks[i];
		}

		//update array size
		size *= 2;
		delete[]marks;
		marks = temp;
		delete[] temp;
	}
	//adding a mark element to the array
	else {
		marks[iter + 1] = mark;
		iter++;
	}

}


int main() {

	bool endGame = false;

	//keep track of the size of dynamic array
	int marks_size = 5;
	int numOfQuiz = 0;

	//variable chance of occurance of random events
	//default is 20, 25 in ez mode
	//the integer variable is the divisor, so a larger value represents a lower chance, vice versa
	int base = 20;

	//variable chance of item drops
	//default is 15, 10 in ez mode
	int base_item = 15;
	
	//instantiate a player object
	Player p;

	//set player stats from player.txt
	loadFromFile(p);

	//display title screen
	printTitleScreen(base, base_item);

	//save the number of turns
	int turns = 1;

	//save the number of days
	int days = 0;

	//the entire game runs inside this while loop
	//auto save every 3 turns
	//the game lasts 10 days, 30 turns
	while (!endGame) {

		//end the game
		if (days == 10) {
			printEndScreen(p, 10);
		}

		//updates days every 3 turns
		else {
			if (turns % 3 == 0) {
				days++;
			}
		}











		turns++;
	}

	
	delete[] marks;

	return 0;
}
