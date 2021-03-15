#include "StressTests.h"
#include "UnitTests.h"


int main() {
	//StressTests stressTests;
	//stressTests.stressTestInsert(START_N_STRESS, STEP_STRESS, END_N_STRESS, ITERATIONS_NUM_STRESS);
	//stressTests.stressTestDelete(START_N_STRESS, STEP_STRESS, END_N_STRESS, ITERATIONS_NUM_STRESS);
	//stressTests.stressTestSearch(START_N_STRESS, STEP_STRESS, END_N_STRESS, ITERATIONS_NUM_STRESS);
	
	UnitTests unitTests;
	//unitTests.unitTestEmptyTree();
	//unitTests.unitTestNegativeValuesTree();
	unitTests.unitTestOrdinaryTree();

	return 0;
}