#pragma once

#include "Tests.h"

#define START_N_STRESS 10000
#define STEP_STRESS 10000
#define END_N_STRESS 10000001
#define ITERATIONS_NUM_STRESS 10


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