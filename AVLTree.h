#pragma once


#include "Tree.h"

using namespace std;

class AVLTree : public Tree {
private:
	Node* root;
public:
	AVLTree(std::set<int>);
	Node* insert_element(Node*, int);
	Node* delete_element(Node*, int);
	bool search_element(Node*, int);

	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
	int getBalance(Node*);
	Node* minValueNode(Node*);

	void print(Node* root);
	Node* getRoot();
};