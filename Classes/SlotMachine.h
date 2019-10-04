#pragma once

#include "Wheel.h"

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

private:
	void loadscreen(int col, int* wheelcolumn);
	void checkwinnings();
	int checkline(int line[3]);
	int credits;
	int betAmount;
	int screen[3][3];

	Wheel* wheels[3];
	bool forceStop;
};
