/**********************
COMP 315 - Introduction to data structures
Singly linked node
This class implements the singly linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head and tail point to null in an empty list
2. tail->next=null
******************/

#include "IntDLLNode.h"

template <class T>
class IntDLList{
public:
	//Default constructor: creates an empty list
	IntDLList();

	//Destructor: deallocate memory
	~IntDLList();

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

private:
	IntDLLNode<T> *head; //A pointer to the first node
	IntDLLNode<T> *tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntDLList<T>::IntDLList()
{
	tail = head = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntDLList<T>::~IntDLList()
{
	//Declare a pointer prtNode
	IntDLLNode<T> *prtNode;
	//prtNode points head
	prtNode=head;

	//While there is a node in the list, remove it
	while(prtNode != 0)
	{
		//prtNode points head->next
		prtNode = head->getNext();

		//delete head
		delete head;

		//the new head is prtNode
		head=prtNode;
	}
}

/***********************
	Implement other methods

***********************/

/*if head are not 0 then create a new node pointing previous to 0, set the val and
the next to head then the next of head are going to point the new node. if the list are empty
just create a new node with the same parameters and head pointing to him and tail too.*/
template <class T>
void IntDLList<T>::addToHead(T val)
{
	if(head!=0){
		head->setPrev(new IntDLLNode<T>(0,val,head));
		head = head-> getPrev();
	}else
		{
			tail = head = new IntDLLNode<T>(0,val,head);
		}
}

/*if tail are not 0 then create a new node pointing previous to tail, set the val and
the next to 0 then the next of tail are going to point the new node. if the list are empty
just create a new node with the same parameters and head pointing to him and tail too.*/
template <class T>
void IntDLList<T>::addToTail(T val)
{
	if(tail!=0){
		tail->setNext(new IntDLLNode<T>(tail,val,0));
		tail = tail->getNext();
	}else
		{
			head = tail = new IntDLLNode<T>(tail,val,0);
		}
}

/*if the list are not empty tmp are going to point head and then
are going to move from head to tail deleting nodes*/
template <class T>
void IntDLList<T>::deleteFromHead()
{
	if (head != 0){
		IntDLLNode<T> *tmp;
		tmp = head;
		head = head->getNext();
		if(head==0){ tail = 0;}
		else{
				head->setPrev(0);
				}
				delete tmp;
	}
}

/*if the list are not empty tmp are going to point tail and then
are going to move from tail to head deleting nodes */
template <class T>
void IntDLList<T>::deleteFromTail()
{
	if (head!=0){
						IntDLLNode<T> *tmp;
						tmp = tail;
						if(head != tail){
											tail = tmp->getPrev();
											tail->setNext(0);
						}else{
							head = tail = 0;
						}
						delete tmp;
	}
}
//this method is for verify if the list is empty
template <class T>
bool IntDLList<T>::isEmpty(){
	bool res;
	res = false;
	if(head == 0){
		res = true;
	}
	return res;
}

/*this method are going to insert the new node by ascendent order */
template <class T>
void IntDLList<T>::sortInsert(T val){
	if (head == 0) {
		addToHead(val);
		return;
	}
	if (val > head->getInfo()) {
		addToHead(val);
		return;
	}
	if (val < tail->getInfo()) {
		addToTail(val);
		return;
	}

	IntDLLNode<T>* prev = head;
	IntDLLNode<T>* cur = head->getNext();
	while ((cur != 0) && (val < cur->getInfo())) {
		prev = cur;
		cur = cur->getNext();
	}

	IntDLLNode<T>* node = new IntDLLNode<T>(prev, val, cur);
	prev->setNext(node);
	if (cur != 0) {
		cur->setPrev(node);
	} else {
		tail = node;
	}
}
//creates a new node and its inserted in pos
/***************************************************************
	if head or pos are equal to 0 the method are going to add a new node from addToHead
	else while pos are greater than i then tmp2 are equal to tmp and tmp are going to point to
	the next of head. if tmp are not equal to 0 then the new node are going to have the valor
	for info and tmp2 for previous and tmp the next.
****************************************************************/
 template <class T>
void IntDLList<T>::insert(int pos, T val){

	if (head == 0 || pos <= 0)
	{
		addToHead(val);
	}
	else
	{
		IntDLLNode<T>* prev = head;
		int i = 1;
		while (i < pos && prev->getNext() != 0) {
			prev = prev->getNext();
			i++;
		}

		if (prev == tail) {
			addToTail(val);
		} else {
			IntDLLNode<T>* cur = prev->getNext();
			IntDLLNode<T>* node = new IntDLLNode<T>(prev, val, cur);
			prev->setNext(node);
			cur->setPrev(node);
		}
	}
}
/*while prtNode are not pointing to 0 this method are going
to print everty node in the list from head to tail*/
template <class T>
void IntDLList<T>::printList()
{
	IntDLLNode<T>*prtNode;
	prtNode = head;
	while(prtNode != 0){
		cout<<prtNode->getInfo()<<"";
		prtNode = prtNode->getNext();
	}
}

/** while prtNode are not pointing to 0 this method
are going to print every node in the list from tail to head*/
template <class T>
void IntDLList<T>::printRevList()
{
	IntDLLNode<T> *prtNode;
	prtNode = tail;
	while(prtNode!=0){
		cout<<prtNode->getInfo()<<"";
		prtNode = prtNode->getPrev();
	}
}
