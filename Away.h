class Away: public State {
	public:
		Away();  
		void enter();
		void exit();
		int updateAndCheckTransitions();

		string symbol = R"(
						     (\
						      ))         )\\
						     ((         /  .(
						      \\.-"```"'` =_/=
						       >  ,       /
						       \   )__.\ |
						        > / /  ||\\
						        \\ \\  \\ \\
						         `" `" `"  `"
		)";

		string message;
};

Away::Away() {}

void Away::enter() {
	// What should happen when the state is entered from another state
	
	// print state symbol
	cout << symbol << endl;
	cout << name << " is far away ! \n" << endl;
}

int Away::updateAndCheckTransitions() {
	// What should happen each turn while the character is in this state.
	// This will probably involve prompting the player for information about the
	// external environment related to what happens in this state.

	// Return the number of the next state to go to. If you are staying in the
	// same state, just return its number

	int returnvalue;
	
	statCheck();

	message = "";

	// user input	
	int choice;
	cout << "\nApproach " << name << "? \n(1) Yes \n(0) No \nYour choice: ";
	cin >> choice;

	// evaluate states... can go to (1) or [0]
	if (choice == 1) {	

		returnvalue = 1; 
		message = name + " looks so cute up close... ";
	}
	else { returnvalue = 0; }

	return returnvalue;
}

void Away::exit() {
	// What happens when we leave this state for a different one.
	system("cls");
	cout << message << endl;

}