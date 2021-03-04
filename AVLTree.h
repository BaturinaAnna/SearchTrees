#pragma once


#include "Tree.h"
#include "NodeAVL.h"

using namespace std;

class AVLTree : public Tree {
private:
	Node* root;
public:
	AVLTree(std::vector<int>);
	Node* insert_element(Node*, int);
	Node* delete_element(Node*, int);
	bool search_element(Node*, int);

	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
	int getBalance(Node*);
	Node* minValueNode(Node*);

	void print(Node*);
	Node* getRoot();
};