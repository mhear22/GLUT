#pragma once
#include "header.h"

class DrawTool
{
public:
	DrawTool(GLuint program);
	
	GLint GetAttrib(GLchar* glChar);
	float RandomFloat(float low, float high);
	
private:
	int modelIndex;
	GLuint Program;
};
