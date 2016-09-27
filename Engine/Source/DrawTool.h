#pragma once
#include "header.h"

class DrawTool
{
public:
	DrawTool(GLuint program);
	
	GLint GetAttrib(GLchar* glChar);
	float RandomFloat(float low, float high);
	int GetPolyStart(int length);
	
private:
	int modelIndex;
	GLuint Program;
};
