#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;
//Abstract Class

class TopSpinADT 
{
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
	TopSpin(int size, int spinSize);
	~TopSpin();
	//Top Spin Functions
	int getSize() const; //return size
	void shiftLeft();//shift all numbers to the left and first value goes to m_tail
	void shiftRight();//shift all numbers to the right and last val goes to m_head
	void shiftLeft(int times);
	void shiftRight(int times);
	void spin(); // spin the value of m_head to m_head + spinsize
	bool isSolved(); //check if the numbers are ordered 1 to n orderly

	//other functions
	friend ostream& operator<< (ostream& os, const TopSpin& s);
};

