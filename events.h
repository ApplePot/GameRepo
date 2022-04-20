#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"

//rng function
//returns true with a probability of 1/base
bool rollDice(int base) {
	int num;
	srand(time(NULL));
	num = rand() % base;
	if (num == 0) {
		return true;
	}
	return false;
}

//returns the mark of random quizes given player stats
int randomMark(Player p) {
	int base_mark;
	srand(time(NULL));
	//default player has 250 in all aspects
	double performance = p.health + p.sanity + p.hunger;
	if (peformance >= 850) {
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

//implement functions that presents different scenarios to the player


