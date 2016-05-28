#include "DrawTool.h"

DrawTool::DrawTool(GLuint program)
{
	Program = program;
	
	
}

void DrawTool::Square(float x, float y, float width, float height)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);

	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
	glEnd();
}

static clock_t lastClock = clock() + 1000;
static float vertex[3][3][2] = {
									{{-1,-1},{-1,0},{-1,1}},
									{{ 0,-1},{0, 0},{0, 1}},
									{{ 1,-1},{1, 0},{1, 1}}
								};
static float centre[2] = {0,0};

void DrawTool::TriangleWall()
{
	if(lastClock <= clock())
	{
		vertex[1][1][0] = { 1.01f * (centre[0] / 10) + 8.99f * (vertex[1][1][0] / 10) };
		vertex[1][1][1] = { 1.01f * (centre[1] / 10) + 8.99f * (vertex[1][1][1] / 10) };

		if(    vertex[1][1][0] <= centre[0] + 0.00001
			&& vertex[1][1][0] >= centre[0] - 0.00001
			&& vertex[1][1][1] <= centre[1] + 0.00001
			&& vertex[1][1][1] >= centre[1] - 0.00001)
		{
			centre[0] = RandomFloat(-0.9, 0.9);
			centre[1] = RandomFloat(-0.9, 0.9);
			lastClock = clock() + 1000;
		}
		else
		{
			lastClock = clock() + 10;
		}

	}

	glBegin(GL_TRIANGLES);

		
		glColor3f(1,0,0);

		glVertex2fv(vertex[0][0]);
		glVertex2fv(vertex[0][1]);
		glVertex2fv(vertex[1][1]);
		
		glVertex2fv(vertex[2][2]);
		glVertex2fv(vertex[2][1]);
		glVertex2fv(vertex[1][1]);

		glColor3f(1,0, 0);
		
		glVertex2fv(vertex[0][1]);
		glVertex2fv(vertex[0][2]);
		glVertex2fv(vertex[1][1]);

		glVertex2fv(vertex[2][0]);
		glVertex2fv(vertex[2][1]);
		glVertex2fv(vertex[1][1]);
	glEnd();
}

std::vector<std::vector<std::vector<std::vector<float>>>> TrianglePoints;

void DrawTool::TriangleWall(int points)
{
	TrianglePoints = std::vector<std::vector<std::vector<std::vector<float>>>>();
	TrianglePoints =	{
							{ { { -1.0, 1.0 } },{ { 0.0, 1.0 } },{ { 1.0, 1.0 } } },
							{ { { -1.0, 0.0 } },{ { 0.0, 0.0 } },{ { 1.0, 0.0 } } },
							{ { { -1.0, -1.0 } },{ { 0.0, -1.0 } },{ { 1.0, -1.0 } } },
						};
	glBegin(GL_POINTS);

	for(int i = 0; i < TrianglePoints.size(); i++)
	{
		for(int t = 0; t < TrianglePoints[i].size(); t++)
		{
			for (int e = 0; e < TrianglePoints[i][t].size(); e++)
			{
				glVertex2f(TrianglePoints[i][t][e][0], TrianglePoints[i][t][e][1]);
			}
		}
	}
	
	glEnd();
}

void DrawTool::LoadDebugWall2D()
{
	VAO = 0;
	VBO = 0;
	
	//VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	
	//VBO
	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	
	GLfloat Vertex[]
	{
		0.0f, 0.8f, 0.0f,
		-0.8f,-0.8f, 0.0f,
		0.8f,-0.8f, 0.0f,
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex), Vertex, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(GetAttrib("vert"));
	glVertexAttribPointer(GetAttrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void DrawTool::DebugWall2D()
{
	glUseProgram(Program);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glUseProgram(0);
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





void DrawTool::DebugWall3D()
{
	std::vector<std::vector<std::vector<std::vector<float>>>> Points = std::vector<std::vector<std::vector<std::vector<float>>>>();
	Points = 
	{
		{
			{
				{ -1.0,0.0,-1.0 },
				{ 0.0,0.0,-1.0 },
				{ 1.0,0.0,-1.0 }
			},
			{
				{ -1.0,1.0,-1.0 },
				{ 0.0,1.0,-1.0 },
				{ 1.0,1.0,-1.0 }
			},
			{
				{ -1.0,-1.0,-1.0 },
				{ 0.0,-1.0,-1.0 },
				{ 1.0,-1.0,-1.0 }
			}
		}
	};


	glBegin(GL_POINTS);
	for (int i = 0; i < Points.size(); i++)
	{
		for (int t = 0; t < Points[i].size(); t++)
		{
			for (int e = 0; e < Points[i][t].size(); e++)
			{
				glVertex3f(Points[i][t][e][0], Points[i][t][e][1], Points[i][t][e][2]);
			}
		}
	}
	glEnd();
}

float DrawTool::RandomFloat(float low, float high)
{
	float f = (float) rand() / (float)RAND_MAX;

	return (f * (high - low)) + low;
}


void DrawTool::Camera()
{
	
}

void DrawTool::Hex(float x, float y, float scale)
{
	glBegin(GL_POLYGON);
	glEnd();


	//glVertex3f(x, y + (scale / 2), 0.0);
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + (scale / 3), y, 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + (scale / 3), y, 0.0);
	//glVertex3f(x + 2 * (scale / 3), y, 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + 2 * (scale / 3), y, 0.0);
	//glVertex3f(x + scale, y + (scale / 2), 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + scale, y + (scale / 2), 0.0);
	//glVertex3f(x + 2 * (scale / 3), y + (scale), 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + 2 * (scale / 3), y + (scale), 0.0);
	//glVertex3f(x + 1 * (scale / 3), y + (scale), 0.0);
	//
	//glVertex3f(x + 1 * (scale / 3), y + (scale), 0.0);
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x, y + (scale / 2), 0.0);
}
