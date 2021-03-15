#include "StressTests.h"


map<TreeType, string> TreeName = { {TreeType::AVL_TREE, "AVL trees"},
									{TreeType::SPLAY_TREE, "Splay trees"},
									{TreeType::CARTESIAN_TREE, "Cartesian trees"},
									{TreeType::RED_BLACK_TREE, "Red-Black trees"} };

bool StressTests::stressTestInsert(int start_n, int step_n, int end_n, int iterations_num) {
	bool result = true;
	for (TreeType treeType : {TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE})
		result = result & stressTestInsertToTree(treeType, start_n, step_n, end_n, iterations_num);
	return result;
}

bool StressTests::stressTestDelete(int start_n, int step_n, int end_n, int iterations_num) {
	bool result = true;
	for (TreeType treeType : { TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE})
		result = result & stressTestDeleteFromTree(treeType, start_n, step_n, end_n, iterations_num);
	return result;
}

bool StressTests::stressTestSearch(int start_n, int step_n, int end_n, int iterations_num) {
	bool result = true;
	for (TreeType treeType : { TreeType::AVL_TREE, TreeType::SPLAY_TREE, TreeType::CARTESIAN_TREE, TreeType::RED_BLACK_TREE})
		result = result & stressTestSearchInTree(treeType, start_n, step_n, end_n, iterations_num);
	return result;
}

// INSERT

bool StressTests::stressTestInsertToTree(TreeType treeType, int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	StressTests stressTests;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			set<int> keysToInsert = makeSetFixedSize(size);
			passed = passed & stressTests.Tests::insertToTree(treeType, tree, keysToInsert);
		}
	}
	if (passed == true) {
		cout << "All insert tests for " << TreeName[treeType] << " are passed" << endl;
		return true;
	}
	cout << "Insert tests for " << TreeName[treeType] << " are failed" << endl;
	return false;
}



// DELETE

bool StressTests::stressTestDeleteFromTree(TreeType treeType, int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	StressTests stressTests;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			passed = passed & stressTests.Tests::deleteFromTree(treeType, tree);
		}
	}
	if (passed == true) {
		cout << "All delete tests for " << TreeName[treeType] << " are passed" << endl;
		return true;
	}
	cout << "Delete tests for " << TreeName[treeType] << " are failed" << endl;
	return false;
}


// SEARCH

bool StressTests::stressTestSearchInTree(TreeType treeType, int start_n, int step_n, int end_n, int iterations_num) {
	bool passed = true;
	StressTests stressTests;
	for (int i = 0; i < iterations_num; i++) {
		for (int size = start_n; size <= end_n; size += step_n) {
			set<int> tree = makeSetFixedSize(size);
			set<int> keysToSearch = makeSetFixedSize(3 * size);
			passed = passed & stressTests.Tests::searchInTree(treeType, tree, keysToSearch);
		}
	}
	if (passed == true) {
		cout << "All search tests for " << TreeName[treeType] << " trees are passed" << endl;
		return true;
	}
	cout << "Search tests for " << TreeName[treeType] << " trees are failed" << endl;
	return false;
}