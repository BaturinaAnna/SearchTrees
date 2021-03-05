//#include <iostream>
//#include <set>

#include "RedBlackTree.h"
#include "AVLTree.h"
#include "CartesianTree.h"
#include "SplayTree.h"



int main() {
	// SPLAY TREES
	/*
	vector<int> s = { 10, 11, 12, 7, 2, 1, 22, 1, 13, 13, 14 };
	SplayTree* st = new SplayTree(s);
	st->print(st->getRoot());
	st->delete_element(st->getRoot(), 0);
	cout << endl;
	st->print(st->getRoot());
	cout << endl;
	cout << st->search_element(st->getRoot(), 0) << endl;
	cout << st->search_element(st->getRoot(), 22) << endl;
	*/


	// CARTESIAN TREES
	/*
	srand(time(NULL));
	vector<int> s = {10, 11, 12, 7, 2, 1};
	CartesianTree* t = new CartesianTree(s);
	t->print(t->getRoot());

	t->delete_element(t->getRoot(), 0);
	cout << endl;
	t->print(t->getRoot());

	cout << t->search_element(t->getRoot(), 1) << endl;
	cout << t->search_element(t->getRoot(), 0) << endl;
	*/


	// AVL
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
	*/


	// RED BLACK TREES
	/*
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