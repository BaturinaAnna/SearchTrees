#include "UnitTests.h"

/*
bool unitTestEmptyTree(int start_n, int step_n, int end_n, int iterations_num) {
	return true;
}


bool stressTestEmptyAVL(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree;
			AVLTree* testAVLTree = new AVLTree(tree);
			set<int> keysToInsert = makeSetFixedSize(size);
			for (int key : keysToInsert) {
				if (tree.find(key) == tree.end()) {
					testAVLTree->insertNode(testAVLTree->getRoot(), key);
					tree.insert(key);
				}
			}
			set<int> testedTree = {};
			testAVLTree->toSet(testAVLTree->getRoot(), testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for AVL trees are passed" << endl;
		return true;
	}
	cout << "Insert tests for AVL trees are failed" << endl;
	return false;
}

*/