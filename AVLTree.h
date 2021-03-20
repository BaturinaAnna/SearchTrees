#pragma once


#include "Tree.h"
#include "NodeAVL.h"

using namespace std;

class AVLTree : public Tree {
private:
	Node* root;
public:
	AVLTree(set<int>);
	AVLTree(vector<int>);
	Node* insertNode(Node*, int);
	Node* deleteNode(Node*, int);
	bool searchNode(Node*, int);

	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
	int getBalance(Node*);
	Node* minValueNode(Node*);

	void print(Node*);
	void toSet(Node*, set<int>&);
	Node* getRoot();
};