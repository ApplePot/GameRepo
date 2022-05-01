#include "player.h"
#include <fstream>
#include <string>

//player.txt will contain 5 lines of numbers
//the first line is player health
//the second line is player sanity
//the third line is player hunger
// the forth line contains the number of unique equipment slots (max 3)
// the fifth line is a series of number that corresponds to the equipments that the player has (max 5)
//e.g. initially
//250
//250
//250
// 0
//0 0 0 0 0
//after mod,
//150
//200
//200
//3
//1 2 5 5 2



//load data from player.txt and copy it to player object
void loadFromFile(Player &p) {

	ifstream ifile;
	ifile.open("player.txt");

	//set the player stats
	int file_input;

	//input health
	cin >> file_input;
	p.health = file_input;

	//input sanity
	cin >> file_input;
	p.sanity = file_input;

	//input hunger
	cin >> file_input;
	p.hunger = file_input;

	//input number of unique items in slot
	cin >> file_input;
	p.equipNumType = file_input;

	//load player equipment
	string last_line;
	getline(cin, last_line);
	int i = 0;
	for (char c : last_line) {
		if (!isspace(c)) {
			p.slots[i] = (int)c;
			i++;
		}
	}
	

	ifile.close();

}

//overwrite the current data in player.txt
//if opt is 'n', overwrite the current data in player.txt with default values (250, 250, 250)
//else, save player stats into player.txt
void saveToFile(Player p, char opt) {

	ofstream ofile;
	ofile.open("play.txt");

	//save current stats to player.txt
	if (opt == 'y') {

		ofile << p.health << endl;
		ofile << p.sanity << endl;
		ofile << p.hunger << endl;
		ofile << p.equipNumType << endl;
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
