#include "Edges.h"

void Edges::solveEdges(Solver& cube, RubiksCube& a) {

	while (!checkEdges(cube)) {
		solveEdge(cube, a);
	}
}

void Edges::solveEdge(Solver& cube, RubiksCube& a) {
	if (cube.cubies[1][1] != 1 && cube.cubies[1][4] != 1) {
		if (cube.cubies[1][1] == 2) {
			if (cube.cubies[1][4] == 3) {
				cube.moves("URRRUUURRRUUURRRURUR", a);
				std::cout << "URRRUUURRRUUURRRURUR";
			}
			else if (cube.cubies[1][4] == 5) {
				cube.moves("BUBUBUUUBBBUUUBBB", a);
				std::cout << "BUBUBUUUBBBUUUBBB";
			}
		}
		else if (cube.cubies[1][1] == 3) {
			if (cube.cubies[1][4] == 4) {
				cube.moves("BBBUUUBBBUUUBBBUBUB", a);
				std::cout << "BBBUUUBBBUUUBBBUBUB";
			}
			else if (cube.cubies[1][4] == 2) {
				cube.moves("UUFUFUFUUUFFFUUUFFF", a);
				std::cout << "BBBUUUBBBUUUBBBUBUB";
			}
		}
		else if (cube.cubies[1][1] == 4) {
			if (cube.cubies[1][4] == 5) {
				cube.moves("UUULLLUUULLLUUULLLULUL", a);
				std::cout << "UUULLLUUULLLUUULLLULUL";
			}
			else if (cube.cubies[1][4] == 3) {
				cube.moves("BBBUUUBBBUUUBBBUBUB", a);
				std::cout << "BBBUUUBBBUUUBBBUBUB";
			}
		}
		else if (cube.cubies[1][1] == 5) {
			if (cube.cubies[1][4] == 2) {
				cube.moves("UUFFFUUUFFFUUUFFFUFUF", a);
				std::cout << "UUFFFUUUFFFUUUFFFUFUF";
			}
			else if (cube.cubies[1][4] == 4) {
				cube.moves("LLLUUULLLUUULLLULUL", a);
				std::cout << "LLLUUULLLUUULLLULUL";
			}
		}
	}

	else if (cube.cubies[5][1] != 1 && cube.cubies[1][3] != 1) {
		if (cube.cubies[5][1] == 2) {
			if (cube.cubies[1][3] == 3) {
				cube.moves("RRRUUURRRUUURRRURUR", a);
				std::cout << "RRRUUURRRUUURRRURUR";
			}
			else if (cube.cubies[1][3] == 5) {
				cube.moves("UULULULUUULLLUUULLL", a);
				std::cout << "UULULULUUULLLUUULLL";
			}
		}
		else if (cube.cubies[5][1] == 3) {
			if (cube.cubies[1][3] == 4) {
				cube.moves("UUUBBBUUUBBBUUUBBBUBUB", a);
				std::cout << "UUUBBBUUUBBBUUUBBBUBUB";
			}
			else if (cube.cubies[1][3] == 2) {
				cube.moves("UFUFUFUUUFFFUUUFFF", a);
				std::cout << "UFUFUFUUUFFFUUUFFF";
			}
		}
		else if (cube.cubies[5][1] == 4) {
			if (cube.cubies[1][3] == 5) {
				cube.moves("UULLLUUULLLUUULLLULUL", a);
				std::cout << "UULLLUUULLLUUULLLULUL";
			}
			else if (cube.cubies[1][3] == 3) {
				cube.moves("RURURUUURRRUUURRR", a);
				std::cout << "RURURUUURRRUUURRR";
			}
		}
		else if (cube.cubies[5][1] == 5) {
			if (cube.cubies[1][3] == 2) {
				cube.moves("UFFFUUUFFFUUUFFFUFUF", a);
				std::cout << "UFFFUUUFFFUUUFFFUFUF";
			}
			else if (cube.cubies[1][3] == 4) {
				cube.moves("UUUBUBUBUUUBBBUUUBBB", a);
				std::cout << "UUUBUBUBUUUBBBUUUBBB";
			}
		}
	}
	else if (cube.cubies[7][1] != 1 && cube.cubies[1][2] != 1) {
		if (cube.cubies[7][1] == 2) {
			if (cube.cubies[1][2] == 3) {
				cube.moves("UUURRRUUURRRUUURRRURUR", a);
				std::cout << "UUURRRUUURRRUUURRRURUR";
			}
			else if (cube.cubies[1][2] == 5) {
				cube.moves("ULULULUUULLLUUULLL", a);
				std::cout << "ULULULUUULLLUUULLL";
			}
		}
		else if (cube.cubies[7][1] == 3) {
			if (cube.cubies[1][2] == 4) {
				cube.moves("UUBBBUUUBBBUUUBBBUBUB", a);
				std::cout << "UUBBBUUUBBBUUUBBBUBUB";
			}
			else if (cube.cubies[1][2] == 2) {
				cube.moves("FUFUFUUUFFFUUUFFF", a);
				std::cout << "FUFUFUUUFFFUUUFFF";
			}
		}
		else if (cube.cubies[7][1] == 4) {
			if (cube.cubies[1][2] == 5) {
				cube.moves("ULLLUUULLLUUULLLULUL", a);
				std::cout << "ULLLUUULLLUUULLLULUL";
			}
			else if (cube.cubies[1][2] == 3) {
				cube.moves("UUURURURUUURRRUUURRR", a);
				std::cout << "UUURURURUUURRRUUURRR";
			}
		}
		else if (cube.cubies[7][1] == 5) {
			if (cube.cubies[1][2] == 2) {
				cube.moves("FFFUUUFFFUUUFFFUFUF", a);
				std::cout << "FFFUUUFFFUUUFFFUFUF";
			}
			else if (cube.cubies[1][2] == 4) {
				cube.moves("UUBUBUBUUUBBBUUUBBB", a);
				std::cout << "UUBUBUBUUUBBBUUUBBB";
			}
		}
	}
	else if (cube.cubies[3][1] != 1 && cube.cubies[1][5] != 1) {
		if (cube.cubies[3][1] == 2) {
			if (cube.cubies[1][5] == 3) {
				cube.moves("UURRRUUURRRUUURRRURUR", a);
				std::cout << "UURRRUUURRRUUURRRURUR";
			}
			else if (cube.cubies[1][5] == 5) {
				cube.moves("LULULUUULLLUUULLL", a);
				std::cout << "LULULUUULLLUUULLL";
			}
		}
		else if (cube.cubies[3][1] == 3) {
			if (cube.cubies[1][5] == 4) {
				cube.moves("UBBBUUUBBBUUUBBBUBUB", a);
				std::cout << "UBBBUUUBBBUUUBBBUBUB";
			}
			else if (cube.cubies[1][5] == 2) {
				cube.moves("UUUFUFUFUUUFFFUUUFFF", a);
				std::cout << "UUUFUFUFUUUFFFUUUFFF";
			}
		}
		else if (cube.cubies[3][1] == 4) {
			if (cube.cubies[1][5] == 5) {
				cube.moves("LLLUUULLLUUULLLULUL", a);
				std::cout << "LLLUUULLLUUULLLULUL";
			}
			else if (cube.cubies[1][5] == 3) {
				cube.moves("UURURURUUURRRUUURRR", a);
				std::cout << "UURURURUUURRRUUURRR";
			}
		}
		else if (cube.cubies[3][1] == 5) {
			if (cube.cubies[1][5] == 2) {
				cube.moves("UUUFFFUUUFFFUUUFFFUFUF", a);
				std::cout << "UUUFFFUUUFFFUUUFFFUFUF";
			}
			else if (cube.cubies[1][5] == 4) {
				cube.moves("UBUBUBUUUBBBUUUBBB", a);
				std::cout << "UBUBUBUUUBBBUUUBBB";
			}
		}
	}
	else if (cube.cubies[3][2] != 2 || cube.cubies[5][5] != 5) {
		cube.moves("LULULUUULLLUUULLL", a);
		std::cout << "LULULUUULLLUUULLL";
	}
	else if (cube.cubies[5][2] != 2 || cube.cubies[3][3] != 3) {
		cube.moves("FUFUFUUUFFFUUUFFF", a);
		std::cout << "FUFUFUUUFFFUUUFFF";
	}
	else if (cube.cubies[5][3] != 3 || cube.cubies[3][4] != 4) {
		cube.moves("RURURUUURRRUUURRR", a);
		std::cout << "RURURUUURRRUUURRR";
	}
	else if (cube.cubies[5][4] != 4 || cube.cubies[3][5] != 5) {
		cube.moves("BUBUBUUUBBBUUUBBB", a);
		std::cout << "BUBUBUUUBBBUUUBBB";
	}


}

int Edges::checkEdges(Solver& cube) {
	if (cube.cubies[3][2] != 2 || cube.cubies[5][2] != 2)
		return 0;
	else if (cube.cubies[3][3] != 3 || cube.cubies[5][3] != 3)
		return 0;
	else if (cube.cubies[3][4] != 4 || cube.cubies[5][4] != 4)
		return 0;
	else if (cube.cubies[3][5] != 5 || cube.cubies[5][5] != 5)
		return 0;
	else
		return 1;
}