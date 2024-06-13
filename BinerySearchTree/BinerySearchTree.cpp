#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = nullptr; //Initializing ROOT to null
	}

	void insert(string element) //insert a node the binary search tree
	{
		Node* newNode = new Node(element, nullptr, nullptr); //Allocation memory for new node
		newNode->info = element; //Assign value to the data field for ner node
		newNode->leftchild = nullptr; //Make the left child of the new node point to NULL
		newNode->rightchild = nullptr; //Make the right child of the new node point to NULL

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode);// Locate the node which will br thr parent of the node to be 

		if (parent == nullptr) //if the parent is NULL (Tree is empty)
		{
			ROOT = newNode; // mark the new node as ROOT
			return; // exit
		}

		if (element < parent->info) // if the value in the data field of the new Node is the less than that of
		{
			parent->leftchild = newNode; // make the left child of the parent point to the new node 
		}
		else if (element > parent->info) // if the value in the data field of the new node is greater than that parent
		{
			parent->rightchild = newNode; // make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		//this function searches the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder( ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}
	void postorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

