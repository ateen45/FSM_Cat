class Hiss: public State {
	public:
		Hiss();  
		void enter();
		void exit();
		int updateAndCheckTransitions();

		string symbol = R"(
		        ,-""""""-.
		     /\j__/\  (  \`--.
		     \`@_@'/  _)  >--.`.
		    _{.:Y:_}_{{_,'    ) )
		   {_}`-^{_} ```     (_/
		)";

		string message;
};

Hiss::Hiss() {}

void Hiss::enter() {
	
	// print state symbol
	cout << symbol << endl;
	cout << name << " is hissing at me ! \n" << endl;
}

int Hiss::updateAndCheckTransitions() {

	int returnvalue;

	statCheck();

	message = "";

	// user input
	int choice;
	cout << "\n(1) Feed \n(2) Pet \nYour choice: ";
	cin >> choice;

	// execute function based on choice
	if (choice == 1) { feed(); }
	else if (choice == 2) { pet(); }
	else { cout << "no choice made... " << endl; }

	// evaluate states... can go to (1), (3), or [2]
	if (temper > 39 && trust > 39) { 

		returnvalue = 1;
		message = "phew!";
	}
	else if (temper < 30 || trust < 30) { 

		returnvalue = 3;
		message = "aaaaAAAAHHHHHH !!! ";
	}
	else { returnvalue = 2; }

	return returnvalue;
}

void Hiss::exit() {
	// What happens when we leave this state for a different one.
	system("cls");
	cout << message << endl;
}