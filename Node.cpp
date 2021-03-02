#include "Node.h"

Node::Node(int key) {
	this->key = key;
	this->left = nullptr;
	this->right = nullptr;
	this->height = 0;
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

int Node::getHeight() {
	if (this == nullptr)
		return 0;
	return this->height;
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

void Node::setHeight(int height) {
	this->height = height;
}