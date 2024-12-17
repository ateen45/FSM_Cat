#include <iostream>
using namespace std;

class State {
	public:
		virtual int updateAndCheckTransitions() = 0;
		virtual void enter() = 0;
		virtual void exit() = 0;
		
		void feed();
		void pet();
		void statReset();
		void statCheck();

		// this string will be used to store the name of the cat... you can name only if you successfully take it home
		static string name;

		// these values are used to reset the cat's stats if he runs away or you do
		static int baseTemper;
		static int baseHunger;
		static int baseTrust;
		static int baseFatigue;

		// these values are used to store current cat stats... higher number is always "good"
		static int temper;
		static int trust;
		static int hunger;
		static int fatigue;

		// stores number of turns passed
		static int turnCount;

};

// executed when feed is chosen
void State::feed() {

	// points between 5 and 10...
	int temperPoints = rand() % 6 + 5;
	int hungerPoints = rand() % 6 + 5;
	int trustPoints = rand() % 6 + 5;

	// random number to compare
	int chance = rand() % 100;
	
	// odds based on hunger... the fuller he is, the less likely he'll accept the food
	// points penalized on failure, increase on success
	if (chance < hunger) {

		cout << R"(

		|\---/|
		| -_- |
		 \_^_/

		)" << endl;
		cout << "meEEOW !!! (yuck ! >:P)" << endl;
		temper -= temperPoints;
		// hunger = hunger;
		trust -= trustPoints;
	}
	else {

		cout << R"(

		|\---/|
		| ^_^ |
		 \_Y_/

		)" << endl;
		cout << "miauuu... (yum !)" << endl;
		temper += temperPoints;
		hunger += hungerPoints;
		trust += trustPoints;
	}
}

// executed when pet is chosen
void State::pet() {


	// points between 5 and 10
	int temperPoints = rand() % 6 + 5;
	int hungerPoints = rand() % 6 + 5;
	int trustPoints = rand() % 6 + 5;

	// random number to compare
	int chance = rand() % 100;

	// the fuller and happier he is, the more likely he'll let you pet him (subtracted trust for balance)
	// penalize points on failure, incresae on success
	if (chance > ((hunger + temper) - trust))  {

		cout << R"(

		|\---/|
		| -_- |
		 \_^_/

		)" << endl;
		cout << "meee-OUCH !!! (watch it, pal)" << endl;
		temper -= temperPoints;
		// hunger = hunger;
		trust -= trustPoints;
	}
	else {

		cout << R"(

		|\---/|
		| ^_^ |
		 \_Y_/

		)" << endl;
		cout << "meeeoowwwww... (oooooo... aaaahhhh...)" << endl;
		temper += temperPoints;
		// hunger = hunger;
		trust += trustPoints;
	}

}

// executed if cat or player runs away... return to base stats (basically a retry)
void State::statReset() {

	temper = baseTemper;
	trust = baseTrust;
	hunger = baseHunger;
	fatigue = baseFatigue;
}

// executed every turn to keep stats within range of 0 to 100...
// will also keep track of turn count to update hunger
void State::statCheck() {

	if (temper > 100) { temper = 100 - (temper - 100); } // if greater than 100, takes surplus and subtracts it from 100
	else if (temper < 0) { temper = 0 + (temper * -1); } // else if less than 0, takes the defecit and adds the inverse
	
	if (trust > 100) { trust = 100 - (trust - 100); }
	else if (trust < 0) { trust = 0 + (trust * -1); }

	if (hunger > 100) { hunger = 100 - (hunger - 100); }
	else if (hunger < 0) { hunger = hunger * -1; }

	if (fatigue > 100) { fatigue = 100 - (fatigue - 100); }
	else if (fatigue < 0) { fatigue = 0 + (fatigue * -1); }

	// increment turns... decrease hunger every 10 turns
	if (turnCount == 10) {

		turnCount = 1;
		int diff = rand() % 10; // random number to decrease hunger
		hunger -= diff;
	}
	else { turnCount++; }

	// display stats
	/*
	cout << "************************************" << endl;
	cout << "temper: " << temper << endl;
	cout << "hunger: " << hunger << endl;
	cout << "trust: " << trust << endl;
	cout << "fatigue: " << fatigue << endl;
	cout << "turnCount: " << turnCount << endl;
	cout << "************************************" << endl;
	*/
}
