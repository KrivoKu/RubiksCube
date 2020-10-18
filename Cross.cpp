#include "Cross.h"

void Cross::solveCross(Solver& Solver, RubiksCube& a) {
	while (checkCross(Solver)) {
		solveEdge(Solver, a);
	}
}

int Cross::checkCross(Solver& Solver) { //must check if in correct position as well
	if (Solver.cubies[1][0] == 0 && Solver.cubies[3][0] == 0 && Solver.cubies[5][0] == 0 && Solver.cubies[7][0] == 0 && Solver.cubies[7][2] == 2 && Solver.cubies[7][3] == 3 && Solver.cubies[7][4] == 4 && Solver.cubies[7][5] == 5) {
		return 0;
	}
	else
		return 1;
}

void Cross::solveEdge(Solver& Solver, RubiksCube& a) {

	//Check edges on all sides --- don't forget, white can be in wrong position on the bottom
	for (int side = 0; side < 6; ++side) {
		for (int edge = 1; edge < 9; edge += 2) {
			if (Solver.cubies[edge][side] == 0) {
				//Solve edge

				switch (side) {


				case 1: {//White edge on top
					if (edge == 1) { //orange side
						switch (Solver.cubies[1][4]) {
						case 2://red
							Solver.moves("UUFF", a);
							std::cout << "UUFF";
							break;
						case 3://green
							Solver.moves("URR", a);
							std::cout << "URR";
							break;
						case 4:
							Solver.moves("BB", a);
							std::cout << "BB";
							break;
						case 5:
							Solver.moves("UUULL", a);
							std::cout << "UUULL";
							break;
						}
					}
					else if (edge == 3) {//Blue side
						switch (Solver.cubies[1][5]) {
						case 2:
							Solver.moves("UUUFF", a);
							std::cout << "UUUFF";
							break;
						case 3://green
							Solver.moves("UURR", a);
							std::cout << "UURR";
							break;
						case 4:
							Solver.moves("UBB", a);
							std::cout << "UBB";
							break;
						case 5:
							Solver.moves("LL", a);
							std::cout << "LL";
							break;
						}
					}
					else if (edge == 5) {//green side
						switch (Solver.cubies[1][3]) {
						case 2://red
							Solver.moves("UFF", a);
							std::cout << "UFF";
							break;
						case 3:
							Solver.moves("RR", a);
							std::cout << "RR";
							break;
						case 4:
							Solver.moves("UUUBB", a);
							std::cout << "UUUBB";
							break;
						case 5:
							Solver.moves("UULL", a);
							std::cout << "UULL";
							break;
						}
					}
					else if (edge == 7) {//red side
						switch (Solver.cubies[1][2]) {
						case 2:
							Solver.moves("FF", a);
							std::cout << "FF";
							break;
						case 3:
							Solver.moves("UUURR", a);
							std::cout << "UUURR";
							break;
						case 4:
							Solver.moves("UUBB", a);
							std::cout << "UUBB";
							break;
						case 5:
							Solver.moves("ULL", a);
							std::cout << "ULL";
							break;
						}
					}
					break;
				}
				case 2: {//White edge on red side

					if (edge == 1) {//Yellow side
						switch (Solver.cubies[7][1]) {
						case 2:
							Solver.moves("UUURRRFR", a);
							std::cout << "UUURRRFR";
							break;
						case 3://green on top, white on red side
							Solver.moves("FRRRFFF", a);
							std::cout << "FRRRFFF";
							break;
						case 4:
							Solver.moves("UUURBBBRRR", a);
							std::cout << "UUURBBBRRR";
							break;
						case 5:
							Solver.moves("FFFLF", a);
							std::cout << "FFFLF";
							break;
						}
					}
					else if (edge == 3) { //Colored edge on blue side
						switch (Solver.cubies[5][5]) {
						case 2:
							Solver.moves("LDLLL", a);
							std::cout << "LDLLL";
							break;
						case 3:
							Solver.moves("UUFUU", a);
							std::cout << "UUFUU";
							break;
						case 4:
							Solver.moves("LLLULBB", a);
							std::cout << "LLLULBB";
							break;
						case 5:
							Solver.moves("L", a);
							std::cout << "L";
							break;

						}
					}
					else if (edge == 5) { //check color on green side
						switch (Solver.cubies[3][3]) {
						case 2:
							Solver.moves("RRRDDDR", a);
							std::cout << "RRRDDDR";
							break;
						case 3:
							Solver.moves("RRR", a);
							std::cout << "RRR";
							break;
						case 4:
							Solver.moves("RUUURRRBB", a);
							std::cout << "RUUURRRBB";
							break;
						case 5:
							Solver.moves("RUURRRLL", a);
							std::cout << "RUURRRLL";
							break;
						}
					}
					else if (edge == 7) { //check white side
						switch (Solver.cubies[1][0]) {
						case 2:
							Solver.moves("FFFDRRRDDD", a);
							std::cout << "FFFDRRRDDD";
							break;
						case 3:
							Solver.moves("FFFRRR", a);
							std::cout << "FFFRRR";
							break;
						case 4:
							Solver.moves("FFUUURBBBRRR", a);
							std::cout << "FFUUURBBBRRR";
							break;
						case 5:
							Solver.moves("FL", a);
							std::cout << "FL";
							break;
						}
					}

					break;
				}
				case 3: //White edge on green side
					if (edge == 1) {//Yellow side
						switch (Solver.cubies[5][1]) {
						case 2:
							Solver.moves("RRRFR", a);
							break;
						case 3:
							Solver.moves("UFRRRFFF", a);
							break;
						case 4:
							Solver.moves("RBBBRRR", a);
							break;
						case 5:
							Solver.moves("UFFFLF", a);
							break;
						}
					}
					else if (edge == 3) { //Colored edge on red side
						switch (Solver.cubies[5][2]) {
						case 2:
							Solver.moves("F", a);
							break;
						case 3:
							Solver.moves("FFFUUUFRR", a);
							break;
						case 4:
							Solver.moves("RRBBBRR", a);
							break;
						case 5:
							Solver.moves("FFFUFLL", a);
							break;

						}
					}
					else if (edge == 5) { //check color on orange side
						switch (Solver.cubies[3][4]) {
						case 2:
							Solver.moves("RRFRR", a);
							break;
						case 3:
							Solver.moves("BUBBBRR", a);
							break;
						case 4:
							Solver.moves("BBB", a);
							break;
						case 5:
							Solver.moves("RRRUFFFLF", a);
							break;
						}
					}
					else if (edge == 7) { //check white side
						switch (Solver.cubies[5][0]) {
						case 2:
							Solver.moves("RFRRR", a);
							std::cout << "RFRRR";
							break;
						case 3:
							Solver.moves("RRUFRRRFFF", a);
							std::cout << "RRUFRRRFFF";
							break;
						case 4:
							Solver.moves("RRRBBBR", a);
							std::cout << "RRRBBBR";
							break;
						case 5:
							Solver.moves("RRUFFFLF", a);
							std::cout << "RRUFFFLF";
							break;
						}
					}
					break;
				case 4: //White edge on orange side
					if (edge == 1) {//Yellow side
						switch (Solver.cubies[1][1]) {
						case 2:
							Solver.moves("URRRFR", a);
							std::cout << "URRRFR";
							break;
						case 3:
							Solver.moves("BBBRB", a);
							std::cout << "BBBRB";
							break;
						case 4:
							Solver.moves("URBBBRRR", a);
							std::cout << "URBBBRRR";
							break;
						case 5:
							Solver.moves("BLLLBBB", a);
							std::cout << "BLLLBBB";
							break;
						}
					}
					else if (edge == 3) { //Colored edge on green side
						switch (Solver.cubies[5][3]) {
						case 2:
							Solver.moves("RRRURFF", a);
							std::cout << "RRRURFF";
							break;
						case 3:
							Solver.moves("R", a);
							std::cout << "RRRURFF";
							break;
						case 4:
							Solver.moves("RRRUUURBB", a);
							std::cout << "RRRUUURBB";
							break;
						case 5:
							Solver.moves("RRRUURLL", a);
							std::cout << "RRRUURLL";
							break;

						}
					}
					else if (edge == 5) { //check color on blue side
						switch (Solver.cubies[3][5]) {
						case 2:
							Solver.moves("LUUULLLFF", a);
							std::cout << "LUUULLLFF";
							break;
						case 3:
							Solver.moves("LUULLLRR", a);
							std::cout << "LUULLLRR";
							break;
						case 4:
							Solver.moves("LULLLBB", a);
							std::cout << "LULLLBB";
							break;
						case 5:
							Solver.moves("LLL", a);
							std::cout << "LLL";
							break;
						}
					}
					else if (edge == 7) { //check white side
						switch (Solver.cubies[7][0]) {
						case 2:
							Solver.moves("BBURRRFR", a);
							std::cout << "BBURRRFR";
							break;
						case 3:
							Solver.moves("BRBBB", a);
							std::cout << "BRBBB";
							break;
						case 4:
							Solver.moves("BBURBBBRRR", a);
							std::cout << "BBURBBBRRR";
							break;
						case 5:
							Solver.moves("BBBLLLB", a);
							std::cout << "BBBLLLB";
							break;
						}
					}
					break;
				case 5: //White edge on blue side

					if (edge == 1) {//Yellow side
						switch (Solver.cubies[3][1]) {
						case 2:
							Solver.moves("LFLLL", a);
							std::cout << "LFLLL";
							break;
						case 3:
							Solver.moves("UUUFRRRFFF", a);
							std::cout << "UUUFRRRFFF";
							break;
						case 4:
							Solver.moves("LLLBL", a);
							std::cout << "LLLBL";
							break;
						case 5:
							Solver.moves("UUUFFFLF", a);
							std::cout << "UUUFFFLF";
							break;
						}
					}
					else if (edge == 3) { //Colored edge on orange side
						switch (Solver.cubies[5][4]) {
						case 2:
							Solver.moves("LLFFFLL", a);
							std::cout << "LLFFFLL";
							break;
						case 3:
							Solver.moves("LUUUFRRRFFF", a);
							std::cout << "LUUUFRRRFFF";
							break;
						case 4:
							Solver.moves("B", a);
							std::cout << "B";
							break;
						case 5:
							Solver.moves("LUUUFFFLF", a);
							std::cout << "LUUUFFFLF";
							break;

						}
					}
					else if (edge == 5) { //check color on red side
						switch (Solver.cubies[3][2]) {
						case 2:
							Solver.moves("FFF", a);
							std::cout << "FFF";
							break;
						case 3:
							Solver.moves("FUUUFFFRR", a);
							std::cout << "FUUUFFFRR";
							break;
						case 4:
							Solver.moves("FUUFFFBB", a);
							std::cout << "FUUFFFBB";
							break;
						case 5:
							Solver.moves("FUFFFLL", a);
							std::cout << "FUFFFLL";
							break;
						}
					}
					else if (edge == 7) { //check white side
						switch (Solver.cubies[3][0]) {
						case 2:
							Solver.moves("LLLFFFL", a);
							std::cout << "LLLFFFL";
							break;
						case 3:
							Solver.moves("LLUFRRRFFF", a);
							std::cout << "LLUFRRRFFF";
							break;
						case 4:
							Solver.moves("LBLLL", a);
							std::cout << "LBLLL";
							break;
						case 5:
							Solver.moves("LLUFFFLF", a);
							std::cout << "LLUFFFLF";
							break;
						}
					}

					break;

				case 0:
					if (edge == 1) {
						if (Solver.cubies[7][2] != 2) {
							while (Solver.cubies[1][2] == 0 || Solver.cubies[7][1] == 0) {
								Solver.moves("U", a);
								std::cout << "U";
							}
							Solver.moves("FF", a);
							std::cout << "FF";
						}
					}
					else if (edge == 5) {
						if (Solver.cubies[7][3] != 3) {
							while (Solver.cubies[1][3] == 0 || Solver.cubies[5][1] == 0) {
								Solver.moves("U", a);
								std::cout << "U";
							}
							Solver.moves("RR", a);
							std::cout << "RR";
						}
					}
					else if (edge == 7) {
						if (Solver.cubies[7][4] != 4) {
							while (Solver.cubies[1][3] == 0 || Solver.cubies[1][1] == 0) {
								Solver.moves("U", a);
								std::cout << "U";
							}
							Solver.moves("BB", a);
							std::cout << "BB";
						}
					}
					else if (edge == 3) {
						if (Solver.cubies[7][5] != 5) {
							while (Solver.cubies[1][5] == 0 || Solver.cubies[3][1] == 0) {
								Solver.moves("U", a);
								std::cout << "U";
							}
							Solver.moves("LL", a);
							std::cout << "LL";
						}
					}

					break;
				}
			}
		}
	}

}