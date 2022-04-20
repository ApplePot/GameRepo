#include "player.h"
#include <ifstream>
#include <string>

//player.txt will contain 5 lines of numbers
//the first line is player health
//the second line is player sanity
//the third line is player hunger
//the forth line contains a series of numbers
// the fifth line contain the number of occupied equipment slots (max 3)
// the sixth line is a series of number that corresponds to the equipments that the player has (max 5)
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
void loadFromFile(const Player &p) {

	istream file("player.txt");
	//set the player stats
	int file_input;
	//input health
	cin >> file_input;
	p.health = stoi(file_input);
	//input sanity
	cin >> file_input;
	p.sanity = stoi(file_input);
	//input hunger
	cin >> file_input;
	p.hunger = stoi(file_input);
	//input number of unique items in slot
	cin >> file_input;
	p.equipNumType = stoi(file_input);

	//load player equipment
	string last_line;
	getline(cin, last_line);
	
	

}

//auto save player stats every 10 turns
//can overwrite the current data in player.txt
//if opt is 'n', overwrite the current data in player.txt with default values
//else, save player stats into player.txt
void saveToFile(Player p, char opt) {


	//if player.txt is empty
	

	//if player.txt has stats


}
