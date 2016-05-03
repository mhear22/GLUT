#include "Game.h"

Game::Game()
{
	int argc = 0;
	char** argv = { };
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400,400);
	glutCreateWindow("window");
	glutFullScreen();
	glutKeyboardUpFunc(KeyPress);
	glutMouseFunc(Mouse);
	glutDisplayFunc(Draw);
	glutIdleFunc(Draw);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glutMainLoop();
}

static high_resolution_clock::time_point lastFrame = high_resolution_clock::now();
static float FPS = 0.0f;

void Game::CheckFPS()
{
	high_resolution_clock::time_point currentFrame = high_resolution_clock::now();
	
	duration<float> delta = duration_cast<duration<float>>(currentFrame - lastFrame);

	
	FPS	= 1.0/delta.count();

	lastFrame = currentFrame;
}

int i = 0;

void Game::Draw()
{
	std::thread t1(CheckFPS);
	t1.detach();

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		
		if(i == 0)
		{
			DrawSquare(-0.9,-0.9,1.8,1.8);
			i = 1;
		}
		else
		{
			i = 0;
		}

	glEnd();
	glutSwapBuffers();
}

void Game::DrawHex(float x, float y, float scale)
{
	


	glVertex3f(x, y + (scale / 2), 0.0);
	glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	glVertex3f(x + (scale / 3), y, 0.0);

	glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	glVertex3f(x + (scale / 3), y, 0.0);
	glVertex3f(x + 2 * (scale / 3), y, 0.0);

	glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	glVertex3f(x + 2 * (scale / 3), y, 0.0);
	glVertex3f(x + scale, y + (scale / 2), 0.0);

	glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	glVertex3f(x + scale, y + (scale / 2), 0.0);
	glVertex3f(x + 2 * (scale / 3), y + (scale), 0.0);

	glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	glVertex3f(x + 2 * (scale / 3), y + (scale), 0.0);
	glVertex3f(x + 1 * (scale / 3), y + (scale), 0.0);

	glVertex3f(x + 1 * (scale / 3), y + (scale), 0.0);
	glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	glVertex3f(x, y + (scale / 2), 0.0);
}

void Game::DrawSquare(float x, float y, float width, float height)
{
	glVertex3f(x, y, 0);
	glVertex3f(x + width, y, 0);
	glVertex3f(x + width, y + height, 0);

	glVertex3f(x + width, y + height, 0);
	glVertex3f(x, y + height, 0);
	glVertex3f(x, y, 0);
}

void Game::KeyPress(unsigned char key, int x, int y)
{
	//escape
	if (key == 27)
	{
		exit(0);
	}

	//alt enter
	if (key == 13)
	{
		glutReshapeWindow(400,400);
		glutPositionWindow(0,0);
	}


}

void Game::Mouse(int button, int state, int x, int y)
{
	
}
