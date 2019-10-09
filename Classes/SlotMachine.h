#include "Wheel.h"
#include <iostream>
#include <vector>

class SlotMachine {
public:
	enum Image
	{
		seven = 1,
		banana,
		watermelon,
		bell,
		bar,
		lemon,
		orange,
		plum,
		cherry
	};

	SlotMachine();
	~SlotMachine();
	void spin();
	void bet(int lines);
	void insertcoin();
	void insertbill(double billAmount);
	void printscreen();

	void forceStop();
	void setSpinnable(bool spin) { spinnable = spin; }

	std::vector<int> getScreen();
	bool getSpinnable() { return spinnable; }
	int getLastWinning() { return lastWinning; }
	int getCredits() { return credits; }

private:
	void loadscreen(int col, int* wheelcolumn);
	void checkwinnings();
	int checkline(int line[3]);
	int credits;
	int betAmount;
	int screen[3][3];
	int lastWinning = 0;
	bool spinnable;

	Wheel* wheels[3];
	bool forceStopped;
};
