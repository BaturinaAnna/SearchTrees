#include <iostream>
#include <set>

#include "RedBlackTree.h"
#include "AVLTree.h"



int main() {
	std::set<int> my_little_set = {1, 3, 10, 5, 11, 13, 4, 2};

	AVLTree* my_little_tree = new AVLTree(my_little_set);
	
	my_little_tree->print(my_little_tree->getRoot());
	cout << endl;
	//my_little_tree->delete_element(my_little_tree->getRoot(), 10);
	//my_little_tree->print(my_little_tree->getRoot());
	//cout << my_little_tree->search_element(my_little_tree->getRoot(), 10) << endl;
	//cout << my_little_tree->search_element(my_little_tree->getRoot(), 30) << endl;
	/*
	my_little_tree->delete_element(my_little_tree->getRoot(), 2);
	my_little_tree->print(my_little_tree->getRoot());
	cout << endl;
	my_little_tree->delete_element(my_little_tree->getRoot(), 3);
	my_little_tree->print(my_little_tree->getRoot());
	cout << endl;
	*/
	my_little_tree->delete_element(my_little_tree->getRoot(), 6);
	my_little_tree->print(my_little_tree->getRoot());
	
	return 0;
}