#include "events.h"
#ifndef CALGPA_H
#define CALGPA_H

#include "player.h"

//max possible GPA is 4.0, min is 0.0
//gpa is calculate from player health, sanity, hunger, and quiz_marks
double calGPA(Player p, int* marks, int iter) {

	double health_part = p.health / 400;
	double sanity_part = p.sanity / 400;
	double hunger_part = p.hunger / 400;
	double sum_mark=0;
	for (int i = 0; i <= iter; i++) {
		sum_mark += marks[i];
	}
	double quiz_marks = sum_mark / (iter*100);
	double total = hunger_part + sanity_part + hunger_part + quiz_marks;
	if (total >= 4.0) {
		return 4.0;
	}
	return total;
	
}

#endif
