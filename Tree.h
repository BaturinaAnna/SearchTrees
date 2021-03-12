#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Node.h"

using namespace std;


class Tree {
public:
	virtual Node* insertNode(Node*, int) = 0;
	virtual Node* deleteNode(Node*, int) = 0;
	virtual bool searchNode(Node*, int) = 0;
	virtual void print(Node*) = 0;	
	virtual void toSet(Node*, set<int>&) = 0;
};
