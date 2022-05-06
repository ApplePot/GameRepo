#ifndef EQUIPMENTS_H
#define EQUIPMENTS_H
#include <string>
using namespace std;

//add 6 equipments for the player to obtain

struct Equipment {

	int id;
	int health_mod;
	int sanity_mod;
	int hunger_mod;
	string name;
	string description;
	
};

//each piece of equipment gives a net boost of 50 to player stats
Equipment equiplist[6] = {
	{ 1, 20, 20, 10, "Luck Charm", "Merely wearing it makes you feel better" },
	{ 2, -20, 35, 35, "Family-size Coke", "It's bad for your health, but it tastes so good!" },
	{ 3, 0, 50, -10, "Edgy Katana", "Carrying this impractical sword makes you feel like a sword master, but it is utterly embarrassing..." },
	{ 4, 50, -5, 5, "Sweaty programmer's sweat", "You can faintly smell coffee from it"},
	{ 5, -20, -25, 95, "Ghost pepper potato chips", "Eating this is torturous, but it is filling"},
	{ 6, 90, -45, 5, "Gigantic lettuce", "Eating a gigantic portion of vegetables is healthy"}
};

#endif