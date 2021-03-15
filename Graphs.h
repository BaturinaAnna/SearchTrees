#pragma once

#include <chrono> 
#include <iostream>
#include <fstream>
#include "Tests.h"

using namespace std::chrono;


class Graphs: public Tests {
public:
	void insertInfo(int, int, int);
	void deleteInfo(int, int, int);
	void searchInfo(int, int, int);
private:
	vector<vector<int>> insertGraph(int, int, int);
	vector<vector<int>> deleteGraph(int, int, int);
	vector<vector<int>> searchGraph(int, int, int);
	vector<int> insertToTree(TreeType, int, int, int);
	vector<int> deleteFromTree(TreeType, int, int, int);
	vector<int> searchInTree(TreeType, int, int, int);
	int insertToAVL(int);
	int insertToSplay(int);
	int insertToRedBlack(int);
	int insertToCartesian(int);
	int deleteFromAVL(int);
	int deleteFromSplay(int);
	int deleteFromCartesian(int);
	int deleteFromRedBlack(int);
	int searchAVL(int);
	int searchSplay(int);
	int searchCartesian(int);
	int searchRedBlack(int);
};
