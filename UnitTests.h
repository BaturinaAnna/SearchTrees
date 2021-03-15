#pragma once

#include "Tests.h"


class UnitTests : public Tests {
public:
	bool unitTestEmptyTree();
	bool unitTestNegativeValuesTree();
	bool unitTestOrdinaryTree();
private:
	bool emptyTree(TreeType);
	bool negativeValuesTree(TreeType);
	bool ordinaryTree(TreeType);
};
