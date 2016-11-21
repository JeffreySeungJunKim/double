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

TopSpin::TopSpin(int& size, int& spinSize) // constructor that 
{
	//Checks params if they are within bounds
	if (size<1 || spinSize>size)
	{
		cout << "invalid entry. Setting size of game and spin to default" << endl;
		gameSize = 20;
		spinSize = 4;
	}
	//Adjust params to user inputted params
	else
	{
		gameSize = size;
		spin_size = spinSize;
	}

	//Adding values to List
	for (int x = 1; x <= size; x++)
	{
		board.addItem(x); // go to circular doubly linked list
	}
}

TopSpin::~TopSpin()
{ // no dma here
}

int TopSpin::getSize() const
{
	return gameSize;
}

ostream& operator << (ostream& os, const TopSpin& s)
{
	CircularDoublyLinkedList<int>::Iterator a1 = (s.board).begin();
	//output stuff dont care that much
	cout << "|-";
	for (int i = 0; i < s.spin_size; i++)
		cout << "--";
	cout << "|" << endl;

	for (int i = 0; i < s.gameSize; i++, ++a1)
	{
		if (i == 0 || i==s.spin_size)
			cout << "| ";
		os << a1.getValue() << " "; //output a value that is stored in node
	}
	//output stuff dont care that much
	cout << endl;
	cout << "|-";
	for (int i = 0; i < s.spin_size; i++)
		cout << "--";
	cout << "|" << endl;
	return os;
}

void TopSpin::shiftLeft()
{
	board.move_head(false);
}

void TopSpin::shiftRight()
{
	board.move_head(true);
}

void TopSpin::spin()
{
	CircularDoublyLinkedList<int>::Iterator g(board.getHead());
	CircularDoublyLinkedList<int>::Iterator here(board.getHead());
	for (int i = 1; i < spin_size; ++i) 
		++g;// get to its location
	for (int k = 1; k <= (spin_size / 2); k++) 
	{
		int temp = here.getValue();
		here.setValue(g.getValue());
		g.setValue(temp);
		++here;
		--g;
	}
}

bool TopSpin::isSolved()
{	//get temp iterator that gets value of the head
	CircularDoublyLinkedList<int>::Iterator temp(board.getHead());
	bool found = false;
	while (!found)// find where number value 1 is
		(temp.getValue() == 1) ? found= true : ++temp;
	++temp;
	int reverseCount = gameSize;
	for (int val = temp.getValue()+1; val <= gameSize; val++, --temp, reversecounter--)
	{
		if (val != temp.getValue() && reversecount != temp.getValue()) // if val does not match return false 
			return 0;
	}
	cout << "CONGRATULATIONS!" << endl;
	return 1;//return true
}


