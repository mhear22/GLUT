#include "header.h"

class DrawTool
{
public:
	DrawTool(GLuint program);
	DrawTool();
	
	void TriangleWall();
	void TriangleWall(int points);
	void DebugWall2D();
	void DebugWall3D();
	void Hex(float x, float y, float scale);
	void Square(float x, float y, float height, float width);
	void Camera();
	
	GLint GetAttrib(GLchar* glChar);
private:
	float RandomFloat(float low, float high);
	GLuint Program;
};