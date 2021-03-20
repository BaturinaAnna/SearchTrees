#include "Tests.h"

void Tests::dfs(Node* node) {
	if (node->getLeft() != nullptr)
		dfs(node->getLeft());
	if (node->getRight() != nullptr)
		dfs(node->getRight());
	delete node;
}

set<int> Tests::makeSetFixedSize(int setSize) {
	srand(time(NULL));
	set<int> resultedSet;
	while (resultedSet.size() != setSize) {
		auto r = rand() % (setSize * 10000000);
		for (int i = 0; i < (setSize / 10000) + 1; i++) {
			r += rand() % (setSize * 10000000) + rand() % (setSize * 10000000)* rand() % (setSize * 10000000) * rand() % (setSize * 10000000);
			r += rand() % (setSize * 10000000) - rand() % (setSize * 10000000) * rand();
		}
		if (resultedSet.find(r) != resultedSet.end())
			cout << "!";
		resultedSet.insert(r);
	}
	return resultedSet;
}

vector<int> Tests::makeVectorFixedSize(int start, int vecSize) {
	vector<int> resultedVec;

	for (int i = start; i < start + vecSize; i++)
		resultedVec.push_back(i);

	random_device rd;
	mt19937 g(rd());
	shuffle(resultedVec.begin(), resultedVec.end(), g);
	return resultedVec;
}

bool Tests::insertToTree(TreeType treeType, set<int> tree, set<int> keysToInsert) {
	switch (treeType) {
	case TreeType::AVL_TREE:
		return insertAVL(tree, keysToInsert);
	case TreeType::SPLAY_TREE:
		return insertSplay(tree, keysToInsert);
	case TreeType::CARTESIAN_TREE:
		return insertCartesian(tree, keysToInsert);
	case TreeType::RED_BLACK_TREE:
		return insertRedBlack(tree, keysToInsert);
	}
}

bool Tests::deleteFromTree(TreeType treeType, set<int>tree) {
	switch (treeType) {
	case TreeType::AVL_TREE:
		return deleteAVL(tree);
	case TreeType::SPLAY_TREE:
		return deleteSplay(tree);
	case TreeType::CARTESIAN_TREE:
		return deleteCartesian(tree);
	case TreeType::RED_BLACK_TREE:
		return deleteRedBlack(tree);
	}
}

bool Tests::searchInTree(TreeType treeType, set<int>tree, set<int> keysToSearch) {
	switch (treeType) {
	case TreeType::AVL_TREE:
		return searchAVL(tree, keysToSearch);
	case TreeType::SPLAY_TREE:
		return searchSplay(tree, keysToSearch);
	case TreeType::CARTESIAN_TREE:
		return searchCartesian(tree, keysToSearch);
	case TreeType::RED_BLACK_TREE:
		return searchRedBlack(tree, keysToSearch);
	}
}

bool Tests::insertAVL(set<int> tree, set<int> keysToInsert) {
	AVLTree* testAVLTree = new AVLTree(tree);
	for (int key : keysToInsert) {
		if (tree.find(key) == tree.end()) {
			testAVLTree->insertNode(testAVLTree->getRoot(), key);
			tree.insert(key);
		}
	}
	set<int> testedTree = {};
	testAVLTree->toSet(testAVLTree->getRoot(), testedTree);
	if (testAVLTree->getRoot() != nullptr) {
		dfs(testAVLTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::insertSplay(set<int> tree, set<int> keysToInsert) {
	SplayTree* testSplayTree = new SplayTree(tree);
	for (int key : keysToInsert) {
		if (tree.find(key) == tree.end()) {
			testSplayTree->insertNode(testSplayTree->getRoot(), key);
			tree.insert(key);
		}
	}
	set<int> testedTree = {};
	testSplayTree->toSet(testSplayTree->getRoot(), testedTree);
	if (testSplayTree->getRoot() != nullptr) {
		dfs(testSplayTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::insertCartesian(set<int> tree, set<int> keysToInsert) {
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	for (int key : keysToInsert) {
		if (tree.find(key) == tree.end()) {
			testCartesianTree->insertNode(testCartesianTree->getRoot(), key);
			tree.insert(key);
		}
	}
	set<int> testedTree = {};
	testCartesianTree->toSet(testCartesianTree->getRoot(), testedTree);
	if (testCartesianTree->getRoot() != nullptr) {
		dfs(testCartesianTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::insertRedBlack(set<int> tree, set<int> keysToInsert) {
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	for (int key : keysToInsert) {
		if (tree.find(key) == tree.end()) {
			testRedBlackTree->insertNode(nullptr, key);
			tree.insert(key);
		}
	}
	set<int> testedTree = {};
	testRedBlackTree->toSet(nullptr, testedTree);
	delete testRedBlackTree;
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteAVL(set<int> tree) {
	set<int> keysToDelete = tree;
	AVLTree* testAVLTree = new AVLTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testAVLTree->deleteNode(testAVLTree->getRoot(), *iterator);
		tree.erase(*iterator);
		iterator++;
	}
	set<int> testedTree = {};
	testAVLTree->toSet(testAVLTree->getRoot(), testedTree);
	if (testAVLTree->getRoot() != nullptr) {
		dfs(testAVLTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteSplay(set<int> tree) {
	set<int> keysToDelete = tree;
	SplayTree* testSplayTree = new SplayTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testSplayTree->deleteNode(testSplayTree->getRoot(), *iterator);
		tree.erase(*iterator);
		iterator++;
	}
	set<int> testedTree = {};
	testSplayTree->toSet(testSplayTree->getRoot(), testedTree);
	if (testSplayTree->getRoot() != nullptr) {
		dfs(testSplayTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteCartesian(set<int> tree) {
	set<int> keysToDelete = tree;
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testCartesianTree->deleteNode(testCartesianTree->getRoot(), *iterator);
		tree.erase(*iterator);
		iterator++;
	}
	set<int> testedTree = {};
	testCartesianTree->toSet(testCartesianTree->getRoot(), testedTree);
	if (testCartesianTree->getRoot() != nullptr) {
		dfs(testCartesianTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteRedBlack(set<int> tree) {
	set<int> keysToDelete = tree;
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testRedBlackTree->deleteNode(nullptr, *iterator);
		tree.erase(*iterator);
		iterator++;
	}
	set<int> testedTree = {};
	testRedBlackTree->toSet(nullptr, testedTree);
	delete testRedBlackTree;
	if (!(includes(testedTree.begin(), testedTree.end(), tree.begin(), tree.end()) && includes(tree.begin(), tree.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::searchAVL(set<int> tree, set<int> keysToSearch) {
	AVLTree* testAVLTree = new AVLTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (tree.find(key) != tree.end());
		bool testResult = testAVLTree->searchNode(testAVLTree->getRoot(), key);
		if (realResult != testResult)
			return false;
	}
	if (testAVLTree->getRoot() != nullptr) {
		dfs(testAVLTree->getRoot());
	}
	return true;
}

bool Tests::searchSplay(set<int> tree, set<int> keysToSearch) {
	SplayTree* testSplayTree = new SplayTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (tree.find(key) != tree.end());
		bool testResult = testSplayTree->searchNode(testSplayTree->getRoot(), key);
		if (realResult != testResult)
			return false;
	}
	if (testSplayTree->getRoot() != nullptr) {
		dfs(testSplayTree->getRoot());
	}
	return true;
}

bool Tests::searchCartesian(set<int> tree, set<int> keysToSearch) {
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (tree.find(key) != tree.end());
		bool testResult = testCartesianTree->searchNode(testCartesianTree->getRoot(), key);
		if (realResult != testResult)
			return false;
	}
	if (testCartesianTree->getRoot() != nullptr) {
		dfs(testCartesianTree->getRoot());
	}
	return true;
}

bool Tests::searchRedBlack(set<int> tree, set<int> keysToSearch) {
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (tree.find(key) != tree.end());
		bool testResult = testRedBlackTree->searchNode(nullptr, key);
		if (realResult != testResult)
			return false;
	}
	delete testRedBlackTree;
	return true;
}


bool Tests::insertToTree(TreeType treeType, vector<int> tree, vector<int> keysToInsert) {
	switch (treeType) {
	case TreeType::AVL_TREE:
		return insertAVL(tree, keysToInsert);
	case TreeType::SPLAY_TREE:
		return insertSplay(tree, keysToInsert);
	case TreeType::CARTESIAN_TREE:
		return insertCartesian(tree, keysToInsert);
	case TreeType::RED_BLACK_TREE:
		return insertRedBlack(tree, keysToInsert);
	}
}

bool Tests::deleteFromTree(TreeType treeType, vector<int>tree) {
	switch (treeType) {
	case TreeType::AVL_TREE:
		return deleteAVL(tree);
	case TreeType::SPLAY_TREE:
		return deleteSplay(tree);
	case TreeType::CARTESIAN_TREE:
		return deleteCartesian(tree);
	case TreeType::RED_BLACK_TREE:
		return deleteRedBlack(tree);
	}
}

bool Tests::searchInTree(TreeType treeType, vector<int>tree, vector<int> keysToSearch) {
	switch (treeType) {
	case TreeType::AVL_TREE:
		return searchAVL(tree, keysToSearch);
	case TreeType::SPLAY_TREE:
		return searchSplay(tree, keysToSearch);
	case TreeType::CARTESIAN_TREE:
		return searchCartesian(tree, keysToSearch);
	case TreeType::RED_BLACK_TREE:
		return searchRedBlack(tree, keysToSearch);
	}
}

bool Tests::insertAVL(vector<int> tree, vector<int> keysToInsert) {
	AVLTree* testAVLTree = new AVLTree(tree);
	for (int key : keysToInsert) {
		if (find(tree.begin(), tree.end(), key) == tree.end()) {
			testAVLTree->insertNode(testAVLTree->getRoot(), key);
			tree.push_back(key);
		}
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testAVLTree->toSet(testAVLTree->getRoot(), testedTree);
	if (testAVLTree->getRoot() != nullptr) {
		dfs(testAVLTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::insertSplay(vector<int> tree, vector<int> keysToInsert) {
	SplayTree* testSplayTree = new SplayTree(tree);
	for (int key : keysToInsert) {
		if (find(tree.begin(), tree.end(), key) == tree.end()) {
			testSplayTree->insertNode(testSplayTree->getRoot(), key);
			tree.push_back(key);
		}
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testSplayTree->toSet(testSplayTree->getRoot(), testedTree);
	if (testSplayTree->getRoot() != nullptr) {
		dfs(testSplayTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::insertCartesian(vector<int> tree, vector<int> keysToInsert) {
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	for (int key : keysToInsert) {
		if (find(tree.begin(), tree.end(), key) == tree.end()) {
			testCartesianTree->insertNode(testCartesianTree->getRoot(), key);
			tree.push_back(key);
		}
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testCartesianTree->toSet(testCartesianTree->getRoot(), testedTree);
	if (testCartesianTree->getRoot() != nullptr) {
		dfs(testCartesianTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::insertRedBlack(vector<int> tree, vector<int> keysToInsert) {
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	for (int key : keysToInsert) {
		if (find(tree.begin(), tree.end(), key) == tree.end()) {
			testRedBlackTree->insertNode(nullptr, key);
			tree.push_back(key);
		}
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testRedBlackTree->toSet(nullptr, testedTree);
	delete testRedBlackTree;
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteAVL(vector<int> tree) {
	vector<int> keysToDelete = tree;
	AVLTree* testAVLTree = new AVLTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testAVLTree->deleteNode(testAVLTree->getRoot(), *iterator);
		tree.erase(find(tree.begin(), tree.end(), *iterator));
		iterator++;
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testAVLTree->toSet(testAVLTree->getRoot(), testedTree);
	if (testAVLTree->getRoot() != nullptr) {
		dfs(testAVLTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteSplay(vector<int> tree) {
	vector<int> keysToDelete = tree;
	SplayTree* testSplayTree = new SplayTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testSplayTree->deleteNode(testSplayTree->getRoot(), *iterator);
		tree.erase(find(tree.begin(), tree.end(), *iterator));
		iterator++;
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testSplayTree->toSet(testSplayTree->getRoot(), testedTree);
	if (testSplayTree->getRoot() != nullptr) {
		dfs(testSplayTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteCartesian(vector<int> tree) {
	vector<int> keysToDelete = tree;
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testCartesianTree->deleteNode(testCartesianTree->getRoot(), *iterator);
		tree.erase(find(tree.begin(), tree.end(), *iterator));
		iterator++;
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testCartesianTree->toSet(testCartesianTree->getRoot(), testedTree);
	if (testCartesianTree->getRoot() != nullptr) {
		dfs(testCartesianTree->getRoot());
	}
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::deleteRedBlack(vector<int> tree) {
	vector<int> keysToDelete = tree;
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	auto iterator = keysToDelete.begin();
	for (int i = 0; i < keysToDelete.size() / 2; i++) {
		testRedBlackTree->deleteNode(nullptr, *iterator);
		tree.erase(find(tree.begin(), tree.end(), *iterator));
		iterator++;
	}
	set<int> testedTree = {};
	set<int> answ(tree.begin(), tree.end());
	testRedBlackTree->toSet(nullptr, testedTree);
	delete testRedBlackTree;
	if (!(includes(testedTree.begin(), testedTree.end(), answ.begin(), answ.end()) && includes(answ.begin(), answ.end(), testedTree.begin(), testedTree.end())))
		return false;
	return true;
}

bool Tests::searchAVL(vector<int> tree, vector<int> keysToSearch) {
	AVLTree* testAVLTree = new AVLTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (find(tree.begin(), tree.end(), key) != tree.end());
		bool testResult = testAVLTree->searchNode(testAVLTree->getRoot(), key);
		if (realResult != testResult)
			return false;
	}
	if (testAVLTree->getRoot() != nullptr) {
		dfs(testAVLTree->getRoot());
	}
	return true;
}

bool Tests::searchSplay(vector<int> tree, vector<int> keysToSearch) {
	SplayTree* testSplayTree = new SplayTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (find(tree.begin(), tree.end(), key) != tree.end());
		bool testResult = testSplayTree->searchNode(testSplayTree->getRoot(), key);
		if (realResult != testResult)
			return false;
	}
	if (testSplayTree->getRoot() != nullptr) {
		dfs(testSplayTree->getRoot());
	}
	return true;
}

bool Tests::searchCartesian(vector<int> tree, vector<int> keysToSearch) {
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (find(tree.begin(), tree.end(), key) != tree.end());
		bool testResult = testCartesianTree->searchNode(testCartesianTree->getRoot(), key);
		if (realResult != testResult)
			return false;
	}
	if (testCartesianTree->getRoot() != nullptr) {
		dfs(testCartesianTree->getRoot());
	}
	return true;
}

bool Tests::searchRedBlack(vector<int> tree, vector<int> keysToSearch) {
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	for (int key : keysToSearch) {
		bool realResult = (find(tree.begin(), tree.end(), key) != tree.end());
		bool testResult = testRedBlackTree->searchNode(nullptr, key);
		if (realResult != testResult)
			return false;
	}
	delete testRedBlackTree;
	return true;
}