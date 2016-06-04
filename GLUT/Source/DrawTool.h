#pragma once
#include "header.h"

class DrawTool
{
public:
	DrawTool(GLuint program);
	DrawTool();
	
	void DebugWall2D();
	void LoadDebugWall2D();
	
	void TriangleWall();
	void DebugWall3D();
	
	GLint GetAttrib(GLchar* glChar);
private:
	float RandomFloat(float low, float high);
	GLuint Program;
	GLuint VAO;
	GLuint VBO;
};