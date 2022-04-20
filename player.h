#include "equipments.h"

struct Player {

	double health;
	double sanity;
	double hunger;
	int equipNumType;
	int slots[5];

};

//check player stats and take actions
void checkStats(Player p, bool &endGame) {

	if (p.health <= 0) {
		endGame = true;
		return;
	}
	else if (p.sanity < 50) {
		if (p.sanity <= 0) {
			cout << "You have gone insane and committed suicide" << endl;
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