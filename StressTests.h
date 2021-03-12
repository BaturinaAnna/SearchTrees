#pragma once

#include "RedBlackTree.h"
#include "AVLTree.h"
#include "CartesianTree.h"
#include "SplayTree.h"

#define START_N 10
#define STEP 5
#define END_N 20
#define ITERATIONS_NUM 1


set<int> makeSetFixedSize(int);
bool stressTestInsertAVL(int, int, int, int);
bool stressTestInsertSplay(int, int, int, int);
bool stressTestInsertCartesian(int, int, int, int);
bool stressTestInsertRedBlack(int, int, int, int);
bool stressTestDeleteAVL(int, int, int, int);
bool stressTestDeleteSplay(int, int, int, int);
bool stressTestDeleteCartesian(int, int, int, int);
bool stressTestDeleteRedBlack(int, int, int, int);
bool stressTestSearchAVL(int, int, int, int);
bool stressTestSearchSplay(int, int, int, int);
bool stressTestSearchCartesian(int, int, int, int);
bool stressTestSearchRedBlack(int, int, int, int);