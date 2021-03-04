#include "CartesianTree.h"

CartesianTree::CartesianTree(vector<int> tree) {
	int prior = rand() % 1000000;
	Node* root = new NodeCartesian(tree[0], prior);
	for (int i = 1; i < tree.size(); i++) {
		root = insert_element(root, tree[i]);
	}
	this->root = root;
}

void CartesianTree::merge(Node*& T, Node* T1, Node* T2) {
	if (T1 == nullptr || T2 == nullptr)
		T = T1 ? T1 : T2;
	else if (dynamic_cast<NodeCartesian*>(T1)->getPrior() >= dynamic_cast<NodeCartesian*>(T2)->getPrior()) {
		if (T1->getRight() == nullptr)
			T1->setRight(T2);			
		else {
			Node* right = T1->getRight();
			merge(right, (T1)->getRight(), T2);
			T1->setRight(right);
		}
		T = T1;		
	}
	else {
		if (T2->getLeft() == nullptr)
			T2->setLeft(T1);
		else {
			Node* left = T2->getLeft();
			merge(left, T1, (T2)->getLeft());
			T2->setLeft(left);
		}
		T = T2;	
	}
}

void CartesianTree::split(Node* T, int x, Node*& T1, Node*& T2) {
	if (T == nullptr) {
		T1 = NULL;
		T2 = NULL;
	}
	else if (x < T->getKey()) {
		Node* left = T->getLeft();
		split(T->getLeft(), x, T1, left);
		T2 = T;
	}
	else {
		Node* right = T->getRight();
		split(T->getRight(), x, right, T2);
		T1 = T;
	}
}

Node* CartesianTree::insert_element(Node* T, int x) {	
	int prior = rand() % 1000000;
	NodeCartesian* Tnew = new NodeCartesian(x, prior);
	Node* T1 = nullptr;
	Node* T2 = nullptr;
	split(T, x, T1, T2);
	Node* Tres1 = NULL;
	Node* Tres2 = NULL;
	merge(Tres1, T1, Tnew);
	merge(Tres2, Tres1, T2);
	this->root = Tres2;
	return Tres2;
}


Node* CartesianTree::delete_element(Node* T, int x) {
	Node* T1 = nullptr;
	Node* T2 = nullptr;
	split(T, x, T1, T2);
	Node* node = T1->getRight();
	Node* parent = T1;
	while (node && node->getKey() <= x) {
		node = node->getRight();
		parent = parent->getRight();
	}
	parent->setRight(nullptr);
	Node* Tres = nullptr;
	merge(Tres, T1, T2);
	//merge();
	this->root = Tres;
	return Tres;
}

Node* CartesianTree::getRoot() {
	return this->root;
}

bool CartesianTree::search_element(Node*, int) {
	return 1;
}

void CartesianTree::print(Node* root) {
	if (root != nullptr) {
		cout << root->getKey() << " " << dynamic_cast<NodeCartesian*>(root)->getPrior() << "\t";
		print(root->getLeft());
		print(root->getRight());
	}
}

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