#include "Graphs.h"

//INSERT
void Graphs::insertInfo(int start_n, int step_n, int end_n) {
	ofstream infoFile;
	infoFile.open("insert.csv");
	vector<vector<int>> results = insertGraph(start_n, step_n, end_n);
	infoFile << "AVL;Cartesian;Red-Black\n";
	for (int i = 0; i < results[0].size(); i++) {
		//infoFile << start_n + i * step_n << ";" << results[0][i] << ";" << results[1][i] << ";" << results[2][i] << ";" << results[3][i] << "\n";
		infoFile << start_n + i * step_n << ";" << results[0][i] << ";" << results[1][i] << ";" << results[2][i] << "\n";
	}
	infoFile.close();
	cout << "Info for insert is recieved" << endl;
}

vector<vector<int>> Graphs::insertGraph(int start_n, int step_n, int end_n) {
	vector<vector<int>> results;
	//for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE}) {
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE}) {
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
		}
		return result;
	}
	case TreeType::SPLAY_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(insertToSplay(i));
		}
		return result;
	}
	case TreeType::CARTESIAN_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(insertToCartesian(i));
		}
		return result;
	}
	case TreeType::RED_BLACK_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(insertToRedBlack(i));
		}
		return result;
	}
	}
}

int Graphs::insertToAVL(int size) {
	Graphs graphs;
	int time_sum = 0;
	for (int i = 0; i < 10; i++) {
		set<int> tree = graphs.Tests::makeSetFixedSize(size);
		AVLTree* testAVLTree = new AVLTree(tree);
		set<int> keysToInsert = graphs.Tests::makeSetFixedSize(1000);
		int time = 0;
		cout << size << endl;
		for (int key : keysToInsert) {
			auto start = high_resolution_clock::now();
			testAVLTree->insertNode(testAVLTree->getRoot(), key);
			auto stop = high_resolution_clock::now();
			time += duration_cast<microseconds>(stop - start).count();
		}
		time += time_sum / 1000;
	}
	return time_sum/10;
}

int Graphs::insertToSplay(int size) {
	Graphs graphs;
	int time_sum = 0;
	for (int i = 0; i < 10; i++) {
		set<int> tree = graphs.Tests::makeSetFixedSize(size);
		SplayTree* testSplayTree = new SplayTree(tree);
		set<int> keysToInsert = graphs.Tests::makeSetFixedSize(1000);
		int time = 0; 
		cout << size << endl;
		for (int key : keysToInsert) {
			auto start = high_resolution_clock::now();
			testSplayTree->insertNode(testSplayTree->getRoot(), key);
			auto stop = high_resolution_clock::now();
			time += duration_cast<microseconds>(stop - start).count();
		}
		time += time_sum / 1000;
	}
	return time_sum/10;
}

int Graphs::insertToRedBlack(int size) {
	Graphs graphs;
	int time_sum = 0;
	for (int i = 0; i < 10; i++) {
		set<int> tree = graphs.Tests::makeSetFixedSize(size);
		RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
		set<int> keysToInsert = graphs.Tests::makeSetFixedSize(1000);
		int time = 0;
		cout << size << endl;
		for (int key : keysToInsert) {
			auto start = high_resolution_clock::now();
			testRedBlackTree->insertNode(nullptr, key);
			auto stop = high_resolution_clock::now();
			time += duration_cast<microseconds>(stop - start).count();
		}
		time_sum += time / 1000;
	}
	return time_sum /10;
}

int Graphs::insertToCartesian(int size) {
	Graphs graphs;
	int time_sum = 0;
	for (int i = 0; i < 10; i++) {
		set<int> tree = graphs.Tests::makeSetFixedSize(size);
		CartesianTree* testCartesianTree = new CartesianTree(tree);
		set<int> keysToInsert = graphs.Tests::makeSetFixedSize(1000);
		int time = 0;
		cout << size << endl;
		for (int key : keysToInsert) {
			if (tree.find(key) == tree.end()) {
				auto start = high_resolution_clock::now();
				testCartesianTree->insertNode(testCartesianTree->getRoot(), key);
				auto stop = high_resolution_clock::now();
				time += duration_cast<microseconds>(stop - start).count();
			}
		}
		time_sum += time/1000;
	}
	return time_sum /10;
}

//DELETE
void Graphs::deleteInfo(int start_n, int step_n, int end_n) {
	ofstream infoFile;
	infoFile.open("delete.csv");
	vector<vector<int>> results = deleteGraph(start_n, step_n, end_n);
	infoFile << "AVL;Splay;Cartesian;Red-Black\n";
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
		}
		return result;
	}
	case TreeType::SPLAY_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(deleteFromSplay(i));
		}
		return result;
	}
	case TreeType::CARTESIAN_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(deleteFromCartesian(i));
		}
		return result;
	}
	case TreeType::RED_BLACK_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(deleteFromRedBlack(i));
		}
		return result;
	}
	}
}

int Graphs::deleteFromAVL(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	AVLTree* testAVLTree = new AVLTree(tree);
	set<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testAVLTree->deleteNode(testAVLTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
}

int Graphs::deleteFromSplay(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	SplayTree* testSplayTree = new SplayTree(tree);
	set<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testSplayTree->deleteNode(testSplayTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
}

int Graphs::deleteFromCartesian(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	set<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testCartesianTree->deleteNode(testCartesianTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
}

int Graphs::deleteFromRedBlack(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	set<int> keysToDelete = tree;
	auto iterator = keysToDelete.begin();
	int time = 0;
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testRedBlackTree->deleteNode(nullptr, *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
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
		}
		return result;
	}
	case TreeType::SPLAY_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(searchSplay(i));
		}
		return result;
	}
	case TreeType::CARTESIAN_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(searchCartesian(i));
		}
		return result;
	}
	case TreeType::RED_BLACK_TREE: {
		vector<int> result;
		for (int i = start; i < end; i += step) {
			result.push_back(searchRedBlack(i));
		}
		return result;
	}
	}
}

int Graphs::searchAVL(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	AVLTree* testAVLTree = new AVLTree(tree);
	set<int> keysToSearch = makeSetFixedSize(100);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testAVLTree->searchNode(testAVLTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
}

int Graphs::searchSplay(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	SplayTree* testSplayTree = new SplayTree(tree);
	set<int> keysToSearch = makeSetFixedSize(100);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testSplayTree->searchNode(testSplayTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
}

int Graphs::searchCartesian(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	CartesianTree* testCartesianTree = new CartesianTree(tree);
	set<int> keysToSearch = makeSetFixedSize(100);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testCartesianTree->searchNode(testCartesianTree->getRoot(), *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
}

int Graphs::searchRedBlack(int size) {
	Graphs graphs;
	set<int> tree = graphs.Tests::makeSetFixedSize(size);
	RedBlackTree* testRedBlackTree = new RedBlackTree(tree);
	set<int> keysToSearch = makeSetFixedSize(100);
	int time = 0;
	auto iterator = keysToSearch.begin();
	for (int i = 0; i < 100; i++) {
		auto start = high_resolution_clock::now();
		testRedBlackTree->searchNode(nullptr, *iterator);
		auto stop = high_resolution_clock::now();
		time += duration_cast<microseconds>(stop - start).count();
		iterator++;
	}
	return time / 10;
}