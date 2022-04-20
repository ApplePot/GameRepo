#include <string>
#include <vector>

//add 6 equipments for the player to obtain

struct equipment {

	int id;
	int health_mod;
	int sanity_mod;
	int hunger_mod;
	string name;
	string description;
	
};

vector<equipment> avaliableList;

//each equipments gives an net stat boost of 50
equipment e1 = { 1, 20, 20, 10, "Luck Charm", "Merely wearing it makes you feel better" };
avaliableList.push_back(e1);
equipment e2 = { 2, -20, 35, 35, "Family-size Coke", "It's bad for your health, but it tastes so good!" };
avaliableList.push_back(e2);
equipment e3 = { 3, 0, 50, -10, "Edgy Katana", "Carrying this impractical sword makes you feel like a sword master, but it is utterly embarrassing..." };
avaliableList.push_back(e3);
equipment e4 = { 4, 50, -5, 5, "Sweaty programmer's sweat", "You can faintly smell coffee from it"};
avaliableList.push_back(e4);
equipment e5 = { 5, -20, -25, 95, "Ghost pepper potato chips", "Eating this is torturous, but it is filling"};
avaliableList.push_back(e5);
equipment e6 = { 6, 90, -45, 5, "Gigantic lettuce", "Eating a gigantic portion of vegetables is healthy"};
avaliableList.push_back(e6);