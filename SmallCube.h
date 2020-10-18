#pragma once
#pragma comment(lib,"glu32.lib")
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GLU.h>


class SmallCube {
public:
	SmallCube();
	SmallCube(const SmallCube&);
	SmallCube(double, double, double, double);
	~SmallCube() = default;
	double getX();
	double getY();
	double getZ();
	double getSize();
	void Draw();
	void Draw(double, double, double);
	void SwitchColorsX();
	void SwitchColorsY();
	void SwitchColorsZ();
	void SetPos(double, double, double);
	void SetColor(int i, sf::Color a);
	sf::Color getColor(int i);
private:
	double angleX, angleY, angleZ;
	double x_, y_, z_;
	sf::Color colors[6];
	double size_;
};