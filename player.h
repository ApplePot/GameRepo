#include "equipments.h"
#include "events.h"

struct Player {

	double health;
	double sanity;
	double hunger;
	int numOfUniqueItem;
	int slots[5];

	bool fullInventory() {
		for (int i = 0; i < 5; i++) {
			if (slots[i] == 0) {
				return false;
			}
		}
		return true;
	}

	void add_item() {

		if (fullInventory()) {
			cout<<"Your inventory is full.\nNo item is added.\n";
			return;
		}
		else {
			//generate an appropiate item id
			//if numOfUniqueItem == 3
			//generate a duplicated id
			int id = randomInt();
			if (numOfUniqueItem == 3) {
				//get the three unique ids
				//store them inside n1, n2, and n3
				int n1=slots[0], n2, n3;
				for (int i=1;i<5;i++) {
					if (slots[i] != n1) {
						slots[i] = n2;
						for (int j=i;j<5;j++) {
							if (slots[j] != n2)&&(slots[j] != n1) {
								n3 = slots[j];
								break;
							}
						}
					}
				}
				
				//reassign id to a random integer until either it is equal to n1, n2, or n3
				while ((id != n1)&&(id != n2)&&(id != n3)) {
					id = randomInt();
				}
				
						
			}
			
			//if numOfUniqueItem < 3
			//generate any item
			else if (numOfUniqueItem < 3) {
				//increment numOfUniqueItem by 1 if id exists in slots array
				if (!numDup(id)) {
					numOfUniqueItem++;
				}
			}
			
			//assign id to an empty slot
			for (int i=0;i<5;i++) {
				if (slots[i] == 0) {
					slots[i] = id;
					return;
				}
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
