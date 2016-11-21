#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;
//Abstract Class

class TopSpinADT {
public:
	virtual void shiftLeft() = 0;
	virtual void shiftRight() = 0;
	virtual void spin() = 0;
	virtual bool isSolved() = 0;
};

class TopSpin :public TopSpinADT
{
private:
	int gameSize;
	int spin_size;
	CircularDoublyLinkedList<int> board; // composition of board
public:
	TopSpin(int& size, int& spinSize);
	~TopSpin();
	//Top Spin Functions
	int getSize() const;
	void shiftLeft();
	void shiftRight();
	void spin();
	bool isSolved();
	//getfunctions
	friend ostream& operator<< (ostream& os, const TopSpin& s);
};

