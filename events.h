#pragma once
#include <iostream>
using namespace std;

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

};

//return a random integer from 1 to 6, inclusive
int randomInt() {
	return rand() % 6 + 1;
}

//check if the given number is a duplicate in slots array
bool numDup(int id, Player player) {
	for (int i = 0; i < 5; i++) {
		if (player.slots[i] == id) {
			return true;
		}
		return false;
	}
}

//adds a suitable item to the player's inventory
//notifies the player upon modification
void add_item(Player p) {

	if (p.fullInventory()) {
		cout << "Your inventory is full.\nNo item is added.\n";
		return;
	}
	else {
		//generate an appropiate item id
		//if numOfUniqueItem == 3
		//generate a duplicated id
		int id = randomInt();
		if (p.numOfUniqueItem == 3) {
			//get the three unique ids
			//store them inside n1, n2, and n3
			int n1 = p.slots[0], n2 = 0, n3 = 0;
			for (int i = 1; i < 5; i++) {
				if (p.slots[i] != n1) {
					p.slots[i] = n2;
					for (int j = i; j < 5; j++) {
						if ((p.slots[j] != n2) && (p.slots[j] != n1)) {
							n3 = p.slots[j];
							break;
						}
					}
				}
			}

			//reassign id to a random integer until either it is equal to n1, n2, or n3
			while ((id != n1) && (id != n2) && (id != n3)) {
				id = randomInt();
			}


		}

		//if numOfUniqueItem < 3
		//generate any item
		else if (p.numOfUniqueItem < 3) {
			//increment numOfUniqueItem by 1 if id exists in slots array
			if (!numDup(id, p)) {
				p.numOfUniqueItem++;
			}
		}

		//assign id to an empty slot
		for (int i = 0; i < 5; i++) {
			if (p.slots[i] == 0) {
				p.slots[i] = id;
				return;
			}
		}

	}
}


//scenarios as functions
void q1(int opt, Player &p) {
	char action;
	char ans;
	std::cout << "You’ve come across a crazy environmentalist today while having lunch at the school canteen today. \nDo you continue to listen to him or decisively leave ignoring possible consequences?\n(input y to listen, n to leave)\n";
	std::cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		std::cout << "What is not a main pollutant of greenhouse gases?\nDiatomic Nitrogen, Tetrafluoromethane, Methane\nPlease select from 1 to 3 respectively\n";
		std::cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == '2') {
			std::cout << "You’ve won against this crazy man, but at what cost?\n";
			system("pause");
			add_item(p);
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				std::cout << "The answer seems to be wrong. Please try again.\n";
				std::cin >> ans;
				if (ans == '2') {
					std::cout << "You’ve finally won against this crazy man, but at what cost?\n";
					system("pause");
					add_item(p);
					p.sanity -= 10;
					std::cout << "You have lost 10 sanity" << endl;
					return;
				}
				//if normal mode, skip
				else {
					std::cout << "Unfortunately your answer is wrong, and the day must go on...\n";
					system("pause");
					return;
				}
			}
		}
	}
	//declines		
	else {
		std::cout << "You’ve won against this crazy man, but at what cost?\nHe fiercely grabs you and does not let you leave. You got a scratch.\n";
		p.health -= 20;
		std::cout << "You have lost 20 sanity" << endl;
		return;
	}
}

void q2(int opt, Player &p) {
	char action;
	int ans;
	std::cout << "The friend you have just met for 2 days asks you for 100 dollars for lunch. He promises that he will pay you back 110 dollars next time you meet. Do you trust him and give away your money?\nenter y to trust, n to not trust\n";
	std::cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		std::cout << "What number divides 51\n20, 17, 5";
		std::cin >> ans;
		system("cls");
		//17 is the correct answer
		if (ans == 17) {
			std::cout << "A trustable friend is always a good friend. Not only does he pay you back as promised, but he also even asks you out for a free meal!\n";
			system("pause");
			add_item(p);
			p.hunger += 50;
			std::cout << "You have gained 50 hunger" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				std::cout << "The answer seems to be wrong. Please try again.\n";
				std::cin >> ans;
				if (ans == 17) {
					std::cout << "A trustable friend is always a good friend. Not only does he pay you back as promised, but he also even asks you out for a free meal!\n";
					system("pause");
					add_item(p);
					p.hunger += 50;
					std::cout << "You have gained 50 hunger" << endl;
					return;
				}
				//if normal mode, skip
				else {
					std::cout << "Unfortunately your answer is wrong, and the day must go on...\n";
					system("pause");
					return;
				}
			}

		}
	}
		//declines		
	else {
		std::cout << "You saved yourself 100 dollars that comes back better in a week, but you didn’t save your new friendship…\n";
		p.health -= 20;
		std::cout << "You have lost 20 health" << endl;
		return;
	}
}

void q3(int opt, Player &p) {
	char action;
	int ans;
	cout << "Moms call you to attend dinner tonight, but you and your hallmates decide to hold an orientation party at the dorm rooms at the same time. Do you respect your family and come eat with them, or decide to have fun with your new hall mates?\n (enter y to accept, n to decline)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "What food is named after a person\nToast, Cherry, Nachosn\Please select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//Nachos is the correct answer
		if (ans == 3) {
			cout << "Your mom understands that you need to build bonding with your new friends, and allows you to party with them, your family could always eat together on the weekends!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 3) {
					cout << "Your mom understands that you need to build bonding with your new friends, and allows you to party with them, your family could always eat together on the weekends!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}
			
		}
	}
	//declines		
	else {
		cout << "Your mom is so mad that she threatens to disown you by the end of the night if you don’t come back, she is now in a very bad mood…\n";
		p.health -= 10;
		p.sanity -= 50;
		p.hunger -= 20;
		cout << "You have lost 10 health, 50 sanity, and 20 hunger" << endl;
		return;
	}
}

void q4(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
				//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}
			

		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}

}

void q5(int opt, Player& p) {

	char action;
	string ans;
	cout << "You’ve walked past university street today and you’ve found a club giving away coffee powders as an exchange for joining their club. The gift looks well-packed. Do you join just because of that?\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Which number do you dial if you want to contact HKU (2859-2111/2858-2549/3917-2882)?\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == "2859-2111") {
			cout << "You proved to be a very smart and decisive person, but the temptation to free gifts is your downfall. You tried out the coffee at night and have a sick stomach…\n";
			system("pause");
			add_item(p);
			p.health -= 50;
			p.sanity -= 10;
			p.hunger -= 20;
			cout << "You have lost 50 health, 10 sanity and 20 hunger" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == "2859-2111") {
					cout << "You proved to be a very smart and decisive person, but the temptation to free gifts is your downfall. You tried out the coffee at night and have a sick stomach…\n";
					system("pause");
					add_item(p);
					p.health -= 50;
					p.sanity -= 10;
					p.hunger -= 20;
					cout << "You have lost 50 health, 10 sanity and 20 hunger" << endl;
					return;
				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "The student holding the stall realizes that you’re a very uncool person, but he can’t do anything about it…\n";
		return;
	}

}

void q6(int opt, Player& p) {

	char action;
	string ans;
	cout << "One of the courses you registered has provided you with recordings for learning purposes. Today, you woke up with sleepy eyes because you couldn’t get enough sleep yesterday. Do you attend the lesson still or just get more sleep (y/n)?\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Which animals have more than two eyes? (Praying mantis/Kauai cave wolf spider/human)\n";
		cin >> ans;
		system("cls");
		//1 is the correct answer
		if (ans == "Praying mantis") {
			cout << "the urge to attend a live lesson is always appreciated, but your body doesn’t. You can always check back the content if you’re not lazy, dummy…\n";
			system("pause");
			add_item(p);
			p.health -= 50;
			p.sanity -= 20;
			p.hunger -= 20;
			cout << "You have lost 50 health, 20 sanity, and 20 hunger" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == "Praying mantis") {
					cout << "the urge to attend a live lesson is always appreciated, but your body doesn’t. You can always check back the content if you’re not lazy, dummy…\n";
					system("pause");
					add_item(p);
					p.health -= 50;
					p.sanity -= 20;
					p.hunger -= 20;
					cout << "You have lost 50 health, 20 sanity, and 20 hunger" << endl;
					return;
				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "It never hurts to sleep for a few more hours right? It may not hurt you but your grade when you give up on lessons easily…\n";
		p.health +=50;
		p.sanity -= 10;
		cout << "You have gained 50 health and lost 10 sanity" << endl;
		return;
	}

}

void q7(int opt, Player& p) {

	char action;
	string ans;
	cout << "You have just realized that a tutor of your course didn’t set a reminder for the upcoming class poster presentation. You have 24 hours to finish your work and present it at class tomorrow. You have no choice but to speed run this task.\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "What is the well-known title for the painting La Gioconda? (The Mona Lisa/The scream/The Starry Night)\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == "The Mona Lisa") {
			cout << "You are a work of wonder and you nailed your presentation work in half a day, even yourself haven’t seen such a hardworking side of you…\n";
			system("pause");
			add_item(p);
			
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == "The Mona Lisa") {
					cout << "You are a work of wonder and you nailed your presentation work in half a day, even yourself haven’t seen such a hardworking side of you…\n";
					system("pause");
					add_item(p);

					return;
				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "You released that you do not have any poster paper at home, and going out to buy one takes unfortunately hours. Your presentation is likely in the mud…\n";
		p.health -= 30;
		p.sanity -= 50;
		p.hunger -= 30;
		cout << "You have lost 30 health, 50 sanity, and 30 hunger" << endl;
		return;
	}
}

void q8(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q9(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q10(int opt, Player& p) {
	
	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q11(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q12(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}

}

void q13(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q14(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q15(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q16(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q17(int opt, Player& p) {
	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}

void q18(int opt, Player& p) {

	char action;
	int ans;
	cout << "It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
	cin >> action;
	system("cls");
	//accepts
	if (action == 'y') {
		cout << "Where does Manila belong?\nThe Fillippines, The Philippines, The Phillippines\nPlease select from 1 to 3 respectively\n";
		cin >> ans;
		system("cls");
		//2 is the correct answer
		if (ans == 2) {
			cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
			system("pause");
			add_item(p);
			p.sanity += 10;
			cout << "You have gained 10 sanity" << endl;
			return;
		}
		//wrong answer
		else {
			//if ez mode, let the player try again
			if (opt == 0) {
				cout << "The answer seems to be wrong. Please try again.\n";
				cin >> ans;
				if (ans == 2) {
					cout << "Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
					system("pause");
					add_item(p);
					p.sanity += 10;
					cout << "You have gained 10 sanity" << endl;
					return;

				}
			}
			//if normal mode, skip
			else {
				cout << "Unfortunately your answer is wrong, and the day must go on...\n";
				system("pause");
				return;
			}


		}
	}
	//declines		
	else {
		cout << "That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
		p.health -= 20;
		cout << "You have lost 20 health" << endl;
		return;
	}
}
