#include"TopSpin.h"

TopSpin::TopSpin(int size, int spinSize) // constructor that get 2 parameter
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
	for (int x = gameSize; x >=1 ; x--)
	{
		board.addItem(x); // go to circular doubly linked list
	}
}

TopSpin::~TopSpin()
{ // no dma here
}

int TopSpin::getSize() const
{
	return gameSize; //return size and dont change any val
}

ostream& operator << (ostream& os, const TopSpin& s)
{
	CircularDoublyLinkedList<int>::Iterator a1 = (s.board).begin();
	//output stuff dont care that much
	cout << "|-";
	for (int i = 0; i < s.spin_size; i++)
		cout << "--";
	cout << "|" << endl;

	//oputs value
	for (int i = 0; i < s.gameSize; i++, ++a1)
	{
		if (i == 0 || i == s.spin_size)
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
	board.move_head(false);//move head giving direction
}

void TopSpin::shiftRight()
{
	board.move_head(true); //move head giving direction
}
void TopSpin::shiftLeft(int times)
{
	for (int i = 0; i < times; i++)
		shiftLeft();
}
void TopSpin::shiftRight(int times)
{
	for (int i = 0; i < times; i++)
		shiftRight();
}
void TopSpin::spin()
{
	CircularDoublyLinkedList<int>::Iterator g(board.getHead());
	CircularDoublyLinkedList<int>::Iterator here(board.getHead());
	//declare 2 nodes so we can swap 2 location 
	for (int i = 1; i < spin_size; ++i)
		++g; //find last node of spin size
	for (int k = 1; k <= (spin_size / 2); k++,++here,--g)
	{
		int temp = here.getValue(); // store value temeraerly
		here.setValue(g.getValue());//set value to the here val
		g.setValue(temp);// set value of temp
	}
}

bool TopSpin::isSolved()
{	//get temp iterator that gets value of the head
	CircularDoublyLinkedList<int>::Iterator temp(board.getHead());
	bool found = false;
	while (!found)// find where number value 1 is
		(temp.getValue() == 1) ? found = true : ++temp;
	--temp; // add one more to compare 2
	for (int val = 2; val <= gameSize; --temp, val++)
	{
		if (val != temp.getValue()) // if val does not match return false 
			return 0; // false

	}
	cout << "CONGRATULATIONS!" << endl;
	return 1;//return true
}


