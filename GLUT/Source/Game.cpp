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
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glutMainLoop();
}


static clock_t currentTime = clock_t();

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
int i2 = 0;

void Game::Draw()
{
	std::thread t1(CheckFPS);
	t1.detach();
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.1,0.1,0.1);
	Draw::Square(-1,-1,2,2);

	glutSwapBuffers();
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
