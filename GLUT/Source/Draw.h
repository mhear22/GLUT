#pragma once

#include <GL/glut.h>


static class Draw
{
public:
	void static Hex(float x, float y, float scale);
	void static Square(float x, float y, float height, float width);
};