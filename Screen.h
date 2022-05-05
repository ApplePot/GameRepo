#include "save_load.h"
#include "calGPA.h"
#include "player.h"
#ifndef SCREEN_H
#define SCREEN_H

void printTitleScreen(int &opt, int &base, int &base_item) {

	cout << "====================================\n\n"; //there are 36 '='s
	cout << "\tStudent simulator 2022\t\t" << endl;
	cout << "====================================\n" << endl;
	//this prompts the player to give an input to start the game
	system("pause");
	//this clears the console output
	system("cls");
	cout << "How hard do you like your game? (Enter 0 for ez, 1 for normal)";

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

void printEndScreen(Player p, int days) {

	char opt;
	cout << "\t\tGame Over!"<<endl;
	//end because the player finished the game
	if (days == 10) {
		cout << "\tYour final GPA is: " << calGPA(p)<<endl;
		//reset data in player.txt
		SaveToFile(p, '');
		system("cls");
		exit(1);
	}
	//end because of negative or zero stats
	else {
		cout << "Would you like to save the current data? (y/n)\n";
		cin >> opt;
		SaveToFile(p, opt);
		}
	}
}

#endif
