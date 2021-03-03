#include "NodeCartesian.h"

NodeCartesian::NodeCartesian(int key, int prior) :Node(key) {
	this->prior = prior;
}


int NodeCartesian::getPrior() {
	return this->prior;
}

void NodeCartesian::setPrior(int prior) {
	this->prior = prior;
}