#pragma once

#include "Tree.h"


class RedBlackTree : public Tree {
private:
	set<int> tree;
public:
	RedBlackTree(std::set<int>);
	RedBlackTree(vector<int>);
	Node* insertNode(Node*, int);
	Node* deleteNode(Node*, int);
	bool searchNode(Node*, int);
	void print(Node*);
	void toSet(Node*, set<int>&);
};