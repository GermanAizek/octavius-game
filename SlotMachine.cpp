#include "Classes/SlotMachine.h"

SlotMachine::SlotMachine()
{
	credits = 0;
	betAmount = 0;

	wheels[0] = new Wheel();
	wheels[1] = new Wheel();
	wheels[2] = new Wheel();

	// Initialize screen
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			screen[i][j] = 0;
		}
	}
}

SlotMachine::~SlotMachine() {
	delete(wheels[0]);
	delete(wheels[1]);
	delete(wheels[2]);
}

// Spins the wheels and calls the loading of each wheel's results.
// Then calls to check for winnings.
void SlotMachine::spin()
{
	if (betAmount > 0) {
		spinnable = true;

		wheels[0]->spin();
		wheels[1]->spin();
		wheels[2]->spin();

		int* column1 = wheels[0]->read();
		int* column2 = wheels[1]->read();
		int* column3 = wheels[2]->read();

		loadscreen(0, column1);
		loadscreen(1, column2);
		loadscreen(2, column3);

		printscreen();
		checkwinnings();

		//betAmount = 0;

		delete[] column1;
		delete[] column2;
		delete[] column3;

		column1 = column2 = column3 = NULL;
	}
	else
		std::cout << "Please make a bet before spinning.\n";
}

void SlotMachine::forceStop()
{
	forceStopped = true;
}

std::vector<int> SlotMachine::getScreen()
{
	std::vector<int> screenVec;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			screenVec.push_back(screen[i][j]);
		}
	}

	return screenVec;
}

// Loads a wheel into the respective column of the screen
void SlotMachine::loadscreen(int col, int* wheelcolumn)
{
	for (int i = 0; i < 3; i++)
		screen[i][col] = wheelcolumn[i];
}

// Simply prints the screen
void SlotMachine::printscreen()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << screen[i][j] << " ";
		}
		std::cout << '\n';
	}
}

// Bet function takes the number of lines the user wants to bet on (3 horizontal, 2 diagonals)
// and checks if they have enough credits to bet that much.
void SlotMachine::bet(int lines)
{
	if ((lines < 1) || (lines > 5)) {
		std::cout << "You may only bet between 1 and 5 lines. Please try again.\n";
	}
	else if ((credits - lines) < 0) {
		std::cout << "You have " << credits << " credits available. Try adding more money.\n";
	}
	else {
		betAmount = lines;
		credits -= betAmount;
	}
}

// Adds a credit
void SlotMachine::insertcoin()
{
	credits = 1000;

	std::cout << "You now have " << credits << " credits.\n";
}

// Adds multiple credits based on the bill denomination.
void SlotMachine::insertbill(double billAmount)
{
	if ((billAmount >= 1.00) && (billAmount <= 20.00)) {
		int newcredits = (int)(billAmount / .25);
		credits += newcredits;

		std::cout << "You now have " << credits << " credits.\n";
	}
}

// Checks lines for wins and adds credits earned.
void SlotMachine::checkwinnings()
{
	int lineValues[3];
	int winnings = 0;

	// Check line middle line
	if (betAmount >= 1) {
		for (int i = 0; i < 3; i++) {
			lineValues[i] = screen[1][i];
		}

		winnings += checkline(lineValues);
	}

	// Check line top line
	if (betAmount >= 2) {
		for (int i = 0; i < 3; i++) {
			lineValues[i] = screen[0][i];
		}

		winnings += checkline(lineValues);
	}

	// Check bottom line
	if (betAmount >= 3) {
		for (int i = 0; i < 3; i++) {
			lineValues[i] = screen[2][i];
		}

		winnings += checkline(lineValues);
	}

	// Check left to right diagonal
	if (betAmount >= 4) {
		for (int i = 0; i < 3; i++) {
			lineValues[i] = screen[i][i];
		}

		winnings += checkline(lineValues);
	}

	// Check right to left diagonal
	if (betAmount == 5) {
		for (int i = 2; i >= 0; i--) {
			lineValues[i] = screen[i][i];
		}

		winnings += checkline(lineValues);
	}

	if (winnings > 0) {
		std::cout << "You won " << winnings << " credits!\n";
		credits += winnings;
	}
	else {
		std::cout << "Sorry, you did not win anything.\n";
	}

	lastWinning = winnings;
	std::cout << "You have " << credits << " credits left.\n\n";
}

// Determines the winning sequences. 
// 3 of a kind wins something
// Two cherries and something else wins as does two luckysevens and something else.
int SlotMachine::checkline(int line[3])
{
	if (line[0] == this->seven && line[1] == this->seven && line[2] == this->seven) { return 1000; }
	if (line[0] == this->watermelon && line[1] == this->watermelon && line[2] == this->watermelon) { return 800; }
	if (line[0] == this->bar && line[1] == this->bar && line[2] == this->bar) { return 600; }
	if (line[0] == this->plum && line[1] == this->plum && line[2] == this->plum) { return 500; }
	if (line[0] == this->bell && line[1] == this->bell && line[2] == this->bell) { return 400; }
	if (line[0] == this->cherry && line[1] == this->cherry && line[2] == this->cherry) { return 375; }
	if (line[0] == this->orange && line[1] == this->orange && line[2] == this->orange) { return 350; }
	if (line[0] == this->banana && line[1] == this->banana && line[2] == this->banana) { return 300; }
	if (line[0] == this->seven && line[1] == this->seven) { return 200; }
	if (line[0] == this->cherry && line[1] == this->cherry) { return 50; }
	if (line[0] == this->lemon && line[1] == this->lemon && line[2] == this->lemon) { return 5; }

	return 0;
}