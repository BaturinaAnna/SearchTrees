#include "SplayTree.h"

SplayTree::SplayTree(set<int> tree) {
	Node* root = nullptr;
	for (auto val : tree) {
		root = insertNode(root, val);
	}
	this->root = root;
}

Node* SplayTree::rightRotate(Node* x) {
	Node* y = x->getLeft();
	x->setLeft(y->getRight());
	y->setRight(x);
	return y;
}

Node* SplayTree::leftRotate(Node* x) {
	Node* y = x->getRight();
	x->setRight(y->getLeft());
	y->setLeft(x);
	return y;
}

Node* SplayTree::splay(Node* root, int key) {
	if (root == nullptr || root->getKey() == key)
		return root;
	if (root->getKey() > key) {
		if (root->getLeft() == nullptr) {
			this->root = root;
			return root;
		}
		if (root->getLeft()->getKey() > key) { // Zig-Zig (Left Left) 
			root->getLeft()->setLeft(splay(root->getLeft()->getLeft(), key));
			root = rightRotate(root);
		}
		else if (root->getLeft()->getKey() < key) { // Zig-Zag (Left Right)
			root->getLeft()->setRight(splay(root->getLeft()->getRight(), key));
			if (root->getLeft()->getRight() != nullptr)
				root->setLeft(leftRotate(root->getLeft()));
		}
		//return (root->getLeft() == nullptr) ? root : rightRotate(root);
		if (root->getLeft() == nullptr) {
			this->root = root;
			return root;
		}
		Node* newRoot = rightRotate(root);
		this->root = newRoot;
		return newRoot;
	}
	else {
		if (root->getRight() == nullptr) {
			this->root = root;
			return root;
		}
		if (root->getRight()->getKey() > key) { // Zag-Zig (Right Left) 
			root->getRight()->setLeft(splay(root->getRight()->getLeft(), key));
			if (root->getRight()->getLeft() != nullptr)
				root->setRight(rightRotate(root->getRight()));
		}
		else if (root->getRight()->getKey() < key) { // Zag-Zag (Right Right) 
			root->getRight()->setRight(splay(root->getRight()->getRight(), key));
			root = leftRotate(root);
		}
		if (root->getRight() == nullptr) {
			this->root = root;
			return root;
		}
		Node* newRoot = leftRotate(root);
		this->root = newRoot;
		return newRoot;
	}
}

Node* SplayTree::insertNode(Node* root, int key) {
	if (root == nullptr) {
		Node* newNode = new Node(key);
		this->root = newNode;
		return newNode;
	}
	root = splay(root, key);
	print(this->getRoot());
	cout << endl;
	if (root->getKey() == key) {
		this->root = root;
		return root;
	}
	Node* insertedNode = new Node(key);
	if (root->getKey() > key) {
		insertedNode->setRight(root);
		insertedNode->setLeft(root->getLeft());
		root->setLeft(nullptr);
	}
	else {
		insertedNode->setLeft(root);
		insertedNode->setRight(root->getRight());
		root->setRight(nullptr);
	}
	this->root = insertedNode;
	return insertedNode;
}

Node* SplayTree::deleteNode(Node* root, int key) {
	Node* temp = nullptr;
	if (root == nullptr)
		return nullptr;   
	root = splay(root, key);
	if (key != root->getKey()) {
		this->root = root;
		return root;
	}
	if (root->getLeft() == nullptr) {
		temp = root;
		root = root->getRight();
	}
	else {
		temp = root;
		root = splay(root->getLeft(), key);
		root->setRight(temp->getRight());
	}
	free(temp);
	this->root = root;
	return root;
}

bool SplayTree::searchNode(Node* root, int key){
	Node* found = splay(root, key);
	if (found == root)
		return false;
	return true;
}

void SplayTree::print(Node* root) {
	if (root != nullptr) {
		cout << root->getKey() << " ";
		print(root->getLeft());
		print(root->getRight());
	}
}

void SplayTree::toSet(Node* root, set<int>& result) {
	if (root != nullptr) {
		result.insert(root->getKey());
		toSet(root->getLeft(), result);
		toSet(root->getRight(), result);
	}
}

Node* SplayTree::getRoot() {
	return this->root;
}