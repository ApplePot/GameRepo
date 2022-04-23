#include "equipments.h"
#include "events.h"

struct Player {

	double health;
	double sanity;
	double hunger;
	int equipNumType;
	int slots[5];

	bool fullInventory() {
		for (int i = 0; i < 5; i++) {
			if (slots[i] == 0) {
				return true;
			}
		}
		return false;
	}

	void add_item() {

		if (fullInventory()) {
			return;
		}
		else {
			int i = 0;
			while (i < 5) {
				if (p.slots[i] == 0) {
					p.slots[i] = randomInt();
					break;
				}
				i++;
			}
		}
	}
			
}; 


//check player stats and take actions
void checkStats(Player p, bool &endGame) {

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