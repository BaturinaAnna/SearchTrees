#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(set<int> tree) {
	this->tree = tree;
}

RedBlackTree::RedBlackTree(vector<int> tree) {
	this->tree = set<int>(tree.begin(), tree.end());
}

Node* RedBlackTree::insertNode(Node* node, int x) {
	this->tree.insert(x);
	return nullptr;
}

Node* RedBlackTree::deleteNode(Node* node, int x) {
	this->tree.erase(x);
	return nullptr;
}

bool RedBlackTree::searchNode(Node* node, int x) {
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

void RedBlackTree::toSet(Node* root, set<int>& result) {
	result = this->tree;
}