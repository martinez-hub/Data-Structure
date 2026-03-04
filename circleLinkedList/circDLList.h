/**********************
COMP 315 - Introduction to data structures
Singly linked node
This class implements the singly linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head point to null in an empty list
2. There is not need of a tail pointer
******************/

#include "intDLLNode.h"
//#include "IntSLList.h"
template <class T>
class circDLList{
public:
	//Default constructor: creates an empty list
	circDLList();

	//Destructor: deallocate memory
	~circDLList();

	//addToHead(T val): creates a new node with val as info,
	//and this new node is the new head
	void addToHead(T val);

	//addToTail(T val): creates a new node with val as info,
	//and this new node is the new tail
	void addToTail(T val);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//sortInsert(T val): creates a new node, and it is inserted sortly
	void sortInsert(T val);

	//insert(int pos, T val): creates a new node, and it is inserted in position pos
	void insert(int pos, T val);

	//printList(): prints all nodes in the list from head to tail
	void printList();

	//printList(): prints all nodes in the list from tail to head
	void printRevList();

	IntDLLNode<T>* searchNode(T i);

private:
	IntDLLNode<T> *head; //A pointer to the first node

};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
circDLList<T>::circDLList()
{
	head = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
circDLList<T>::~circDLList()
{
	while(!isEmpty())
		this->deleteFromHead();
}

/***********************
	Implement other methods

***********************/
/*
if head is not equal to 0, we create a new node were the previous
of head is the previous of him and the next of head is the next
of him and head are going to point to him. Else create a node were
next and previous is him
*/
template <class T>
void circDLList<T>::addToHead(T val)
{
	if(head!=0)
	{
		//not an empty list
		IntDLLNode<T>*tmp;
		tmp=new IntDLLNode<T>(head->getPrev(),val,head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);
		head=tmp;
	}
	else
	{
		//an empty list
		cout<<"Empty list"<<endl;
		head = new IntDLLNode<T>(0,val,0);
		head->setPrev(head);
		head->setNext(head);
	}
}
/*
If head is not equal to 0, we create a new node were the previous
of head is the previous of him and the next of head is the next
of him and head are going to point to him. Else create a node were
next and previous is him.
*/
template <class T>
void circDLList<T>::addToTail(T val)
{
	if(head!=0)
	{
		//not an empty list
		IntDLLNode<T>*tmp;
		tmp=new IntDLLNode<T>(head->getPrev(),val,head);
		head->getPrev()->setNext(tmp);
		head->setPrev(tmp);

	}
	else
	{
		//an empty list
		cout<<"Empty list"<<endl;
		head = new IntDLLNode<T>(0,val,0);
		head->setPrev(head);
		head->setNext(head);
	}
}

/*
If head are not equal to 0 a temporary pointer is created pointing to head.
If head is equal to the next of him then head is equal to 0. Else tmp are going
to point to the head and head are going to be moved to the next node of him
then delete that previous node.
*/
template <class T>
void circDLList<T>::deleteFromHead()
{
	if(head!=0)
	{
		IntDLLNode<T> *tmp;
		tmp = head;
		if (head == head->getNext())
			{
				//one node list
				head = 0;
			}
			else
		{
			//list with more than one node
				head->getNext()->setPrev(head->getPrev());
				head->getPrev()->setNext(head->getNext());

					head = head->getNext();
			}
			delete tmp;
	}
}
/*
	If head are not equal to 0 a temporary pointer is created pointing to the last
	node. If head is equal to the next of him then head is equal to 0. Else the previous of tmp
	are going to be the previous of head then delete the last node.
*/
template <class T>
void circDLList<T>::deleteFromTail()
{
	if(head!=0)
	{
		IntDLLNode<T> *tmp;
		tmp= head->getPrev();
		if(head == head->getNext())
		{
			//one node list
			head = 0;
		}
		else
		{
			//a list with more than one node
			tmp->getPrev()->setNext(head);
			head->setPrev(tmp->getPrev());
		}
		delete tmp;
	}
}

/*
this method is for verify if the list is empty
*/
template <class T>
bool circDLList<T>::isEmpty()
{
	bool res;
	res = false;
	if(head == 0)
	{
		res = true;
	}
	return res;
}

/*
If the list is empty addTohead. Else for insert a new node sortly two pointers
are created with one pointing to head. Then while the val are less then the info
of tmp and the next of tmp are not equal to the head then tmp2 are pointing
to tmp and tmp is moved to the next of him. If the next of tmp are equal to the head and
val is less then the info of tmp then addToTail. else if tmp are equal to head and val is
greater then tmp info then addToHead. else create a new node with (tmp2,val,tmp) and the next
of tmp2 are going to point that node and the previous of tmp too.
*/
template <class T>
void circDLList<T>::sortInsert(T val)
{
	if (head == 0) {
		addToHead(val);
		return;
	}
	if (val > head->getInfo()) {
		addToHead(val);
		return;
	}

	IntDLLNode<T>* prev = head;
	IntDLLNode<T>* cur = head->getNext();
	while (cur != head && val < cur->getInfo()) {
		prev = cur;
		cur = cur->getNext();
	}
	if (cur == head && val < prev->getInfo()) {
		addToTail(val);
		return;
	}

	IntDLLNode<T>* newNode = new IntDLLNode<T>(prev, val, cur);
	prev->setNext(newNode);
	cur->setPrev(newNode);
}

/*
Two temporary pointers are created for move inside the list.
if head are equal to 0 or the position inserted by the user is 1 then addToHead.
Else the two pointers are going to be moved in the list until tmp find the position.
Then a new node are created with (previos tmp2, val info, next tmp). then the next of tmp2
is this node and the prev of tmp too.
*/
template <class T>
void circDLList<T>::insert(int pos, T val)
{
	if (head == 0 || pos <= 1)
	{
		addToHead(val);
	}
	else
	{
		IntDLLNode<T>* prev = head;
		IntDLLNode<T>* cur = head->getNext();
		int i = 2;
		while (i < pos && cur != head) {
			prev = cur;
			cur = cur->getNext();
			i++;
		}
		if (cur == head) {
			addToTail(val);
		} else {
			IntDLLNode<T> *newNode = new IntDLLNode<T>(prev, val, cur);
			prev->setNext(newNode);
			cur->setPrev(newNode);
		}
	}
}

/*
for print the list, a temporary pointer are created pointing to the head
then if the pointer are not equal to 0, while the next of prtnode are not
equal to the head are going to print the info of every node. Then print the last node.
*/
template <class T>
void circDLList<T>::printList()
{
	IntDLLNode<T> *prtNode;
	prtNode = head;
	if(prtNode != 0)
	{
		while (prtNode->getNext() != head)
		{
			cout<<prtNode->getInfo()<<" ";
			prtNode = prtNode->getNext();
		}
		cout << prtNode->getInfo()<< " ";
	}
}

/*
for print rev list, a temporary pointer are created pointing to the head
then if the pointer are not equal to 0, while the previous of prtnode are not
equal to the head are going to print the info of every node. Then print the last node.
*/
template <class T>
void circDLList<T>::printRevList()
{
	IntDLLNode<T> *prtNode;
	prtNode = head;
	if(prtNode != 0)
	{
		while(prtNode->getPrev()!=head)
		{
			prtNode = prtNode->getPrev();
			cout<<prtNode->getInfo()<<" ";
		}
		cout<<head->getInfo()<< " ";
	}
}

template <class T>
IntDLLNode<T>* circDLList<T>::searchNode(T i)
{
	if (head == 0) {
		return 0;
	}

	IntDLLNode<T> *tmp = head;
	do {
		if (tmp->getInfo() == i) {
			return tmp;
		}
		tmp = tmp->getNext();
	} while (tmp != head);

	return 0;
}
