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

//call this function whenever the player want to view inventory
void viewInventory() {
	//get the number of items that the player has
	int counter = 0;
	for (int i=0;i<5;i++) {
		if (p.slots[i] == 0) {
			counter++;
		}
	}
	
	if (counter > 0) {
		cout<<"You currently have "<<counter<<" item(s)."<<endl;
		
		//print out all non-empty slots
		int i=0;
		while (p.slots[i] != 0) {
			if (i == 5) {
				break;
			}
			else {
				int id = p.slots[i];
				cout<<"===================================="<<endl;
				cout<<"Item Name: "<<equiplist[id -1].name<<endl;
				cout<<"Item description: "<<equiplist[id -1].description<<endl;
				cout<<"Item health bonus: "<<equiplist[id -1].health_mod<<endl;
				cout<<"Item sanity bonus: "<<equiplist[id -1].sanity_mod<<endl;
				cout<<"Item hunger bonus: "<<equiplist[id -1].hunger_mod<<endl;
				cout<<"===================================="<<endl;
			}
			i++;
		}
	}
	else {
		cout<<"Your inventory is empty.\n";
}
			

int main() {
	
	//stores the difficulty, 0 for ez, 1 for normal
	int opt=1;
	
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
	printTitleScreen(opt, base, base_item);

	//stores the number of days
	int days = 0;

	//the entire game runs inside this while loop
	//auto save every 3 turns
	//the game lasts 10 days, 30 turns
	while (!endGame) {
		
		//allows the player to view their inventory items
		char view;
		cout<<"Do you want to view your inventory (y/n)?\n";
		cin>>view;
		if (view == 'y') {
			viewInventory();
			system("pause");
			system("cls");	
		}
		
		//allows the player to save their current stats and equipments
		char save;
		cout<<"Do you want to save your progress (y/n)?\n";
		cin>>save;
		if (save == 'y') {
			saveToFile(p, save);
		}
		
		//presents question
		
		
		
		//presents quiz, depending on chance
		if (rollDice(base)) {
			cout<<"You suddenly remember that you have a quiz to attend!\n";
			numOfQuiz++;
			int m = randomMark(p);
			add_mark(marks, m, marks_size, numOfQuiz);
			cout<<"Your score for the quiz is "<<m<<endl;
		}

		//deduct 25 hunger points after every day
		p.hunger-=25;
		
		//check player stats
		checkStats(p, endGame);
		
		//end the game and show the player his/her gpa
		if (days == 12) {
			printEndScreen(p, days);
			break;
		}
		days++;
		
	}

	//free up memory after the program has ended
	delete[] marks;

	return 0;
}
