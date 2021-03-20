#include "Graphs.h"

//INSERT
void Graphs::insertInfo(int start_n, int step_n, int end_n) {
	ofstream infoFile;
	infoFile.open("insert.csv");
	vector<vector<int>> results = insertGraph(start_n, step_n, end_n);
	infoFile << "Number of elements;AVL;Splay;Cartesian;Red-Black\n";
	for (int i = 0; i < results[0].size(); i++) {
		infoFile << start_n + i * step_n << ";" << results[0][i] << ";" << results[1][i] << ";" << results[2][i] << ";" << results[3][i] << "\n";
	}
	infoFile.close();
	cout << "Info for insert is recieved" << endl;
}

vector<vector<int>> Graphs::insertGraph(int start_n, int step_n, int end_n) {
	vector<vector<int>> results;
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE}) {
		vector<int> result = insertToTree(treeType, start_n, step_n, end_n);
		results.push_back(result);
		cout << "done" << endl;
	}
	return results;
}

vector<int> Graphs::insertToTree(TreeType treeType, int start, int step, int end) {
	switch (treeType) {
	case TreeType::AVL_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(insertToAVL(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::SPLAY_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(insertToSplay(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::CARTESIAN_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(insertToCartesian(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::RED_BLACK_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(insertToRedBlack(i));
			cout << i << endl;
		}
		return result;
	}
	}
}

int Graphs::insertToAVL(int size) {
	Graphs graphs;
	vector<int> backet = graphs.Tests::makeVectorFixedSize(0, size + 10000);
	vector<int> tree(backet.begin(), backet.begin() + size);
	AVLTree* testAVLTree = new AVLTree(tree);
	vector<int> keysToInsert(backet.begin() + size, backet.end());
	int time = 0;
	for (int key : keysToInsert) {
		auto start = high_resolution_clock::now();
		testAVLTree->insertNode(testAVLTree->getRoot(), key);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
	}
	graphs.Tests::dfs(testAVLTree->getRoot());
	delete(testAVLTree);
	return time;
}

int Graphs::insertToSplay(int size) {
	Graphs graphs;
	vector<int> backet = graphs.Tests::makeVectorFixedSize(0, size + 10000);
	vector<int> tree(backet.begin(), backet.begin() + size);
	SplayTree* testSplayTree = new SplayTree(tree);
	vector<int> keysToInsert(backet.begin() + size, backet.end());
	int time = 0; 
	for (int key : keysToInsert) {
		auto start = high_resolution_clock::now();
		testSplayTree->insertNode(testSplayTree->getRoot(), key);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
	}
	graphs.Tests::dfs(testSplayTree->getRoot());
	delete(testSplayTree);
	return time;
}

int Graphs::insertToRedBlack(int size) {
	Graphs graphs;
	vector<int> backet = graphs.Tests::makeVectorFixedSize(0, size + 10000);
	vector<int> tree(backet.begin(), backet.begin() + size);
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	vector<int> keysToInsert(backet.begin() + size, backet.end());
	int time = 0;
	for (int key : keysToInsert) {
		auto start = high_resolution_clock::now();
		testRedBlackTree->insertNode(nullptr, key);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
	}
	delete(testRedBlackTree);
	return time;
}

int Graphs::insertToCartesian(int size) {
	Graphs graphs;
	vector<int> backet = graphs.Tests::makeVectorFixedSize(0, size + 10000);
	vector<int> tree(backet.begin(), backet.begin() + size);
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	vector<int> keysToInsert(backet.begin() + size, backet.end());
	int time = 0;
	for (int key : keysToInsert) {
		if (find(tree.begin(), tree.end(), key) == tree.end()) {
			auto start = high_resolution_clock::now();
			testCartesianTree->insertNode(testCartesianTree->getRoot(), key);
			auto stop = high_resolution_clock::now();
			time += duration_cast<microseconds>(stop - start).count();
		}
	}
	graphs.Tests::dfs(testCartesianTree->getRoot());
	delete(testCartesianTree);
	return time;
}

//DELETE
void Graphs::deleteInfo(int start_n, int step_n, int end_n) {
	ofstream infoFile;
	infoFile.open("delete.csv");
	vector<vector<int>> results = deleteGraph(start_n, step_n, end_n);
	infoFile << "Number of elements;AVL;Splay;Cartesian;Red-Black\n";
	for (int i = 0; i < results[0].size(); i++) {
		infoFile << start_n + i * step_n << ";" << results[0][i] << ";" << results[1][i] << ";" << results[2][i] << ";" << results[3][i] << "\n";
	}
	infoFile.close();
	cout << "Info for delete is recieved" << endl;
}

vector<vector<int>> Graphs::deleteGraph(int start_n, int step_n, int end_n) {
	vector<vector<int>> results;
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE}) {
		vector<int> result = deleteFromTree(treeType, start_n, step_n, end_n);
		cout << "done" << endl;
		results.push_back(result);
	}
	return results;
}

vector<int> Graphs::deleteFromTree(TreeType treeType, int start, int step, int end) {
	switch (treeType) {
	case TreeType::AVL_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(deleteFromAVL(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::SPLAY_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(deleteFromSplay(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::CARTESIAN_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(deleteFromCartesian(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::RED_BLACK_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(deleteFromRedBlack(i));
			cout << i << endl;
		}
		return result;
	}
	}
}

int Graphs::deleteFromAVL(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	AVLTree* testAVLTree = new AVLTree(tree);
	vector<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testAVLTree->deleteNode(testAVLTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	graphs.Tests::dfs(testAVLTree->getRoot());
	delete(testAVLTree);
	return time;
}

int Graphs::deleteFromSplay(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	SplayTree* testSplayTree = new SplayTree(tree);
	vector<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	testSplayTree->deleteNode(testSplayTree->getRoot(), *iterator);
	iterator++;
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testSplayTree->deleteNode(testSplayTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	graphs.Tests::dfs(testSplayTree->getRoot());
	delete(testSplayTree);
	return time;
}

int Graphs::deleteFromCartesian(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	vector<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testCartesianTree->deleteNode(testCartesianTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	graphs.Tests::dfs(testCartesianTree->getRoot());
	delete(testCartesianTree);
	return time;
}

int Graphs::deleteFromRedBlack(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	vector<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testRedBlackTree->deleteNode(nullptr, *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	delete(testRedBlackTree);
	return time;
}

//SEARCH

void Graphs::searchInfo(int start_n, int step_n, int end_n) {
	ofstream infoFile;
	infoFile.open("search.csv");
	vector<vector<int>> results = searchGraph(start_n, step_n, end_n);
	infoFile << "Number of elements;AVL;Splay;Cartesian;Red-Black\n";
	for (int i = 0; i < results[0].size(); i++) {
		infoFile << start_n + i*step_n << ";" << results[0][i] << ";" << results[1][i] << ";" << results[2][i] << ";" << results[3][i] << "\n";
	}
	infoFile.close();
	cout << "Info for search is recieved" << endl;
}

vector<vector<int>> Graphs::searchGraph(int start_n, int step_n, int end_n) {
	vector<vector<int>> results;
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE}) {
		vector<int> result = searchInTree(treeType, start_n, step_n, end_n);
		cout << "done" << endl;
		results.push_back(result);
	}
	return results;
}

vector<int> Graphs::searchInTree(TreeType treeType, int start, int step, int end) {
	switch (treeType) {
	case TreeType::AVL_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(searchAVL(i));
			cout << i << endl;

		}
		return result;
	}
	case TreeType::SPLAY_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(searchSplay(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::CARTESIAN_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(searchCartesian(i));
			cout << i << endl;
		}
		return result;
	}
	case TreeType::RED_BLACK_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(searchRedBlack(i));
			cout << i << endl;
		}
		return result;
	}
	}
}

int Graphs::searchAVL(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	AVLTree* testAVLTree = new AVLTree(tree);
	vector<int> keysToSearch = makeVectorFixedSize(0, size);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testAVLTree->searchNode(testAVLTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	graphs.Tests::dfs(testAVLTree->getRoot());
	delete(testAVLTree);
	return time;
}

int Graphs::searchSplay(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	SplayTree* testSplayTree = new SplayTree(tree);
	vector<int> keysToSearch = makeVectorFixedSize(0, size);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testSplayTree->searchNode(testSplayTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	graphs.Tests::dfs(testSplayTree->getRoot());
	delete(testSplayTree);
	return time;
}

int Graphs::searchCartesian(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	vector<int> keysToSearch = makeVectorFixedSize(0, size);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testCartesianTree->searchNode(testCartesianTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	graphs.Tests::dfs(testCartesianTree->getRoot());
	delete(testCartesianTree);
	return time;
}

int Graphs::searchRedBlack(int size) {
	Graphs graphs;
	vector<int> tree = graphs.Tests::makeVectorFixedSize(0, size);
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	vector<int> keysToSearch = makeVectorFixedSize(0, size);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 10000; i++) {
		auto start = high_resolution_clock::now();
		testRedBlackTree->searchNode(nullptr, *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	delete(testRedBlackTree);
	return time;
}