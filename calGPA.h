#ifndef CALGPA_H
#define CALGPA_H

#include "player.h"

//max possible GPA is 4.0, min is 0.0
//gpa is calculate from player health, sanity, and hunger
double calGPA(Player p) {

	double health_part = p.health / 100;
	double sanity_part = p.sanity / 100;
	double hunger_part = p.hunger / 100;
	double total = hunger_part + sanity_part + hunger_part;
	if (total > 4.0) {
		return total % 4;
	}
	return total;
	
}

#endif
