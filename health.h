#ifndef HEALTH_H
#define HEALTH_H

#include "hline.h"

/*  Health Assistant. This class uses the "hline" class to save W20-values 
 *  that mark the propability of a person being cured or getting sick.
 *  Helps handling the management of the health values and their regarding actions.
 *  "getH" directly returns the value of the change (-1 to +3)
 *  wich will be processed in the "rusian" class.
**/

class health {
	private:
			hline dead;
			hline sick;
			hline weak;
			hline heal;

	public:
		health() {
			initialize(true);
		}
		health(bool Y) {
			initialize(Y);
		}
		
		void initialize(bool Y) { // only two different tables neccessary and therefore available. Choose with boolean-variable.
			if (Y) {
				dead.assign ( 46, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,2,2, 3,3,3,3,3, 3,3,3,4,4, 4 ); 
				sick.assign ( 46, 1,1,2,2,2, 2,3,3,3,3, 3,3,3,3,3, 3,3,3,3,3, 3,3,3,4,4, 4,4,4,4,4, 5,5,5,5,6, 6,6,6,6,7, 7,7,8,8,8, 9 ); 
				weak.assign ( 46, 4,4,4,5,5, 5,5,5,6,6, 6,7,7,7,7, 8,8,8,9,9, 9,10,10,10,11, 11,11,12,12,12, 12,12,13,13,13, 14,14,14,14,15, 15 ); 
				heal.assign ( 46, 13,14,14,14,15, 15,15,16,16,16, 17,17,17,17,18, 18,18,18,18,18, 19,19,19,19,19, 20,20,20,20,20, 20,20,20,20,20, 20,20,20,20,20, 20,20,20,20,20, 20 ); 
			} else {
				dead.assign ( 46, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0 );
				sick.assign ( 46, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,1,1, 1,1,1,1,1, 1,1,1,2,2, 2,2,2,2,2, 2,3,3,3,3, 3,3,3,3,3, 3,3,4,4,4, 4 ); 
				weak.assign ( 46, 2,2,2,2,2, 2,2,2,2,2, 2,2,2,2,2, 2,3,3,3,3, 3,3,3,3,3, 3,3,3,4,4, 4,4,4,4,4, 5,5,5,5,6, 6,7,7,8,8, 9 ); 
				heal.assign ( 46, 6,6,6,6,6, 7,7,7,7,8, 8,8,8,9,9, 9,9,10,10,10, 10,10,11,11,11, 11,12,12,12,13, 13,13,13,13,13, 13,14,14,15,15, 15,16,17,18,19, 19  ); 
			}
		}
		
		int getH(int age, int dice) { // Determines change of health
					if (dice < dead.get(age)) {
				return 3; 
			} else if (dice < sick.get(age)) {
				return 2;
			} else if (dice < weak.get(age)) {
				return 1;
			} else if (dice >= heal.get(age)) {
				return -1;
			} else {
				return 0;
			}
		}
		
		
};

// declared on global scope
health work(1);
health cure(0);


#endif // HEALTH_H