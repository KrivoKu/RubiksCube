#pragma once
#include "RubiksCube.h"

#include <iostream>

class Solver {
public:
	int cubies[9][6];
	Solver();
	~Solver() = default;
	std::string printSequence(std::string);
	void moves(std::string, RubiksCube& a);
	void output();
	void Scramble(RubiksCube& a);
	void ReadFile(RubiksCube& a, std::string file);
	void R(int, RubiksCube& a);
	void L(int, RubiksCube& a);
	void U(int, RubiksCube& a);
	void D(int, RubiksCube& a);
	void F(int, RubiksCube& a);
	void B(int, RubiksCube& a);
};