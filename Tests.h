#pragma once

//#include <iostream>
#include <map>
#include "RedBlackTree.h"
#include "AVLTree.h"
#include "CartesianTree.h"
#include "SplayTree.h"
#include  <random>

enum class TreeType { AVL_TREE, SPLAY_TREE, CARTESIAN_TREE, RED_BLACK_TREE };

class Tests {
public:
	bool insertToTree(TreeType, set<int>, set<int>);
	bool insertToTree(TreeType, vector<int>, vector<int>);
	bool deleteFromTree(TreeType, set<int>);
	bool deleteFromTree(TreeType, vector<int>);
	bool searchInTree(TreeType, set<int>, set<int>);
	bool searchInTree(TreeType, vector<int>, vector<int>);
	set<int> makeSetFixedSize(int);
	vector<int> makeVectorFixedSize(int, int);
	void dfs(Node*);
private:
	bool insertAVL(set<int>, set<int>);
	bool insertSplay(set<int>, set<int>);
	bool insertCartesian(set<int>, set<int>);
	bool insertRedBlack(set<int>, set<int>);
	bool deleteAVL(set<int>);
	bool deleteSplay(set<int>);
	bool deleteCartesian(set<int>);
	bool deleteRedBlack(set<int>);
	bool searchAVL(set<int>, set<int>);
	bool searchSplay(set<int>, set<int>);
	bool searchCartesian(set<int>, set<int>);
	bool searchRedBlack(set<int>, set<int>);

	bool insertAVL(vector<int>, vector<int>);
	bool insertSplay(vector<int>, vector<int>);
	bool insertCartesian(vector<int>, vector<int>);
	bool insertRedBlack(vector<int>, vector<int>);
	bool deleteAVL(vector<int>);
	bool deleteSplay(vector<int>);
	bool deleteCartesian(vector<int>);
	bool deleteRedBlack(vector<int>);
	bool searchAVL(vector<int>, vector<int>);
	bool searchSplay(vector<int>, vector<int>);
	bool searchCartesian(vector<int>, vector<int>);
	bool searchRedBlack(vector<int>, vector<int>);
};