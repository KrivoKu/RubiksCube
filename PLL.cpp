#include "PLL.h"

void PLL::solvePLL(Solver& cube, RubiksCube& a) {
	adjustUFace(cube, a);
	while (!checkCorners(cube, a)) {
		solveCorners(cube, a);
		adjustUFace(cube, a);
	}

	while (!checkEdges(cube, a)) {
		solveEdges(cube, a);
	}
}

void PLL::adjustUFace(Solver& cube, RubiksCube& a) {
	while (cube.cubies[2][5] != 5 || cube.cubies[0][2] != 2) {
		cube.moves("U", a);
		std::cout << "U";
	}
}

void PLL::solveEdges(Solver& cube, RubiksCube& a) {
	if (cube.cubies[1][2] == 5 && cube.cubies[1][3] == 2 && cube.cubies[1][4] == 4 && cube.cubies[1][5] == 3) {
		cube.moves("RRURURRRUUURRRUUURRRURRR", a);
		std::cout << "RRURURRRUUURRRUUURRRURRR";
	}
	else if (cube.cubies[1][2] == 3 && cube.cubies[1][3] == 5 && cube.cubies[1][4] == 4 && cube.cubies[1][5] == 2) {
		cube.moves("RUUURURURUUURRRUUURR", a);
		std::cout << "RUUURURURUUURRRUUURR";
	}
	else if (cube.cubies[1][2] == 4 && cube.cubies[1][3] == 5 && cube.cubies[1][4] == 2 && cube.cubies[1][5] == 3) {
		cube.moves("RRLLDRRLLUURRLLDRRLL", a);
		std::cout << "RRLLDRRLLUURRLLDRRLL";
	}
	else if (cube.cubies[1][2] == 3 && cube.cubies[1][3] == 2 && cube.cubies[1][4] == 5 && cube.cubies[1][5] == 4) {
		cube.moves("URRRUUURUUURURUUURRRURURRUUURRRU", a);
		std::cout << "URRRUUURUUURURUUURRRURURRUUURRRU";
	}
	else {
		cube.moves("RRURURRRUUURRRUUURRRURRR", a);
		std::cout << "RRURURRRUUURRRUUURRRURRR";
		adjustUFace(cube, a);
		cube.moves("RRLLDRRLLUURRLLDRRLL", a);
		std::cout << "RRLLDRRLLUURRLLDRRLL";
		cube.moves("RRURURRRUUURRRUUURRRURRR", a);
		std::cout<< "RRURURRRUUURRRUUURRRURRR";
		adjustUFace(cube, a);
	}
}

void PLL::solveCorners(Solver& cube, RubiksCube& a) {
	if (cube.cubies[2][2] == 4 && cube.cubies[0][3] == 5 && cube.cubies[2][3] == 2
		&& cube.cubies[0][4] == 3 && cube.cubies[2][4] == 3 && cube.cubies[0][5] == 4) {
		cube.moves("RRRFRRRBBRFFFRRRBBRR", a);
		std::cout << "RRRFRRRBBRFFFRRRBBRR";
	}
	else if (cube.cubies[2][2] == 4 && cube.cubies[0][3] == 5 && cube.cubies[2][3] == 3
		&& cube.cubies[0][4] == 4 && cube.cubies[2][4] == 2 && cube.cubies[0][5] == 3) {
		cube.moves("RBBBRRRFRBRRRFFLLLBLFLLLBBBL", a);
		std::cout << "RBBBRRRFRBRRRFFLLLBLFLLLBBBL";
	}
	else {
		cube.moves("RRRFRRRBBRFFFRRRBBRR", a);
		std::cout << "RRRFRRRBBRFFFRRRBBRR";
	}
}

int PLL::checkCorners(Solver& cube, RubiksCube& a) {
	if (cube.cubies[0][2] != 2 || cube.cubies[2][2] != 2 || cube.cubies[0][3] != 3 || cube.cubies[2][3] != 3 || cube.cubies[0][4] != 4 || cube.cubies[2][4] != 4 || cube.cubies[0][5] != 5 || cube.cubies[2][5] != 5) {
		return 0;
	}
	else
		return 1;
}

int PLL::checkEdges(Solver& cube, RubiksCube& a) {
	if (cube.cubies[1][2] == 2 && cube.cubies[1][3] == 3 && cube.cubies[1][4] == 4 && cube.cubies[1][5] == 5) {
		return 1;
	}
	else {
		return 0;
	}
}