#include "DrawTool.h"

DrawTool::DrawTool(GLuint program)
{
	Program = program;
}

void DrawTool::LoadDebugWall3D()
{
	VAO = 0;
	VBO = 0;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	GLfloat Vertex[]
	{
		-0.8f, 0.8f, 0.8f,
		-0.8f,-0.8f, 0.8f,
		0.8f,-0.8f, 0.8f,

		-0.8f, 0.8f, 0.8f,
		0.8f,-0.8f, 0.8f,
		0.8f, 0.8f, 0.8f,


		-0.8f, 0.8f, -0.8f,
		-0.8f,-0.8f, -0.8f,
		0.8f,-0.8f, -0.8f,

		-0.8f, 0.8f, -0.8f,
		0.8f,-0.8f, -0.8f,
		0.8f, 0.8f, -0.8f,

	};

	_polyStart = 0;
	_polyEnd = sizeof(Vertex) / sizeof(Vertex[0]) * 3;


	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex), Vertex, GL_STATIC_DRAW);
	glEnableVertexAttribArray(GetAttrib((GLchar *)"vert"));
	glVertexAttribPointer(GetAttrib((GLchar *)"vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}



void DrawTool::draw()
{
	
	glBindVertexArray(VAO);
	//link this to the class better
	glDrawArrays(GL_TRIANGLES, _polyStart, _polyEnd);
	glBindVertexArray(0);
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