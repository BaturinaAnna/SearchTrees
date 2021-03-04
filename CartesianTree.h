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
	void merge(Node*&, Node*, Node*); 
	CartesianTree(vector<int>);
	void split(Node*, int, Node*&, Node*&);
	Node* insert_element(Node*, int);
	Node* delete_element(Node*, int);
	bool search_element(Node*, int);
	Node* getRoot();
	void print(Node*);
};
