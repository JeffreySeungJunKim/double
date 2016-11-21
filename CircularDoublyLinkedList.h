#pragma once
template <class T>
class CircularDoublyLinkedList 
{
//Allowing for nodes for head and tail 
private:
	class Node {
	public:
		//Node Constructor 
		Node(T val, Node* nx = nullptr, Node* prv = nullptr) :Value(val), next(nx), previous(prv)
		{		}
		T Value;
		Node*next;
		Node*previous;
	};
	//doubly linked list declaration
	Node* m_head;
	Node* m_tail;
	unsigned int m_size;

public:
	//Create the CircularDoublyLinkedList
	CircularDoublyLinkedList();
	//destrcutor
	~CircularDoublyLinkedList();
	//Add Item to end of the list 
	void addItem(T val);
	//get head
	inline Node*getHead()const { return m_head; }
	//move head and get direction as parameter
	void move_head(bool direction);
	
	class Iterator {// iterators are used for efficient traversal of linked lists
	private:
		Node* m_ptr;    // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator++ () { m_ptr = m_ptr->next; } // for forward traversing, e,g, Iterator i=begin(); ... ++i;
		void operator--() { m_ptr = m_ptr->previous; }
		bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
		int operator *() { return m_ptr->Value; }
		T getValue() { return m_ptr->Value; }
		void setValue(int val) { m_ptr->Value = val; }
	};
	Iterator begin() const{ return Iterator(m_head); }
	Iterator end() const{ return Iterator(m_tail); }
	
};

//Template creation of CircularDoublyLinkedList

//Creation of DoublyLinkedList
//Head and tail point to nothing 
template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() :
m_head(nullptr), m_tail(nullptr), m_size(0)
{}
template <class T>
CircularDoublyLinkedList<T>:: ~CircularDoublyLinkedList()
{
	Node * here = m_head, *nextNode;
	//delete until all the node is freed
	while (this->m_size>0)
	{
		nextNode = here->next;
		delete here;
		here = nextNode;
		m_size--;
	}
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
	m_size++;
}
template <class T>
void CircularDoublyLinkedList<T>::move_head(bool direction)
{
	if (direction)
	{//moving to the  right
		m_head = m_head->next;
		m_tail = m_tail->next;
	}
	else
	{//moving to the left
		m_head = m_head->previous;
		m_tail = m_tail->previous;
	}
}






