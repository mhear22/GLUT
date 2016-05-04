#pragma once

#include <GL/glut.h>
#include <string>

class Draw
{
public:
	void static Hex(float x, float y, float scale);
	void static Square(float x, float y, float height, float width);
	void static Text(float x, float y, std::string text);
};