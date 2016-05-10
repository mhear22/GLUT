#include "Draw.h"

void Draw::Square(float x, float y, float width, float height)
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

void Draw::Text(float x, float y, std::string text)
{
	glColor3f(0, 0, 1);
	glRasterPos2f(x,y);
	for (int i = 0; i < text.length() ; i++)
	{
		if(text[i] == '.')
		{
			break;
		}
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
	}
}


static clock_t lastClock = clock() + 1000;
static float vertex[3][3][2] = {
									{{-1,-1},{-1,0},{-1,1}},
									{{ 0,-1},{0, 0},{0, 1}},
									{{ 1,-1},{1, 0},{1, 1}}
								};
static float centre[2] = {0,0};

void Draw::TriangleWall()
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

float Draw::RandomFloat(float low, float high)
{
	float f = (float) rand() / (float)RAND_MAX;

	return (f * (high - low)) + low;
}

void Draw::Hex(float x, float y, float scale)
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