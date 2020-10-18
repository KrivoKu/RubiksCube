#pragma once
#include "Solver.h"

class Corners {

public:
	static void solveCorners(Solver&, RubiksCube& a);
private:
	static int checkCorners(Solver&);
	static int checkBottomLayer(Solver& cube);
};
