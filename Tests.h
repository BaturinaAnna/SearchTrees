#pragma once

//#include <iostream>
#include <map>
#include "RedBlackTree.h"
#include "AVLTree.h"
#include "CartesianTree.h"
#include "SplayTree.h"


enum class TreeType { AVL_TREE, SPLAY_TREE, CARTESIAN_TREE, RED_BLACK_TREE };

class Tests {
public:
	bool insertToTree(TreeType, set<int>, set<int>);
	bool deleteFromTree(TreeType, set<int>);
	bool searchInTree(TreeType, set<int>, set<int>);
	set<int> makeSetFixedSize(int);
private:
	bool insertAVL(set<int> tree, set<int> keysToInsert);
	bool insertSplay(set<int> tree, set<int> keysToInsert);
	bool insertCartesian(set<int> tree, set<int> keysToInsert);
	bool insertRedBlack(set<int> tree, set<int> keysToInsert);
	bool deleteAVL(set<int> tree);
	bool deleteSplay(set<int> tree);
	bool deleteCartesian(set<int> tree);
	bool deleteRedBlack(set<int> tree);
	bool searchAVL(set<int> tree, set<int> keysToSearch);
	bool searchSplay(set<int> tree, set<int> keysToSearch);
	bool searchCartesian(set<int> tree, set<int> keysToSearch);
	bool searchRedBlack(set<int> tree, set<int> keysToSearch);
};