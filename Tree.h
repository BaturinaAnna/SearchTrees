#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Node.h"

using namespace std;


class Tree {
public:
	virtual Node* insert_element(Node*, int) = 0;
	virtual Node* delete_element(Node*, int) = 0;
	virtual bool search_element(Node*, int) = 0;
	virtual void print(Node*) = 0;
};
