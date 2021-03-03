#pragma once

#include <vector>
#include "Tree.h"
#include "NodeCartesian.h"

using namespace std;

class CartesianTree : public Tree {
private:
	Node* root;
public:
	CartesianTree(vector<vector<int>>);
	Node* insert_element(Node*, Node*);
	Node* delete_element(Node*, Node*);
	bool search_element(Node*, Node*);
	Node* getRoot();
	void print(Node*);
};
