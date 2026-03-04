/**********************
COMP 315 - Introduction to data structures
Binary Search Tree node
This class implements the binary search tree node using templates
Each nodes two attributes:
	-info: stores the actual value
	-right: a pointer to the right node in the list
******************/


#include <iostream>
//#include "circDLList.h"
//#include "Book.h"
//using namespace std;
/**********************************
Class Declaration

***********************/
template <class T>
class BSTNode{
public:
	BSTNode(); //Default constructor
	BSTNode( BSTNode<T>*, T , BSTNode<T>*); //Special constructor
	T& getInfo(); //getInfo
	const T& getInfo() const; //getInfo const
	BSTNode<T>* getLeft(); // getLeft
	BSTNode<T>* getRight(); // getRight
	//circDLList<Book>* getCirc(); 
	void setInfo(T); //setInfo 
	void setLeft(BSTNode<T> *); //Set left
	void setRight(BSTNode<T> *); //Set right
	//void setCirc(circDLList<Book> *);
private:
	
	BSTNode<T> *left;//Points to the left child
	T info; //Actual data	
	BSTNode<T> *right; //Points to the right child
	//circDLList<Book> *circ;

};


/*****
	Default constructor
	Creates a empty node
*****/
template <class T>
BSTNode<T>::BSTNode()
	{	right=left=0; }

/******
	Special constructor:
	Creates a node with value i in the info attribute and right pointing to null
	@params:
		*l: pointer to the left node		
		i: actual value to be stored
		*r: pointer to the right node
*******/
template <class T>
BSTNode<T>::BSTNode(BSTNode<T> *l, T i, BSTNode<T> *r)
 {	info=i; 
	left=l;
	right=r; }

/********
	getInfo
	returns the info value
*********/
template <class T>
T& BSTNode<T>::getInfo()
		{return info;}

template <class T>
const T& BSTNode<T>::getInfo() const
		{return info;}

/********
	getright
	returns a point to right child
**********/
template <class T>
BSTNode<T> *BSTNode<T>::getRight()
	{return right;}

/********
	getleft
	returns a point to left child
**********/
template <class T>
BSTNode<T> *BSTNode<T>::getLeft()
	{return left;}
/*
template <class T>
circDLList<Book> *BSTNode<T>::getCirc()
{return circ; }
*/
/********
	setInfo
	Set i as the node info
*******/
template <class T>
void BSTNode<T>::setInfo(T i)
	{ info = i;}

/********
	setright
	Points right attribute to the right child	
********/
template <class T>
void BSTNode<T>::setRight(BSTNode<T> *r)
	{ right = r;}

/********
	setleft
	Points right attribute to the left child	
********/
template <class T>
void BSTNode<T>::setLeft(BSTNode<T> *l)
	{ left = l;}

/*
template <class T>
void BSTNode<T>::setCirc(circDLList<Book> *c)
{
	circ = c;
}*/
