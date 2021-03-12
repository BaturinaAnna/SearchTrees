#include "StressTests.h"


set<int> makeSetFixedSize(int setSize) {
	srand(time(NULL));
	set<int> resultedSet;
	while (resultedSet.size() != setSize) {
		resultedSet.insert(rand() % (setSize * 1000));
	}
	return resultedSet;
}


// INSERT

bool stressTestInsertAVL(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
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

bool stressTestInsertSplay(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			SplayTree* testSplayTree = new SplayTree(tree);
			set<int> keysToInsert = makeSetFixedSize(size);
			for (int key : keysToInsert) {
				if (tree.find(key) == tree.end()) {
					testSplayTree->insertNode(testSplayTree->getRoot(), key);
					tree.insert(key);
				}
			}
			set<int> testedTree = {};
			testSplayTree->toSet(testSplayTree->getRoot(), testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for Splay trees are passed" << endl;
		return true;
	}
	cout << "Insert tests for Splay trees are failed" << endl;
	return false;
}

bool stressTestInsertCartesian(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			CartesianTree* testCartesianTree = new CartesianTree(tree);
			set<int> keysToInsert = makeSetFixedSize(size);
			for (int key : keysToInsert) {
				if (tree.find(key) == tree.end()) {
					testCartesianTree->insertNode(testCartesianTree->getRoot(), key);
					tree.insert(key);
				}
			}
			set<int> testedTree = {};
			testCartesianTree->toSet(testCartesianTree->getRoot(), testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for Cartesian trees are passed" << endl;
		return true;
	}
	cout << "Insert tests for Cartesian trees are failed" << endl;
	return false;
}

bool stressTestInsertRedBlack(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
			set<int> keysToInsert = makeSetFixedSize(size);
			for (int key : keysToInsert) {
				if (tree.find(key) == tree.end()) {
					testRedBlackTree->insertNode(nullptr, key);
					tree.insert(key);
				}
			}
			set<int> testedTree = {};
			testRedBlackTree->toSet(nullptr, testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for Red-Black trees are passed" << endl;
		return true;
	}
	cout << "Insert tests for Red-Black trees are failed" << endl;
	return false;
}

// DELETE
bool stressTestDeleteAVL(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			set<int> keysToDelete = tree;
			AVLTree* testAVLTree = new AVLTree(tree);
			auto iterator = keysToDelete.begin();
			testAVLTree->print(testAVLTree->getRoot());
			cout << endl;
			for (int i = 0; i < size / 2; i++) {
				testAVLTree->deleteNode(testAVLTree->getRoot(), *iterator);
				testAVLTree->print(testAVLTree->getRoot());
				cout << endl;
				tree.erase(*iterator);
				iterator++;
			}
			set<int> testedTree = {};
			testAVLTree->toSet(testAVLTree->getRoot(), testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All delete tests for AVL trees are passed" << endl;
		return true;
	}
	cout << "Delete tests for AVL trees are failed" << endl;
	return false;
}

bool stressTestDeleteSplay(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			set<int> keysToDelete = tree;
			SplayTree* testSplayTree = new SplayTree(tree);
			auto iterator = keysToDelete.begin();
			for (int i = 0; i < size / 2; i++) {
				testSplayTree->deleteNode(testSplayTree->getRoot(), *iterator);
				tree.erase(*iterator);
				iterator++;
			}
			set<int> testedTree = {};
			testSplayTree->toSet(testSplayTree->getRoot(), testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All delete tests for Splay trees are passed" << endl;
		return true;
	}
	cout << "Delete tests for Splay trees are failed" << endl;
	return false;
}

bool stressTestDeleteCartesian(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			set<int> keysToDelete = tree;
			CartesianTree* testCartesianTree = new CartesianTree(tree);
			auto iterator = keysToDelete.begin();
			for (int i = 0; i < size / 2; i++) {
				testCartesianTree->deleteNode(testCartesianTree->getRoot(), *iterator);
				tree.erase(*iterator);
				iterator++;
			}
			set<int> testedTree = {};
			testCartesianTree->toSet(testCartesianTree->getRoot(), testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All delete tests for Cartesian trees are passed" << endl;
		return true;
	}
	cout << "Delete tests for Cartesian trees are failed" << endl;
	return false;
}

bool stressTestDeleteRedBlack(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			set<int> keysToDelete = tree;
			RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
			auto iterator = keysToDelete.begin();
			for (int i = 0; i < size / 2; i++) {
				testRedBlackTree->deleteNode(nullptr, *iterator);
				tree.erase(*iterator);
				iterator++;
			}
			set<int> testedTree = {};
			testRedBlackTree->toSet(nullptr, testedTree);
			if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end()))) {
				passed = false;
			}
		}
	}
	if (passed == true) {
		cout << "All delete tests for Red-Black trees are passed" << endl;
		return true;
	}
	cout << "Delete tests for Red-Black trees are failed" << endl;
	return false;
}

// SEARCH

bool stressTestSearchAVL(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			AVLTree* testAVLTree = new AVLTree(tree);
			set<int> keysToSearch = makeSetFixedSize(3 * size);
			for (int key : keysToSearch) {
				bool realResult = (tree.find(key) != tree.end());
				bool testResult = testAVLTree->searchNode(testAVLTree->getRoot(), key);
				if (realResult != testResult) {
					passed = false;
				}
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for AVL trees are passed" << endl;
		return true;
	}
	cout << "Search tests for AVL trees are failed" << endl;
	return false;
}

bool stressTestSearchSplay(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			SplayTree* testSplayTree = new SplayTree(tree);
			set<int> keysToSearch = makeSetFixedSize(3 * size);

			testSplayTree->print(testSplayTree->getRoot());
			cout << endl;

			for (int key : keysToSearch) {
				bool realResult = (tree.find(key) != tree.end());
				bool testResult = testSplayTree->searchNode(testSplayTree->getRoot(), key);

				cout << key << " R: " << realResult << " T: " << testResult << endl;

				if (realResult != testResult) {
					passed = false;
				}
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for Splay trees are passed" << endl;
		return true;
	}
	cout << "Search tests for Splay trees are failed" << endl;
	return false;
}

bool stressTestSearchCartesian(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			CartesianTree* testCartesianTree = new CartesianTree(tree);
			set<int> keysToSearch = makeSetFixedSize(3 * size);
			for (int key : keysToSearch) {
				bool realResult = (tree.find(key) != tree.end());
				bool testResult = testCartesianTree->searchNode(testCartesianTree->getRoot(), key);
				if (realResult != testResult) {
					passed = false;
				}
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for Cartesian trees are passed" << endl;
		return true;
	}
	cout << "Search tests for Cartesian trees are failed" << endl;
	return false;
}

bool stressTestSearchRedBlack(int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
			set<int> keysToSearch = makeSetFixedSize(3 * size);
			for (int key : keysToSearch) {
				bool realResult = (tree.find(key) != tree.end());
				bool testResult = testRedBlackTree->searchNode(nullptr, key);
				if (realResult != testResult) {
					passed = false;
				}
			}
		}
	}
	if (passed == true) {
		cout << "All insert tests for Red-Black trees are passed" << endl;
		return true;
	}
	cout << "Search tests for Red-Black trees are failed" << endl;
	return false;
}