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
	void bet(int);
	void insertcoin();
	void insertbill(double);
	void printscreen();

private:
	void loadscreen(int, int*);
	void checkwinnings();
	int checkline(int line[3]);
	int credits;
	int betAmount;
	int screen[3][3];

	Wheel* wheels[3];
};
