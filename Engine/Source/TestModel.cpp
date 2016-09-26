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
	
	_polyStart = 0;
	_polyEnd = sizeof(Vertex) / sizeof(Vertex[0]) * 3;
	
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex), Vertex, GL_STATIC_DRAW);
	glEnableVertexAttribArray(tool->GetAttrib((GLchar *)"vert"));
	glVertexAttribPointer(tool->GetAttrib((GLchar *)"vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void TestModel::Draw(DrawTool* tool)
{
	glBindVertexArray(VAO);
	//link this to the class better
	glDrawArrays(GL_TRIANGLES, _polyStart, _polyEnd);
	glBindVertexArray(0);
}
