#include "Node.h"

Node::Node(int key) {
	this->key = key;
	this->left = nullptr;
	this->right = nullptr;
}

int Node::getKey() {
	return this->key;
}

Node* Node::getLeft() {
	return this->left;
}

Node* Node::getRight() {
	return this->right;
}

void Node::setKey(int key) {
	this->key = key;
}

void Node::setLeft(Node* left) {
	this->left = left;
}

void Node::setRight(Node* right) {
	this->right = right;
}