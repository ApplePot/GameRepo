#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"

srand(time(NULL));

//rng function
//returns true with a probability of 1/base
bool rollDice(int base) {
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
	srand(time(NULL));

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

//return a random integer from 0 to 5, inclusive
int randomInt() {
	return rand() % 6 + 1;
}

//implement functions that presents different scenarios to the player


