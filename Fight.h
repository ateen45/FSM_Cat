class Fight: public State {
	public:
		Fight();  
		void enter();
		void exit();
		int updateAndCheckTransitions();

		string symbol = R"(
		   __
                  ` \\
          /\=/\-""-.//
         = 'Y' =  ,  \
          '-^-'  /(  /
           /;_,) |\\ \
          (_/ (_/ (_(_/
          ""  ""  "" ""
		)";

		string message;
};

Fight::Fight() {}

void Fight::enter() {
	
	// print state symbol
	cout << symbol << endl;
	cout << name << " is scratching me ! \n" << endl;
}

int Fight::updateAndCheckTransitions() {

	int returnvalue;

	statCheck();

	message = "";

	// user input
	int choice;
	cout << "\n(1) Feed \n(2) Pet \n(0) Run away \nYour choice: ";
	cin >> choice;

	// execute functions based on choice
	if (choice == 1) { feed(); }
	else if (choice == 2) { pet(); }
	else if (choice == 0) {

		// player chose to run away, so cat stats are reset
		statReset();
		returnvalue = 0;
		message = "finally i'm safe...";

		return returnvalue;
	}
	else { cout << "no choice made..." << endl; }

	// evaluate states... can go to (0), (2), or [3] << 0 handled above >>
	if (temper > 29 && trust > 29) { 

		returnvalue = 2; 
		message = "okaaayyy... i better not make " + name + " mad again...";
	}
	else { returnvalue = 3; }

	return returnvalue;
}

void Fight::exit() {
	// What happens when we leave this state for a different one.
	system("cls");
	cout << message << endl;
}