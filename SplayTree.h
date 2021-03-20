#pragma once

#include "Tree.h"
#include "NodeSplay.h"

class SplayTree : public Tree {
private:
	Node* root;
public:
	SplayTree(set<int>);
	SplayTree(vector<int>);
	Node* insertNode(Node*, int);
	Node* deleteNode(Node*, int);
	bool searchNode(Node*, int);
	Node* splay(Node*);

	void zig(Node*);
	void zig_zig(Node*);
	void zig_zag(Node*);

	void print(Node*);
	void toSet(Node*, set<int>&);
	Node* getRoot();
};
