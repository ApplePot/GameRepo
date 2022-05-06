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
    string ans;   
    std::cout<<"You’ve come across a crazy environmentalist today while having lunch at the school canteen today. \nDo you continue to listen to him or decisively leave ignoring possible consequences?\n(enter y to listen, n to leave)\n";
    std::cin>>action;
    system("cls");
    //accepts
    if (action=='y') {
        std::cout<<"What is not a main pollutant of greenhouse gases?\nDiatomic, Nitrogen, Tetrafluoromethane, Methane\n";
        std::cin>>ans;
        system("cls");  
        //Nitrogen is the correct answer
        if (ans == "Nitrogen") {
            std::cout<<"You’ve won against this crazy man, but at what cost?\n";
            system("pause");
            add_item(p);
            return;     
        }
        //wrong answer
        else {
            //if ez mode, let the player try again
            if (opt == 0) {
                std::cout<<"The answer seems to be wrong. Please try again.\n";
                std::cin>>ans;
                if (ans == "Nitrogen") {
                    std::cout<<"You’ve finally won against this crazy man, but at what cost?\n";
                    system("pause");
                    add_item(p);
                    p.sanity-=10;
                    std::cout<<"You have lost 10 sanity"<<endl;
                    return;
                }
            }
            //if normal mode, skip
            else {
                std::cout<<"Unfortunately your answer is wrong, and the day must go on...\n";
                system("pause");
                return;
            }
        }
    }               
    //declines      
    else{
        std::cout<<"You’ve won against this crazy man, but at what cost?\nHe fiercely grabs you and does not let you leave. You got a scratch.\n";
        system("pause");
        system("cls");
        p.health-=20;
        std::cout<<"You have lost 20 sanity"<<endl;
        system("pause");
        system("cls");
        return;
    }               
}

void q2(int opt, Player &p) {
    char action;
    int ans;    
    std::cout<<"The friend you have just met for 2 days asks you for 100 dollars for lunch. He promises that he will pay you back 110 dollars next time you meet. Do you trust him and give away your money?\n(enter y to trust, n to not trust)\n";
    std::cin>>action;
    system("cls");
    //accepts
    if (action=='y') {
        std::cout<<"What number divides 51?\n20, 17, 5";
        std::cin>>ans;
        system("cls");  
        //17 is the correct answer
        if (ans == 17) {
            std::cout<<"A trustable friend is always a good friend. Not only does he pay you back as promised, but he also even asks you out for a free meal!\n";
            system("pause");
            add_item(p);
            p.hunger+=50;
            std::cout<<"You have gained 50 hunger"<<endl;
            return;     
        }
        //wrong answer
        else {
            //if ez mode, let the player try again
            if (opt == 0) {
                std::cout<<"The answer seems to be wrong. Please try again.\n";
                std::cin>>ans;
                if (ans == 17) {
                    std::cout<<"A trustable friend is always a good friend. Not only does he pay you back as promised, but he also even asks you out for a free meal!\n";
                    system("pause");
                    add_item(p);
                    p.hunger+=50;
                    std::cout<<"You have gained 50 hunger"<<endl;
                    return;
                }
            }
            //if normal mode, skip
            else {
                std::cout<<"Unfortunately your answer is wrong, and the day must go on...\n";
                system("pause");
                system("cls");
                return;
            }
        }            
    }       
    //declines      
    else {
        std::cout<<"You saved yourself 100 dollars that comes back better in a week, but you didn’t save your new friendship…\n";
        system("pause");
        system("cls");
        p.health-=20;
        std::cout<<"You have lost 20 health"<<endl;
        return;
    }       
}

void q3(int opt, Player &p) {
    char action;
    string ans;    
    std::cout<<"Moms call you to attend dinner tonight, but you and your hallmates decide to hold an orientation party at the dorm rooms at the same time. Do you respect your family and come eat with them, or decide to have fun with your new hall mates?\n (enter y to accept, n to decline)\n";
    std::cin>>action;
    system("cls");
    //accepts
    if (action=='y') {
        std::cout<<"What food is named after a person\nToast, Cherry, Nachos\n";
        std::cin>>ans;
        system("cls");  
        //Nachos is the correct answer
        if (ans == "Nachos") {
            std::cout<<"Your mom understands that you need to build bonding with your new friends, and allows you to party with them, your family could always eat together on the weekends!\n";
            system("pause");
            add_item(p);
            p.sanity+=10;
            std::cout<<"You have gained 10 sanity"<<endl;
            return;     
        }
        //wrong answer
        else {
            //if ez mode, let the player try again
            if (opt == 0) {
                std::cout<<"The answer seems to be wrong. Please try again.\n";
                std::cin>>ans;
                if (ans == "Nachos") {
                    std::cout<<"Your mom understands that you need to build bonding with your new friends, and allows you to party with them, your family could always eat together on the weekends!\n";
                    system("pause");
                    add_item(p);
                    p.sanity+=10;
                    std::cout<<"You have gained 10 sanity"<<endl;
                    return;
                }
            }
            //if normal mode, skip
            else {
                std::cout<<"Unfortunately your answer is wrong, and the day must go on...\n";
                system("pause");
                return;
            }
        }            
    }        
    //declines      
    else {
        std::cout<<"Your mom is so mad that she threatens to disown you by the end of the night if you don’t come back, she is now in a very bad mood…\n";
        system("pause");
        system("cls");
        p.health-=10;
        p.sanity-=50;
        p.hunger-=20;
        std::cout<<"You have lost 10 health, 50 sanity, and 20 hunger"<<endl;
        system("pause");
        system("cls");
        return;
    }   
    
}
void q4(int opt, Player &p) {
    char action;
    string ans;    
    std::cout<<"It is your responsibility to find a competent teammate in your common core course’s presentation.\nYou see another student at the corner of the class looking for a teammate.\nDo you go over and ask for a team?\n(enter y to go over, n to do nothing)\n";
    std::cin>>action;
    system("cls");
    //accepts
    if (action=='y') {
        std::cout<<"Where does Manila belong?\nThe_Fillippines, The_Philippines, The_Phillippines\n";
        std::cin>>ans;
        system("cls");  
        //The_Philippines is the correct answer
        if (ans == "The_Philippines") {
            std::cout<<"Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
            system("pause");
            add_item(p);
            p.sanity+=10;
            std::cout<<"You have gained 10 sanity"<<endl;
            return;     
        }
    
        //wrong answer
        else {
            //if ez mode, let the player try again
            if (opt == 0) {
                std::cout<<"The answer seems to be wrong. Please try again.\n";
                std::cin>>ans;
                if (ans == "The_Philippines") {
                    std::cout<<"Turns out this shy man you’re talking to is a genius at geography.\nNot only you’ve gotten a cool friend, your final project turns out to be much easier to finish!\n";
                    system("pause");
                    add_item(p);
                    p.sanity+=10;
                    std::cout<<"You have gained 10 sanity"<<endl;
                    return;
                }
            }
            //if normal mode, skip
            else {
                std::cout<<"Unfortunately your answer is wrong, and the day must go on...\n";
                system("pause");
                return;
            }
        }            
    }        
    //declines      
    else {
        std::cout<<"That student may be as shy as you, but not as silly as you.\nHe is secretly a genius at geography and has just missed a chance to get a great score in the upcoming project.\n";
        system("pause");
        system("cls");
        p.health-=20;
        std::cout<<"You have lost 20 health"<<endl;
        system("pause");
        system("cls");
        return;
    }   
    
}
void q5(int opt, Player &p) {
    char action;
    string ans;    
    std::cout<<"You’ve walked past university street today and you’ve found a club giving away coffee powders as an exchange for joining their club.\nThe gift looks well-packed. \nDo you join just because of that?\n(enter y to join, n to decline)\n";
    std::cin>>action;
    system("cls");
    //accepts
    if (action=='y') {
        std::cout<<"Which number do you dial if you want to contact HKU?\n2859-2111, 2858-2549, 3917-2882\n";
        std::cin>>ans;
        system("cls");  
        //2859-2111 is the correct answer
        if (ans == "2859-2111") {
            std::cout<<"You proved to be a very smart and decisive person, but the temptation to free gifts is your downfall.\nYou tried out the coffee at night and have a sick stomach…\n";
            system("pause");
            add_item(p);
            p.health-=50;
            p.sanity-=10;
            p.hunger-=20;
            std::cout<<"You have lost 50 health, 10 sanity and 20 hunger"<<endl;
            return;     
        }
        //wrong answer
        else {
            //if ez mode, let the player try again
            if (opt == 0) {
                std::cout<<"The answer seems to be wrong. Please try again.\n";
                std::cin>>ans;
                if (ans == "2859-2111") {
                    std::cout<<"The student holding the stall realizes that you’re a very uncool person, but he can’t do anything about it…\n";
                    system("pause");
                    add_item(p);
                    return;
                }
            }
            //if normal mode, skip
            else {
                std::cout<<"Unfortunately your answer is wrong, and the day must go on...\n";
                system("pause");
                return;
            }
        }            
    }       
    //declines      
    else {
        std::cout<<"The student holding the stall realizes that you’re a very uncool person, but he can’t do anything about it…\n";
        system("pause");
        system("cls");
        return;
    }       
}
void q6(int opt, Player &p) {
    char action;
    string ans;    
    std::cout<<"One of the courses you registered has provided you with recordings for learning purposes.\nToday, you woke up with sleepy eyes because you couldn’t get enough sleep yesterday.\nDo you attend the lesson still or just get more sleep?\n(enter y to attend lesson, n to continue sleeping)";
    std::cin>>action;
    system("cls");
    //accepts
    if (action=='y') {
        std::cout<<"Which animals have more than two eyes?\nKauai_cave_wolf_spider, Praying_mantis, human\n";
        std::cin>>ans;
        system("cls");  
        //Praying_mantis is the correct answer
        if (ans == "Praying_mantis" {
            std::cout<<"The urge to attend a live lesson is always appreciated, but your body doesn’t.\nYou can always check back the content if you’re not lazy, dummy…\n";
            system("pause");
            add_item(p);
            p.health-=50;
            p.sanity-=20;
            p.hunger-=20;
            std::cout<<"You have lost 50 health, 20 sanity and 20 hunger"<<endl;
            return;     
        }
        //wrong answer
        else {
            //if ez mode, let the player try again
            if (opt == 0) {
                std::cout<<"The answer seems to be wrong. Please try again.\n";
                std::cin>>ans;
                if (ans == "Praying_mantis") {
                    std::cout<<"The urge to attend a live lesson is always appreciated, but your body doesn’t.\nYou can always check back the content if you’re not lazy, dummy…\n";
                    system("pause");
                    add_item(p);
                    p.health-=50;
                    p.sanity-=20;
                    p.hunger-=20;
                    std::cout<<"You have lost 50 health, 20 sanity and 20 hunger"<<endl;
                    return;
                }
            }
            //if normal mode, skip
            else {
                std::cout<<"Unfortunately your answer is wrong, and the day must go on...\n";
                system("pause");
                return;
            }
        }
    }
    //declines      
    else {
        std::cout<<"It never hurts to sleep for a few more hours right? It may not hurt you but your grade when you give up on lessons easily…\n";
        system("pause");
        system("cls");
        p.health+=50;
        p.sanity-=10;
        std::cout<<"You have gained 50 health, and lost 10 sanity"<<endl;
        system("pause");
        system("cls");
        return;
    }   
    
}
void q7(int opt, Player &p) {
    string ans;    
    std::cout<<"You have just realized that a tutor of your course didn’t set a reminder for the upcoming class poster presentation.\nYou have 24 hours to finish your work and present it at class tomorrow.\nYou have no choice but to speed run this task.";c
    system("pause");
    std::cout<<"What is the well-known title for the painting La Gioconda?\nThe_scream, The_Starry_Night, The_Mona_Lisa\n";
    std::cin>>ans;
    system("cls");  
    //The_Mona_Lisa is the correct answer
    if (ans == "The_Mona_Lisa") {
        std::cout<<"You are a work of wonder and you nailed your presentation work in half a day, even yourself haven’t seen such a hardworking side of you…\n";
        system("pause");
        add_item(p);
        p.health+=20;
        p.sanity-=10;
        p.hunger-=20;
        std::cout<<"You have gained 20 health, lost 10 sanity and 20 hunger"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans == "The_Mona_Lisa") {
                std::cout<<"You are a work of wonder and you nailed your presentation work in half a day, even yourself haven’t seen such a hardworking side of you…\n";
                add_item(p);
                p.health+=20;
                p.sanity-=10;
                p.hunger-=20;
                std::cout<<"You have gained 20 health, lost 10 sanity and 20 hunger"<<endl;
                return;
            }
        }
        //if wrong, output
        else {
            std::cout<<"You released that you do not have any poster paper at home, and going out to buy one takes unfortunately hours.\nYour presentation is likely in the mud…\n";
            system("pause");
            system("cls");
            p.health-=50;
            p.sanity-=50;
            p.hunger-=30
            std::cout<<"You have lost 50 health, 50 sanity and 30 sanity"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q8(int opt, Player &p) {
    string ans;    
    std::cout<<"During your midterm test, your dad is watching youtube at home.\nThe large demand of bandwidth causes the router to shut off.\nNow you have no internet connection.\nYou decided to share your mobile data to your pc so that you can continue the test.\n";
    system("cls");
    std::cout<<"Which YouTube video reached 1 billion views first?\nGangnam_Styles, Despacito, Shape_of_You\n";
    std::cin>>ans;
    system("cls");  
    //Gangnam_Styles is the correct answer
    if (ans == "Gangnam_Styles") {
        std::cout<<"You are a living genius and aced the test with a very great score despite the unfortunate event.\n";
        system("pause");
        add_item(p);
        p.sanity-=20;
        p.hunger-=20;
        std::cout<<"You have lost 20 sanity and 20 hunger"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans == "Gangnam_Styles") {
                std::cout<<"You are a work of wonder and you nailed your presentation work in half a day, even yourself haven’t seen such a hardworking side of you…\n";
                add_item(p);
                p.sanity-=20;
                p.hunger-=20;
                std::cout<<"You have lost 20 sanity and 20 hunger"<<endl;
                return;
            }         
        }
        //wrong answer, output this
        else {
            std::cout<<"Seems like someone has been watching YouTube too much too with their data, and the data is on slow mode right now.\nThe video call is so laggy that you can’t see the displayed questions.\nOh no…\n";
            system("pause");
            system("cls");
            p.sanity-=80
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q9(int opt, Player &p) {
    string ans;    
    std::cout<<"You have to attend a face-to-face midterm test today, but the elevator from the MTR station to the campus is jammed with a lot of people.\nExit A is your desired exit. Exit C seems to have a shorter queue but switching exits also means that you’re further away from your destination.\nThe test starts in 10 minutes sharp. Do you switch exits?\n";
    system("cls");
    std::cout<<"Which is the earliest subway station in the world?\nParis, London, Hong Kong\n";
    std::cin>>ans;
    system("cls");  
    //London is the correct answer
    if (ans == "London") {
        std::cout<<"Your athlete instinct leads you to victory. You speed through the crowd and manage to get in the class on time.\nHaving sudden sprints does not feel right, but that’s what makes you healthy.\n";
        system("pause");
        add_item(p);
        p.health+=20;
        p.sanity-=10;
        std::cout<<"You have gained 20 health, and lost 10 sanity"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans =="London") {
                std::cout<<"Your athlete instinct leads you to victory. You speed through the crowd and manage to get in the class on time.\nHaving sudden sprints does not feel right, but that’s what makes you healthy.\n";
                add_item(p);
                p.health+=20;
                p.sanity-=10;
                std::cout<<"You have gained 20 health, and lost 10 sanity"<<endl;
                return;     
            }    
        }
        //wrong answer, output this
        else {
            std::cout<<"Well, money doesn’t grow on trees, and so does time. What do you expect? You’re late lol.\n";
            system("pause");
            system("cls");
            p.sanity-=50;
            p.hunger-=20;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q10(int opt, Player &p) {
    string ans;    
    std::cout<<"After class today, your good friend asks you to finish the upcoming project in the library.\nIt is due 2 weeks later, and you’re very tired from the previous lecture.\nAll you want to do is to rest and get a drink from The Coffee Academïcs.\nDo you decline your friend and relax?\n";
    system("cls");
    std::cout<<"Which of these are Coca-Cola brands?\nSmartwater, Mountain Dew, Miranda\n";
    std::cin>>ans;
    system("cls");  
    //Smartwater is the correct answer
    if (ans =="Smartwater" ) {
        std::cout<<"You feel like it’s the right thing to finish your project ASAP regardless of the due date.\nYour friend forces you to join him while you think that you still have a choice.\nIn the library, you are mentally not prepared for the work and fall asleep.\nYou complain that it would have been your bed that you’re taking a nap on, plus a tasty cup of chocolate.\n";
        system("pause");
        add_item(p);
        p.health+=10;
        p.sanity-=30;
        p.hunger-=10;
        std::cout<<"You have gained 10 health, and lost 30 sanity and 10 hunger"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans == "Smartwater") {
                std::cout<<"You feel like it’s the right thing to finish your project ASAP regardless of the due date.\nYour friend forces you to join him while you think that you still have a choice.\nIn the library, you are mentally not prepared for the work and fall asleep.\nYou complain that it would have been your bed that you’re taking a nap on, plus a tasty cup of chocolate.\n";
                system("pause");
                add_item(p);
                p.health+=10;
                p.sanity-=30;
                p.hunger-=10;
                std::cout<<"You have gained 10 health, and lost 30 sanity and 10 hunger"<<endl;
                return;    
            }         
        }
        //wrong answer, output this
        else {
            std::cout<<"You feel like it’s the right thing to finish your project ASAP regardless of the due date.\nYour friend forces you to join him while you think that you still have a choice.\nIn the library, you are mentally not prepared for the work and fall asleep.\nYou complain that it would have been your bed that you’re taking a nap on, plus a tasty cup of chocolate.\n";
            system("pause");
            system("cls");
            p.health+=10;
            p.sanity-=30;
            p.hunger-=10;
            std::cout<<"You have gained 10 health, and lost 30 sanity and 10 hunger"<<endl;
            system("pause");
            system("cls");
            return;     
        }
    }   
}
void q11(int opt, Player &p) {
    string ans;    
    std::cout<<"Nothing much really happened today, you are chilling in your dorm room and trying to get some rest for the upcoming week of assignments.\nThe only thing you want right now is a good sleep. You heard that listening to music may help with sleep and decided to try.\n";
    system("cls");
    std::cout<<"Which music composer lived the longest lives?\nBeethoven, Mozart, Bach\n";
    std::cin>>ans;
    system("cls");  
    //Bach is the correct answer
    if (ans == "Bach") {
        std::cout<<"listening to classical music when sleeping is really your jam. You woke up the next day full of energy.\n";
        system("pause");
        add_item(p);
        p.health+=100;
        p.sanity+=50;
        std::cout<<"You have gained 100 health and 50 sanity"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans =="Bach" ) {
                std::cout<<"listening to classical music when sleeping is really your jam. You woke up the next day full of energy.\n";
                system("pause");
                add_item(p);
                p.health+=100;
                p.sanity+=50;
                std::cout<<"You have gained 100 health and 50 sanity"<<endl;
                return;  
            }   
        }
        //wrong answer, output this
        else {
            std::cout<<"All you hear is just the same melodies repeating for the whole night. Don’t talk about sleeping, you have a hard time staying sane.\n";
            system("pause");
            system("cls");
            p.health-=50;
            p.sanity-=100;
            std::cout<<"You have lost 50 health and 100 sanity"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q12(int opt, Player &p) {
    char action;
    string ans;    
    std::cout<<"You are now studying for the last midterm test this week, by then your lovely weekend arrives.\nHowever, you feel a bad pain in your stomach today when revising mid way through the notes.\nYou really need some rest today or else you will not be able to wake up in time tomorrow.\nWhat do you do now?(enter y to sleep, n to study)";
    std::cin>>action;
    system("cls");
    //accepts
    if (action=='y') {
        std::cout<<"Good thing you chose to rest yesterday. You’re happy that your stomach feels fine now, and you could still finish most of the questions in the test.\n";
        system("pause");
        add_item(p);
        p.sanity+=10;
        p.hunger-=50;
        std::cout<<"You have gained 10 sanity, and lost 50 hunger"<<endl;
        return;     
        }
    //declines      
    else {
        std::cout<<"It’s never too late to study, they said. Well it is too late for now… You managed to remember all the things you learned though.\nFortunately you woke up in time and finished most of your test.\n";
        system("pause");
        system("cls");
        p.health-=50;
        p.sanity-50;
        p.hunger-=50;
        std::cout<<"You have lost 50 health, 50 sanity and 50 hunger"<<endl;
        system("pause");
        system("cls");
        return;
    }   
    
}
void q13(int opt, Player &p) {
    string ans;    
    std::cout<<"It is crazy that you have to do a 40 minute presentation with 2 other group mates. It is mindblowing that you’ve spent hours practistd::cing and rehearsing the product.\nThe time has come, you wish not to stutter to give the best presentation.\n";
    system("cls");
    std::cout<<"What does the pancreas make?Adrenaline, Insulin, Blood\n";
    std::cin>>ans;
    system("cls");  
    //Insulin is the correct answer
    if (ans =="Insulin" ) {
        std::cout<<"You are so talented and run through the presentation smoothly, this presentation has to be an A.\n";
        system("pause");
        add_item(p);
        p.health+=100;
        p.sanity+=20;
        std::cout<<"You have gained 100 health and 20 sanity"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans =="Insulin" ) {
                std::cout<<"You are so talented and run through the presentation smoothly, this presentation has to be an A.\n";
                system("pause");
                add_item(p);
                p.health+=100;
                p.sanity+=20;
                std::cout<<"You have gained 100 health and 20 sanity"<<endl;
                return; 
            }            
        }
        //wrong answer, output this
        else {
            std::cout<<"Despite your great effort, the tutor could not appreciate the fact that you are choking crazy during the presentation.\nThe Q&A question raised your eyebrows and you are unable to answer all the questions…\n";
            system("pause");
            system("cls");
            p.health-=100;
            p.sanity-=100;
            p.hunger-=20;
            std::cout<<"You have lost 100 health, 100 sanity and 20 hunger"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q14(int opt, Player &p) {
    string ans;    
    std::cout<<"You have to shoot a video and edit it for submission. You are struggling to convert the files into the correct format so that you can edit them.\nYou are trying hard and hope to find the perfect tutorial on YouTube to save your GPA.\n";
    system("cls");
    std::cout<<"Which photo format allows a transparent background?\nmp3, jpg, png\n ";
    std::cin>>ans;
    system("cls");  
    //png is the correct answer
    if (ans =="png" ) {
        std::cout<<"Nothing could stop you now. You’re on a rampage and still going strong.\n";
        system("pause");
        add_item(p);
        p.health+=75;
        p.sanity+=75;
        std::cout<<"You have gained 75 health and 75 sanity"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans == "png") {
                std::cout<<"Nothing could stop you now. You’re on a rampage and still going strong.\n";
                system("pause");
                add_item(p);
                p.health+=75;
                p.sanity+=75;
                std::cout<<"You have gained 75 health and 75 sanity"<<endl;
                return;    
            }             
        }
        //wrong answer, output this
        else {
            std::cout<<"Well, you eventually find the right tutorial video, just that it is in bad quality. This day can’t get even worse…\n";
            system("pause");
            system("cls");
            p.sanity-=100;
            std::cout<<"You have lost 100 sanity"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q15(int opt, Player &p) {
    string ans;    
    std::cout<<"There is this one common core course that you didn’t really pay attention to during class, and now it backfires and comes for you now.\nYou are required to do a debate during class. You have no idea what’s going on and you are in deep trouble.\nYou look at your friend in class for help and see if you can get any hints off the topic.\n";
    system("cls");
    std::cout<<"How does a microwave reheat bread?\nWith_electromagnetic_waves, With_ultraviolet_waves, With_microwaves\n";
    std::cin>>ans;
    system("cls");  
    //With_electromagnetic_waves is the correct answer
    if (ans =="With_electromagnetic_waves" ) {
        std::cout<<"You picked up the hint so well you created a killer stand point for your team. The opposing left team is left shocked but with respect.\n";
        system("pause");
        add_item(p);
        p.health+=100;
        p.sanity+=50;
        std::cout<<"You have gained 100 health and 50 sanity"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans =="With_electromagnetic_waves" ) {
                std::cout<<"You picked up the hint so well you created a killer stand point for your team. The opposing left team is left shocked but with respect.\n";
                system("pause");
                add_item(p);
                p.health+=100;
                p.sanity+=50;
                std::cout<<"You have gained 100 health and 50 sanity"<<endl;
                return; 
            }    
        }
        //wrong answer, output this
        else {
            std::cout<<"You stood still for 2 minutes straight trying to find any word you know about the topic. DEAD SILENCE.\n";
            system("pause");
            system("cls");
            p.health-=100;
            p.sanity-=50;
            p.hunger-=30;
            std::cout<<"You have lost 100 health, 50 sanity and 30 hunger"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q16(int opt, Player &p) {
    string ans;    
    std::cout<<"You notice that you have to hand in 3 assignments within 2 days. It is driving you insane that you can’t eat a full meal without thinking about your time management.\nYou are this close from succeeding but yet this easy to give up…\n";
    system("cls");
    std::cout<<"Which of these cars has 4 doors?\nLamborghini_Aventador, Dodge_Charger, Toyota_Smart\n";
    std::cin>>ans;
    system("cls");  
    //Dodge_Charger is the correct answer
    if (ans =="Dodge_Charger" ) {
        std::cout<<"you realized that the assignments are quite easy when you reread the questions again. You believed in yourself that you would finish them in no time.\n";
        system("pause");
        add_item(p);
        p.health+=50;
        p.sanity+=50;
        p.hunger+=50;
        std::cout<<"You have gained 50 health, 50 sanity and 50 hunger"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans =="Dodge_Charger" ) {
                std::cout<<"you realized that the assignments are quite easy when you reread the questions again. You believed in yourself that you would finish them in no time.\n";
                system("pause");
                add_item(p);
                p.health+=50;
                p.sanity+=50;
                p.hunger+=50;
                std::cout<<"You have gained 50 health, 50 sanity and 50 hunger"<<endl;
                return;   
            }  
        }
        //wrong answer, output this
        else {
            std::cout<<"You found an energy drink in your fridge that you bought a long time ago, little did you know that it has expired for a long time.\nYou spent your whole day in the bathroom.\nYour weight is not the only thing you’re gonna lose in these 2 days. Your marks as well…\n";
            system("pause");
            system("cls");
            p.health-=100;
            p.sanity-=50;
            p.hunger-=50;
            std::cout<<"You have lost 100 health, 50 sanity and 50 hunger"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q17(int opt, Player &p) {
    string ans;    
    std::cout<<"In the language class you enrolled in, you have to share in front of your class your favorite hobby and cannot bring a script.\nYou know you need to spend time on remembering the speech, and tomorrow you will be presenting.\n";
    system("cls");
    std::cout<<"What constellation has only three stars?\nOrion's_Belt, Gemini, Cancer\n";
    std::cin>>ans;
    system("cls");  
    //Orion's_Belt is the correct answer
    if (ans =="Orion's_Belt") {
        std::cout<<"Practice makes perfect. You do so well in class the professor is very impressed.\nNow you’re a happy person too.\n";
        system("pause");
        add_item(p);
        p.health+=100;
        p.hunger+=50;
        std::cout<<"You have gained 100 health, and 50 hunger"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans =="Orion's_Belt" ) {
                std::cout<<"Practice makes perfect. You do so well in class the professor is very impressed.\nNow you’re a happy person too.\n";
                system("pause");
                add_item(p);
                p.health+=100;
                p.hunger+=50;
                std::cout<<"You have gained 100 health, and 50 hunger"<<endl;
                return;
            }
        }
        //wrong answer, output this
        else {
            std::cout<<"It is never great to forget the script during a presentation. You lost count of the content that you're presenting and got extremely embarrassed.\nYou want to hide in a hole ASAP.\n";
            system("pause");
            system("cls");
            p.health-=100;
            p.sanity-=100;
            p.hunger-=50;
            std::cout<<"You have lost 100 health, 100 sanity and 50 hunger"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
void q18(int opt, Player &p) {
    string ans;    
    std::cout<<"Doing programming homework is always a great way to train your mind and be creative. The project requires you to code a mini game for your class to play with.\nYou need a lot of time understanding and learning the syntaxes, and the deadline is coming real soon…\n";
    system("cls");
    std::cout<<"Which of these is a programming language?\nBB-8, MIB, Python\n";
    std::cin>>ans;
    system("cls");  
    //Python is the correct answer
    if (ans =="Python" ) {
        std::cout<<"you are a very organized person, and so are your programs.\nYour final run turns out to be fine like wine.\n";
        system("pause");
        add_item(p);
        p.sanity+=50;
        p.hunger+=50;
        std::cout<<"You have gained 50 sanity and 50 hunger"<<endl;
        return;     
    }
    //wrong answer
    else {
        //if ez mode, let the player try again
        if (opt == 0) {
            std::cout<<"The answer seems to be wrong. Please try again.\n";
            std::cin>>ans;
            if (ans =="Python" ) {
                std::cout<<"you are a very organized person, and so are your programs.\nYour final run turns out to be fine like wine.\n";
                system("pause");
                add_item(p);
                p.sanity+=50;
                p.hunger+=50;
                std::cout<<"You have gained 50 sanity and 50 hunger"<<endl;
                return;   
            }  
        }
        //wrong answer, output this
        else {
            std::cout<<"Debugging was never your cup of tea, nor your piece of cake.\nThe clock is ticking and yet you're struggling still…\n";
            system("pause");
            system("cls");
            p.health-=100;
            p.sanity-=100;
            p.hunger-=100;
            std::cout<<"You have lost 100 health, 100 sanity and 100 hunger"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}
