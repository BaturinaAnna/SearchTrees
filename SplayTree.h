#pragma once

#include "Tree.h"
#include "Node.h"

class SplayTree : public Tree {
private:
	Node* root;
public:
	SplayTree(vector<int>);
	Node* insert_element(Node*, int);
	Node* delete_element(Node*, int);
	bool search_element(Node*, int);

	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
	Node* splay(Node* root, int key);

	void print(Node*);
	Node* getRoot();
};
