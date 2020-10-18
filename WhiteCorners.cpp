#include "WhiteCorners.h"

void Corners::solveCorners(Solver& cube, RubiksCube& a) {
	while (checkBottomLayer(cube)) {

		//get a white corner into the top layer

		if (cube.cubies[0][0] == 0 || cube.cubies[6][2] == 0 || cube.cubies[8][5] == 0) {
			while (cube.cubies[6][1] == 0 || cube.cubies[0][2] == 0 || cube.cubies[2][5] == 0) {
				cube.moves("U", a);
				std::cout << "U";
			}
			cube.moves("FUFFF", a);
			std::cout << "FUFFF";

		}
		if (cube.cubies[2][0] == 0 || cube.cubies[8][2] == 0 || cube.cubies[6][3] == 0) {
			while (cube.cubies[8][1] == 0 || cube.cubies[2][2] == 0 || cube.cubies[0][3] == 0) {
				cube.moves("U", a);
				std::cout << "U";
			}
			cube.moves("RURRR", a);
			std::cout << "RURRR";

		}
		if (cube.cubies[6][0] == 0 || cube.cubies[8][4] == 0 || cube.cubies[6][5] == 0) {
			while (cube.cubies[0][1] == 0 || cube.cubies[2][4] == 0 || cube.cubies[0][5] == 0) {
				cube.moves("U", a);
				std::cout << "U";
			}
			cube.moves("LULLL", a);
			std::cout << "LULLL";
		}
		if (cube.cubies[8][0] == 0 || cube.cubies[8][3] == 0 || cube.cubies[6][4] == 0) {
			while (cube.cubies[2][1] == 0 || cube.cubies[2][3] == 0 || cube.cubies[0][4] == 0) {
				cube.moves("U", a);
				std::cout << "U";
			}
			cube.moves("BUBBB", a);
			std::cout << "BUBBB";
		}
	}


	while (checkCorners(cube)) {

		//then perform the alg for the case: RUURRRUUURURRR, RURRR, FFFUUUF

		if (cube.cubies[8][1] == 0) {
			if (cube.cubies[2][2] == 2) { //red and blue
				cube.moves("UFUUFFFUUUFUFFF", a);
				std::cout << "UFUUFFFUUUFUFFF";
			}
			else if (cube.cubies[2][2] == 3) { //green and red
				cube.moves("RUURRRUUURURRR", a);
				std::cout << "RUURRRUUURURRR";
			}
			else if (cube.cubies[2][2] == 4) { //orange and green
				cube.moves("UUUBUUBBBUUUBUBBB", a);
				std::cout << "UUUBUUBBBUUUBUBBB";
			}
			else if (cube.cubies[2][2] == 5) { //orange and blue
				cube.moves("UULUUULLLUULULLL", a);
				std::cout << "UULUUULLLUULULLL";
			}


		}

		else if (cube.cubies[0][3] == 0) {
			if (cube.cubies[2][2] == 2) { //red green
				cube.moves("RURRR", a);
				std::cout << "RURRR";
			}
			else if (cube.cubies[2][2] == 3) { //green orange
				cube.moves("UUUBUBBB", a);
				std::cout << "UUUBUBBB";
			}
			else if (cube.cubies[2][2] == 4) { //orange blue
				cube.moves("UULULLL", a);
				std::cout << "UULULLL";
			}
			else if (cube.cubies[2][2] == 5) { //red blue
				cube.moves("UFUFFF", a);
				std::cout << "UFUFFF";
			}
		}

		else if (cube.cubies[2][2] == 0) {
			if (cube.cubies[0][3] == 2) { //blue red
				cube.moves("ULLLUUUL", a);
				std::cout << "ULLLUUUL";
			}
			else if (cube.cubies[0][3] == 3) { //red green
				cube.moves("FFFUUUF", a);
				std::cout << "FFFUUUF";
			}
			else if (cube.cubies[0][3] == 4) { //orange green
				cube.moves("URRRUUUR", a);
				std::cout << "URRRUUUR";
			}
			else if (cube.cubies[0][3] == 5) { //orange blue
				cube.moves("UUBBBUUUB", a);
				std::cout << "UUBBBUUUB";
			}

		}
		else {
			cube.moves("U", a);
			std::cout << "U";
		}

	}
}

int Corners::checkCorners(Solver& cube) {
	if (!cube.cubies[0][0] && !cube.cubies[2][0] && !cube.cubies[6][0] && !cube.cubies[8][0]) {

		return 0;
	}
	else {
		return 1;
	}
}

int Corners::checkBottomLayer(Solver& cube) {
	if (cube.cubies[0][0] && cube.cubies[2][0] && cube.cubies[6][0] && cube.cubies[8][0]
		&& cube.cubies[6][2] && cube.cubies[8][2] && cube.cubies[6][3] && cube.cubies[8][3]
		&& cube.cubies[6][4] && cube.cubies[8][4] && cube.cubies[6][5] && cube.cubies[8][5]) {

		return 0;
	}

	else if (!cube.cubies[0][0] && !cube.cubies[2][0] && !cube.cubies[6][0] && !cube.cubies[8][0]) {
		return 0;
	}

	else {
		return 1;
	}
}