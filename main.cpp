#include <iostream>
#include <string>
#include "TopSpin.h"
using namespace std;


int main()
{
	int size, spinsize; // ini
	cout << "game size: "; cin >> size; // get size
	cout << "spin size?: "; cin >> spinsize; //get spinsize
	TopSpin a1(size, spinsize);//constructor that uses parameters size and spinsize
	cout << a1;
	int input;
	cout << "how many moves? ";
	cin >> input;

	for (int i = 0; i < input; i++)
		a1.shiftLeft();
	a1.spin();
	cout << a1;


	
	while (true)
	{
		int response = 0;
		cout << "Please choose from the following options enter your choice by entering the corresponding number: " << endl;
		cout << "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		cout << "your choice: ";
		cin >> response;
		//initialize before switch statement is used
		int direction = -1;
		int numberOfShifts = 0;
		switch (response)
		{//Shift 
		case 1:
			cout << "How many shifts do you want to have?" << endl;
			cin >> numberOfShifts;
			cout << "Which Direction of shift do you want? (right/left)(1/2) " << endl;
			cin >> direction;
			if (direction == 1)
			{
				for (int i = 0; i < numberOfShifts; i++)
					a1.shiftRight(); // shift games to the right n times
			}
			else
			{
				for (int i = 0; i < numberOfShifts; i++)
					a1.shiftLeft();// shift games to the left n times
			}
			cout << a1;
			if (a1.isSolved())
				return 0;
			break;
		case 2:
			a1.spin(); // flip the value that is within the game
			cout << a1;
			if (a1.isSolved())
				return 0;
			break;
		case 3:
			return 0; // exit the program
			break;
		}
	}
		
	return 0;
	}
