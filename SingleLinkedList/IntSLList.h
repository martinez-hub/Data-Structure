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

#include "IntSLLNode.h"

template <class T>
class IntSLList{
public:
	//Default constructor: creates an empty list
	IntSLList();

	//Destructor: deallocate memory
	~IntSLList();	

	//addToHead(T val): creates a new node with val as info, 
	//and this new node is the new head 
	void addToHead(T val);

	//addToTail(T val): creates a new node with val as info, 
	//and this new node is the new tail 	
	void addToTail(T val);

	//add after head
	void addAfterHead (T i);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//delete before tail
	void deleteBeforeTail();

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//sortInsert(T val): creates a new node, and it is inserted sortly
	void sortInsert(T val);

	//insert(int pos, T val): creates a new node, and it is inserted in position pos
	void insert(int pos, T val);

	//printList(): prints all nodes in the list
	void printList();
private:
	IntSLLNode<T> *head; //A pointer to the first node
	IntSLLNode<T> *tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntSLList<T>::IntSLList()
{
	tail = head = 0;
}

/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntSLList<T>::~IntSLList()
{
	//Declare a pointer prtNode	
	IntSLLNode<T> *prtNode;
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
	Implement the other methods here	
***********************/  

//adding a new node from head

	/*****
	add un nuevo con head apuntando a el y el tail esta apuntando 
	a ground mueve tail a apuntar a donde apunta head
	*****/
template <class T>
void IntSLList<T>::addToHead(T val){
	head = new IntSLLNode<T>(val,head);
		if (tail==0){
			tail = head;
		}
}
//adding a new node from tail

	/***** 
	si tail no apunta a 0 crea un nodo luego de donde apunta tail
	y mueve a tail a ese nodo. De lo contrario creo un nodo apuntando 
	a 0 y luego tail head apunta a ese nodo
	*****/
template <class T>
void IntSLList<T>::addToTail(T val){
	if(tail != 0){
		tail->setNext(new IntSLLNode<T>(val,0));
		tail = tail->getNext();
	}
	else{
	head = tail = new IntSLLNode<T>(val,0);	
      	}
}

//deleting a node from head
	/****
	Creas un pointer para moverte por nodo, lo asignas a donde apunta head y vas moviendo
	head y eliminando el pointer creado
	****/
template <class T>
void IntSLList<T>::deleteFromHead(){
	if(head !=0){
		IntSLLNode<T> *tmp;
		tmp = head;
		head = head->getNext();
		if(head == 0){tail = 0;}
		delete tmp;
	}
}
//deleting a node from tail
	/***
	creas un pointer para moverte por nodo, lo asignas apuntando a donde apunta head y si 
	head != tail entonces sigues moviendote hasta la posicion antes de tail y mueves tail
	a esa posicion y el pointer creado lo mueves al que apunta a ground y al completar 		eliminas ese pointer.
	***/
template <class T>
void IntSLList<T>::deleteFromTail(){
	if(head !=0){
		IntSLLNode<T> *tmp;
		tmp = head;
		if(head != tail) {
		 while (tmp->getNext() != tail){
					tmp= tmp->getNext();}
			tail=tmp;
			tmp=tmp->getNext();
			tail->setNext(0);
	}else {head = tail = 0;}
	delete tmp;}
}

	/******
	verifica si el head apunta a ground y te devuelve si es cierto o falso
	******/
template <class T>
bool IntSLList<T>::isEmpty(){
	bool res;
	res = false;
	if(head == 0){
		res = true;
	}
	return res;
}

	/******
	si el head = 0 add from head; si el tail = 0 add from tail; de lo contrario se 		se crean 2 pointers donde el principal se utilizara para moverse por nodo
	y el secundario estara posicionandose en el anterior al nodo que se acaba de mover
	el principal para guardar la info y de esa manera los organiza de manera 		descendente	
	******/
template <class T>
void IntSLList<T>::sortInsert(T val){
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

	IntSLLNode<T>* prev = head;
	IntSLLNode<T>* cur = head->getNext();
	while ((cur != 0) && (val < cur->getInfo())) {
		prev = cur;
		cur = cur->getNext();
	}
	prev->setNext(new IntSLLNode<T>(val, cur));
}

//creates a new node and its inserted in pos
template <class T>
void IntSLList<T>::insert(int pos, T val){
	/***************************************************************
		verifica si el head = 0 o si el size de nodos es 1 pues 
		inserta un nuevo nodo from head, de no ser asi se va por el else
	****************************************************************/ 
	if (head == 0 || pos <= 0)
	{
		addToHead(val);	
	} 
	else 
		/* 
		declaramos dos pointers; uno para movernos y el otro 
		para guardar la movida anterior del pointer principal
		*/	 
	{
	IntSLLNode<T> *tmp;
	tmp = head;
	int i = 1;
		/* 
		mientras i < pos mueve tmp al proximo nodo y utiliza tmp2 
		para posicionarlo   en el nodo anterior al que se movio tmp
		*/
	while (i < pos && tmp->getNext() != 0)
	{
		tmp = tmp->getNext();
		i++;
	}

	if (tmp == tail) {
		addToTail(val);
	} else {
		tmp->setNext(new IntSLLNode<T>(val,tmp->getNext()));
	}
	}

}

//printing
	/*
	se crea un pointer y se posiciona donde esta head, 
	el mismo mientras el info no sea 0 se seguira moviendo 
	por nodos e imprimiendo el info de cada nodo
	*/
template <class T>
void IntSLList<T>::printList(){
	IntSLLNode<T> *prtNode;
	prtNode = head;
	while(prtNode != 0) {
		cout<<prtNode->getInfo()<<" ";
		prtNode=prtNode->getNext();
	}
	cout << endl;
}
/*
	Borra el nodo anterior a tail si la lista tiene 3 o mas elementos, si la lista tiene 		solo un elemento hace deleteFromTail(), si la lista tiene 2 elementos hace
	deleteFromHead(). De no tener elementos te informara que esta empty.

Para realizar el deleteBeforeTail():
	Se crean tres pointers;
		tmp3: apuntando a head
		tmp2: apuntando al proximo de head
		tmp: apuntando al proximo de tmp2

	Mientras tmp no sea igual que tail se van a mover y van a ir desalojando memoria 		haciendole delete al que esta antes de tail hasta que solo quede tail y al quedar solo 		tail hara el deleteFromTail().

******************************************************/
template <class T>
void IntSLList<T> :: deleteBeforeTail() {

	if (head == 0)
	{
		cout<< " No existen Nodos " << endl;	
	}

	else if (head == tail)
	{
		deleteFromTail();
	}
	else if (head -> getNext() == tail)
	{
		deleteFromHead();
	}

	else{
		IntSLLNode<T> *tmp, *tmp2, *tmp3;
		tmp3 = head;
		tmp2 = head -> getNext();
		tmp = tmp2 -> getNext();
		
		while (tmp != tail){
			tmp3 = tmp2;
			tmp2 = tmp2 -> getNext();
			tmp = tmp ->getNext();
		}
		tmp3 -> setNext(tmp);
		delete tmp2;		
	}	
}

template <class T>
void IntSLList<T> :: addAfterHead(T i){
	IntSLLNode<T> *tmp;
	tmp = head;

	if (head == 0){
		addToHead(i);
	}
	else{
	tmp = new IntSLLNode<T>(i, head -> getNext());
	head -> setNext(tmp);

	if(head == tail ){
	tail = head-> getNext();
	}
	}	
}
