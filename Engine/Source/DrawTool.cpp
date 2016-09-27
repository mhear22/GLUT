#include "DrawTool.h"

DrawTool::DrawTool(GLuint program)
{
	Program = program;
	modelIndex = 0;
}

int DrawTool::GetPolyStart(int length)
{
	auto start = modelIndex;
	modelIndex += length;
	return start;
}

GLint DrawTool::GetAttrib(GLchar* glChar)
{
	auto x = glGetAttribLocation(Program, glChar);
	if(x == -1 || !x)
	{
		throw std::runtime_error("Could not find attribute");
	}
	return x;
}

float DrawTool::RandomFloat(float low, float high)
{
	float f = (float) rand() / (float)RAND_MAX;

	return (f * (high - low)) + low;
}
