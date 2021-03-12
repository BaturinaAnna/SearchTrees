#pragma once

#include "Tree.h"
#include "Node.h"

class SplayTree : public Tree {
private:
	Node* root;
public:
	SplayTree(set<int>);
	Node* insertNode(Node*, int);
	Node* deleteNode(Node*, int);
	bool searchNode(Node*, int);

	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
	Node* splay(Node* root, int key);

	void print(Node*);
	void toSet(Node*, set<int>&);
	Node* getRoot();
};
