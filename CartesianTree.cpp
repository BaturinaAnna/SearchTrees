#include "CartesianTree.h"


/*
CartesianTree::CartesianTree(vector<vector<int>> tree) {
	for (auto node: tree) {
		Node* ins_node = new NodeCartesian(node[0], node[1]);
		root = insert_element(root, ins_node);
	}
	this->root = root;
}

void split(Node* node, int key, Node* left, Node* right) {
	if (node == nullptr) {
		node->setRight(nullptr);
		node->setLeft(nullptr);
	}
	else if (key < node->getKey()) {
		split(dynamic_cast<NodeCartesian*>(node->getLeft()), key, left, dynamic_cast<NodeCartesian*>(node->getLeft()));
		node->setRight(node);
	}
	else {
		split(dynamic_cast<NodeCartesian*>(node->getRight()), key, dynamic_cast<NodeCartesian*>(node->getRight()), right);
		left = node;
	}
}

Node* CartesianTree::insert_element(Node* root, Node* ins_node) {
	if (root == nullptr) {
		root = ins_node;
		return root;
	}
	else if (dynamic_cast<NodeCartesian*>(ins_node)->getPrior() > dynamic_cast<NodeCartesian*>(root)->getPrior()) {
		split(root, ins_node->getKey(), ins_node->getLeft(), ins_node->getRight());
		root = ins_node;
		return root;
	}
	else {
		insert_element(ins_node->getKey() < root->getKey() ? root->getLeft() : root->getRight(), ins_node);
		return root;
	}
}


void merge(Node* root, Node* left, Node* right) {
	if (!left || !right)
		root = left ? left : right;
	else if (dynamic_cast<NodeCartesian*>(left)->getPrior() > dynamic_cast<NodeCartesian*>(right)->getPrior()) {
		merge(dynamic_cast<NodeCartesian*>(left)->getRight(), dynamic_cast<NodeCartesian*>(left)->getRight(), right);
		root = left;
	}
	else {
		merge(dynamic_cast<NodeCartesian*>(right)->getLeft(), left, dynamic_cast<NodeCartesian*>(right)->getLeft());
		root = right;
	}
}


Node* CartesianTree::delete_element(Node* root, Node* ins_node) {
	int key = ins_node->getKey();
	if (root->getKey() == key) {
		merge(root, root->getLeft(), root->getRight());
		return root;
	}
	else
		delete_element(key < root->getKey() ? root->getLeft() : root->getRight(), ins_node);
}

bool CartesianTree::search_element(Node*, Node*) {
	return 0;
}

Node* CartesianTree::getRoot() {
	return this->root;
}

void CartesianTree::print(Node* root) {
	if (root != nullptr) {
		cout << root->getKey() << " " << dynamic_cast<NodeCartesian*>(root)->getPrior() << "\t";
		print(root->getLeft());
		print(root->getRight());
	}
}
*/