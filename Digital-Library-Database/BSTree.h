/**********************
COMP 315 - Introduction to data structures
Binary Search Tree
This class implements the Binary Search Tree using templates
Each list has one attribute:
	-root: first node in tree

Considerations:
1. root points to null in an empty list

******************/

#include "BSTNode.h"
using namespace std;

template <class T>
class BSTree{
public:
	//Default constructor: creates an empty tree
	BSTree();

	//Destructor: deallocate memory
	//~BSTree();

	//insert(T val): creates a new node with val as info,
	void insert(T val);

	//remove(T val): remove the first node with val as info,
	//if the node is removed, returns true, otherwise returns false
	bool remove(T val);

	//search(T val): returns a pointer to node with val as info
	BSTNode<T>* search(T val);


	//If the tree is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//printInOrder(): InOrder Traversal
	void printInOrder();

	//printPreOrder(): PreOrder Traversal
	void printPreOrder();

	//printPostOrder(): PostOrder Traversal
	void printPostOrder();

	void visitInOrder2(BSTNode<T>* node);
	void printInOrder2();

private:
	BSTNode<T> *root; //A pointer to the first node

	void visitInOrder(BSTNode<T> *node);//Recursive support method for printInOrder
	void visitPreOrder(BSTNode<T> *node);//Recursive support method for printPreOrder
	void visitPostOrder(BSTNode<T> *node);//Recursive support method for printPostOrder
	void removePostOrder(BSTNode<T>* node);//Recursive support method for the destructor
	BSTNode<T>* recursiveSearch(BSTNode<T> *node, T val);//Recursive support method for search
	bool recursiveSearchForRemove(BSTNode<T> *node, T val);//Recursive support method for remove
	BSTNode<T>* findLowest(BSTNode<T> *node);//Extract the lowest node in a subtree rooted on node
};

/****************
	Default constructor: creates an empty Binary Search tree
*****************/
template <class T>
BSTree<T>::BSTree()
{
	root = 0;
}

/*template <class T>
BSTree<T>::~BSTree()
{
	removePostOrder(root);
}*/

/*
	This method insert a new node in the binary search tree. The greatest vals to
	the right and the lowers to the left.
*/
template <class T>
void BSTree<T>::insert(T val)
{
	if (root == 0)
	 {
	root = new BSTNode<T>(0, val, 0);
	}
else {
	BSTNode<T>* tmp, * sRoot = NULL;
	tmp = root;

	while (tmp != 0){
		sRoot = tmp;
		if (val.getName() < sRoot->getInfo().getName())
			tmp = tmp->getLeft();
		else
			tmp = tmp->getRight();
		}
		if (val.getName() < sRoot->getInfo().getName())
			sRoot->setLeft(new BSTNode<T>(0, val, 0));
		else
			sRoot->setRight(new BSTNode<T>(0, val, 0));
	}
}

/*
	This method round around the binary search tree looking for a val that the user enters 
	for delete it. 
*/

template <class T>
bool BSTree<T>::remove(T val)
{
	bool res = false;
if (root != 0)

{
if (root->getInfo() == val) {
	if ((root->getLeft() == 0) &&
		(root->getRight() == 0)) {
		delete root;
		root = 0;
	}
	else {
		BSTNode<T>* tmp;
		tmp = root;
		if (root->getLeft() == 0)
			root = root->getRight();
		else if (root->getRight() == 0)
			root = root->getLeft();

		else {
			BSTNode<T>* lowest;
			lowest = findLowest(root->getRight());
			if (root->getRight() == lowest) {
					lowest->setLeft(root->getLeft());
				root = lowest;
			}
			else {
				root = lowest;
				root->setLeft(tmp->getLeft());
				root->setRight(tmp->getRight());
			}
		} delete tmp;
	}  res = true;
}
else
	res = recursiveSearchForRemove(root, val);
} return res;
}

/*
	This method is for search a valor using the function recursiveSearch and returns a pointer
	to the node.
*/
template <class T>
 BSTNode<T>*BSTree<T>::search(T val) {
	{
		return recursiveSearch(root, val);
	}
}

 /*
	This is a boolean method for verify if the tree is empty.
 */
template <class T>
bool BSTree<T>::isEmpty()
{

	bool res;
	res = false;
	if (root == 0)
	{
		res = true;
	}
	return res;
}

/*
	Method who calls the support method visitInOrder for print the tree in ascendant order.
*/
template <class T>
void BSTree<T>::printInOrder()
{
		visitInOrder(root);
}
/*
	Method who calls the support method visitPreOrder for print the tree in traversal order
*/
template <class T>
void BSTree<T>::printPreOrder()
{
		visitPreOrder(root);
}

/*
	Method who calls the support method visitPostOrder for print the tree in traversal order
*/
template <class T>
void BSTree<T>::printPostOrder()
{
		visitPostOrder(root);
}

/*
	Recursive support method for print visiting the binary tree in ascendant order.
*/
template <class T>
void BSTree<T>::visitInOrder(BSTNode<T>* node)
	{
		if (node == 0)
		return;
			visitInOrder(node->getLeft());
			cout << "-" << node->getInfo().getName()<< "\n";
			visitInOrder(node->getRight());

	}

		/*
			Recursive support method for print visiting the tree in preOrder that get the root first
			 then the left node and for final the right node.
		*/
template <class T>
void BSTree<T>::visitPreOrder (BSTNode<T>* node)
{
	if (node == 0)
		return;

		cout << "-" <<node->getInfo() << "-";
		visitPreOrder(node->getLeft());
		visitPreOrder(node->getRight());

}

	/*
		Recursive support method for printPreOrder that get the left side first, then the right side 
		and for final the root.
	*/
template <class T>
void BSTree<T>::visitPostOrder(BSTNode<T>* node)//Recursive support method for printPostOrder
{
	if (node == 0)
	return;

		visitPostOrder(node->getLeft());
		visitPostOrder(node->getRight());
		cout << "-" << node->getInfo() << "-";

}

/*
	Recursive method for delete all the binary tree nodes in postorder that eliminate all the left side
	first, then the right side and for final the root.
*/
template <class T>
void BSTree<T>:: removePostOrder(BSTNode<T>* node)//Recursive support method for the destructor
{

	if (node == 0) return;
	if (node->getLeft() != 0)
	removePostOrder(node->getLeft());
	if (node->getRight() != 0)
	removePostOrder(node->getRight());

	cout << "\n Deleting node: " << node->getInfo().getName() << "\n\n";
	delete node;


	return ;
}

/*
	Method for search a node in the tree with some val and then return a pointer to that node.
*/
template <class T>
BSTNode<T> *BSTree<T>:: recursiveSearch(BSTNode<T> *node, T val)//Recursive support method for search
{
	BSTNode<T>* res;
	res = 0;
	if (node != 0) {
		if (val.getName() == node->getInfo().getName())
			res = node;
		else if (val.getName() < node->getInfo().getName())
			res = recursiveSearch(node->getLeft(), val);
		else
			res = recursiveSearch(node->getRight(), val);
	}
	return res;
}

/*
	Method that runs the tree looking for a node for delete it. When the node its founded and delete it then
	the left node are going to be the root of the subtree.
*/
template <class T>
bool BSTree<T>::recursiveSearchForRemove(BSTNode<T>* node, T val)//Recursive support method for remove
{
	if (node == 0) {
		return false;
	}

	if (val.getName() < node->getInfo().getName()) {
		BSTNode<T>* found = node->getLeft();
		if (found == 0) {
			return false;
		}
		if (found->getInfo().getName() != val.getName()) {
			return recursiveSearchForRemove(found, val);
		}

		if (found->getRight() == 0) {
			node->setLeft(found->getLeft());
		} else {
			BSTNode<T>* tmp = findLowest(found->getRight());
			node->setLeft(tmp);
			tmp->setLeft(found->getLeft());
			if (tmp != found->getRight()) {
				tmp->setRight(found->getRight());
			}
		}
		delete found;
		return true;
	}

	if (val.getName() > node->getInfo().getName()) {
		BSTNode<T>* found = node->getRight();
		if (found == 0) {
			return false;
		}
		if (found->getInfo().getName() != val.getName()) {
			return recursiveSearchForRemove(found, val);
		}

		if (found->getRight() == 0) {
			node->setRight(found->getLeft());
		} else {
			BSTNode<T>* tmp = findLowest(found->getRight());
			node->setRight(tmp);
			tmp->setLeft(found->getLeft());
			if (tmp != found->getRight()) {
				tmp->setRight(found->getRight());
			}
		}
		delete found;
		return true;
	}

	return false;
}
/*
	Method for find the lowest node in the tree visiting all the tree but going all the time
	to the left because the lowest node usually are in the left if not its the root.
*/
template <class T>
BSTNode<T>* BSTree<T>::findLowest(BSTNode<T>* node)//Extract the lowest node in a subtree rooted on node
{
	BSTNode<T> *tmp;
	if (node->getLeft() == 0) {
		tmp = node;
	}
	else {
		while (node->getLeft()->getLeft() != 0)
			node = node->getLeft();
		tmp = node->getLeft();
		node->setLeft(tmp->getRight());
	}
	return tmp;
}

/*
	Method for print the book info
*/
template<class T>
void BSTree<T>::visitInOrder2(BSTNode<T>* node)
{
	if (node == 0)
		return;
	visitInOrder2(node->getLeft());
	cout << "-" << node->getInfo().getName() << "\n";
	cout << "-" << node->getInfo().getBooks() << "\n";
	//cout << "-" << node->getInfo().getBooks()->getInfo().getPlot() << "\n";
	//cout << "-" << node->getInfo().getBooks()->getInfo().getLast().getFirst() << "\n";
	//cout << "-" << node->getInfo().getBooks()->getInfo().getEditor() << "\n";
	//cout << "-" << node->getInfo().getBooks()->getInfo().getRyear() << "\n";
	visitInOrder2(node->getRight());
	//list.search(*gen)->getInfo().getBooks()->searchNode(btmp)->getInfo().getTitle()*/
}
template<class T>
void BSTree<T>::printInOrder2()
{
	visitInOrder2(root);
}
