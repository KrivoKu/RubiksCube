#pragma once
#include "Solver.h"

class Cross {
public:
	static void solveCross(Solver&, RubiksCube& a);
	static int checkCross(Solver&);
	static void solveEdge(Solver&, RubiksCube& a);
};