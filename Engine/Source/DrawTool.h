#pragma once
#include "header.h"

class DrawTool
{
public:
	DrawTool(GLuint program);
	
	void draw();
	void LoadDebugWall2D();
	void LoadDebugWall3D();
	
private:
	GLint GetAttrib(GLchar* glChar);
	float RandomFloat(float low, float high);
	GLuint Program;
	GLuint VAO;
	GLuint VBO;
	int _polyStart;
	int _polyEnd;
};