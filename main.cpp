#include <iostream>
#include "SmallCube.h"
#include "RubiksCube.h"
#include "Solver.h"
#include "Cross.h"
#include "WhiteCorners.h"
#include "Edges.h"
#include "OLL.h"
#include "PLL.h"

#define M_PI 3.1415

int main() {
	RubiksCube a;
	Solver s;
	Cross k;
	Corners p;
	Edges e;
	OLL oll;
	PLL pll;
	std::string b;
	sf::ContextSettings window_settings;
	window_settings.depthBits = 24;
	window_settings.stencilBits = 8;
	window_settings.antialiasingLevel = 2;
	sf::Window window1(sf::VideoMode(900, 900), "Cube", sf::Style::Close, window_settings);
	float angle;
	float angleX = 0, angleY = 0;
	bool Rotate = false;
	float mousePos[2];
	while (window1.isOpen())
	{
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);
		glClearDepth(1.f);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-350, 350, -350, 350, -350, 350);
		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window1.close();
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				Rotate = true;
				mousePos[0] = event.mouseMove.x;
				mousePos[1] = event.mouseMove.y;
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				Rotate = false;
			}
			if (event.mouseMove.x && Rotate) {
				float RX = (event.mouseMove.x - mousePos[0]) / 2;
				float RY = (event.mouseMove.y - mousePos[1]) / 2;
				angleX += RX;
				angleY += RY;
				mousePos[0] = event.mouseMove.x;
				mousePos[1] = event.mouseMove.y;
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Q)
			{
				s.R(1, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::W)
			{
				s.R(3, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::E)
			{
				s.L(1, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::R)
			{
				s.L(3, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::A)
			{
				s.U(1, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::S)
			{
				s.U(3, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::D)
			{
				s.D(1, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::F)
			{
				s.D(3, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Z)
			{
				s.B(1, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::X)
			{
				s.B(3, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::C)
			{
				s.F(1, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::V)
			{
				s.F(3, a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Y)
			{
				std::cout << "To solve cross, do this moves: ";
				k.solveCross(s, a);
				std::cout << std::endl;
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::U)
			{
				std::cout << "To solve white side, do this moves: ";
				p.solveCorners(s, a);
				std::cout<<std::endl;
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::I)
			{
				std::cout << "To do F2L, do this moves: ";
				e.solveEdges(s, a);
				std::cout << std::endl;
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::O)
			{
				std::cout << "To do yellow layer, do this moves: ";
				oll.solveOLL(s, a);
				std::cout << std::endl;
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::P)
			{
				std::cout << "To solve cube, do this moves: ";
				pll.solvePLL(s, a);
				std::cout << std::endl;
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::J)
			{
				s.Scramble(a);
			}
			if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::B)
			{
				std::cout << "What is file name?";
				std::cin >> b;
				s.ReadFile(a, b);
			}
		}
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0, 0, 0);
		gluLookAt(a.getCenterX() + cos(angleX / 180 * M_PI) * 100 * cos(angleY / 180 * M_PI), a.getCenterY() + sin(angleY / 180 * M_PI) * 100, a.getCenterZ() + sin(angleX / 180 * M_PI) * 100 * cos(angleY / 180 * M_PI), a.getCenterX(), a.getCenterY(), a.getCenterZ(), 0, 1, 0);
		a.Draw();
		window1.display();
	}
	return 0;
}