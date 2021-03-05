#include "CartesianTree.h"


CartesianTree::CartesianTree(vector<int> tree) {
	int prior = rand() % 1000000;
	Node* root = new NodeCartesian(tree[0], prior);
	for (int i = 1; i < tree.size(); i++) {
		root = insert_element(root, tree[i]);
	}
	this->root = root;
}

Node* CartesianTree::merge(Node* T1, Node* T2) {
	if (T2 == nullptr)
		return T1;
	else if (T1 == nullptr)
		return T2;
	else if (dynamic_cast<NodeCartesian*>(T1)->getPrior() > dynamic_cast<NodeCartesian*>(T2)->getPrior()) {
		T1->setRight(merge(T1->getRight(), T2));
		return T1;
	}
	else {
		T2->setLeft(merge(T1, T2->getLeft()));
		return T2;
	}
}

pair<Node*, Node*> CartesianTree::split(Node* T, int x) {
	if (T == nullptr) {
		return { nullptr, nullptr };
	}
	else if (x > T->getKey()) {
		Node* T1 = nullptr;
		Node* T2 = nullptr;
		pair<Node*, Node*> trees = { T1, T2 };
		trees = split(T->getRight(), x);
		T->setRight(trees.first);
		return { T, trees.second };
	}
	else {
		Node* T1 = nullptr;
		Node* T2 = nullptr;
		pair<Node*, Node*> trees = { T1, T2 };
		trees = split(T->getLeft(), x);
		T->setLeft(trees.second);
		return { trees.first, T };
	}
}

Node* CartesianTree::insert_element(Node* T, int x) {	
	int prior = rand() % 1000000;
	NodeCartesian* Tnew = new NodeCartesian(x, prior);
	Node* T1 = nullptr;
	Node* T2 = nullptr;
	pair<Node*, Node*> trees = { T1, T2 };
	trees = split(T, x);
	Node* Tres1 = nullptr;
	Node* Tres2 = nullptr;
	Tres1 = merge(trees.first, Tnew);
	Tres2 = merge(Tres1, trees.second);
	this->root = Tres2;
	return Tres2;
}


Node* CartesianTree::delete_element(Node* T, int x) {
	Node* T1 = nullptr;
	Node* T2 = nullptr;
	Node* Tres = nullptr;
	Node* parent = nullptr;
	Node* node = T;
	bool goTo = 0; //0 - left, 1 - right
	while (node && node->getKey() != x) {
		if (x < node->getKey()) {
			parent = node;
			node = node->getLeft();
			goTo = 0;
		}
		else if (x > node->getKey()) {
			parent = node;
			node = node->getRight();
			goTo = 1;
		}
	}
	if (node == nullptr) {
		return this->root;
	}
	Tres = merge(node->getLeft(), node->getRight());
	if (parent == nullptr) {
		this->root = Tres;
		return Tres;
	}
	else if (goTo == 0) {
		parent->setLeft(Tres);
		return this->root;
	}
	parent->setRight(Tres);
	return this->root;
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

bool search_cartesian(Node* root, int key, bool finded) {
	if (root != nullptr)
	{
		if (root->getKey() == key) {
			finded = true;
		}
		else if (root->getKey() < key) {
			finded = search_cartesian(root->getRight(), key, finded);
		}
		else {
			finded = search_cartesian(root->getLeft(), key, finded);
		}
	}
	return finded;
}

bool CartesianTree::search_element(Node* root, int key) {
	bool finded = false;
	return search_cartesian(root, key, finded);
}