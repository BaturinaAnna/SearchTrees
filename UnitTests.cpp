#include "UnitTests.h"
 
map<TreeType, string> TreeNames = { {TreeType::AVL_TREE, "AVL trees"},
									{TreeType::SPLAY_TREE, "Splay trees"},
									{TreeType::CARTESIAN_TREE, "Cartesian trees"},
									{TreeType::RED_BLACK_TREE, "Red-Black trees"} };

bool UnitTests::unitTestEmptyTree() {
	bool result = true;
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE})
		result = result & emptyTree(treeType);
	return result;
}

bool UnitTests::unitTestNegativeValuesTree() {
	bool result = true;
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE})
		result = result & negativeValuesTree(treeType);
	return result;
}

bool UnitTests::unitTestOrdinaryTree() {
	bool result = true;
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE})
		result = result & ordinaryTree(treeType);
	return result;
}

bool UnitTests::emptyTree(TreeType treeType) {
	bool passed = true;
	UnitTests unitTests;
	set<int> tree;
	passed = passed & unitTests.Tests::deleteFromTree(treeType, tree);
	passed = passed & unitTests.Tests::searchInTree(treeType, tree, { 1, 2, 3 });
	passed = passed & unitTests.Tests::insertToTree(treeType, tree, { 1, 2, 3 });
	if (passed == true) {
		cout << "All unit tests for empty " << TreeNames[treeType] << " are passed" << endl;
		return true;
	}
	cout << "Unit tests for empty " << TreeNames[treeType] << " are failed" << endl;
	return false;
}

bool UnitTests::negativeValuesTree(TreeType treeType) {
	bool passed = true;
	UnitTests unitTests;
	set<int> tree = { -10, -5, -1 };
	passed = passed & unitTests.Tests::deleteFromTree(treeType, tree);
	passed = passed & unitTests.Tests::searchInTree(treeType, tree, { -1, 1, -5, 5, -10, 10});
	passed = passed & unitTests.Tests::insertToTree(treeType, tree, { -15, -20, -25});
	if (passed == true) {
		cout << "All unit tests for " << TreeNames[treeType] << " that consists of negative values are passed" << endl;
		return true;
	}
	cout << "Unit tests for " << TreeNames[treeType] << " that consists of negative values are failed" << endl;
	return false;
}

bool UnitTests::ordinaryTree(TreeType treeType) {
	bool passed = true;
	UnitTests unitTests;
	set<int> tree = { 0, 1, 10, 15, 19, 20, 32, 35, 77, 84 };
	passed = passed & unitTests.Tests::deleteFromTree(treeType, tree);
	passed = passed & unitTests.Tests::searchInTree(treeType, tree, { 0, 1, 2, 3, 10, 15, 16, 17, 19, 20 });
	passed = passed & unitTests.Tests::insertToTree(treeType, tree, { 25, 28, 44, 55, 66, 88 });
	if (passed == true) {
		cout << "All unit tests for ordinary " << TreeNames[treeType] << " are passed" << endl;
		return true;
	}
	cout << "Unit tests for ordinary " << TreeNames[treeType] << " are failed" << endl;
	return false;
}