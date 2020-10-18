#pragma once
#include <iostream>
#include "RubiksCube.h"

#define M_PI 3.1415

double angle = 2;

RubiksCube::RubiksCube()
{
	a[0][0][0] = SmallCube();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			{
				if (i == 0 && k == 0 && j == 0)
					continue;
				a[i][j][k] = SmallCube(a[0][0][0].getSize(), (2 * a[0][0][0].getSize() + 1) * i, (2 * a[0][0][0].getSize() + 1) * j, (2 * a[0][0][0].getSize() + 1) * k);
			}
	size_ = a[0][0][0].getSize() * 6 + 3;
	centerX = size_ / 2 + 1.5;
	centerY = size_ / 2 + 1.5;
	centerZ = size_ / 2 + 1.5;
}

RubiksCube::RubiksCube(const RubiksCube& Cube)
{
	size_ = Cube.size_;
	centerX = Cube.centerX;
	centerY = Cube.centerY;
	centerZ = Cube.centerZ;
}

double RubiksCube::getCenterX()
{
	return centerX;
}

double RubiksCube::getCenterY()
{
	return centerY;
}

double RubiksCube::getCenterZ()
{
	return centerZ;
}

void RubiksCube::Draw()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			{
				a[i][j][k].Draw(a[i][j][k].getX(), a[i][j][k].getY(), a[i][j][k].getZ());
			}
}


void RubiksCube::SwitchColors(int face, bool clockwise)
{
	int k;
	if (clockwise)
		k = 1;
	else
		k = 3;
	while (k--)
	{
		if (face == 1 || face == 0)
		{
			int p = (face % 2) * 2;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Rotate[j][2 - i] = a[i][j][p];
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Rotate[i][j].SwitchColorsZ();
					for (int c = 0; c < 6; c++)
						a[i][j][p].SetColor(c, Rotate[i][j].getColor(c));
				}
			}
		}
		else if (face == 2 || face == 3)
		{
			int j = (face % 2) * 2;
			for (int i = 0; i < 3; i++)
				for (int k = 0; k < 3; k++)
					Rotate[k][2 - i] = a[i][j][k];
			for (int i = 0; i < 3; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					Rotate[i][k].SwitchColorsY();
					for (int c = 0; c < 6; c++)
						a[i][j][k].SetColor(c, Rotate[i][k].getColor(c));
				}
			}
		}
		else if (face == 4 || face == 5)
		{
			int i = (face % 2) * 2;
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					Rotate[k][2 - j] = a[i][j][k];
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					Rotate[j][k].SwitchColorsX();
					for (int c = 0; c < 6; c++)
						a[i][j][k].SetColor(c, Rotate[j][k].getColor(c));
				}
			}
		}
	}
}