#pragma once
#include "Solver.h"

class OLL {

public:
	static void solveOLL(Solver&, RubiksCube&);
private:
	static int findState(Solver&); //Rotate U 4 times, check each cube state against file
	static int findEdges(Solver&);
	static void solveCase(Solver&, int, RubiksCube& a);
	static int checkOLL(Solver&);
	static int checkEdges(Solver&);
};
