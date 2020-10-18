#pragma once
#include "SmallCube.h"

class RubiksCube {
public:
	RubiksCube();
	RubiksCube(const RubiksCube&);
	~RubiksCube() = default;
	double getCenterX();
	double getCenterY();
	double getCenterZ();
	void Draw();
	void SwitchColors(int, bool);
private:
	SmallCube a[3][3][3];
	SmallCube Rotate[3][3];
	double size_;
	double centerX;
	double centerY;
	double centerZ;
};