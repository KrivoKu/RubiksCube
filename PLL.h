#pragma once
#include "Solver.h"

class PLL {

public:
	static void solvePLL(Solver&, RubiksCube&);
	static void adjustUFace(Solver&, RubiksCube&);
	static void solveCorners(Solver&, RubiksCube&);
	static int checkCorners(Solver&, RubiksCube&);
	static int checkEdges(Solver&, RubiksCube&);
	static void solveEdges(Solver&, RubiksCube&);
};