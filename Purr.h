class Purr: public State {
	public:
		Purr();  
		void enter();
		void exit();
		int updateAndCheckTransitions();

		string symbol = R"(
		 /\     /\
		{  `---'  }
		{  O   O  }
		~~>  V  <~~
		 \  \|/  /
		  `-----'__
		  /     \  `^\_
		 {       }\ |\_\_   W
		 |  \_/  |/ /  \_\_( )
		  \__/  /(_E     \__/
		    (  /
		)";

		string message;
};

Purr::Purr() {}

void Purr::enter() {
	
	// print state symbol
	cout << symbol << endl;
	cout << name << " is purring! \n" << endl;
}

int Purr::updateAndCheckTransitions() {

	int returnvalue;

	statCheck();

	message = "";

	// user input
	int choice;
	cout << "\n(1) Feed \n(2) Pet \n(3) Play with " << name << "\nYour choice: ";
	cin >> choice;

	// execute function based on choice
	if (choice == 1) { feed(); }
	else if (choice == 2) { pet(); }
	else if (choice == 3) {

		// cat will only play if stats are "very high" (80+)
		if (temper > 79 && trust > 79) { 

			returnvalue = 5;
			message = "good thing i brought this yarn...";

			return returnvalue;
		}
		else { cout << "\n" << name << " doesn't want to play right now..." << endl; }

	}
	else {
		
		cout << "no choice made" << endl;
	}

	// evaluate states... can go to (1), (5), (6), or [4] << 5 handled above >>
	if (fatigue > 79 && temper > 79 && trust > 79) { // will only sleep if stats are "very high" (80+) << fatigue handled in Play state >>
		
		returnvalue = 6; 
		message = "awwww " + name + " must've been tired...";
	}
	else if (temper < 60 || trust < 60) { 
		
		returnvalue = 1; 
		message = name + " stopped purring... </3";
	}
	else { returnvalue = 4; }

	return returnvalue;
}

void Purr::exit() {
	// What happens when we leave this state for a different one.
	system("cls");
	cout << message << endl;
}