#include "TestModel.h"

TestModel::TestModel()
{
	_polyStart = 0;
	_polyEnd = 0;
}

void TestModel::Load(DrawTool* tool)
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

	int length = sizeof(Vertex) / sizeof(Vertex[0]) * 3;
	_polyStart = 0;
	_polyEnd = _polyStart + length;
	
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex), Vertex, GL_STATIC_DRAW);
	glEnableVertexAttribArray(tool->GetAttrib((GLchar *)"vert"));
	glVertexAttribPointer(tool->GetAttrib((GLchar *)"vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void TestModel::Draw(DrawTool* tool)
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, _polyStart, _polyEnd);
	glBindVertexArray(0);
}
