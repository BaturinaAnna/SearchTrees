#include "StressTests.h"


int main() {
	StressTests stressTests;
	stressTests.stressTestInsert(START_N, STEP, END_N, ITERATIONS_NUM);
	//stressTests.stressTestDelete(START_N, STEP, END_N, ITERATIONS_NUM);
	//stressTests.stressTestSearch(START_N, STEP, END_N, ITERATIONS_NUM);
	
	return 0;
}