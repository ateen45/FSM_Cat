
/* 
 * File:   main.cpp
 * Author: John Sullins
 * Modified by: Alan Cuevas
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <ctime>

#include "State.h" 
#include "Away.h"		     // 0
#include "Approached.h"	// 1
#include "Hiss.h"		   // 2
#include "Fight.h"		// 3
#include "Purr.h"		 // 4
#include "Play.h"		// 5
#include "Sleep.h" // 6

using namespace std;

/***** Initialize any static global variables */ 
int State::baseTemper;
int State::baseTrust;
int State::baseHunger;
int State::baseFatigue;

int State::temper;
int State::trust;
int State::hunger;
int State::fatigue;
int State::turnCount = 1; // turn counter starts @ 1
string State::name = "the cat"; // orginal name

/**** Main driver for FSM ****************************/
int main(int argc, char** argv) {

	// randomize and conserve base stats
	srand(time(nullptr));
	State::baseTemper = (rand() % 21) + 40;		// random int between 40 and 60
	State::baseTrust = (rand() % 21) + 40;		// random int between 40 and 60
	State::baseHunger = (rand() % 31) + 20;		// random int between 20 - 50
	State::baseFatigue = (rand() % 31) + 30; 	// random int between 30 and 60

	// set changeable stats for cat
	State::temper = State::baseTemper;
	State::trust = State::baseTrust;
	State::hunger = State::baseHunger;
	State::fatigue = State::baseFatigue;

	/* IMPORTANT! Change the 3 to the number of states you have ***/
	State *states[7];

 	/* IMPORTANT! Modify this code to create each of your states ***/
  	states[0] = new Away();          // cat is AWAY from you
  	states[1] = new Approached();   // cat is APPROACHED by you
  	states[2] = new Hiss();        // cat is HISSing at you
  	states[3] = new Fight();      // cat is FIGHTing you
  	states[4] = new Purr();      // cat is PURRing at you
  	states[5] = new Play();     // cat is PLAYing with you
  	states[6] = new Sleep();   // cat is SLEEPing on you

  	/**** End of code to modify ****/

  	int currentState = 0;
  	int nextState;  

  	states[0]->enter();
  	while(1) {
    	nextState = states[currentState]->updateAndCheckTransitions();
    	if (nextState != currentState) {
      		states[currentState]->exit();
      		currentState = nextState;
      		states[currentState]->enter();
      	}	
    }

	return 0;
}
