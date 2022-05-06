#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "equipments.h"
#include "events.h"

//to implement system function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

//declare all functions

bool rollDice(int base);
int randomMark(Player p);
void checkStats(Player p, bool& endGame);
double calGPA(Player p, int* marks, int iter);
void printTitleScreen(int& opt, int& base, int& base_item);
void loadFromFile(Player& p);
void saveToFile(Player p, char opt);
void printEndScreen(Player p, int days, int numOfQuiz, int* marks);
void presentEvent(int opt, Player& p, int days);

//==================================================================================
//declare linked list for storing previous random number
struct Node {
	int value;
	Node* prev;
};

Node* tail = NULL;

//define functions

//rng function
//returns true with a probability of 1/base
bool rollDice(int base) {
	srand(time(0));
	int num;
	num = rand() % base;
	if (num == 0) {
		return true;
	}
	return false;
}

//returns the mark of random quizes based on player stats
int randomMark(Player p) {
	int base_mark;
	srand(time(0));

	//default player has 250 in all aspects
	int performance = p.health + p.sanity + p.hunger;
	if (performance >= 850) {
		base_mark = 65;
	}
	else if (performance <= 500) {
		base_mark = 40;
	}
	else {
		base_mark = 50;
	}
	return (rand() % (100 - base_mark)) + base_mark;
}

//check player stats and take actions
void checkStats(Player p, bool& endGame) {

	if (p.health <= 0) {
		endGame = true;
		return;
	}
	else if (p.sanity < 50) {
		if (p.sanity <= 0) {
			cout << "You have gone insane" << endl;
			endGame = true;
			return;
		}
		p.health -= 20;
	}
	else if (p.hunger < 50) {
		if (p.hunger <= 0) {
			cout << "You have fainted..." << endl;
			endGame = true;
			return;
		}
		p.health -= 25;
		p.sanity -= 25;
	}
	return;

}

//calculate the final GPA
double calGPA(Player p, int* marks, int iter) {

	double health_part = p.health / 400;
	double sanity_part = p.sanity / 400;
	double hunger_part = p.hunger / 400;
	double sum_mark = 0;
	for (int i = 0; i <= iter; i++) {
		sum_mark += marks[i];
	}
	double quiz_marks = sum_mark / (iter * 100);
	double total = hunger_part + sanity_part + hunger_part + quiz_marks;
	if (total >= 4.0) {
		return 4.0;
	}
	return total;

}

//prints the title screen
//lets the player choose difficulty
void printTitleScreen(int& opt, int& base, int& base_item) {
	
	cout << "====================================\n\n"; //there are 36 '='s
	cout << "\tStudent simulator 2022\t\t" << endl;
	cout << "====================================\n" << endl;
	//this prompts the player to give an input to start the game
	system("pause");
	//this clears the console output
	system("cls");
	cout << "How hard do you like your game? (Enter 0 for ez, 1 for normal)\n";

	cin >> opt;
	if (opt == 0) {

		//increase occurance of random item drops, decrease base_item, default is 20
		base_item = 10;

		//decrease chance of random events, increase base
		base = 25;
	}
	system("cls");
	return;

}

//load data from player.txt and copy it to a player object
void loadFromFile(Player& p) {

	ifstream ifile;
	ifile.open("player.txt");

	if (ifile.fail()) {
		cout << "Input file is missing and the game cannot proceed.\n";
		exit(1);
	}
	else {
		
		//input health
		ifile >> p.health>>p.sanity>>p.hunger>>p.numOfUniqueItem;

		//input equipment ids
		for (int i = 0; i < 5; i++) {
			ifile >> p.slots[i];
		}
		
	}
	ifile.close();

}

//overwrite the current data in player.txt
//if opt is 'n', overwrite the current data in player.txt with default values (250, 250, 250)
//else, save player stats into player.txt
void saveToFile(Player p, char opt) {

	ofstream ofile;
	ofile.open("player.txt");

	//save current stats to player.txt
	if (opt == 'y') {

		ofile << p.health << endl;
		ofile << p.sanity << endl;
		ofile << p.hunger << endl;
		ofile << p.numOfUniqueItem << endl;
		for (int i = 0; i < 5; i++) {
			if (i == 4) {
				ofile << p.slots[i];
			}
			else {
				ofile << p.slots[i] << " ";
			}
		}

	}

	//reset all player stats
	else {

		for (int i = 0; i < 3; i++) {
			ofile << 250 << endl;
		}

		ofile << 0 << endl;

		for (int i = 0; i < 5; i++) {
			if (i == 4) {
				ofile << 0;
			}
			else {
				ofile << 0 << " ";
			}
		}

	}

	ofile.close();

}

//presents the end screen
void printEndScreen(Player p, int days, int numOfQuiz, int* marks) {

	char opt = '0';
	cout << "\t\tGame Over!" << endl;
	//end because the player finished the game
	if (days == 10) {
		cout << "\tYour final GPA is: " << calGPA(p, marks, numOfQuiz) << endl;
		//reset data in player.txt
		saveToFile(p, opt);
		system("cls");
		exit(1);
	}
	//end because of negative or zero stats
	else {
		cout << "Would you like to save the current data? (y/n)\n";
		cin >> opt;
		saveToFile(p, opt);
	}
}

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
void viewInventory(Player p) {
	//get the number of items that the player has
	int counter = 0;
	for (int i=0;i<5;i++) {
		if (p.slots[i] != 0) {
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
		cout << "Your inventory is empty.\n";
	}
}

//prints the status of the player
void printStatus(Player p) {

	cout << "Health: " << p.health << " Sanity: " << p.sanity << " Hunger: " << p.hunger << endl;

}

void applyStatus(Player &p) {

	for (int id : p.slots) {
		if (id != 0) {
			p.hunger += equiplist[id-1].hunger_mod;
			p.health += equiplist[id-1].health_mod;
			p.sanity += equiplist[id-1].sanity_mod;
		}
	}

}

//initialize difficulty and load player stats
void initGame(Player &p, int &opt, int &base, int &base_item) {

	loadFromFile(p);
	applyStatus(p);
}

//presents question to the player randomly
void presentEvent(int opt, Player &p, int days) {

	//create a new node n
	//the value of n must no equal that of the previous node
	Node* n = new Node;
	int val = randomInt();

	//building the list to store previous value
	//the list has at least 1 node
	if (tail != NULL) {
		int prevNum = tail->value;
		while (val == prevNum) {
			val = randomInt();
		}
	}
	n->value = val;
	n->prev = tail;
	tail = n;
	
	
	switch (days) {
	case 0: case 1:
		//presents q1 to q6
		switch (val) {
		case 1:
			q1(opt, p);
			break;
		case 2:
			q2(opt, p);
			break;
		case 3:
			q3(opt, p);
			break;
		case 4:
			q4(opt, p);
			break;
		case 5:
			q5(opt, p);
			break;
		case 6:
			q6(opt, p);
			break;
		}
		break;
	case 2: case 3:
		//presents q7 to q12
		switch (val) {
		case 1:
			q7(opt, p);
			break;
		case 2:
			q8(opt, p);
			break;
		case 3:
			q9(opt, p);
			break;
		case 4:
			q10(opt, p);
			break;
		case 5:
			q11(opt, p);
			break;
		case 6:
			q12(opt, p);
			break;
		}
		break;
	case 4: case 5:
		//presents q13 to q18
		switch (val) {
		case 1:
			q13(opt, p);
			break;
		case 2:
			q14(opt, p);
			break;
		case 3:
			q15(opt, p);
			break;
		case 4:
			q16(opt, p);
			break;
		case 5:
			q17(opt, p);
			break;
		case 6:
			q18(opt, p);
			break;
		}
		break;
	}
	
}

int main() {
	
	//stores the difficulty, 0 for ez, 1 for normal
	int opt=1;
	
	bool endGame = false;

	//keep track of the size of dynamic array
	int marks_size = 5;
	int numOfQuiz = 0;

	//variable chance of occurance of random quizes
	//default is 5, 10 in ez mode
	//the integer variable is the divisor, so a larger value represents a lower chance, vice versa
	int base = 5;

	//variable chance of item drops
	//default is 15, 10 in ez mode
	int base_item = 15;
	
	//instantiate a player object
	Player p;

	//intialize the game
	initGame(p, opt, base, base_item);
	
	//display title screen
	printTitleScreen(opt, base, base_item);

	//stores the number of days
	int days = 0;

	//the entire game runs inside this while loop
	//auto save every 3 turns
	//the game lasts 10 days, 30 turns
	while (!endGame) {
		
		printStatus(p);
		//allows the player to view their inventory items
		char view;
		cout<<"Do you want to view your inventory (y/n)?\n";
		cin>>view;
		system("cls");
		if (view == 'y') {
			printStatus(p);
			viewInventory(p);
			system("pause");
			system("cls");	
		}
		
		//allows the player to save their current stats and equipments
		char save;
		cout<<"Do you want to save your progress (y/n)?\n";
		cin>>save;
		if (save == 'y') {
			printStatus(p);
			saveToFile(p, save);
		}
		system("cls");

		printStatus(p);
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

		//end the game and show the player his/her gpa
		if (days == 12) {
			printEndScreen(p, days, numOfQuiz, marks);
			break;
		}

		days++;

		saveToFile(p, 'y');
		system("cls");
		cout << "Auto saved progress\n";
		cout << "The next day.." << endl;
		system("pause");
		system("cls");

		//check player stats
		checkStats(p, endGame);
		
	}
	system("pause");

	//free up memory after the program has ended
	delete[] marks;
	exit(1);
	return 0;
}
