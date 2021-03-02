#pragma once

#include "Tree.h"


class RedBlackTree : public Tree {
private:
	std::set<int> tree;
public:
	RedBlackTree(std::set<int> tree);
	Node* insert_element(Node*, int x);
	Node* delete_element(Node*, int x);
	bool search_element(Node*, int x);
	void print(Node* root);
};