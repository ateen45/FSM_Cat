class Approached: public State {
	public:
		Approached();  
		void enter();
		void exit();
		int updateAndCheckTransitions();

		string symbol = R"(
		 ,_     _
		 |\\_,-~/
		 / _  _ |    ,--.
		(  @  @ )   / ,-'
		 \  _T_/-._( (
		 /         `. \
		|         _  \ |
		 \ \ ,  /      |
		  || |-_\__   /
		 ((_/`(____,-'

		)"; 

		string message;
};

Approached::Approached() {}

void Approached::enter() {

	// print state symbol
	cout << symbol << endl;
	cout << name << " is just chilling... \n" << endl;
}

int Approached::updateAndCheckTransitions() {

	int returnvalue;

	statCheck();

	message = "";

	// user input
	int choice;
	cout << "\n(1) Feed \n(2) Pet \nYour choice: ";
	cin >> choice;

	// execute functions based on choice
	if (choice == 1) { feed(); }
	else if (choice == 2) { pet(); }
	else { cout << "no choice made" << endl; }

	// evaluate states ... can go to: (2), (4), or [1]
	if (temper < 39 || trust < 39) { 
		
		returnvalue = 2; 
		message = "uh oh...";
	}
	else if (temper > 59 && trust > 59) { 
		
		returnvalue = 4; 
		message = "awwwwww!";
	}
	else { returnvalue = 1; }

	return returnvalue;
}

void Approached::exit() {
	// What happens when we leave this state for a different one.
	system("cls");
	cout << message << endl;
}
