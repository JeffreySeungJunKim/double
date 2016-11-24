#pragma once
template <class T>
class CircularDoublyLinkedList 
{
//Allowing for nodes for head and tail 
private:
	class Node {
	public:
		//Node Constructor 
		Node(T val, Node* nx = nullptr, Node* prv = nullptr)
		{
			this->Value = val;
			this->next = nx;
			this->previous = prv;
		}
		//stores next and previous
		T Value;
		Node*next;
		Node*previous;
	};
	//doubly linked list declaration
	Node* m_head;
	Node* m_tail;
	unsigned int m_size;

public:
	//constructor
	CircularDoublyLinkedList();
	//destrcutor
	~CircularDoublyLinkedList();
	//Add Item to the head.
	void addItem(T val);
	//get head
	inline Node*getHead()const { return m_head; }
	//move head and get direction as parameter
	void move_head(bool direction);
	//default function that will not be used but i want the mark
	unsigned int size() const;
	bool isEmpty() const;
	T removeHead();
	T retrieveHead()const;
	void addTail(T val);
	T removeTail();
	T retrieveTail()const;
	void add(unsigned pos, T val);
	T replace(unsigned pos, T val);
	T remove(unsigned pos);
	T retrieve(unsigned pos);
	void swap(unsigned pos1, unsigned pos2);
	
	
	class Iterator 
	{// iterators are used for efficient traversal of linked lists
	private:
		Node* m_ptr;    // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator++ () { m_ptr = m_ptr->next; } // for forward traversing to next node
		void operator--() { m_ptr = m_ptr->previous; } // operator -- that is pre-operator transversing to previous node
		T getValue() { return m_ptr->Value; } // use get function to access the private node
		void setValue(int val) { m_ptr->Value = val; } // set value using 
	};
	Iterator begin() const{ return Iterator(m_head); }
	Iterator end() const{ return Iterator(m_tail); }
};

//Template creation of CircularDoublyLinkedList
//Head and tail point to nothing if it is the first node
template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() :
m_head(nullptr), m_tail(nullptr), m_size(0)
{}
template <class T>
CircularDoublyLinkedList<T>:: ~CircularDoublyLinkedList()
{
	Node * here = m_head, *nextNode;
	//delete until all the node is freed
	while (this->m_size > 0)
	{
		nextNode = here->next;
		delete here;
		here = nextNode;
		m_size--;
	}
}
template<class T>
unsigned int CircularDoublyLinkedList<T>::size() const
{
	retun this->m_size;
}
template<class T>
bool CircularDoublyLinkedList<T>::isEmpty() const
{
	return (m_size == 0);
}
template<class T>
T CircularDoublyLinkedList<T>::removeHead()
{
	Node * oldNode = m_head; // store temp node to delete
	T returnVal = m_head->Value;
	//link before deleting
	m_head = m_head->next;
	m_tail->next = m_head;
	m_head->previous=m_tail
	if (m_head == nullptr) 
		m_tail = nullptr;
	m_size--;
	delete oldNode; // delete that node
	return returnVal;//return value of the old node had
}
template<class T>
T CircularDoublyLinkedList<T>::retrieveHead() const
{
	return m_head->Value;
}
template <class T>
void CircularDoublyLinkedList<T>::addTail( T val)
{
	if (isEmpty())
		addItem(val);
	else 
	{
		Node *temp = new Node(val);
		temp->previous = m_tail;
		temp->next = m_head;
		m_tail = temp;
		m_size++;
	}
}
template <class T>
T CircularDoublyLinkedList<T>::removeTail()
{
	Node * old = m_tail;
	T returnVal = m_tail->Value;
	m_tail = m_tail->previous;
	m_tail->next = m_head;
	m_head->previous = m_tail;
	
	if (m_head == nullptr) m_tail = nullptr;
	m_size--;
	delete old; // delete that node
	return returnVal;//return value of the old node had
}
template <class T>
T CircularDoublyLinkedList<T>::retrieveTail() const
{
	return (m_tail->Value);
}
template <class T>
void CircularDoublyLinkedList<T>::add(unsigned pos, T val)
{
	if (isEmpty() || pos > m_size)
	{
		cout << "invalid position, returning without change" << endl;
		return;
	}
		
	Node* temp =m_head;
	for (int i = 1; i < pos-1; i++)
		temp = temp->next;
	temp->next = new Node(val, temp->next, temp);
	(temp->next)->previous = temp;
	m_size++;
}
template <class T>
T CircularDoublyLinkedList<T>::replace(unsigned pos, T val)
{
	T returnValue;
	if (pos > m_size || pos ==0) 
	{//errormessage if the pos is greater than the size or zero
		cout << "invalid position, returning without change" << endl;
		return 0;
	}
		
	Node * here = m_head;
	//go to the position using forloop
	for (unsigned int k = 1; k < pos; k++)
		here = here->next;
	//if you find that place replace the val to user inputeed value
	returnValue = here->Value;
	here->Value = val;
	return returnValue;
}

template <class T>
T CircularDoublyLinkedList<T>::remove(unsigned pos)
{
	if (pos == 0 || pos >m_size)
	{ //give error message if the position is greater then the size or is zero
		cout << "invalid position, returning without change" << endl;
		return;
	}
	//if it is the first remove head
	if (n == 1)
		return removeHead();
	//if its at the end of the size, remove head
	if (n == m_size)
		return removeTail();
	//if not 3 cases do this equations
	Node * here = m_head;
	for (unsigned int k = 1; k < pos - 1; k++)
		here = here->next;
	Node * kill = here->next;// find a place to kill
	T returnVal = kill->value;//save return val
	//link the nodes again so there are no runtime error
	here->next = kill->next;
	(kill->next)->previous = here;
	//delete wanted node
	delete kill;
	m_size--; //adjust size
	return returnVal;
}

template <class T>
void CircularDoublyLinkedList<T>::swap(unsigned pos1, unsigned pos2)
{
	if (pos1 == 0 || pos2 == 0 || pos1 > m_size || pos2 > m_size)
	{//give error message if the position is greater then the size or is zero
		cout << "invalid position, returning without change" << endl;
		return;
	}
	Node *temp = m_head;
	Node *temp2 = m_head;
	T store_val;
	//go to pos 1
	for (int i = 1; i < pos1; i++)
		temp = temp->next;
	//go 2 pos 2
	for (int i = 1; i < pos2; i++)
		temp2 = temp2->next;
	//swap value
	store_val = temp->Value;
	temp->Value = temp2->Value;
	temp2->Value = store_val;
}
template <class T>
void CircularDoublyLinkedList<T>::addItem(T val)
{
	//Create a new node with null previous and next pointers
	m_head = new Node(val, this->m_head, this->m_tail);
	//If this is the first value 
	if (m_tail == nullptr) // check if this is the first value that was inputed
		m_tail = m_head;//Set head and tail to accompany nodes 
	
	//Preceding Value 
	else {
		//Point previous node's previous to the new temp 
		(m_head->next)->previous = m_head;
		(m_head->previous)->next = m_head;
	}
	m_size++;//increment size
}
template <class T>
void CircularDoublyLinkedList<T>::move_head(bool direction)
{
	if (direction)
	{//moving to the  right
		m_head = m_head->previous;
		m_tail = m_tail->previous;
	}
	else
	{//moving to the left
		m_head = m_head->next;
		m_tail = m_tail->next;
	}
}
