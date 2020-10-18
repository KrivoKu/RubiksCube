#include "SmallCube.h"

SmallCube::SmallCube()
{
	size_ = 30;
	x_ = 0;
	y_ = 0;
	z_ = 0;
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	colors[4] = sf::Color::White;
	colors[5] = sf::Color::Yellow;
	colors[0] = sf::Color::Green;
	colors[1] = sf::Color::Cyan;
	colors[2] = sf::Color::Red;
	colors[3] = sf::Color::Magenta;
}

SmallCube::SmallCube(double size, double x, double y, double z)
{
	size_ = size;
	x_ = x;
	y_ = y;
	z_ = z;
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	colors[4] = sf::Color::White;
	colors[5] = sf::Color::Yellow;
	colors[0] = sf::Color::Green;
	colors[1] = sf::Color::Cyan;
	colors[2] = sf::Color::Red;
	colors[3] = sf::Color::Magenta;
}

SmallCube::SmallCube(const SmallCube& Cube)
{
	size_ = Cube.size_;
	x_ = Cube.x_;
	y_ = Cube.y_;
	z_ = Cube.z_;
	colors[0] = Cube.colors[0];
	colors[1] = Cube.colors[1];
	colors[2] = Cube.colors[2];
	colors[3] = Cube.colors[3];
	colors[4] = Cube.colors[4];
	colors[5] = Cube.colors[5];
}

double SmallCube::getX()
{
	return x_;
}

double SmallCube::getY()
{
	return y_;
}

double SmallCube::getZ()
{
	return z_;
}

double SmallCube::getSize()
{
	return size_;
}

void SmallCube::Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3ub(colors[0].r, colors[0].g, colors[0].b);
	glNormal3f(0, 0, 1);
	glVertex3f(-size_, -size_, -size_);
	glVertex3f(size_, -size_, -size_);
	glVertex3f(size_, size_, -size_);
	glVertex3f(-size_, size_, -size_);
	glColor3ub(colors[1].r, colors[1].g, colors[1].b);
	glNormal3f(0, 0, -1);
	glVertex3f(size_, -size_, size_);
	glVertex3f(-size_, -size_, size_);
	glVertex3f(-size_, size_, size_);
	glVertex3f(size_, size_, size_);

	glColor3ub(colors[2].r, colors[2].g, colors[2].b);
	glNormal3f(-1, 0, 0);
	glVertex3f(-size_, -size_, size_);
	glVertex3f(-size_, -size_, -size_);
	glVertex3f(-size_, size_, -size_);
	glVertex3f(-size_, size_, size_);

	glColor3ub(colors[3].r, colors[3].g, colors[3].b);
	glNormal3f(1, 0, 0);
	glVertex3f(size_, -size_, -size_);
	glVertex3f(size_, -size_, size_);
	glVertex3f(size_, size_, size_);
	glVertex3f(size_, size_, -size_);

	glColor3ub(colors[4].r, colors[4].g, colors[4].b);
	glNormal3f(0, 1, 0);
	glVertex3f(-size_, -size_, size_);
	glVertex3f(size_, -size_, size_);
	glVertex3f(size_, -size_, -size_);
	glVertex3f(-size_, -size_, -size_);

	glColor3ub(colors[5].r, colors[5].g, colors[5].b);
	glNormal3f(0, -1, 0);
	glVertex3f(-size_, size_, -size_);
	glVertex3f(size_, size_, -size_);
	glVertex3f(size_, size_, size_);
	glVertex3f(-size_, size_, size_);

	glEnd();
	glPopMatrix();
}

void SmallCube::Draw(double x, double y, double z)
{
	SetPos(x, y, z);
	glTranslatef(x_, y_, z_);
	Draw();
	glTranslatef(-x_, -y_, -z_);
}

void SmallCube::SwitchColorsY()
{
	sf::Color temp = colors[2];
	colors[2] = colors[0];
	colors[0] = colors[3];
	colors[3] = colors[1];
	colors[1] = temp;
}

void SmallCube::SwitchColorsZ()
{
	sf::Color temp = colors[5];
	colors[5] = colors[2];
	colors[2] = colors[4];
	colors[4] = colors[3];
	colors[3] = temp;
}

void SmallCube::SwitchColorsX()
{
	sf::Color temp = colors[0];
	colors[0] = colors[5];
	colors[5] = colors[1];
	colors[1] = colors[4];
	colors[4] = temp;
}

void SmallCube::SetPos(double x, double y, double z)
{
	x_ = x;
	y_ = y;
	z_ = z;
}

sf::Color SmallCube::getColor(int i)
{
	return colors[i];
}

void SmallCube::SetColor(int i, sf::Color a)
{
	colors[i] = a;
}