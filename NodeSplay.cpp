#include "NodeSplay.h"

NodeSplay::NodeSplay(int key):Node(key) {
	this->parent = nullptr;
}

NodeSplay* NodeSplay::getParent() {
	return this->parent;
}

void NodeSplay::setParent(NodeSplay* parent) {
	this->parent = parent;
}