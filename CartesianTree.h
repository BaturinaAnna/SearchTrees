#pragma once

#include <vector>
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "Tree.h"
#include "NodeCartesian.h"

using namespace std;

class CartesianTree : public Tree {
private:
	Node* root;
public:
	Node* merge(Node*, Node*); 
	CartesianTree(set<int>);
	CartesianTree(vector<int>);
	pair<Node*, Node*> split(Node*, int);
	Node* insertNode(Node*, int);
	Node* deleteNode(Node*, int);
	bool searchNode(Node*, int);
	Node* getRoot();
	void toSet(Node*, set<int>&);
	void print(Node*);
};
