#pragma once

#include "Tests.h"

#define START_N 10
#define STEP 5
#define END_N 20
#define ITERATIONS_NUM 1


class StressTests: public Tests {
public: 
	bool stressTestInsert(int, int, int, int);
	bool stressTestDelete(int, int, int, int);
	bool stressTestSearch(int, int, int, int);
private:
	bool stressTestInsertToTree(TreeType, int, int, int, int);
	bool stressTestDeleteFromTree(TreeType, int, int, int, int);
	bool stressTestSearchInTree(TreeType, int, int, int, int);
};