#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(std::set<int> tree) {
	this->tree = tree;
}

Node* RedBlackTree::insert_element(Node* node, int x) {
	this->tree.insert(x);
	return nullptr;
}

Node* RedBlackTree::delete_element(Node* node, int x) {
	this->tree.erase(x);
	return nullptr;
}

bool RedBlackTree::search_element(Node* node, int x) {
	auto finded = this->tree.find(x);
	if (finded != this->tree.end()) {
		return true;
	}
	else {
		return false;
	}
}

void RedBlackTree::print(Node* root) {
	for (int i : this->tree) {
		std::cout << i << ' ';
	}
}