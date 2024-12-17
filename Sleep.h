class Sleep: public State {
	public:
		Sleep();  
		void enter();
		void exit();
		int updateAndCheckTransitions();

		string symbol = R"(
		      |\      _,,,---,,_
		ZZZzz /,`.-'`'    -.  ;-;;,_
		     |,4-  ) )-,_. ,\ (  `'-'
		    '---''(_/--'  `-'\_) 
		)";

		string message;
};

Sleep::Sleep() {}

void Sleep::enter() {

	// print state symbol
	cout << symbol << endl;
	cout << name << " is sleeping ! \n" << endl;
}

int Sleep::updateAndCheckTransitions() {
	
	int returnvalue;

	statCheck();

	message = "";

	// user input
	int choice;
	cout << "\n(1) Pet \n(2) Take home \n(0) Leave alone \nYour choice: ";
	cin >> choice;

	// evaluate states... can go to (4), (0), or [6]
	if (choice == 1) {

		// stores current values for trust and temper
		int oldTemper = temper;
		int oldTrust = trust;
		pet();
		// checks for pet() failure, since one or both of these values should decrease
		if (temper < oldTemper || trust < oldTrust) { 

			returnvalue = 4;
			message = name + " woke up ! (must've pet too hard...)";
		}
		else { returnvalue = 6; } // stays asleep
	}
	else if (choice == 2) { 

		// chance to fail... higher stats = higher chance success (meant to have low chance)
		int chance = rand() % 101;
		if (chance < (100 - temper) + (100 - trust) + (100 - hunger) ){

			statReset();
			returnvalue = 0;
			message = "oh no! i startled " + name + " !";
			
		}
		else {

			cout << "took " << name << " home ! :)" << endl;
			cout << name << " is now your pet! \n" << endl;
			cout << "write a name for your new pet: ";
			cin >> name;

			returnvalue = 4;
			message = "awwwww " + name + " is happy to be home! <3";
		}
	}
	else { returnvalue = 6; }

	return returnvalue;
}

void Sleep::exit() {
	// What happens when we leave this state for a different one.
	system("cls");
	cout << message << endl;
}