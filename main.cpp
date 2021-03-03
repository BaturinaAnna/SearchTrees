//#include <iostream>
//#include <set>

#include "RedBlackTree.h"
#include "AVLTree.h"
#include "CartesianTree.h"



int main() {
	vector<vector<int>> s = {{10, 13}, {7, 12}, {5, 7}, {4, 3}, {6, 1}, {15, 10}, {14, 9}, {20, 9}, {18, 7}};
	CartesianTree* t = new CartesianTree(s);
	cout << t -> getRoot()->getRight();
	//t->print(t->getRoot());


	/*
	std::set<int> my_little_set = {1, 3, 10, 5, 11, 13, 4, 2};
	
	AVLTree* my_little_tree = new AVLTree(my_little_set);

	my_little_tree->print(my_little_tree->getRoot());
	cout << endl;
	
	Node* n10 = new NodeAVL(10);
	Node* n30 = new NodeAVL(30);
	Node* n2 = new NodeAVL(2);
	Node* n3 = new NodeAVL(3);
	Node* n6 = new NodeAVL(10);
	
	my_little_tree->delete_element(my_little_tree->getRoot(), n10);
	my_little_tree->print(my_little_tree->getRoot());
	cout << my_little_tree->search_element(my_little_tree->getRoot(), n10) << endl;
	cout << my_little_tree->search_element(my_little_tree->getRoot(), n30) << endl;
	my_little_tree->delete_element(my_little_tree->getRoot(), n2);
	my_little_tree->print(my_little_tree->getRoot());
	cout << endl;
	my_little_tree->delete_element(my_little_tree->getRoot(), n3);
	my_little_tree->print(my_little_tree->getRoot());
	cout << endl;
	my_little_tree->delete_element(my_little_tree->getRoot(), n6);
	my_little_tree->print(my_little_tree->getRoot());
	*/
	
	return 0;
}