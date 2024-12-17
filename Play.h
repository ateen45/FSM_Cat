class Play: public State {
	public:
		Play();  
		void enter();
		void exit();
		int updateAndCheckTransitions();

		string symbol = R"(
                   .-o=o-.
               ,  /=o=o=o=\ .--.
              _|\|=o=O=o=O=|    \
          __.'  a`\=o=o=o=(`\   /
          '.   a 4/`|.-""'`\ \ ;'`)   .---.
            \   .'  /   .--'  |_.'   / .-._)
             `)  _.'   /     /`-.__.' /
              `'-.____;     /'-.___.-'
                       `"""`
		)";

		string message;
};

Play::Play() {}

void Play::enter() {
	
	// print state symbol
	cout << symbol << endl;
	cout << name << " is playing ! \n" << endl;
}

int Play::updateAndCheckTransitions() {
	
	int returnvalue;

	statCheck();

	message = "";

	// int used to increase fatigue
	int incr = (rand() % 6) + 5; // number beween 5 and 10
	fatigue += incr;

	// int used to decrease hunger
	int decr = (rand() % 6) + 5; // number between 5 and 10
	hunger -= decr;

	// user input
	int choice;
	cout << "\nKeep playing? \n(1) Yes \n(0) No \nYour choice: ";
	cin >> choice;

	// execute player choice
	if (choice == 1) {

		// chance to fail ... back to purr (the fuller cat is, the higher chance to keep playing)
		int chance = rand() % 100;
		if (chance < 100 - hunger ) {

			returnvalue = 4;
			message = "guess " + name + " wanted to take a break ?";
		}
		else {

			// execute on success 
			cout << "meeeeooww! (this is fun !)" << endl;

			// checks fatigue to keep playing [5] or sleep (6)
			if (fatigue > 79 && temper > 79 && temper > 79) { 

				returnvalue = 6; 
				message = "awwww so much playing made " + name + " sleepy...";
			}
			else { returnvalue = 5; }
		}
	} // stopped playing, so goes to Purr
	else { 

		returnvalue = 4; 
		message = "that's enough playing for right now...";
	}

	return returnvalue;
}

void Play::exit() {
	// What happens when we leave this state for a different one.
	system("cls");
	cout << message << endl;
}