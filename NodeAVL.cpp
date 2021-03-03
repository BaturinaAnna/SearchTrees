#include "NodeAVL.h"

NodeAVL::NodeAVL(int key):Node(key) {
	this->height = 0;
}


int NodeAVL::getHeight() {
	if (this == nullptr)
		return 0;
	return this->height;
}

void NodeAVL::setHeight(int height) {
	this->height = height;
}