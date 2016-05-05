#pragma once

#include <GL/glut.h>
#include <string>
#include <time.h>
#include <random>
#include <math.h>

class Draw
{
public:
	void static TriangleWall();
	void static Hex(float x, float y, float scale);
	void static Square(float x, float y, float height, float width);
	void static Text(float x, float y, std::string text);

private:
	float static RandomFloat(float low, float high);
};