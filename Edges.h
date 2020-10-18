#pragma once
#include "Solver.h"
class Edges {
public:
	static void solveEdges(Solver& cube, RubiksCube& a);
private:
	static void solveEdge(Solver& cube, RubiksCube& a);
	static int checkEdges(Solver& cube);
};