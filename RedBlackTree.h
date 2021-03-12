#pragma once

#include "Tree.h"


class RedBlackTree : public Tree {
private:
	std::set<int> tree;
public:
	RedBlackTree(std::set<int> tree);
	Node* insertNode(Node*, int x);
	Node* deleteNode(Node*, int x);
	bool searchNode(Node*, int x);
	void print(Node* root);
	void toSet(Node*, set<int>&);
};